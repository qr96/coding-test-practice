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

int solution(int N, int M, int k, 
	vector<vector<int>> board, vector<int> direction, vector<vector<int>> prior) {
	
	int answer = 0;
	int remain = M;
	vector<vector<pair<int, int>>> smell;
	vector<tuple<int, int, int>> position(M);

	for (int i = 0; i < N; i++) {
		vector<pair<int, int>> tmp(N);
		smell.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > 0) {
				smell[i][j].first = board[i][j];
				smell[i][j].second = k;
				position[board[i][j] - 1] = make_tuple(i, j, direction[board[i][j] - 1]);
			}
		}
	}

	while (answer <= 1000) {
		for (int i = 0; i < M; i++) {
			int r = get<0>(position[i]);
			int c = get<1>(position[i]);
			int d = get<2>(position[i]);

			if (r == -1 && c == -1) continue;

			for (int j = 0; j < 4; j++) {
				int dir = prior[i * 4 + d - 1][j];

				if (dir == 1) {
					if (r - 1 >= 0 && smell[r - 1][c].first == 0) {
						r = r - 1;
						d = dir;
						break;
					}
				}
				else if (dir == 2) {
					if (r + 1 < N && smell[r + 1][c].first == 0) {
						r = r + 1;
						d = dir;
						break;
					}
				}
				else if (dir == 3) {
					if (c - 1 >= 0 && smell[r][c - 1].first == 0) {
						c = c - 1;
						d = dir;
						break;
					}
				}
				else if (dir == 4) {
					if (c + 1 < N && smell[r][c + 1].first == 0) {
						c = c + 1;
						d = dir;
						break;
					}
				}
			}

			if (position[i] == make_tuple(r, c, d)) {
				for (int j = 0; j < 4; j++) {
					int dir = prior[i * 4 + d - 1][j];

					if (dir == 1) {
						if (r - 1 >= 0 && smell[r - 1][c].first == i+1) {
							r = r - 1;
							d = dir;
							break;
						}
					}
					else if (dir == 2) {
						if (r + 1 < N && smell[r + 1][c].first == i+1) {
							r = r + 1;
							d = dir;
							break;
						}
					}
					else if (dir == 3) {
						if (c - 1 >= 0 && smell[r][c - 1].first == i+1) {
							c = c - 1;
							d = dir;
							break;
						}
					}
					else if (dir == 4) {
						if (c + 1 < N && smell[r][c + 1].first == i+1) {
							c = c + 1;
							d = dir;
							break;
						}
					}
				}
			}

			position[i] = make_tuple(r, c, d);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (smell[i][j].second > 0) {
					smell[i][j].second--;

					if (smell[i][j].second == 0) {
						smell[i][j].first = 0;
					}
				}
			}
		}

		for (int i = 0; i < M; i++) {
			int r = get<0>(position[i]);
			int c = get<1>(position[i]);
			if (r == -1 && c == -1) continue;

			for (int j = i + 1; j < M; j++) {
				int r2 = get<0>(position[j]);
				int c2 = get<1>(position[j]);
				if (r2 == -1 && c2 == -1) continue;

				if (r == r2 && c == c2) {
					position[j] = make_tuple(-1, -1, 0);
					remain--;
				}
			}
		}

		for (int i = 0; i < M; i++) {
			int r = get<0>(position[i]);
			int c = get<1>(position[i]);

			if (r == -1 && c == -1) continue;

			smell[r][c].second = k;
			smell[r][c].first = i + 1;
		}

		answer++;

		if (remain == 1) break;
	}

	if (answer > 1000) answer = -1;

	return answer;
}

int main() {
	int input;
	int N, M, k;
	vector<vector<int>> board;
	vector<int> direction;
	vector<vector<int>> prior;

	cin >> N >> M >> k;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int i = 0; i < N; i++) {
			cin >> input;
			tmp.push_back(input);
		}
		board.push_back(tmp);
	}

	for (int i = 0; i < M; i++) {
		cin >> input;
		direction.push_back(input);
	}

	for (int i = 0; i < 4 * M; i++) {
		vector<int> tmp;
		for (int j = 0; j < 4; j++) {
			cin >> input;
			tmp.push_back(input);
		}
		prior.push_back(tmp);
	}

	cout << solution(N, M, k, board, direction, prior) << endl;

	return 0;
}
