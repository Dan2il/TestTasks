import logging
import sys
import cProfile
import pstats
import requests
import os
import configparser

from twocaptcha import TwoCaptcha
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.chrome.options import Options


logging.basicConfig(
    level=logging.INFO,
    format='[%(asctime)s] #%(levelname)-8s %(filename)s:%(lineno)d - %(message)s',
    handlers=[
        logging.StreamHandler(sys.stdout)  # Для вывода в stdout
    ]
)
logger = logging.getLogger()
config = configparser.ConfigParser()

# Чтение INI-файла
config.read("data.ini")


# для работы, необходимо указать api key
URL = "https://proxy6.net/"
APIKEY = config["Settings"]["APIKEY"]
EMAIL = config["Settings"]["email"]
PASSWORD = config["Settings"]["password"]


class Bot:
    def __init__(self, TIME_WAIT:int=5):
        options = Options()
        options.add_argument("--disable-bluetooth")
        options.add_argument("--ignore-certificate-errors")  # Игнорировать ошибки сертификатов
        options.add_argument("--allow-insecure-localhost")  # Позволить небезопасные соединения с localhost
        options.add_argument("--log-level=3")  # Устанавливает минимальный уровень логов (ERROR)
        options.add_argument("--headless")
        self.driver = webdriver.Chrome(options=options)

        self.driver.implicitly_wait(TIME_WAIT)
        self.driver.maximize_window()


    def __del__(self):
        self.driver.close()
        self.driver.quit()

    def __captcha_solv_recaptcha(self, sitekey: str, url: str) -> bool:
        try:
            wait = WebDriverWait(self.driver, 15)
            solver = TwoCaptcha(APIKEY)
            result = solver.recaptcha(sitekey=sitekey,
                                      url=url)
            recaptcha_response_element = wait.until(
                EC.presence_of_element_located((By.CSS_SELECTOR, "#g-recaptcha-response")))
            self.driver.execute_script(f'arguments[0].value = "{result["code"]}";', recaptcha_response_element)
            logger.info(f"solv recaptcha success")
        except Exception as e:
            logger.error(f"error solv recaptcha: {e}")
            return False
        return True

    def __captcha_solv_normal(self, captcha_url: str) -> dict:
        result = {}
        try:
            headers = {
                "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36",
                "Referer": self.driver.current_url,
            }
            session = requests.Session()
            session.headers = headers
            cookies = self.driver.get_cookies()
            cookies_dict = {cookie['name']: cookie['value'] for cookie in cookies}
            session.cookies = cookies_dict
            response = requests.get(captcha_url, cookies=cookies_dict, headers=headers, timeout=10)
            with open("captcha.png", "wb") as f:
                f.write(response.content)
            solver = TwoCaptcha(APIKEY)
            result = solver.normal('captcha.png', lang='en')
            try:
                os.remove('captcha.png')
            except Exception as e:
                logger.error(f"file deletion error: {e}")
            logger.info(f"result normal captcha {result}")
        except Exception as e:
            logger.error(f"error solv normal captcha: {e}")
        return result

    def check_normal_captcha(self) -> bool:
        wait = WebDriverWait(self.driver, 15)
        try:
            if wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#captcha img"))):
                captcha_image = wait.until(
                    EC.visibility_of_element_located((By.CSS_SELECTOR, "#captcha img")))
                url_image = captcha_image.get_attribute("src")
                captcha_image_result = self.__captcha_solv_normal(captcha_url=url_image)
                wait.until(
                    EC.visibility_of_element_located((By.CSS_SELECTOR, "input[name='sec_code']"))).send_keys(
                    captcha_image_result.get("code", ""))
                WebDriverWait(self.driver, 15).until(
                    EC.element_to_be_clickable((By.CSS_SELECTOR, "form#form-login button[type='submit']"))
                ).click()
                logger.info(f"solv normal captcha success")
            else:
                logger.info(f"normal captcha not found")
        except Exception as e:
            logger.error(f"error solv normal captcha")
            return False
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
                captcha_result = self.__captcha_solv_recaptcha(sitekey, URL)

                if captcha_result:
                    WebDriverWait(self.driver, 15).until(
                        EC.element_to_be_clickable((By.CSS_SELECTOR, "form#form-login button[type='submit']"))
                    ).click()
                    self.check_normal_captcha()
                    logger.info("Login success")
                    return True
        except Exception as e:
            logger.error(f"not success, exception: {e}")
        return False

    def get_proxy(self):
        result_proxy = []
        wait = WebDriverWait(self.driver, 15)
        try:
            wait.until(EC.presence_of_element_located((By.XPATH, "//a[contains(@href, 'proxy6.net/user/proxy')]"))).click()
            all_proxy_elements = wait.until(EC.presence_of_all_elements_located(
                (By.XPATH, "//tr[starts-with(@id, 'el-')]")))

            for proxy in all_proxy_elements:
                try:
                    ip_port = proxy.find_element(By.XPATH, ".//div[@class='right clickselect ']/b").text
                    date_time = proxy.find_element(By.XPATH, ".//div[@class='right color-success']").text
                    result_proxy.append(f"{ip_port} - {date_time}")
                    logger.info(f"append: {ip_port} - {date_time}")
                except Exception as e:
                    logger.error(f"String processing error: {proxy.get_attribute('id')}, {e}")
        except Exception as e:
            logger.error(f"Error get proxy: {e}")
        return result_proxy


def main():
    bot = Bot()
    counter_attempt = 5
    counter = 0
    while counter < counter_attempt:
        result = bot.login(EMAIL, PASSWORD)
        if result:
            proxy = bot.get_proxy()
            break
        counter += 1


if __name__ == "__main__":
    # profiler = cProfile.Profile()
    # profiler.enable()
    main()
    # profiler.disable()
    #
    # stats = pstats.Stats(profiler)
    # stats.strip_dirs()
    # stats.sort_stats("cumulative")  # Сортировка по времени
    # stats.print_stats(10)  # Показать только топ-10 функций
