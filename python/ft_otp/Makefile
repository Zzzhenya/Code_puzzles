NAME = ft_otp

all:$(NAME)

#brew install virtualenv
#python3 -m venv env
#virtualenv env
$(NAME): requirements.txt ft_otp.py Makefile
	python3 -m venv env
	. env/bin/activate && pip3 install --upgrade pip && pip3 install -r requirements.txt  && python3 -m pip install --upgrade Pillow && pip3 install isHex && pip3 install pyotp
# 	chmod +x ft_otp
# 	cp spider.py spider && chmod +x f
# 	cp scorpion.py scorpion && chmod +x scorpion

fclean: 
	rm -rf ft_otp
	rm -rf env