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

int solution(vector<vector<int>> board, int L, int R) {
	int answer = 0;
	int N = board.size();
	int r = 0;
	int c = 0;
	int land = 0;
	int people = 0;

	while (1) {
		vector<vector<int>> visited;
		queue<pair<int, int>> que;
		bool flag = true;

		for (int i = 0; i < N; i++) {
			vector<int> row;
			row.assign(N, 0);
			visited.push_back(row);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) {
					vector<pair<int, int>> vp;
					visited[i][j] = 1;
					land = 0;
					people = 0;

					que.push(make_pair(i, j));

					while (!que.empty()) {
						r = que.front().first;
						c = que.front().second;
						que.pop();

						people += board[r][c];
						land++;
						vp.push_back(make_pair(r, c));

						if (r - 1 >= 0 && visited[r-1][c]==0 &&
							abs(board[r-1][c]-board[r][c]) >= L && 
							abs(board[r - 1][c] - board[r][c]) <= R) {
							que.push(make_pair(r - 1, c));
							visited[r - 1][c] = 1;
						}
						if (c - 1 >= 0 && visited[r][c-1] == 0 &&
							abs(board[r][c-1] - board[r][c]) >= L &&
							abs(board[r][c-1] - board[r][c]) <= R) {
							que.push(make_pair(r, c-1));
							visited[r][c-1] = 1;
						}
						if (r + 1 < N && visited[r + 1][c] == 0 &&
							abs(board[r + 1][c] - board[r][c]) >= L &&
							abs(board[r + 1][c] - board[r][c]) <= R) {
							que.push(make_pair(r + 1, c));
							visited[r + 1][c] = 1;
						}
						if (c + 1 < N && visited[r][c + 1] == 0 &&
							abs(board[r][c + 1] - board[r][c]) >= L &&
							abs(board[r][c + 1] - board[r][c]) <= R) {
							que.push(make_pair(r, c + 1));
							visited[r][c + 1] = 1;
						}
					}

					if (land > 1) flag = false;
					people /= land;
					for (int m = 0; m < vp.size(); m++) {
						board[vp[m].first][vp[m].second] = people;
					}

				}
			}
		}

		if (flag) break;

		answer++;
	}

	return answer;
}

int main() {
	int input;
	int N, L, R;
	vector<vector<int>> board;

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			cin >> input;
			row.push_back(input);
		}
		board.push_back(row);
	}
	
	cout << solution(board, L, R) << endl;

	return 0;
}
