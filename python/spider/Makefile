NAME = spider

all:$(NAME)

#brew install virtualenv
#python3 -m venv env
#virtualenv env
$(NAME): requirements.txt spider.py Makefile
	virtualenv env
	. env/bin/activate && pip3 install --upgrade pip && pip3 install -r requirements.txt  
	cp spider.py spider && chmod +x spider
	cp scorpion.py scorpion && chmod +x scorpion

fclean: 
	rm -rf spider
	rm -rf scorpion
	rm -rf env
	rm -rf data


#Python/3.9/lib/python/site-packages/urllib3/__init__.py:34: NotOpenSSLWarning: urllib3 v2.0 only supports OpenSSL 1.1.1+, currently the 'ssl' module is compiled with 'LibreSSL 2.8.3'. See: https://github.com/urllib3/urllib3/issues/3020
 # warnings.warn(54