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
	int answer = 100;
	int cctvNum = 0;
	int count = 0;
	int r, c;
	vector<int> dir;
	vector<int> cctv_r;
	vector<int> cctv_c;
	vector<vector<int>> tmp;

	for (int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if (map[i][j] > 0 && map[i][j] < 6) {
				cctvNum++;
				cctv_r.push_back(i);
				cctv_c.push_back(j);
			}
		}
	}
	dir.assign(cctvNum+1, 0);

	while(dir.back() == 0) {
		tmp = map;

		for (int i = 0; i < cctvNum; i++) {
			r = cctv_r[i];
			c = cctv_c[i];

			if (map[r][c] == 1) {
				if (dir[i] == 0) {
					for (int j = c + 1; j < M; j++) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
				}
				else if (dir[i] == 1) {
					for (int j = r - 1; j >= 0; j--) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
				}
				else if (dir[i] == 2) {
					for (int j = c - 1; j >= 0; j--) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
				}
				else if (dir[i] == 3) {
					for (int j = r + 1; j < N; j++) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
				}
			}
			else if (map[r][c] == 2) {
				if (dir[i] == 0 || dir[i] == 2) {
					for (int j = c + 1; j < M; j++) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
					for (int j = c - 1; j >= 0; j--) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
				}
				else if (dir[i] == 1 || dir[i] == 3) {
					for (int j = r - 1; j >= 0; j--) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
					for (int j = r + 1; j < N; j++) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
				}
			}
			else if (map[r][c] == 3) {
				if (dir[i] == 0) {
					for (int j = c + 1; j < M; j++) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
					for (int j = r - 1; j >= 0; j--) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
				}
				else if (dir[i] == 1) {
					for (int j = r - 1; j >= 0; j--) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
					for (int j = c - 1; j >= 0; j--) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
				}
				else if (dir[i] == 2) {
					for (int j = c - 1; j >= 0; j--) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
					for (int j = r + 1; j < N; j++) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
				}
				else if (dir[i] == 3) {
					for (int j = r + 1; j < N; j++) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
					for (int j = c + 1; j < M; j++) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
				}
			}
			else if (map[r][c] == 4) {
				if (dir[i] == 0) {
					for (int j = c + 1; j < M; j++) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
					for (int j = r - 1; j >= 0; j--) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
					for (int j = c - 1; j >= 0; j--) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
				}
				else if (dir[i] == 1) {
					for (int j = r - 1; j >= 0; j--) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
					for (int j = c - 1; j >= 0; j--) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
					for (int j = r + 1; j < N; j++) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
				}
				else if (dir[i] == 2) {
					for (int j = c - 1; j >= 0; j--) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
					for (int j = r + 1; j < N; j++) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
					for (int j = c + 1; j < M; j++) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
				}
				else if (dir[i] == 3) {
					for (int j = r + 1; j < N; j++) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
					for (int j = c + 1; j < M; j++) {
						if (map[r][j] == 6) break;
						else if (map[r][j] == 0) tmp[r][j] = 7;
					}
					for (int j = r - 1; j >= 0; j--) {
						if (map[j][c] == 6) break;
						else if (map[j][c] == 0) tmp[j][c] = 7;
					}
				}
			}
			else if (map[r][c] == 5) {
				for (int j = c + 1; j < M; j++) {
					if (map[r][j] == 6) break;
					else if (map[r][j] == 0) tmp[r][j] = 7;
				}
				for (int j = r - 1; j >= 0; j--) {
					if (map[j][c] == 6) break;
					else if (map[j][c] == 0) tmp[j][c] = 7;
				}
				for (int j = c - 1; j >= 0; j--) {
					if (map[r][j] == 6) break;
					else if (map[r][j] == 0) tmp[r][j] = 7;
				}
				for (int j = r + 1; j < N; j++) {
					if (map[j][c] == 6) break;
					else if (map[j][c] == 0) tmp[j][c] = 7;
				}
			}
		}

		count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tmp[i][j] == 0) count++;
			}
		}

		if (answer > count) answer = count;

		for (int i = 0; i < cctvNum+1; i++) {
			if (dir[i] < 3) {
				for (int j = 0; j < i; j++) {
					dir[j] = 0;
				}
				dir[i]++;
				break;
			}
		}
	}

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
		for (int j = 0; j < M; j++) {
			cin >> input;
			row.push_back(input);
		}
		map.push_back(row);
	}

	cout << solution(map, N, M) << endl;

	return 0;
}
