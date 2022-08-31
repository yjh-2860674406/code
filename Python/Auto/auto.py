import json
from selenium import webdriver
from selenium.webdriver.chrome.service import Service

service = Service(r"../Auto/msedgedriver.exe")
wb = webdriver.Edge(service=service)

wb.get("https://stuhealth.jnu.edu.cn/#/login")
