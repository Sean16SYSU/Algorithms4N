import numpy as np
import matplotlib.pyplot as plt
import os
import shutil
import imageio


def plotAndSave(X, Y, path):
    plt.cla()
    plt.bar(X, Y)
    plt.savefig(path)


def checkfile(path):
    if not os.path.exists(path):
        os.mkdir(path)
    else:
        shutil.rmtree(path)
        os.mkdir(path)


if __name__ == '__main__':
    size = 30
    path = './PNG'
    algorithmname = '简单排序'
    Xs = list(range(size))
    A = np.random.randint(-10, 10, size)

    checkfile(path)

    PNGLIST = []

    i, j, times = 0, 0, 0
    PNGLIST.append(os.path.join(path, str(times) + '.png'))
    times += 1
    plotAndSave(Xs, A, PNGLIST[-1])
    while i < size - 1:
        j = i + 1
        while j < size:
            if A[i] > A[j]:
                A[i], A[j] = A[j], A[i]
                if times % 2 == 0:
                    PNGLIST.append(os.path.join(path, str(times) + '.png'))
                    plotAndSave(Xs, A, PNGLIST[-1])
                times += 1
            j += 1
        i += 1
    PNGLIST.append(os.path.join(path, str(times) + '.png'))
    plotAndSave(Xs, A, PNGLIST[-1])
    
    generated_images = []
    for png_path in PNGLIST:
        generated_images.append(imageio.imread(png_path))
    shutil.rmtree(path)
    generated_images = generated_images + [generated_images[-1]] * 5
    imageio.mimsave(algorithmname + '.gif', generated_images, 'GIF', duration=0.1)

