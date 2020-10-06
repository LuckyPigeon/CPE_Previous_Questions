# -*- coding: utf-8 -*-
import itertools, requests, os, scrapy
from bs4 import BeautifulSoup
from cpe_crawler.items import CpeCrawlerItem

class CpePreviousSpider(scrapy.Spider):
    name = 'cpespreviouspider'
    allowed_domains = ['cpe.cse.nsysu.edu.tw', 'uva.onlinejudge.org']
    start_urls = ['https://cpe.cse.nsysu.edu.tw/cpe/test_data/problems/']

    def parse(self, response):
        tables = response.xpath('//div/table').extract()

        for table in tables:
            soup = BeautifulSoup(table, 'html.parser')
            question_urls = soup.select('table > tr > td > a')
            if len(question_urls) == 6:
                for index in range(6):
                    item = CpeCrawlerItem()
                    item['id'] = question_urls[index].text.strip('\t|\r|\n').split(':')[0]
                    item['pdf'] = question_urls[index].get('href')
                    item['code'] = ''
                    yield scrapy.Request(url=response.urljoin(item['pdf']), callback=self.parsePdf, meta={'question': item})
            else:
                questions_group = [x for x in question_urls if '/testData/' not in x.get('href')]
                questions_group = [[x for x in itertools.islice(questions_group, start, start+3)] for start in range(0, len(questions_group), 3)] 
                for question in questions_group:
                    item = CpeCrawlerItem()
                    item['id'] = question[0].text.strip('\t|\r|\n').split(':')[0]
                    item['pdf'] = question[1].get('href')
                    item['code'] = question[2].get('href')
                    yield scrapy.Request(url=response.urljoin(item['code']), callback=self.parseCode, meta={'question': item})

        # soup = BeautifulSoup(tables[-1], 'html.parser')
        # question_urls = soup.select('table > tr > td > a')
        # if len(question_urls) == 6:
        #     for index in range(6):
        #         item = CpeCrawlerItem()
        #         item['id'] = question_urls[index].text.strip('\t|\r|\n').split(':')[0]
        #         item['pdf'] = question_urls[index].get('href')
        #         item['code'] = ''
        #         print('TITLE: ' + item['id'])
        #         yield scrapy.Request(url=response.urljoin(item['pdf']), callback=self.parsePdf, meta={'question': item})
        # else:
        #     questions_group = [x for x in question_urls if '/testData/' not in x.get('href')]
        #     questions_group = [[x for x in itertools.islice(questions_group, start, start+3)] for start in range(0, len(questions_group), 3)] 
        #     for question in questions_group:
        #         item = CpeCrawlerItem()
        #         item['id'] = question[0].text.strip('\t|\r|\n').split(':')[0]
        #         item['pdf'] = question[1].get('href')
        #         item['code'] = question[2].get('href')
        #         yield scrapy.Request(url=response.urljoin(item['code']), callback=self.parseCode, meta={'question': item})
    
    def parsePdf(self, response):
        FOLDER_BASE = 'D:\\CPE\\CPE\\'
        current_dir = FOLDER_BASE + response.meta['question']['id'] + '\\'
        pdf_name = os.path.basename(response.meta['question']['pdf'])

        if not os.path.exists(current_dir):
            os.mkdir(current_dir)
            print('CREATE FOLDER!!!' + response.meta['question']['id'])

        with open(current_dir + pdf_name, 'wb') as f:
            f.write(response.body)

    def parseCode(self, response):
        FOLDER_BASE = 'D:\\CPE\\歷屆試題\\'
        current_dir = FOLDER_BASE + response.meta['question']['id'] + '\\'
        pdf_name = os.path.basename(response.meta['question']['pdf'])
        code_name = os.path.splitext(os.path.basename(response.meta['question']['code']))[0] + '.cpp'

        pdf_response = requests.get(response.meta['question']['pdf'])
        code_response = ''.join(response.xpath('//pre/text()').extract()[0].split('\r')).strip('\n')

        if not os.path.exists(current_dir):
            os.mkdir(current_dir)
            print('CREATE FOLDER!!!' + response.meta['question']['id'])

        with open(current_dir + pdf_name, 'wb') as f:
            f.write(pdf_response.content)

        with open(current_dir + code_name, 'w') as f:
            f.write(code_response)
