import numpy as np
from PIL import Image

def ImageToFFT(image):
    """
    image: a 2D numpy array
    Return: a 2D numpy array, as the FFT of the image

    You can use np.fft API.
    """
    # TODO: your code here
    raise NotImplementedError


def SampleByThreshold(size, threshold=0.8):
    """
    size: shape of the image
    threshold: threshold to set the value
    Return: an image of white noise
    """
    # TODO: your code here
    raise NotImplementedError

def SampleByWindow(size, window_size=(4, 4)):
    """
    size: shape of the image
    window_size: shape of subgrid
    Return: an image of white noise
    """
    # TODO: your code here
    raise NotImplementedError

def PoissonDiskSampling(size, radius, max_iter=100):
    """
    size: shape of the image
    radius: maximum distance between points
    max_iter: maximum number of iterations to try to add one point
    Reutrn: an image of sampled points
    """
    # TODO: your code here
    raise NotImplementedError
