import pandas
import time
import os
import logging
import datetime

from selenium import webdriver
from selenium.webdriver.common.by import By

URL = "https://rpachallenge.com/"

class ChromeController():
    driver = None

    def __init__(self, url):
        self.driver = webdriver.Chrome()
        self.driver.maximize_window()
        if url != "" or None:
            self.driver.get(url)

    def __del__(self):
        self.driver.close()

def main():
    dir_name = os.path.dirname(os.path.abspath(__file__))
    logging.basicConfig(level=logging.INFO,filename=dir_name + "\\challenge.log",
                        filemode="a")
    logging.info("START: %s", str(datetime.datetime.now()))

    try:
        if os.path.exists(dir_name + "\\challenge.xlsx"):
            data_challenge = pandas.read_excel(dir_name + "\\challenge.xlsx")

            if not data_challenge.empty:
                # запускаем браузер и переходим на нужную страницу
                chrome = ChromeController(URL)
                logging.info("read challenge.xlsx: %s", str(datetime.datetime.now()))
                for index, row in data_challenge.iterrows():
                    # помещаем данные
                    chrome.driver.find_element(By.CSS_SELECTOR,
                                            "input[_ngcontent-c2][ng-reflect-name=\"labelFirstName\"]").send_keys(row["First Name"])
                    chrome.driver.find_element(By.CSS_SELECTOR,
                                            "input[_ngcontent-c2][ng-reflect-name=\"labelLastName\"]").send_keys(row["Last Name "])
                    chrome.driver.find_element(By.CSS_SELECTOR,
                                            "input[_ngcontent-c2][ng-reflect-name=\"labelAddress\"]").send_keys(row["Address"])
                    chrome.driver.find_element(By.CSS_SELECTOR,
                                            "input[_ngcontent-c2][ng-reflect-name=\"labelPhone\"]").send_keys(row["Phone Number"])
                    chrome.driver.find_element(By.CSS_SELECTOR,
                                            "input[_ngcontent-c2][ng-reflect-name=\"labelEmail\"]").send_keys(row["Email"])
                    chrome.driver.find_element(By.CSS_SELECTOR,
                                            "input[ng-reflect-name=\"labelCompanyName\"]").send_keys(row["Company Name"])
                    chrome.driver.find_element(By.CSS_SELECTOR,
                                            "input[_ngcontent-c2][ng-reflect-name=\"labelRole\"]").send_keys(row["Role in Company"])
                    logging.info("set data:\n%s", str(row) + "\n")
                    # нажатие клавиши SUBMIT
                    chrome.driver.find_element(By.CSS_SELECTOR, ".btn:nth-child(2)").click()
    except Exception as e:
        logging.error("ERROR: %s", str(e))

    logging.info("FINISH: %s", str(datetime.datetime.now()) + "\n")

if __name__ == "__main__":
    main()