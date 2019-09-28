#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

// 随机整数[b, e)
#define RAND(b, e) (rand() % ((e) - (b)) + (b))
// 随机浮点数 0,1
#define RANDFLOAT() ((double)rand() / double(RAND_MAX))

// 种群数量
int LEN = 22;
int tempLEN = LEN * LEN;
// 交配的概率，编译的概率
double pc = 0.8, pm = 0.9;
// 种群的所有路径
int **Paths;
int **tempPaths;
int temp_index = 0;
double **Mat;
double *Value, *tempValue;
int globalValue_index, stay_in_global_times = 0;

double globalValue;
int *globalPath;

// TSP节点数量
int N = 0;

// 适应值函数
double CalValue(int *p)
{ // read only
	double t = 0;
	for (int i = 1; i < N; ++i)
	{
		t += Mat[p[i - 1]][p[i]];
	}
	t += Mat[p[N - 1]][0];
	return t;
}

void initialPath(int *Path, int j);
void initialPaths();
void find_min(int first = 1);

// 自然选择
void select();
// 交配
void crossover(int *p1, int *p2);
// 变异
void mutation(int *Path);
//
void preserve(int *p1, int *p2, int v1, int v2);

int main()
{
	srand((unsigned)time(NULL));
	ifstream cin("data.txt"); 

	cin >> N;
	Mat = new double *[N];
	for (int i = 0; i < N; ++i)
	{
		Mat[i] = new double[N];
	}

	// read data from data.txt
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Mat[i][j];
		}
	}
	// new Path...
	Paths = new int *[LEN];
	for (int i = 0; i < LEN; ++i)
	{
		Paths[i] = new int[N];
	}
	tempPaths = new int *[tempLEN];
	for (int i = 0; i < tempLEN; ++i)
	{
		tempPaths[i] = new int[N];
	}
	Value = new double[LEN];
	tempValue = new double[tempLEN];

	globalPath = new int[N];
	// end new Path...
	initialPaths(); // initialize paths

	while (true)
	{
		temp_index = 0;
		for (int i = 0; i < LEN; i++)
		{
			if (temp_index >= tempLEN)
				break;
			preserve(Paths[i], NULL, Value[i], NULL);
			for (int j = i + 1; j < LEN; ++j)
			{
				if (temp_index >= tempLEN)
					break;
				if (RANDFLOAT() < pc)
					crossover(Paths[i], Paths[j]);
			}
		}

		for (int i = 0; i < LEN; ++i)
		{
			if (temp_index >= tempLEN)
				break;
			if (RANDFLOAT() < pm)
				mutation(Paths[i]);
		}
		select();
		if (stay_in_global_times == 10)
		{
			break;
		}
	}
	cout << globalValue << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << globalPath[i] << " --> ";
	}

	// delete Path...
	delete[] tempValue;
	delete[] Value;
	for (int i = 0; i < tempLEN; ++i)
	{
		delete[] tempPaths[i];
	}
	delete[] tempPaths;

	for (int i = 0; i < LEN; ++i)
	{
		delete[] Paths[i];
	}
	delete[] Paths;

	for (int i = 0; i < N; ++i)
	{
		delete[] Mat[i];
	}
	delete[] Mat;
	system("pause");
}

// preserve the parents.
void preserve(int *p1, int *p2, int v1, int v2)
{
	for (int i = 0; i < N; ++i)
	{
		tempPaths[temp_index][i] = p1[i];
	}
	tempValue[temp_index] = v1;
	//if (tempValue[temp_index] < 0) cout << "wrong\n";
	temp_index++;
	if (p2 != NULL)
	{
		for (int i = 0; i < N; ++i)
		{
			tempPaths[temp_index][i] = p2[i];
		}
		tempValue[temp_index] = v2;
		//if (tempValue[temp_index] < 0) cout << "wrong\n";
		temp_index++;
	}
}

struct enumate
{
	double data;
	int index;
	bool operator<(const enumate &e) const
	{
		return data < e.data;
	}
};

vector<int> argsort_temp_value()
{
	enumate *data = new enumate[temp_index];
	for (int i = 0; i < temp_index; ++i)
	{
		data[i].data = tempValue[i];
		data[i].index = i;
	}
	sort(data, data + temp_index);
	vector<int> ans(temp_index);
	for (int i = 0; i < temp_index; ++i)
		ans[i] = data[i].index;
	delete[] data;
	return ans;
}

