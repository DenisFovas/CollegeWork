#!/usr/bin/python3

from Models import PPMImage
from Service import YUVFormater, CompressedImageService
import os
import datetime

if __name__ == "__main__":
    ppm_image = PPMImage.PPMImage(os.getcwd() + "/resources/nt-P3.ppm")
    yuv_format = YUVFormater.YUVFormater(ppm_image.width, ppm_image.height)
    print("Changing the format from RGB to YUV..." + str(datetime.datetime.now()))
    yuv_format.insertPixels(ppm_image.image)
    print("Downsapling the matrices..." + str(datetime.datetime.now()))
    yuv_format.downsapling()
    print("Compressing the matrices..." + str(datetime.datetime.now()))
    yuv_format.u_compressed_image = CompressedImageService.CompressedImageService.compress_matrix_by_2(yuv_format.u_compressed_image)
    yuv_format.v_compressed_image = CompressedImageService.CompressedImageService.compress_matrix_by_2(yuv_format.v_compressed_image)
    yuv_format.u_compressed_image.print()
    yuv_format.v_compressed_image.print()
