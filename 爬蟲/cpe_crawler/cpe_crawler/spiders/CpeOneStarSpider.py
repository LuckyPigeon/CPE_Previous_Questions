# -*- coding: utf-8 -*-
import itertools, requests, os, scrapy
from bs4 import BeautifulSoup
from cpe_crawler.items import CpeCrawlerItem

class CpePreviousSpider(scrapy.Spider):
    name = 'cpeonestarspider'
    allowed_domains = ['jennaweng0621.pixnet.net', 'uva.onlinejudge.org', 'onlinejudge.org']
    start_urls = ['https://jennaweng0621.pixnet.net/blog/post/403629785-cpe%E9%A1%8C%E7%9B%AE%E7%9B%AE%E9%8C%84%E5%8F%8A%E8%A7%A3%E7%AD%94']

    def parse(self, response):
        tables = response.xpath('//div/table').extract()

        one_star = tables[0]

        soup = BeautifulSoup(one_star, 'html.parser')

        one_star_url = soup.select('table > tbody > tr > td > a')
        one_star_url = [x.get('href') for x in one_star_url]

        one_star_id = soup.select('table > tbody > tr > td')
        one_star_id = [x.text.split('(')[1].strip(r')|\xa0') for x in one_star_id if '(' in x.text]
        one_star_id = [x.split('\xa0')[0] for x in one_star_id]
        one_star_id = [x.split(')')[0] for x in one_star_id]
        one_star_id = [x.strip('UVA') for x in one_star_id]

        for index in range(len(one_star_id)):
            item = CpeCrawlerItem()

            item['id'] = one_star_id[index]

            yield scrapy.Request(url=response.urljoin(one_star_url[index]), callback=self.parseCode, meta={'question': item})

    def parseCode(self, response):
        FOLDER_BASE = 'D:\\CPE\\一星題\\'
        current_dir = FOLDER_BASE + response.meta['question']['id'] + '\\'
        code_name = os.path.splitext(os.path.basename(response.meta['question']['id']))[0] + '.cpp'
        article_content = response.xpath('//div[@id="article-content-inner"]').extract()
        url = 'https://onlinejudge.org/external/' + response.meta['question']['id'][:-2] + '/' + response.meta['question']['id'] + '.pdf'

        soup = BeautifulSoup(article_content[0], 'html.parser')

        if not os.path.exists(current_dir):
            os.mkdir(current_dir)
            print('CREATE FOLDER!!!' + response.meta['question']['id'])

        with open(current_dir + code_name, 'w') as f:
            f.write(soup.text.strip('\n').replace('\xa0', ''))

        yield scrapy.Request(url=url, callback=self.parsePdf, meta={'question': response.meta['question']})

    def parsePdf(self, response):
        FOLDER_BASE = 'D:\\CPE\\一星題\\'
        current_dir = FOLDER_BASE + response.meta['question']['id'] + '\\'
        
        with open(current_dir + response.meta['question']['id'] + '.pdf', 'wb') as f:
            f.write(response.body)
