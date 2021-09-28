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

int solution(vector<vector<int>> map, int N, int M) {
	int answer = 1000000;
	int chicken_dis;
	vector<vector<int>> shops; //r, c
	vector<vector<int>> homes;
	vector<int> selected;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				vector<int> info;
				info.push_back(i);
				info.push_back(j);
				homes.push_back(info);
			}
			else if (map[i][j] == 2) {
				vector<int> info;
				info.push_back(i);
				info.push_back(j);
				shops.push_back(info);
			}
		}
	}

	for (int i = 0; i < shops.size() - M; i++) {
		selected.push_back(0);
	}
	for (int i = 0; i < M; i++) {
		selected.push_back(1);
	}

	do {
		chicken_dis = 0;
		for (int i = 0; i < homes.size(); i++) {
			int min = 1000000;
			int tmp = 0;
			for (int j = 0; j < shops.size(); j++) {
				if (selected[j] == 1) {
					tmp = abs(homes[i][0] - shops[j][0]) + abs(homes[i][1] - shops[j][1]);
					if (min > tmp) min = tmp;
				}
				
			}
			chicken_dis += min;
		}

		if (answer > chicken_dis) answer = chicken_dis;
		
	} while (next_permutation(selected.begin(), selected.end()));

	return answer;
}

int main() {
	int input;
	int N = 0;
	int M = 0;
	vector<vector<int>> map;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			cin >> input;
			row.push_back(input);
		}
		map.push_back(row);
	}

	cout << solution(map, N, M) << endl;

	return 0;
}
