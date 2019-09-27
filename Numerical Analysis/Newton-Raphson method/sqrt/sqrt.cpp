#include <iostream>
using namespace std;
#define itTime 1000 // the Maximum Iteration Times 
#define eps 1e-10 // precision accuracy
#define abs(x) ((x > 0? (x):-(x))) 
int main() {
	int N, time = 1;
	cin >> N; // input number N;
	double x = N / 2., tmp;
	while (time++ < itTime) {
		tmp = x / 2. + N / (2. * x);
		if (abs(tmp - x) < eps) break;
		x = tmp;
	}
	printf("sqrt(%d) = %.10lf\n", N, tmp);
	system("pause");
}