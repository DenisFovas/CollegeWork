#!/usr/bin/python3

from models.ppm_image import PPMImage
from service.image_compression import CompressedImageService
from service.yuv_formater import YUVFormater

import os
import datetime

if __name__ == "__main__":
    ppm_image = PPMImage(os.getcwd() + "/resources/nt-P3.ppm")
    yuv_format = YUVFormater(ppm_image.width, ppm_image.height)
    print("Changing the format from RGB to YUV..." + str(datetime.datetime.now()))
    yuv_format.insertPixels(ppm_image.image)
    print("Downsapling the matrices..." + str(datetime.datetime.now()))
    yuv_format.downsapling()
    print("Compressing the matrices..." + str(datetime.datetime.now()))
    