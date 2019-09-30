import numpy as np
import random
import matplotlib.pyplot as plt
import os
import shutil
import imageio

def create_data(N, xu=10, yu=10, xd=-10, yd=-10):
    fx = lambda: random.random() * (xu - xd) + xd
    fy = lambda: random.random() * (yu - yd) + yd
    calDistance = lambda x, y: np.sqrt((x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2)

    points = [(0, 0)] * N
    for i in range(N):
        points[i] = (fx(), fy())
    Mat = np.zeros((N, N))
    for i in range(N):
        for j in range(i + 1, N):
            dv = calDistance(points[i], points[j])
            Mat[i][j], Mat[j][i] = dv, dv
    return points, Mat


def calpathValue(path):
    global Mat
    temp = Mat[0][path[0]]
    for i in range(len(path) - 1):
        temp += Mat[path[i]][path[i + 1]]
    temp += Mat[path[-1]][0]
    return temp


def initial():
    global N
    init = list(range(1, N, 1))
    pack = [0] * LEN
    packValue = [0] * LEN
    for i in range(LEN):
        random.shuffle(init)
        data = init
        pack[i] = data.copy()
        packValue[i] = calpathValue(pack[i])
    indexes = np.argsort(packValue)
    pack = np.array(pack)[indexes]
    packValue = np.sort(packValue)
    return packValue, pack


# i: pack
def preserve(i):
    global tempPack, tempPackValue, pack, packValue, tempIndex
    tempPackValue[tempIndex] = packValue[i]
    tempPack[tempIndex] = pack[i].copy()
    tempIndex += 1


def select():
    global N, pack, tempPack, tempPackValue, tempIndex, LEN, packValue

    tpk = tempPack[:tempIndex]
    tpkv = tempPackValue[:tempIndex]

    indexes = np.argsort(tpkv)
    tpk = np.array(tpk)[indexes]
    tpkv = np.sort(tpkv)

    pack = tpk[:LEN]
    packValue = tpkv[:LEN]


def crossover(i, j):
    global N, pack, tempPack, tempPackValue, tempIndex
    times = random.randint(1, N - 2)
    indexes = [0] * times
    for t in range(times):
        if t == 0:
            indexes[t] = random.randint(0, N - times - 1)
        else:
            indexes[t] = random.randint(indexes[t - 1] + 1, N - times + t - 1)
    tempPack[tempIndex] = pack[i].copy()
    pack_j_reindex = pack[j].copy()[indexes]
    count = 0
    for v in range(N - 1):
        if count >= times: break
        if tempPack[tempIndex][v] in pack_j_reindex:
            tempPack[tempIndex][v] = pack_j_reindex[count]
            count += 1
    tempPackValue[tempIndex] = calpathValue(tempPack[tempIndex])

    tempIndex += 1
    tempPack[tempIndex] = pack[j].copy()
    pack_i_reindex = pack[i].copy()[indexes]
    count = 0
    for v in range(N - 1):
        if count >= times: break
        if tempPack[tempIndex][v] in pack_i_reindex:
            tempPack[tempIndex][v] = pack_i_reindex[count]
            count += 1
    tempPackValue[tempIndex] = calpathValue(tempPack[tempIndex])

    tempIndex += 1


def mutation(i):
    global N, pack, tempPack, tempPackValue, tempIndex
    times = random.randint(1, N - 2)
    indexes = [0] * times
    for t in range(times):
        if t == 0:
            indexes[t] = random.randint(0, N - times - 1)
        else:
            indexes[t] = random.randint(indexes[t - 1] + 1, N - times + t - 1)
    origin_indexes = indexes.copy()
    random.shuffle(indexes)
    tempPack[tempIndex] = pack[i].copy()

    for t in range(times):
        tempPack[tempIndex][indexes[t]] = pack[i][origin_indexes[t]]
    tempPackValue[tempIndex] = calpathValue(tempPack[tempIndex])
    tempIndex += 1


def draw(path, pv):
    global points, N, TIMESIT, PNGFILE, PNGLIST
    plt.cla()
    plt.title('cross=%.4f' % pv)
    xs = [p[0] for p in points]
    ys = [p[1] for p in points]
    plt.scatter(xs, ys, color='b')
    xs = np.array(xs)
    ys = np.array(ys)
    plt.plot(xs[[0, path[0]]], ys[[0, path[0]]], color='r')
    for i in range(N - 2):
        plt.plot(xs[[path[i], path[i + 1]]], ys[[path[i], path[i + 1]]], color='r')
    plt.plot(xs[[path[N - 2], 0]], ys[[path[N - 2], 0]], color='r')
    plt.scatter(xs[0], ys[0], color='k', linewidth=10)
    plt.savefig('%s/%d.png' % (PNGFILE, TIMESIT))
    PNGLIST.append('%s/%d.png' % (PNGFILE, TIMESIT))
    TIMESIT += 1


if __name__ == '__main__':
    # N, Mat = read_data()
    TIMESIT = 0
    PNGFILE = './png/'
    PNGLIST = []
    if not os.path.exists(PNGFILE):
        os.mkdir(PNGFILE)
    else:
        shutil.rmtree(PNGFILE)
        os.mkdir(PNGFILE)

    N = 20
    points, Mat = create_data(N)
    LEN = 40
    pc, pm = 0.7, 0.97
    NOTMORETHANstayINGV = 30

    packValue, pack = initial()

    tempLEN = LEN * LEN
    tempPack = [[0] * N] * tempLEN
    tempPackValue = [0] * tempLEN

    tempIndex = 0

    global_Value = packValue[0]
    draw(pack[0], global_Value)
    stayinGV = 0

    while True:
        tempIndex = 0
        for i in range(LEN):
            preserve(i)
            if random.random() < pm:
                mutation(i)
            if i == LEN - 1: break
            for j in range(i + 1, LEN):
                if tempIndex >= tempLEN: break
                if random.random() < pc:
                    crossover(i, j)
        select()
        if packValue[0] < global_Value:
            global_Value = packValue[0]
            draw(pack[0], global_Value)
            stayinGV = 0
        elif packValue[0] == global_Value:
            stayinGV += 1
        else:
            print("Something wrong")
            break
        if stayinGV == NOTMORETHANstayINGV:
            break

    print(global_Value)
    print(0, end='-->')
    for i in pack[0]:
        print(i, end='-->')

    generated_images = []
    for png_path in PNGLIST:
        generated_images.append(imageio.imread(png_path))
    shutil.rmtree(PNGFILE)  # 可删掉
    generated_images = generated_images + [generated_images[-1]] * 5
    imageio.mimsave('TSP-GA.gif', generated_images, 'GIF', duration=0.5)

