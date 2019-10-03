#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include <string>

string a, b, all;
bool Arr[1000][1000]; //Arr[i][j]表示 以 a[i]和b[j]结束的串在不在其中  在 = true,或者 不在 = false ;

int find(char c, int no = -1) //no表示不是坐标no
{
    for (int i = 0; i < all.length(); ++i)
    {
        if (all[i] == c && i != no)
            return i;
    }
    return -1;
}
void oper()
{
    int pp1 = find(a[0]);
    int pp2 = find(b[0], pp1); //得到在pp2 != pp1的前提下找到了b[0]的开头,还是从前面找
    if (pp2 == -1)
    { //通过这种方式的寻找，确保了，最后一个元素在两者中都存在
        cout << "no" << endl;
        return;
    } //这是一种可能，在这种可能之下
    Arr[0][0] = true;
    if (pp1 > pp2)
    {
        for (int i = pp2 + 1; i < pp1; ++i)
        {
            if (b[i] != all[i])
            {
                cout << "no" << endl;
                return;
            }
            Arr[0][i] = true;
        }
    }
    else
    {
        for (int i = pp1 + 1; i < pp2; ++i)
        {
            if (a[i] != all[i])
            {
                cout << "no" << endl;
                return;
            }
            Arr[i][0] = true;
        }
    } //要明白一点，两个开头的位置之间的字符必定是属于前面那个字符所对应的字符串的
    //至此，就开始遍历所有的起始位置 ,两个位置都划归到了同一位置

    //进行斜着的填表过程，每一斜行，都有，横纵坐标相加都是相等的，就是说，考虑的都是对于all来说，都是前面的
    //cat tree tcraete
    int p = max(pp1, pp2) + 1; //用 p来表示需要处理的all 的第p个元素(从0开始计数)，其实很明显可以看到
    //目前，指定到了准确的位置
    while (p < all.length())
    { //p表示第p个元素，就是表示第p斜行
        for (int i = 0; i <= p; ++i)
        { //对于这个第p个元素，只有三种可能，第一，这个属于a[i]，第二，这个属于b[j],第三个，都不属于，则返回;
            bool aB = false, bB = false;
            if (i >= 1)
            {
                if (a[i] == all[p])
                    aB = Arr[i - 1][p - i - 1];
            }
            if (p - i - 1 >= 1)
            {
                if (b[p - i - 1] == all[p])
                    bB = Arr[i][p - i - 2];
            }
            Arr[i][p - i - 1] = aB || bB;
        }
        ++p;
    }
    if (Arr[a.length() - 1][b.length() - 1])
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return;
}

int main()
{
    int n, caseNo = 0;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> all;
        cout << "Data set " << ++caseNo << ": ";
        if (a.length() + b.length() != all.length())
        {
            cout << "no" << endl;
            continue;
        }
        memset(Arr, false, sizeof(Arr));
        oper();
    }
}