import requests
import sys
import subprocess
import time
from bs4 import *
from urllib.parse import urlparse
from urllib.parse import urlsplit
from requests.exceptions import ConnectionError
from requests.packages.urllib3.exceptions import MaxRetryError
from requests.packages.urllib3.exceptions import ProxyError as urllib3_ProxyError
from lxml.html import fromstring
import requests
from itertools import cycle
import traceback

def get_proxies():
    url = 'https://free-proxy-list.net/'
    response = requests.get(url)
    parser = fromstring(response.text)
    proxies = set()
    for i in parser.xpath('//tbody/tr')[:10]:
        if i.xpath('.//td[7][contains(text(),"yes")]'):
            proxy = ":".join([i.xpath('.//td[1]/text()')[0], i.xpath('.//td[2]/text()')[0]])
            proxies.add(proxy)
    return proxies

sleep_time = 10
sleep_freq = 1

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def expected_time(lines):
    mini = float(lines)/float(100)
    add_sl = (float(sleep_time)*float(lines))/(float(sleep_freq)*float(60))
    eprint("Estimated Waiting time... : ",mini+add_sl," minutes ,","Total URLS: ",lines)

urls_file = open('out.txt', 'w')
sys.stdout = urls_file

# EDIT these
contest_id = 1324
problem_id = 560265
page_start = 1
page_end = 4

x = "https://codeforces.com/contest/"+str(contest_id)+"/standings/page/"

count_accepted = 0
proxies = get_proxies()
proxy_pool = cycle(proxies)

for k in range(page_start,page_end+1):
    
    proxy = next(proxy_pool)  
    y=str(str(x)+str(k))
    response = requests.get(y) #,proxies={"http": proxy, "https": proxy}
    html = response.content
    soup = BeautifulSoup(html, "html5lib")
    table = soup.find_all(problemid=problem_id)
    time.sleep(1)
    if ((k % sleep_freq) == 0):
      eprint("Sleeping.....",sleep_time," seconds")
      time.sleep(sleep_time)

    for p in table:
    	try:
    		list_books = p.select(".acceptedsubmissionid")
    		print("https://codeforces.com/contest/"+str(contest_id)+"/submission/"+str(p['acceptedsubmissionid']))
    		count_accepted+=1
    		eprint("scraping accepted submission URLS... ",count_accepted,", page ",k)
    	except:
    		eprint("Skipping. Connnection error")

eprint("ACCEPTED =",count_accepted)
extracted = count_accepted
urls_file.close()
