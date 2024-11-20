#!/usr/bin/python3

import sys
import os
import argparse
import requests
import re
import shutil
from bs4 import BeautifulSoup
from urllib.parse import urljoin
'''
/Users/shenya/Library/Python/3.9/lib/python/site-packages/urllib3/__init__.py:34: 
NotOpenSSLWarning: urllib3 v2.0 only supports OpenSSL 1.1.1+, 
currently the 'ssl' module is compiled with 'LibreSSL 2.8.3'. 
See: https://github.com/urllib3/urllib3/issues/3020
'''
import time

'''
Parse and receive arguments for the program
'''
def get_args():
    parser = argparse.ArgumentParser(prog='Spider')
    parser.add_argument('-r', action='store_true', dest='rec', required=False)
    parser.add_argument('-l', nargs=1, action='store', dest='l', type =int, default=[2])
    parser.add_argument('-p', nargs=1, action = 'store', dest='p', default=['./data/'])
    parser.add_argument(nargs=1, action = 'store', dest='url')
    args = parser.parse_args()
    #parser.print_help()
    return (args)

'''
helper function to print all the received arguments
'''
def print_args(args):
    print("Recurse:\t", args.rec, type(args.rec))
    if (args.rec == True):
        print("levels: ", args.l[0], type(args.l[0]))
    print("Path:\t\t", args.p, type(args.p))
    print("URL:\t\t", args.url, type(args.url))

def parse_url(img_url, web_url):
    new_url = urljoin(str(img_url), str(web_url))
    return (new_url)

def make_directory(path):
    if (os.path.isdir(path)):
        return (1)
    try:
        os.mkdir(path)
        return (1)
    except Exception as e:
        print (f"Exception: {e}")
        return (0)

def scan_and_find(web_url, link, r, r_levels, save_path, idx, page):
    if (idx == r_levels):
        return
    if (page == 0):
        return
    soup = BeautifulSoup(page, 'html.parser')
    # check if BS4 or requests returns a html or a file
    #/Users/shenya/das-kleine-projekt/AOC_2023/python/spider/./spider:55: MarkupResemblesLocatorWarning: The input looks more like a filename than markup. 
    #You may want to open this file and pass the filehandle into Beautiful Soup.
    image_elements = soup.find_all('img')
    if (image_elements == 0):
        return
    image_urls =  [img['src'] for img in image_elements]
    for url in image_urls:
        if url is not None:
            if url.startswith('https://'):
                continue
            else:
                url = urljoin(web_url, url)
            file_name = save_path + url.replace('/', '_')
            print(idx, ": ", link, " ", url, " ", file_name)
        res = requests.get(url, stream = True)
        if res.status_code == 200:
            with open(file_name,'wb') as f:
                shutil.copyfileobj(res.raw, f)
            print('Done!!')
        else:
            print('\t\t FAILED!!', url,  res.status_code)
    links = soup.find_all("a")
    if (links == 0):
        return
    arr = []
    for link in links:
        if link is not None:
            arr.append(link.get("href"))
        #print(link.get("href"))
    for link in arr:
        if link is not None:
            if link.startswith('https://'):
                continue
            else:
                link = urljoin(web_url, link)
            new_page = requests.get(link).text
            scan_and_find(web_url, link, r, r_levels, save_path, idx + 1, new_page)

def main():
    args = get_args()
    # make directory if there is no data directory 
    # or mentioned path
    print_args(args)
    # check robots.txt maybe?
    # page = requests.get(args.url[0] + "/robots.txt").text
    # print(page)
    if (make_directory(args.p[0]) == 0):
        return
    scan_and_find(args.url[0], args.url[0], args.rec, args.l[0], args.p[0], 0, requests.get(args.url[0]).text)
    # find_links(args)

if __name__ == "__main__":
    main()