void select()
{
	vector<int> id = argsort_temp_value();
	for (int i = 0; i < temp_index; ++i)
		if (tempValue[i] < 0)
			cout << tempValue[i] << endl;
	for (int i = 0; i < LEN; ++i)
	{
		Value[i] = tempValue[id[i]];
		for (int j = 0; j < N; ++j)
		{
			Paths[i][j] = tempPaths[id[i]][j];
		}
	}
	if (Value[0] < globalValue)
	{
		for (int i = 0; i < N; ++i)
			globalPath[i] = Paths[0][i];
		stay_in_global_times = 0;
		globalValue = Value[0];
	}
	else if (Value[0] == globalValue)
	{
		stay_in_global_times++;
	}
	else
	{
		cout << "Something wrong" << Value[0] << endl;
	}
}

// 基于次序的交配方式
void crossover(int *p1, int *p2)
{
	// generate son from p1 and p2
	int crossn = RAND(0, N - 1);
	if (crossn == 0)
		return;
	int *indexs = new int[crossn];
	for (int i = 0; i < crossn; ++i)
	{
		if (i == 0)
			indexs[i] = RAND(1, N - crossn + 1);
		else
		{
			indexs[i] = RAND(indexs[i - 1] + 1, N - crossn + i + 1);
		}
	}
	// copy from p2
	for (int i = 0; i < N; ++i)
	{
		tempPaths[temp_index][i] = p2[i];
	}
	int use_count = 0;
	for (int i = 0; i < N; ++i)
	{
		if (use_count == crossn)
			break;
		for (int j = 0; j < crossn; ++j)
		{
			if (tempPaths[temp_index][i] == p1[indexs[j]])
			{
				tempPaths[temp_index][i] = p1[indexs[use_count]];
				use_count++;
				break;
			}
		}
	}
	// cal value
	tempValue[temp_index] = CalValue(tempPaths[temp_index]);

	temp_index++;
	// copy from p1
	for (int i = 0; i < N; ++i)
	{
		tempPaths[temp_index][i] = p1[i];
	}
	use_count = 0;
	for (int i = 0; i < N; ++i)
	{
		if (use_count == crossn)
			break;
		for (int j = 0; j < crossn; ++j)
		{
			if (tempPaths[temp_index][i] == p2[indexs[j]])
			{
				tempPaths[temp_index][i] = p2[indexs[use_count]];
				use_count++;
				break;
			}
		}
	}
	tempValue[temp_index] = CalValue(tempPaths[temp_index]);
	temp_index++;
	delete[] indexs;
}

// 基于次序的变异
void mutation(int *Path)
{
	int a = RAND(1, N), b, t;
	if (a == N - 1)
	{
		b = RAND(1, N - 1);
		t = a;
		a = b;
		b = t;
	}
	else
	{
		b = RAND(a + 1, N);
	}
	for (int i = 0; i < N; ++i)
	{
		if (i == a)
			tempPaths[temp_index][i] = Path[b];
		else if (i == b)
			tempPaths[temp_index][i] = Path[a];
		else
			tempPaths[temp_index][i] = Path[i];
	}
	tempValue[temp_index] = CalValue(tempPaths[temp_index]);
	temp_index++;
}

void initialPaths()
{
	for (int i = 0; i < LEN; ++i)
		initialPath(Paths[i], i);
	find_min();
}

void find_min(int first)
{
	int temp = 0;
	for (int i = 1; i < LEN; ++i)
		if (Value[temp] > Value[i])
			temp = i;
	if (first)
	{
		globalValue = Value[temp];
		for (int i = 0; i < N; ++i)
			globalPath[i] = Paths[temp][i];
	}
	else if (Value[temp] < globalValue)
	{
		globalValue = Value[temp];
		for (int i = 0; i < N; ++i)
			globalPath[i] = Paths[temp][i];
	}
}

void initialPath(int *Path, int j)
{
	for (int i = 0; i < N; ++i)
	{
		Path[i] = i;
	}
	// Path[i]表示路上第i个点的标记为Path[i]
	// Path[0] = 0
	int tx, t;
	for (int i = 1; i < N - 1; ++i)
	{
		tx = RAND(i, N);
		if (tx != i)
		{ // swap
			t = Path[i];
			Path[i] = Path[tx];
			Path[tx] = t;
		}
	}
	Value[j] = CalValue(Path);
}
