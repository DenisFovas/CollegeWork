from Image import PPMImage
from Service import YUVFormater
import os
import datetime

if __name__ == "__main__":
    print("Reading the image..." + str(datetime.datetime.now()))
    ppm_image = PPMImage.PPMImage(os.getcwd() + "/resources/nt-P3.ppm")
    yuv_format = YUVFormater.YUVFormater(ppm_image.width, ppm_image.height)
    print("Changing the format from RGB to YUV..." + str(datetime.datetime.now()))
    yuv_format.insertPixels(ppm_image.image)
    yuv_format.downsapling422()
    print("Done " + str(datetime.datetime.now()))
    print("Result:")
    yuv_format.y.print()
    yuv_format.u.print()
    yuv_format.v.print()