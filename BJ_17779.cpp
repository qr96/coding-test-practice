#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int area(int N, vector<vector<int>> map, int popularity, int x, int y, int d1, int d2) {
	int area[5] = {};
	int max = 0;
	int min = 1000000;

	for (int r = 0; r < x + d1; r++) {
		for (int c = 0; c <= y; c++) {
			if (r >= x && c >= y - (r - x)) continue;

			area[0] += map[r][c];
		}
	}

	for (int r = 0; r <= x + d2; r++) {
		for (int c = y + 1; c < N; c++) {
			if (r > x && c <= y + (r - x)) continue;

			area[1] += map[r][c];
		}
	}

	for (int r = x + d1; r < N; r++) {
		for (int c = 0; c < y - d1 + d2; c++) {
			if (r <= x + d1 + d2 && c >= y - d1 + r - x - d1) continue;

			area[2] += map[r][c];
		}
	}

	for (int r = x + d2 + 1; r < N; r++) {
		for (int c = y - d1 + d2; c < N; c++) {
			if (r <= x + d1 + d2 && c <= y + d2 - (r - x - d2)) continue;

			area[3] += map[r][c];
		}
	}

	area[4] = popularity - area[0] - area[1] - area[2] - area[3];

	for (int i = 0; i < 5; i++) {
		if (max < area[i]) max = area[i];
		if (min > area[i]) min = area[i];
	}

	return max - min;
}

int solution(int N, vector<vector<int>> map){
	int answer = 50000;
	int popularity = 0;
	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			popularity += map[i][j];
		}
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			for (int d1 = 1; d1 < N && y - d1 >= 0; d1++) {
				for (int d2 = 1; d2 < N && y + d2 < N && x + d1 + d2 < N; d2++) {
					result = area(N, map, popularity, x, y, d1, d2);
					if (answer > result) answer = result;
				}
			}
		}
	}

	return answer;
}

int main() {
	int input;
	int N;
	vector<vector<int>> map;
	

	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			cin >> input;
			row.push_back(input);
		}
		map.push_back(row);
	}

	cout << solution(N, map) << endl;

	return 0;
}
