#!/usr/bin/python3

import os

key = os.urandom(32).hex()
with open('key.hex', 'w') as hexkey:
	hexkey.write(key)

print(key)
