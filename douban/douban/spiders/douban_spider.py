# -*- coding: utf-8 -*-
import scrapy

class DoubanSpiderSpider(scrapy.Spider):
    #爬虫名字
    name = 'douban_spider'
    #允许的域名 爬取url都属于这个域名
    allowed_domains = ['movie.douban.com']
    #起始url
    start_urls = ['https://movie.douban.com/top250/']

    def parse(self, response):
        print(response.text)  # 打印响应内容
        pass
