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

int solution(int N, vector<vector<int>> map){
	int answer = 50000;
	int popularity = 0;
	int min = 100;
	int max = 100;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			popularity += map[i][j];
		}
	}

	for(int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= y - 1; d1++) {
				for (int d2 = 1; y + d2 <= N && x + d1 + d2 <= N; d2++) {
					int area[5] = { 0, };

					for (int r = 1; r < x + d1; r++) {
						for (int c = 1; c <= y + r - 1; c++) {
							area[0] += map[r - 1][c - 1];
						}
					}

					for (int r = 1; r <= x + d2; r++) {
						for (int c = y + 1 + r - 1; c <= N; c++) {
							area[1] += map[r - 1][c - 1];
						}
					}
					
					for (int r = x + d1; r <= N; r++) {
						for (int c = 1; c < y - d1 + d2 - r + 1; c++) {
							area[2] += map[r - 1][c - 1];
						}
					}

					for (int r = x + d2 + 1; r <= N; r++) {
						for (int c = y - d1 + d2 + r - 1; c <= N; c++) {
							area[3] += map[r - 1][c - 1];
						}
					}

					area[4] = popularity - area[3] - area[2] - area[1] - area[0];

					max = 0;
					min = 50000;

					for (int i = 0; i < 5; i++) {
						if (max < area[i]) max = area[i];
						if (min > area[i]) min = area[i];
					}

					if (answer > max - min) {
						answer = max - min;
						cout << max << " - " << min << " = " << answer << endl;
					}
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
