import time
import logging
import sys

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC


logging.basicConfig(
    level=logging.INFO,
    format='[%(asctime)s] #%(levelname)-8s %(filename)s:%(lineno)d - %(message)s',
    handlers=[
        logging.StreamHandler(sys.stdout)  # Для вывода в stdout
    ]
)
logger = logging.getLogger()

URL = "https://proxy6.net/"


class Bot:

    def __init__(self):
        self.driver = webdriver.Chrome()
        self.driver.implicitly_wait(15)
        self.driver.maximize_window()

    @staticmethod
    def __captcha_solv(sitekey: str, url: str) -> str:
        # место для решателя капчи
        time.sleep(25)
        return True

    def login(self, email: str, password: str):
        try:
            self.driver.get(URL)
            counter = 0
            while counter < 5:
                wait = WebDriverWait(self.driver, 15)

                wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "a[data-role='login']"))).click()
                wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "input[name='email']"))).send_keys(email)
                wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "input[name='password']"))).send_keys(password)
                logger.info(f"set: {email}:{password}")

                element = wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, "div.g-recaptcha")))
                sitekey = element.get_attribute("data-sitekey")
                logger.info(f"sitekey: {sitekey}")
                captcha_result = self.__captcha_solv(sitekey, URL)
                logger.info(f"captcha_result: {captcha_result}")
                if captcha_result:
                    WebDriverWait(self.driver, 15).until(
                        EC.element_to_be_clickable((By.CSS_SELECTOR, "form#form-login button[type='submit']"))
                    ).click()
                    logger.info("Login success")
                    return True
        except Exception as e:
            logger.error(f"not success, exception: {e}")
        return False



def main():
    email = "tzpythondemo@domconnect.ru"
    password = "qJ2qY0aG0e"
    bot = Bot()
    result = bot.login(email, password)


if __name__ == "__main__":
    main()
