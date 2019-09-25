#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

double arr[4];

bool DFS(double *tmp, string* formulas, int size) {
	if (size == 1) {
		// cout << tmp[0] << " " << formulas[0] << endl;
		if (tmp[0] == 24) {
			cout << formulas[0] << endl;
			return true;
		}
		return false;
	}
	double *new_tmp = new double[size - 1];
	string *new_formulas = new string[size - 1];
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			int tot = 0;
			for (int p = 0; p < size; ++p) {
				if (p != i && p != j) {
					new_tmp[tot++] = tmp[p];
				}
			}
			tot = 0;
			for (int p = 0; p < size; ++p) {
				if (p != i && p != j) {
					new_formulas[tot++] = formulas[p];
				}
			}

			// op:0, temp + value
			new_tmp[size - 2] = tmp[i] + tmp[j];
			new_formulas[size - 2] = (string("(") + formulas[i] + string("+") + formulas[j] + string(")"));
			if (DFS(new_tmp, new_formulas, size - 1))
				return true;

			// op:1, temp - value
			new_tmp[size - 2] = tmp[i] - tmp[j];
			new_formulas[size - 2] = (string("(") + formulas[i] + string("-") + formulas[j] + string(")"));
			if (DFS(new_tmp, new_formulas, size - 1))
				return true;

			// op:2, value - temp 
			new_tmp[size - 2] = tmp[j] - tmp[i];
			new_formulas[size - 2] = (string("(") + formulas[j] + string("-") + formulas[i] + string(")"));
			if (DFS(new_tmp, new_formulas, size - 1))
				return true;
			// op:3, temp / value
			new_tmp[size - 2] = tmp[i] / tmp[j];
			new_formulas[size - 2] = (string("(") + formulas[i] + string("/") + formulas[j] + string(")"));
			if (DFS(new_tmp, new_formulas, size - 1))
				return true;

			// op:4, value / temp 
			new_tmp[size - 2] = tmp[j] / tmp[i];
			new_formulas[size - 2] = (string("(") + formulas[j] + string("/") + formulas[i] + string(")"));
			if (DFS(new_tmp, new_formulas, size - 1))
				return true;

			// op:5, temp * value
			new_tmp[size - 2] = tmp[i] * tmp[j];
			new_formulas[size - 2] = (string("(") + formulas[i] + string("*") + formulas[j] + string(")"));
			if (DFS(new_tmp, new_formulas, size - 1))
				return true;
		}
	}
	delete[] new_tmp;
	delete[] new_formulas;
	return false;
}

int main() {
	int time;
	cin >> time;
	
	while (time--) {
		for (int i = 0; i < 4; ++i) {
			cin >> arr[i];
		}
		string formula[4];
		for (int i = 0; i < 4; ++i) formula[i] = to_string(int(arr[i]));
		if (DFS(arr, formula, 4)) {
			continue;
		}
		else {
			cout << "None\n";
		}
	}
	system("pause");
}