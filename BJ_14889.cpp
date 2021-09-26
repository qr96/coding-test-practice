#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

vector<vector<int>> combi(int n, int r) {
	vector<int> tmp;
	vector<vector<int>> result;

	for (int i = 0; i < n - r; i++) {
		tmp.push_back(0);
	}

	for (int i = 0; i < r; i++) {
		tmp.push_back(1);
	}

	do
	{
		vector<int> comb;
		for (int i = 0; i < n; i++)
		{	
			comb.push_back(tmp[i]);
		}
		if (!comb.empty()) result.push_back(comb);

	} while (next_permutation(tmp.begin(), tmp.end()));

	return result;
}

int solution(vector<vector<int>> stats){
	int answer = 1000000;
	int sum = 0;
	int N = stats.size();
	vector<vector<int>> combination;
	int A, B;
		
	combination = combi(N, N/2);

	for (int i = 0; i < combination.size(); i++) {
		A = 0;
		B = 0;
		for (int j = 0; j < combination[i].size(); j++) {
			for (int k = j + 1; k < combination[i].size(); k++) {
				if (combination[i][j] == 1 && combination[i][k] == 1) {
					A += stats[j][k];
					A += stats[k][j];
				}
				else if (combination[i][j] == 0 && combination[i][k] == 0) {
					B += stats[j][k];
					B += stats[k][j];
				}
			}
		}
		if (answer > abs(A - B)) answer = abs(A - B);
	}

	return answer;
}

int main() {
	int input;
	int N;
	vector<vector<int>> stats;

	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			cin >> input;
			row.push_back(input);
		}
		stats.push_back(row);
	}

	cout << solution(stats) << endl;

	return 0;
}
