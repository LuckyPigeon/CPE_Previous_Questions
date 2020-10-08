# -*- coding: utf-8 -*-
import itertools, requests, os, scrapy
from bs4 import BeautifulSoup
from cpe_crawler.items import CpeCrawlerItem

class CpePreviousSpider(scrapy.Spider):
    name = 'cpeonestarspider' # 爬蟲的名稱
    allowed_domains = ['jennaweng0621.pixnet.net', 'uva.onlinejudge.org', 'onlinejudge.org']# 爬蟲允許瀏覽的網域
    start_urls = ['https://jennaweng0621.pixnet.net/blog/post/403629785-cpe%E9%A1%8C%E7%9B%AE%E7%9B%AE%E9%8C%84%E5%8F%8A%E8%A7%A3%E7%AD%94'] # 該爬蟲的初始網頁

    def parse(self, response):
        tables = response.xpath('//div/table').extract() # 使用xpath XML路徑語言定義需要爬取的div標籤下的table表格
                                                         # extract()選取元素字串
        one_star = tables[0]  # 爬完的data type是list，僅使用index=0的table標籤內容

        soup = BeautifulSoup(one_star, 'html.parser') # BeautifulSoup是一個python套件，解析html資料方便後續萃取資料

        one_star_url = soup.select('table > tbody > tr > td > a') # 選取table中含有<a>（超連結）的html標籤，會有多個，因此會是list
        one_star_url = [x.get('href') for x in one_star_url] # 獲取每個<a>標籤中的href參數（連結網址）

        one_star_id = soup.select('table > tbody > tr > td') # 取得<td>標籤（欄）

        # 以下四行是為了取得UVA題目編號（僅有號碼）
        one_star_id = [x.text.split('(')[1].strip(r')|\xa0') for x in one_star_id if '(' in x.text]
        one_star_id = [x.split('\xa0')[0] for x in one_star_id]
        one_star_id = [x.split(')')[0] for x in one_star_id]
        one_star_id = [x.strip('UVA') for x in one_star_id]

        for index in range(len(one_star_id)): # 遍歷所有題目，設定index為0~題數
            item = CpeCrawlerItem() # item為CpeCrawlerItem物件，該物件定義所需要爬取的項目

            item['id'] = one_star_id[index] # 將物件的id設為UVA題目編號

            yield scrapy.Request(url=response.urljoin(one_star_url[index]), callback=self.parseCode, meta={'question': item})
            # 產生器產生Request，並產出request
            # url: 使用line 19取得的url前往有cpp檔案的blog網址。
            # callback: 使用parseCode的function爬取cpp檔案
            # meta: item物件跟著response送進callback

    def parseCode(self, response):
        FOLDER_BASE = 'D:\\CPE\\一星題\\'   # output根目錄名稱
        current_dir = FOLDER_BASE + response.meta['question']['id'] + '\\' # 各題目的目錄名稱
        code_name = os.path.splitext(os.path.basename(response.meta['question']['id']))[0] + '.cpp' # 生成題目code的cpp檔名
        article_content = response.xpath('//div[@id="article-content-inner"]').extract() # 選取id為article-content-inner的div標籤
        url = 'https://onlinejudge.org/external/' + response.meta['question']['id'][:-2] + '/' + response.meta['question']['id'] + '.pdf'
        # 爬取pdf檔，格式為url + 題目id%100 + 題目id.pdf

        soup = BeautifulSoup(article_content[0], 'html.parser') # bs4做處理

        if not os.path.exists(current_dir): # 還沒有題目目錄的話就建立目錄
            os.mkdir(current_dir)
            print('CREATE FOLDER!!!' + response.meta['question']['id'])

        with open(current_dir + code_name, 'w') as f: # 寫入cpp檔
            f.write(soup.text.strip('\n').replace('\xa0', '')) # 去除無用空白

        yield scrapy.Request(url=url, callback=self.parsePdf, meta={'question': response.meta['question']})
        # 產生爬取pdf的request，送進meta（內容為question）給callback(parsePdf)

    def parsePdf(self, response):
        FOLDER_BASE = 'D:\\CPE\\一星題\\'
        current_dir = FOLDER_BASE + response.meta['question']['id'] + '\\' # 資料夾
        
        with open(current_dir + response.meta['question']['id'] + '.pdf', 'wb') as f: # 寫入pdf檔
            f.write(response.body)
