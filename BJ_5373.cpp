#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int solution(int n, vector<string> rotates) {
	int answer = 0;
	char tmp = 'a';
	char stmp[3];

	string cube_f[3] = { "rrr", "rrr", "rrr" };
	string cube_l[3] = { "ggg", "ggg", "ggg" };
	string cube_r[3] = { "bbb", "bbb", "bbb" };
	string cube_b[3] = { "ooo", "ooo", "ooo" };
	string cube_u[3] = { "www", "www", "www" };
	string cube_d[3] = { "yyy", "yyy", "yyy" };

	for (int j = 0; j < n; j++) {
		if (rotates[j].compare("F+") == 0) {
			tmp = cube_f[0][0];
			cube_f[0][0] = cube_f[1][0];
			cube_f[1][0] = cube_f[2][0];
			cube_f[2][0] = cube_f[2][1];
			cube_f[2][1] = cube_f[2][2];
			cube_f[2][2] = cube_f[1][2];
			cube_f[1][2] = cube_f[0][2];
			cube_f[0][2] = cube_f[0][1];
			cube_f[1][0] = tmp;

			stmp[0] = cube_u[2][0];
			stmp[1] = cube_u[2][1];
			stmp[2] = cube_u[2][2];
			cube_u[2][0] = cube_l[2][2];
			cube_u[2][1] = cube_l[1][2];
			cube_u[2][2] = cube_l[0][2];
			cube_l[0][2] = cube_d[0][0];
			cube_l[1][2] = cube_d[0][1];
			cube_l[2][2] = cube_d[0][2];
			cube_d[0][0] = cube_r[2][0];
			cube_d[0][1] = cube_r[1][0];
			cube_d[0][2] = cube_r[0][0];
			cube_r[2][0] = stmp[2];
			cube_r[1][0] = stmp[1];
			cube_r[0][0] = stmp[0];
		}
		else if (rotates[j].compare("F-") == 0) {
			tmp = cube_f[0][0];
			cube_f[0][0] = cube_f[0][1];
			cube_f[0][1] = cube_f[0][2];
			cube_f[0][2] = cube_f[1][2];
			cube_f[1][2] = cube_f[2][2];
			cube_f[2][2] = cube_f[2][1];
			cube_f[2][1] = cube_f[2][0];
			cube_f[2][0] = cube_f[1][0];
			cube_f[1][0] = tmp;

			stmp[0] = cube_u[2][0];
			stmp[1] = cube_u[2][1];
			stmp[2] = cube_u[2][2];
			cube_u[2][0] = cube_r[0][0];
			cube_u[2][1] = cube_r[1][0];
			cube_u[2][2] = cube_r[2][0];
			cube_r[0][0] = cube_d[0][2];
			cube_r[1][0] = cube_d[0][1];
			cube_r[2][0] = cube_d[0][0];
			cube_d[0][2] = cube_l[2][2];
			cube_d[0][1] = cube_l[1][2];
			cube_d[0][0] = cube_l[0][2];
			cube_l[2][2] = stmp[0];
			cube_l[1][2] = stmp[1];
			cube_l[0][2] = stmp[2];
		}
		else if (rotates[j].compare("L+") == 0) {
			tmp = cube_l[0][0];
			cube_l[0][0] = cube_l[1][0];
			cube_l[1][0] = cube_l[2][0];
			cube_l[2][0] = cube_l[2][1];
			cube_l[2][1] = cube_l[2][2];
			cube_l[2][2] = cube_l[1][2];
			cube_l[1][2] = cube_l[0][2];
			cube_l[0][2] = cube_l[0][1];
			cube_l[1][0] = tmp;

			stmp[0] = cube_u[0][0];
			stmp[1] = cube_u[1][0];
			stmp[2] = cube_u[2][0];
			cube_u[2][0] = cube_b[0][2];
			cube_u[1][0] = cube_b[1][2];
			cube_u[0][0] = cube_b[2][2];
			cube_b[0][2] = cube_d[2][0];
			cube_b[1][2] = cube_d[1][0];
			cube_b[2][2] = cube_d[0][0];
			cube_d[2][0] = cube_f[2][0];
			cube_d[1][0] = cube_f[1][0];
			cube_d[0][0] = cube_f[0][0];
			cube_f[2][0] = stmp[2];
			cube_f[1][0] = stmp[1];
			cube_f[0][0] = stmp[0];
		}
		else if (rotates[j].compare("L-") == 0) {
			tmp = cube_l[0][0];
			cube_l[0][0] = cube_l[0][1];
			cube_l[0][1] = cube_l[0][2];
			cube_l[0][2] = cube_l[1][2];
			cube_l[1][2] = cube_l[2][2];
			cube_l[2][2] = cube_l[2][1];
			cube_l[2][1] = cube_l[2][0];
			cube_l[2][0] = cube_l[1][0];
			cube_l[1][0] = tmp;

			stmp[0] = cube_u[0][0];
			stmp[1] = cube_u[1][0];
			stmp[2] = cube_u[2][0];
			cube_u[0][0] = cube_f[0][0];
			cube_u[1][0] = cube_f[1][0];
			cube_u[2][0] = cube_f[2][0];
			cube_f[0][0] = cube_d[0][0];
			cube_f[1][0] = cube_d[1][0];
			cube_f[2][0] = cube_d[2][0];
			cube_d[0][0] = cube_b[2][2];
			cube_d[1][0] = cube_b[1][2];
			cube_d[2][0] = cube_b[0][2];
			cube_b[2][2] = stmp[0];
			cube_b[1][2] = stmp[1];
			cube_b[0][2] = stmp[2];
		}
		else if (rotates[j].compare("R+") == 0) {
			tmp = cube_r[0][0];
			cube_r[0][0] = cube_r[1][0];
			cube_r[1][0] = cube_r[2][0];
			cube_r[2][0] = cube_r[2][1];
			cube_r[2][1] = cube_r[2][2];
			cube_r[2][2] = cube_r[1][2];
			cube_r[1][2] = cube_r[0][2];
			cube_r[0][2] = cube_r[0][1];
			cube_r[1][0] = tmp;
		}
		else if (rotates[j].compare("R-") == 0) {
			tmp = cube_r[0][0];
			cube_r[0][0] = cube_r[0][1];
			cube_r[0][1] = cube_r[0][2];
			cube_r[0][2] = cube_r[1][2];
			cube_r[1][2] = cube_r[2][2];
			cube_r[2][2] = cube_r[2][1];
			cube_r[2][1] = cube_r[2][0];
			cube_r[2][0] = cube_r[1][0];
			cube_r[1][0] = tmp;
		}
		else if (rotates[j].compare("U+") == 0) {

		}
		else if (rotates[j].compare("U-") == 0) {

		}
		else if (rotates[j].compare("D+") == 0) {

		}
		else if (rotates[j].compare("D-") == 0) {

		}
		else if (rotates[j].compare("B+") == 0) {

		}
		else if (rotates[j].compare("B-") == 0) {

		}
	}

	for (int j = 0; j < 3; j++) {
		cout << cube_u[j] << endl;
	}

	return answer;
}

int main() {
	string input;
	int T;
	int n;
	vector<int> numbers;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		vector<string> rotates;
		for (int j = 0; j < n; j++) {
			cin >> input;
			rotates.push_back(input);
		}
		solution(n, rotates);
	}

	

	return 0;
}
