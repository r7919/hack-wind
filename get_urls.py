import requests
import sys
import subprocess
from bs4 import *
from urllib.parse import urlparse
from urllib.parse import urlsplit

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def expected_time(lines):
    mini = float(lines)/float(39)
    eprint("Estimated Waiting time... : ",mini," minutes")

urls_file = open('out.txt', 'w')
sys.stdout = urls_file

# EDIT these
contest_id = 1312
problem_id = 557979
page_start = 14
page_end = 14

x = "https://codeforces.com/contest/"+str(contest_id)+"/standings/page/"

count_accepted = 0

for k in range(page_start,page_end+1):
    
    y=str(str(x)+str(k))
    response = requests.get(y)
    html = response.content
    soup = BeautifulSoup(html, "html5lib")
    table = soup.find_all(problemid=problem_id)

    for p in table:
    	try:
    		list_books = p.select(".acceptedsubmissionid")
    		print("https://codeforces.com/contest/"+str(contest_id)+"/submission/"+str(p['acceptedsubmissionid']))
    		count_accepted+=1
    		eprint("scraping accepted submission URLS... ",count_accepted)
    	except:
    		pass

eprint("ACCEPTED =",count_accepted)
extracted = count_accepted
urls_file.close()
