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


def MergeSort(A, s, e):

    global PNGLIST, times

    if s >= e:
        return None
    mid = (s + e) // 2
    MergeSort(A, s, mid)
    MergeSort(A, mid + 1, e)

    i, j, tot = s, mid + 1, 0
    B = A.copy()

    while i <= mid and j <= e:
        if A[i] > A[j]:
            B[tot] = A[j]
            j += 1
        else:
            B[tot] = A[i]
            i += 1
        tot += 1
    while i <= mid:
        B[tot] = A[i]
        i += 1
        tot += 1
    while j <= e:
        B[tot] = A[j]
        j += 1
        tot += 1

    for i in range(tot):
        A[s + i] = B[i]

    PNGLIST.append(os.path.join(path, str(times) + '.png'))
    plotAndSave(Xs, A, PNGLIST[-1])
    times += 1


if __name__ == '__main__':
    size = 30
    path = './PNG'
    algorithmname = '归并排序'
    Xs = list(range(size))
    A = np.random.randint(-10, 10, size)

    checkfile(path)

    PNGLIST = []

    i, j, times = 0, 0, 0
    PNGLIST.append(os.path.join(path, str(times) + '.png'))
    plotAndSave(Xs, A, PNGLIST[-1])
    times += 1

    MergeSort(A, 0, size-1)
    PNGLIST.append(os.path.join(path, str(times) + '.png'))
    plotAndSave(Xs, A, PNGLIST[-1])

    generated_images = []
    for png_path in PNGLIST:
        generated_images.append(imageio.imread(png_path))
    shutil.rmtree(path)
    generated_images = generated_images + [generated_images[-1]] * 5
    imageio.mimsave(algorithmname + '.gif', generated_images, 'GIF', duration=0.1)

