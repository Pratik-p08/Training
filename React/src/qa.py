from selenium import webdriver
from webdriver_manager.chrome  import ChromeDriverManager
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

driver=webdriver.Chrome(executable_path=ChromeDriverManager().install())
driver.maximize_window()
driver.get("http://localhost:3000/")
# driver.find_element(By.XPATH,'button[text="submit"]').send_keys("Pratik Patil")
# driver.close()

import pdb 
driver.find_element(By.XPATH,'//*[@id="title"]').send_keys("qa1 ")
driver.find_element(By.XPATH,'//*[@id="description"]').send_keys("qa description testing")
driver.find_element(By.XPATH,'//*[@id="author"]').send_keys("qa author")
driver.find_element(By.XPATH,'//*[@id="reading_time"]').send_keys("11")
driver.find_element(By.XPATH,'//*[@id="root"]/div/div[2]/button').click()
WebDriverWait(driver, 10).until(EC.invisibility_of_element_located((By.XPATH, '//*[@id="Loading"]')))

driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")

pdb.set_trace()
