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

int solution(vector<vector<int>> board) {
	int answer = 0;
	int fishes = 0;
	int r = 0;
	int c = 0;
	int exp = 0;
	int level = 2;
	int N = 0;

	N = board.size();

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] >= 1 && board[i][j] <= 6 && board[i][j] < level) fishes++;
			else if (board[i][j] == 9) {
				r = i;
				c = j;
			}
		}
	}

	board[r][c] = 0;

	while (1) {
		int br = 0;
		int bc = 0;
		int d = 0;
		int dis = -1;
		queue<pair<int, int>> que;
		queue<int> depth;
		vector<vector<int>> visited;
		vector<pair<int, int>> candid;

		for (int i = 0; i < N; i++) {
			vector<int> tmp;
			tmp.assign(N, 0);
			visited.push_back(tmp);
		}

		visited[r][c] = 1;
		que.push(make_pair(r, c));
		depth.push(0);

		while (!que.empty()) {
			br = que.front().first;
			bc = que.front().second;
			d = depth.front();

			que.pop();
			depth.pop();

			if (board[br][bc] <= 6 && board[br][bc] > 0 && board[br][bc] < level) {
				if (dis == -1) {
					dis = d;
					candid.push_back(make_pair(br, bc));
				}
				else if (dis != d) {
					break;
				}
				else {
					candid.push_back(make_pair(br, bc));
				}
			}

			if (br - 1 >= 0 && visited[br-1][bc] == 0 && board[br-1][bc] <= level) {
				visited[br - 1][bc] = 1;
				que.push(make_pair(br - 1, bc));
				depth.push(d + 1);
			}
			if (bc - 1 >= 0 && visited[br][bc-1] == 0 && board[br][bc-1] <= level) {
				visited[br][bc-1] = 1;
				que.push(make_pair(br, bc-1));
				depth.push(d + 1);
			}
			if (bc + 1 < N && visited[br][bc + 1] == 0 && board[br][bc + 1] <= level) {
				visited[br][bc + 1] = 1;
				que.push(make_pair(br, bc + 1));
				depth.push(d + 1);
			}
			if (br + 1 < N && visited[br + 1][bc] == 0 && board[br + 1][bc] <= level) {
				visited[br + 1][bc] = 1;
				que.push(make_pair(br + 1, bc));
				depth.push(d + 1);
			}
		}

		for (int i = 1; i < candid.size(); i++) {
			if (candid[0].first > candid[i].first) {
				candid[0] = candid[i];
			}
			else if (candid[0].first == candid[i].first) {
				if (candid[0].second > candid[i].second) {
					candid[0] = candid[i];
				}
			}
		}

		if (!candid.empty()) {
			answer += dis;
			r = candid[0].first;
			c = candid[0].second;
			board[r][c] = 0;
			exp++;
			if (exp == level) {
				level++;
				exp = 0;
			}
		}
		else {
			break;
		}
	}


	return answer;
}

int main() {
	int input;
	int N, K;
	vector<vector<int>> board;

	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			cin >> input;
			row.push_back(input);
		}
		board.push_back(row);
	}
	
	cout << solution(board) << endl;

	return 0;
}
