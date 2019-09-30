import numpy as np
import random


def read_data(file='data.txt'):
    with open(file, 'r') as f:
        N = int(f.readline().replace('\n', ''))
        Mat = [0] * 10
        for i in range(N):
            Mat[i] = list(map(int, f.readline().replace('\n', '').split(' ')))
    return N, Mat


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


if __name__ == '__main__':
    N, Mat = read_data()

    LEN = 25
    pc, pm = 0.7, 0.97
    NOTMORETHANstayINGV = 10

    packValue, pack = initial()

    tempLEN = LEN * LEN
    tempPack = [[0] * N] * tempLEN
    tempPackValue = [0] * tempLEN

    tempIndex = 0

    global_Value = packValue[0]
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
