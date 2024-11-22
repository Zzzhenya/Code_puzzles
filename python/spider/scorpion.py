#!/usr/bin/python3

import sys
import time
import os
import PIL
from PIL import Image
from PIL.ExifTags import TAGS


def get_exif(file_path):
    image = Image.open(file_path)
    print(f"{'File path':25}: {image.filename}")
    name = image.filename
    while (name.find('/') != -1):
        name = name[name.find('/') + 1:]
    print(f"{'File name':25}: {name}")
    print(f"{'Created time':25}: {time.ctime(os.path.getctime(file_path))}")
    print(f"{'Modified time':25}: {time.ctime(os.path.getmtime(file_path))}")
    print(f"{'Image size':25}: {image.size}")
    print(f"{'Image format':25}: {image.format}")
    print(f"{'Image mode':25}: {image.mode}")
    exifdata = image.getexif()
    if exifdata is not None:
        for tag_id in exifdata:
            # get the tag name, instead of human unreadable tag id
            tag = TAGS.get(tag_id, tag_id)
            data = exifdata.get(tag_id)
            # decode bytes 
            if isinstance(data, bytes):
                data = data.decode()
            print(f"{tag:25}: {data}")

def main():
    argc = 0
    for arg in sys.argv:
        argc += 1
    if (argc < 2):
        print("At least one file path")
    else:
        i  = 1
        while (i < argc):
            try:
                get_exif(sys.argv[i])
            except Exception as e:
                print(f"{'File':25}: {sys.argv[i]}")
                print (f"Exception: {e}")
            print("=========================================")
            i += 1

if __name__ == '__main__':
    main()