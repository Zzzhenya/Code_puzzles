#!/usr/bin/python3

import argparse
import sys
from cryptography.fernet import Fernet
import pyotp
import os

def get_args():
    parser = argparse.ArgumentParser()
    group = parser.add_mutually_exclusive_group(required = True)
    group.add_argument('-g', action='store', dest='g')
    group.add_argument('-k', action='store', dest='k')
    args = parser.parse_args()
    if (len(sys.argv) < 3):
        return (args, True)
    if (len(sys.argv[2]) < 1):
        return (args, True)
    return (args, False)

def print_args():
    print(f'{"cmd":8}: {sys.argv[1][1]}')
    print(f'{"link":8}: {sys.argv[2]}')

def key_is_64(hexa_key):
    if (len(hexa_key) < 64):
        raise Exception('Error: Key too short: len should be at least 64')
    # if (len(hexa_key) > 64):
    #     raise Exception('Error: Key too long: len should be 64')

def key_is_hexa(hexa_key):
    try:
        val = int(hexa_key, 16)
    except:
        raise Exception('Error: Key is not hexadecimal')

def process_and_store_key(file):
    if os.path.isfile(file):
        with open(file, 'rb') as f:
            hexa_key = f.read()
        hexa_key = str(hexa_key)[2:-3]
        print(hexa_key)
    else:
        hexa_key = file
    key_is_64(hexa_key)
    key_is_hexa(hexa_key)
    key = Fernet.generate_key()
    fernet = Fernet(key)
    with open('ft_otp.fernet', 'wb') as filekey:
        filekey.write(key)
    encMessage = fernet.encrypt(hexa_key.encode())
    with open('ft_otp.key', 'wb') as encodedkey:
        encodedkey.write(encMessage)
    print("Hexa original:\t\t\t",hexa_key, " : ", len(hexa_key))
    print("Fernet key:\t\t\t", key, " : ", len(key))
    print("Hexa encoded with fernet:\t", encMessage, " : ", len(encMessage))


def generate_temp_password(key_file):
    # with open('ft_otp.fernet', 'rb') as filekey:
    #     key = filekey.read()
    # fernet = Fernet(key)
    with open(key_file, 'rb') as file:
        original = file.read()
    # print(str(fernet.decrypt(original))[2:-1])
    # create a new temporary password
    import pyotp
    import time
    #
    totp = pyotp.TOTP('base32secret3232')
    val = totp.now()
    print(val) # => '492039'
    while (1):
    # OTP verified for current time
        print(totp.now())
        print(totp.verify(val)) # => True
        time.sleep(1)


def main():
    args, empty_args = get_args()
    if (not empty_args):
        print_args()
    else:
        return
    
    if (sys.argv[1][1] == 'g'):
        try:
            process_and_store_key(args.g)
        except Exception as e:
            print(f'{e}')
    else:
        generate_temp_password(args.k)
    

if __name__ == "__main__":
    main()
