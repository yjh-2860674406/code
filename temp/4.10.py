import requests
from bs4 import BeautifulSoup

url = "https://www.baidu.com/"
header = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.114 Safari/537.36"}

req = requests.get(url=url, headers = header)

print(req.text)