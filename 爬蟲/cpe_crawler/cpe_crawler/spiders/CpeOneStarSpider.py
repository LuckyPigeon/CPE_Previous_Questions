# -*- coding: utf-8 -*-
import itertools, requests, os, scrapy
from bs4 import BeautifulSoup
from cpe_crawler.items import CpeCrawlerItem

class CpePreviousSpider(scrapy.Spider):
    name = 'cpeonestarspider' # 爬蟲的名稱
    allowed_domains = ['jennaweng0621.pixnet.net', 'uva.onlinejudge.org', 'onlinejudge.org']# 爬蟲允許瀏覽的網域
    start_urls = ['https://jennaweng0621.pixnet.net/blog/post/403629785-cpe%E9%A1%8C%E7%9B%AE%E7%9B%AE%E9%8C%84%E5%8F%8A%E8%A7%A3%E7%AD%94'] # 該爬蟲的初始網頁

    def parse(self, response):
        tables = response.xpath('//div/table').extract() # 使用 xpath XML 路徑語言定義需要爬取的 div 標籤下的 table 表格
                                                         # extract() 選取元素字串
        one_star = tables[0]  # 爬完的 data type 是 list ，僅使用 index=0 的 table 標籤內容

        soup = BeautifulSoup(one_star, 'html.parser') # BeautifulSoup 是一個 python 套件，解析 html 資料方便後續萃取資料

        one_star_url = soup.select('table > tbody > tr > td > a') # 選取 table 中含有 <a>（超連結）的 html 標籤，會有多個，因此會是 list
        one_star_url = [x.get('href') for x in one_star_url] # 獲取每個 <a> 標籤中的 href 參數（連結網址）

        one_star_id = soup.select('table > tbody > tr > td') # 取得 <td> 標籤（欄）

        # 以下四行是為了取得 UVA 題目編號（僅有號碼）
        one_star_id = [x.text.split('(')[1].strip(r')|\xa0') for x in one_star_id if '(' in x.text]
        one_star_id = [x.split('\xa0')[0] for x in one_star_id]
        one_star_id = [x.split(')')[0] for x in one_star_id]
        one_star_id = [x.strip('UVA') for x in one_star_id]

        for index in range(len(one_star_id)): # 遍歷所有題目，設定 index 為 0~ 題數
            item = CpeCrawlerItem() # item 為 CpeCrawlerItem 物件，該物件定義爬取項目的欄位名稱 ( Scheme )

            item['id'] = one_star_id[index] # 將物件的 id 設為 UVA 題目編號

            yield scrapy.Request(url=response.urljoin(one_star_url[index]), callback=self.parseCode, meta={'question': item})
            # 產生器產生 Request ，並產出 request
            # url: 使用 line 19 取得的 url 前往有 cpp 檔案的 blog 網址。
            # callback: 使用 parseCode 的 function 爬取 cpp 檔案
            # meta: item 物件跟著 response 送進 callback

    def parseCode(self, response):
        FOLDER_BASE = 'D:\\CPE\\一星題\\'   # output 根目錄名稱
        current_dir = FOLDER_BASE + response.meta['question']['id'] + '\\' # 各題目的目錄名稱
        code_name = response.meta['question']['id'] + '.cpp' # 生成題目 code 的 cpp 檔名
        article_content = response.xpath('//div[@id="article-content-inner"]').extract() # 選取 id 為 article-content-inner 的 div 標籤
        url = 'https://onlinejudge.org/external/' + response.meta['question']['id'][:-2] + '/' + response.meta['question']['id'] + '.pdf'
        # 爬取 pdf 檔，格式為 ( url ) + ( 題目 id %100 ) + ( 題目 id.pdf )

        soup = BeautifulSoup(article_content[0], 'html.parser') # bs4 做處理

        if not os.path.exists(current_dir): # 還沒有題目目錄的話就建立目錄
            os.mkdir(current_dir)
            print('CREATE FOLDER!!!' + response.meta['question']['id'])

        with open(current_dir + code_name, 'w') as f: # 寫入 cpp 檔
            f.write(soup.text.strip('\n').replace('\xa0', '')) # 去除無用空白

        yield scrapy.Request(url=url, callback=self.parsePdf, meta={'question': response.meta['question']})
        # 產生爬取 pdf 的 request ，送進 meta （內容為 question ）給 callback (parsePdf)

    def parsePdf(self, response):
        FOLDER_BASE = 'D:\\CPE\\一星題\\'
        current_dir = FOLDER_BASE + response.meta['question']['id'] + '\\' # 資料夾
        
        with open(current_dir + response.meta['question']['id'] + '.pdf', 'wb') as f: # 寫入 pdf 檔
            f.write(response.body)
