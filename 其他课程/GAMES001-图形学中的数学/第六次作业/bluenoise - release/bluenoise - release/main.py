from PIL import Image
import numpy as np
from utils import *
import os

def SaveGreyImage(image, path):
    image = (image - np.min(image)) / (np.max(image) - np.min(image)) * 255
    img = Image.fromarray(image.astype(np.uint8))
    img.save(path)

os.makedirs("output", exist_ok=True)

size = (256, 256)

noise0 = SampleByThreshold(size, 0.9375)
SaveGreyImage(noise0, 'output/noise0.png')

noise0_fft = ImageToFFT(noise0)
SaveGreyImage(noise0_fft, 'output/noise0_fft.png')

noise1 = SampleByWindow(size, (4, 4))
SaveGreyImage(noise1, 'output/noise1.png')

noise1_fft = ImageToFFT(noise1)
SaveGreyImage(noise1_fft, 'output/noise1_fft.png')

noise2 = PoissonDiskSampling(size, 3)
SaveGreyImage(noise2, 'output/noise2.png')

noise2_fft = ImageToFFT(noise2)
SaveGreyImage(noise2_fft, 'output/noise2_fft.png')
