import os


def toc(file='README.md',
        stpath='.',
        stopwith='dir',
        withlink=True,
        firstNotInSet=['.', '_']):
    def toc_f(stpath='.',
              stopwith='dir',
              withlink=True,
              firstNotInSet=['.', '_']):
        def rec_toc_f(stpath='.', stopwith='dir'):
            totalstr_arr = []

            for name in os.listdir(stpath):
                if name[0] in firstNotInSet:
                    continue
                totalpath = os.path.join(stpath, name)
                if os.path.isdir(totalpath) or stopwith == 'file':
                    if withlink:
                        totalstr_arr += [
                            '* [' + name + ']({0})'.format(totalpath[1:].replace(' ', '%20'))
                        ]
                    else:
                        totalstr_arr += ['* ' + name]
                    tmpstr = rec_toc_f(totalpath, stopwith=stopwith)
                    if tmpstr is None or len(tmpstr) == 0:
                        continue
                    tmpstr = list(map(lambda x: '   ' + x, tmpstr))
                    totalstr_arr += tmpstr
            return totalstr_arr

        tarr = rec_toc_f(stpath, stopwith)
        return '\n'.join(tarr)

    toc = toc_f(stpath=stpath,
                stopwith=stopwith,
                withlink=withlink,
                firstNotInSet=firstNotInSet)
    with open('README.md', 'r', encoding='utf-8') as f:
        data = f.read()
    if '[toc]' in data:
        toc = toc_f(stpath=stpath,
                    stopwith=stopwith,
                    withlink=withlink,
                    firstNotInSet=firstNotInSet)

        data = data.replace('[toc]', toc)
        with open('README.md', 'w', encoding='utf-8') as f:
            f.write(data)


if __name__ == '__main__':
    toc()