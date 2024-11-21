#!/usr/bin/python3

import os
import argparse
import requests
import shutil
from bs4 import BeautifulSoup
from urllib.parse import urljoin, urlparse
from colorama import Fore, Back, Style
import time
'''
/Users/shenya/Library/Python/3.9/lib/python/site-packages/urllib3/__init__.py:34: 
NotOpenSSLWarning: urllib3 v2.0 only supports OpenSSL 1.1.1+, 
currently the 'ssl' module is compiled with 'LibreSSL 2.8.3'. 
See: https://github.com/urllib3/urllib3/issues/3020

/ The input looks more like a filename than markup. 
You may want to open this file and pass the filehandle into Beautiful Soup.
'''
'''
Parse and receive arguments for the program
'''
def get_args():
    parser = argparse.ArgumentParser(prog='Spider')
    parser.add_argument('-r', action='store_true', dest='rec', required=False)
    parser.add_argument('-l', nargs=1, action='store', dest='l', type =int, default=[5])
    parser.add_argument('-p', nargs=1, action = 'store', dest='p', default=['./data/'])
    parser.add_argument(nargs=1, action = 'store', dest='url')
    args = parser.parse_args()
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

def right_img_type(url, ftypes):
    for ty in ftypes:
        if url.endswith(ty) == True:
            return (True)
    return (False)

def find_images_get(web_url, link, save_path, idx, ftypes, url, img_arr):
    i = 1
    if url is None:
        return
    if url.startswith('https://') != True:
        url = urljoin(web_url, url)
    print(url)
    if (right_img_type(url, ftypes) != 1):
        qp_url = url[:url.find('?')]
        if right_img_type(qp_url, ftypes) != 1:
            return
        else:
            qp_url + str(i)
            i = i+1
    else:
        qp_url = url
    file_name = save_path + qp_url.replace('/', '_')
    img_arr.add(tuple([url, file_name]))

def scan_and_find(web_url, link, r, r_levels, save_path, idx, page, ftypes, img_arr):
    if (idx == r_levels):
        return
    if (page is None):
        return
    print(idx)
    soup = BeautifulSoup(page, 'html.parser')
    image_elements = soup.find_all('img')
    if (image_elements is not None):
        image_urls =  [img['src'] for img in image_elements]
        for url in image_urls:
            find_images_get(web_url, link, save_path, idx, ftypes, url, img_arr)
    if (r == False):
        return
    links = soup.find_all("a")
    if (links is None):
        return
    links = [x.get('href') for x in soup.select('a') if 'mailto' not in x.get('href')]
    arr = set()
    for link in links:
        if link is not None:
            arr.add(link)
            # arr.add(link.get("href"))
    for link in arr:
        if link is not None:
            if link.startswith('https://') != True :
                link = urljoin(web_url, link)
                print(link)
            if (link != 'javascript:void(0)'):
                new_page = requests.get(link)
                if (new_page.ok):
                    scan_and_find(web_url, link, r, r_levels, save_path, idx + 1, new_page.text, ftypes, img_arr)


def download_images(img_arr):
    file_count = 0
    long_names = 1
    for img in img_arr:
        print(img[0] , " : ", img[1])
        url = img[0]
        file_name = img[1]
        if (len(file_name) > 256):
            file_name = filename[10:] + str(long_names)
            long_names = long_names + 1
        res = requests.get(url, stream = True)
        if res.ok:
            if file_count == 5:
                time.sleep(1)
                file_count = 0
            with open(file_name,'wb') as f:
                shutil.copyfileobj(res.raw, f)
            print(Fore.GREEN + 'Success!!' + Style.RESET_ALL)
            file_count = file_count + 1
        else:
            print(Fore.RED, 'IMG FAILED!!', url,  res.status_code, Style.RESET_ALL)

def get_domain(url):
    obj = urlparse(url)
    new_url = obj.scheme + '://' + obj.netloc
    print(url, " : ", new_url)
    return (new_url)

def main():
    args = get_args()
    if (args.rec == False):
        args.l[0] = 1
    # make directory if there is no data directory 
    # or mentioned path
    print_args(args)
    # check robots.txt maybe?
    # page = requests.get(args.url[0] + "/robots.txt").text
    # print(page)
    if (make_directory(args.p[0]) == 0):
        return
    ftypes = ['.jpg', '.jpeg', '.png', '.gif', '.bmp']
    img_arr = set()
    domain = get_domain(args.url[0])
    print(domain)
    page = requests.get(args.url[0])
    if (page.ok):
        print("OK\t", args.url[0])
        scan_and_find(domain, args.url[0], args.rec, args.l[0], args.p[0], 0, page.text, ftypes, img_arr)
    # # for img in img_arr:
    # #     print(img[0] , " : ", img[1])
    if (len(img_arr) == 0):
        print('No images')
        return
    download_images(img_arr)
    # find_links(args)

if __name__ == "__main__":
    main()
