#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int solution(vector<vector<int>> board, vector<vector<int>> chess) {
	int answer = 0;
	int r = 0;
	int c = 0;
	int d = 0;
	int N = 0;
	int K = 0;
	int idx = 0;
	vector<vector<vector<int>>> bd;

	N = board.size();
	K = chess.size();

	for (int i = 0; i < N; i++) {
		vector<vector<int>> tmp;
		for (int j = 0; j < N; j++) {
			vector<int> v;
			tmp.push_back(v);
		}
		bd.push_back(tmp);
	}

	for (int i = 0; i < chess.size(); i++) {
		r = chess[i][0] - 1;
		c = chess[i][1] - 1;
		d = chess[i][2];

		bd[r][c].push_back(i);
	}

	while (answer <= 1000) {
		for (int i = 0; i < chess.size(); i++) {
			r = chess[i][0] - 1;
			c = chess[i][1] - 1;
			d = chess[i][2];

			idx = 0;
			while (bd[r][c][idx] != i) idx++;

			if (d == 1) {
				if (c + 1 < N && board[r][c + 1] != 2) {
					//move
					if (board[r][c + 1] == 0) {
						for (int j = idx; j < bd[r][c].size(); j++) {
							chess[bd[r][c][j]][1] = c + 2;
							bd[r][c + 1].push_back(bd[r][c][j]);
						}
					}
					else if (board[r][c + 1] == 1) {
						for (int j = bd[r][c].size() - 1; j >= idx; j--) {
							chess[bd[r][c][j]][1] = c + 2;
							bd[r][c + 1].push_back(bd[r][c][j]);
						}
					}
					bd[r][c].resize(idx);

					if (bd[r][c + 1].size() >= 4) return answer+1;
				}
				else {
					chess[i][2] = 2;
					if (c - 1 >= 0 && board[r][c - 1] != 2) i--;
				}
			}
			else if (d == 2) {
				if (c - 1 >= 0 && board[r][c - 1] != 2) {
					//move
					if (board[r][c - 1] == 0) {
						for (int j = idx; j < bd[r][c].size(); j++) {
							chess[bd[r][c][j]][1] = c;
							bd[r][c - 1].push_back(bd[r][c][j]);
						}
					}
					else if (board[r][c - 1] == 1) {
						for (int j = bd[r][c].size() - 1; j >= idx; j--) {
							chess[bd[r][c][j]][1] = c;
							bd[r][c - 1].push_back(bd[r][c][j]);
						}
					}
					bd[r][c].resize(idx);

					if (bd[r][c - 1].size() >= 4) return answer+1;
				}
				else {
					chess[i][2] = 1;
					if (c + 1 < N && board[r][c + 1] != 2) i--;
				}
			}
			else if (d == 3) {
				if (r - 1 >= 0 && board[r - 1][c] != 2) {
					//move
					if (board[r - 1][c] == 0) {
						for (int j = idx; j < bd[r][c].size(); j++) {
							chess[bd[r][c][j]][0] = r;
							bd[r - 1][c].push_back(bd[r][c][j]);
						}
					}
					else if (board[r - 1][c] == 1) {
						for (int j = bd[r][c].size() - 1; j >= idx; j--) {
							chess[bd[r][c][j]][0] = r;
							bd[r - 1][c].push_back(bd[r][c][j]);
						}
					}
					bd[r][c].resize(idx);

					if (bd[r - 1][c].size() >= 4) return answer + 1;
				}
				else {
					chess[i][2] = 4;
					if (r + 1 < N && board[r + 1][c] != 2) i--;
				}
			}
			else if (d == 4) {
				if (r + 1 < N && board[r + 1][c] != 2) {
					//move
					if (board[r + 1][c] == 0) {
						for (int j = idx; j < bd[r][c].size(); j++) {
							chess[bd[r][c][j]][0] = r + 2;
							bd[r + 1][c].push_back(bd[r][c][j]);
						}
					}
					else if (board[r + 1][c] == 1) {
						for (int j = bd[r][c].size() - 1; j >= idx; j--) {
							chess[bd[r][c][j]][0] = r + 2;
							bd[r + 1][c].push_back(bd[r][c][j]);
						}
					}
					bd[r][c].resize(idx);

					if (bd[r + 1][c].size() >= 4) return answer + 1;
				}
				else {
					chess[i][2] = 3;
					if (r - 1 >= 0 && board[r - 1][c] != 2) i--;
				}
			}
		}

		answer++;
	}

	if (answer > 1000) answer = -1;


	return answer;
}

int main() {
	int input;
	int N, K;
	vector<vector<int>> board;
	vector<vector<int>> chess;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			cin >> input;
			row.push_back(input);
		}
		board.push_back(row);
	}
	
	for (int i = 0; i < K; i++) {
		vector<int> info;
		for (int j = 0; j < 3; j++) {
			cin >> input;
			info.push_back(input);
		}
		chess.push_back(info);
	}

	cout << solution(board, chess) << endl;

	return 0;
}
