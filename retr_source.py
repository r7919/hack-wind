import requests
import os
import shutil
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

folder = 'trash/'
for filename in os.listdir(folder):
    file_path = os.path.join(folder, filename)
    try:
        if os.path.isfile(file_path) or os.path.islink(file_path):
            os.unlink(file_path)
        elif os.path.isdir(file_path):
            shutil.rmtree(file_path)
    except Exception as e:
        print('Failed to delete %s. Reason: %s' % (file_path, e))

all_lines = sum(1 for line in open('out.txt'))
input_urls = open('out.txt', 'r')
sys.stdin = input_urls

# EDIT these
# till_url_line = 10
till_url_line = all_lines
till_url_line = min(all_lines,till_url_line)
expected_time(till_url_line)

cpp = 0

for k in range(1,till_url_line+1):
    
    url = input()
    response = requests.get(url)
    html = response.content
    soup = BeautifulSoup(html, "html5lib")
    table = soup.find(id="program-source-text")
    s = table.text
    # cpp files filter 
    if (s.find('#include') != -1): 
      cpp+=1
      g = open('trash/'+str(cpp)+'.cpp', 'w')
      sys.stdout = g
      print("// SOURCE: ","[",url,"]")
      print(table.text)
      g.close()
      eprint("Extracting cpp submissions... ",cpp)

input_urls.close()
