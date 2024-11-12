from bs4 import BeautifulSoup
import requests
import re
import shutil

mainurl = 'https://en.wikipedia.org/wiki/Main_Page'
ext = 'iso'

# sends a get reuest to specified url
# https://www.w3schools.com/python/ref_requests_get.asp
# parameters url, params, allow_redirects, auth, cert, cookies, headers
# proxies, stream, timeout, verify
# returns: requests.response object, .text Returns the content of the response, in unicode
page = requests.get(mainurl).text
# https://realpython.com/beautiful-soup-web-scraper-python/
# takes requests.response.text or .content as input - HTML content scraped
# use appropriate parser and returns a beautifulsoup object
soup = BeautifulSoup(page, 'html.parser')
#https://brightdata.com/faqs/beautifulsoup/extract-image-urls
# Step 5: Extract image URLs from HTML
# Example: Find all image elements and extract their 'src' attributes
image_elements = soup.find_all('img')
image_urls = [img['src'] for img in image_elements]

# Step 6: Print the extracted image URLs
name = "img"
num = 1
for url in image_urls:
	file_name = name + "_" + str(num) + re.split(r'/', url.lstrip('/'))[-1]
	if ((url[0] == '.') & (url[1] == '/')):
		new_url = mainurl+url.removeprefix('./')
	elif((url[0] == '/') & (url[1] != '/')):
		new_url = mainurl+url#.removeprefix('/')
	elif((url[0] == '/') & (url[1] == '/')):
		new_url = "https:"+url
	else:
		new_url = url
	res = requests.get(new_url, stream = True)
	if res.status_code == 200:
		with open(file_name,'wb') as f:
			shutil.copyfileobj(res.raw, f)
		print('Image sucessfully Downloaded: ',file_name)
	else:
		print('Image Couldn\'t be retrieved', url, new_url,  res.status_code)
	num += 1
