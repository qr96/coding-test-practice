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

int N;
int M;

int block1_1(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (c + 3 < M) {
		for (int i = c; i < c + 4; i++) {
			result += board->at(r).at(i);
		}
	}
	
	return result;
}

int block1_2(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 3 < N) {
		for (int i = r; i < r + 4; i++) {
			result += board->at(i).at(c);
		}
	}

	return result;
}

int block2(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 1 < N && c + 1 < M) {
		result += board->at(r).at(c);
		result += board->at(r + 1).at(c);
		result += board->at(r).at(c+1);
		result += board->at(r+1).at(c+1);
	}

	return result;
}

int block3_1(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 2 < N && c + 1 < M) {
		result += board->at(r).at(c);
		result += board->at(r+1).at(c);
		result += board->at(r+2).at(c);
		result += board->at(r+2).at(c+1);
	}

	return result;
}

int block3_2(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 1 < N && c + 2 < M) {
		result += board->at(r).at(c);
		result += board->at(r).at(c+1);
		result += board->at(r).at(c+2);
		result += board->at(r+1).at(c);
	}

	return result;
}

int block3_3(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 2 < N && c + 1 < M) {
		result += board->at(r).at(c);
		result += board->at(r).at(c+1);
		result += board->at(r+1).at(c+1);
		result += board->at(r+2).at(c+1);
	}

	return result;
}

int block3_4(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 1 < N && c + 2 < M) {
		result += board->at(r).at(c+2);
		result += board->at(r+1).at(c);
		result += board->at(r+1).at(c+1);
		result += board->at(r+1).at(c+2);
	}

	return result;
}

int block3_5(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 2 < N && c + 1 < M) {
		result += board->at(r).at(c+1);
		result += board->at(r+1).at(c+1);
		result += board->at(r+2).at(c);
		result += board->at(r+2).at(c+1);
	}

	return result;
}

int block3_6(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 1 < N && c + 2 < M) {
		result += board->at(r).at(c);
		result += board->at(r).at(c+1);
		result += board->at(r).at(c+2);
		result += board->at(r+1).at(c+2);
	}

	return result;
}

int block3_7(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 2 < N && c + 1 < M) {
		result += board->at(r).at(c);
		result += board->at(r).at(c+1);
		result += board->at(r+1).at(c);
		result += board->at(r+2).at(c);
	}

	return result;
}

int block3_8(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 1 < N && c + 2 < M) {
		result += board->at(r).at(c);
		result += board->at(r + 1).at(c);
		result += board->at(r + 1).at(c+1);
		result += board->at(r + 1).at(c+2);
	}

	return result;
}

int block4_1(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 2 < N && c + 1 < M) {
		result += board->at(r).at(c);
		result += board->at(r+1).at(c);
		result += board->at(r+1).at(c+1);
		result += board->at(r+2).at(c+1);
	}

	return result;
}

int block4_2(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 1 < N && c + 2 < M) {
		result += board->at(r).at(c+1);
		result += board->at(r).at(c+2);
		result += board->at(r+1).at(c);
		result += board->at(r+1).at(c+1);
	}

	return result;
}

int block4_3(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 2 < N && c + 1 < M) {
		result += board->at(r).at(c+1);
		result += board->at(r+1).at(c);
		result += board->at(r+1).at(c+1);
		result += board->at(r+2).at(c);
	}

	return result;
}

int block4_4(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 1 < N && c + 2 < M) {
		result += board->at(r).at(c);
		result += board->at(r).at(c+1);
		result += board->at(r+1).at(c+1);
		result += board->at(r+1).at(c+2);
	}

	return result;
}

int block5_1(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 1 < N && c + 2 < M) {
		result += board->at(r).at(c);
		result += board->at(r).at(c+1);
		result += board->at(r).at(c+2);
		result += board->at(r+1).at(c+1);
	}

	return result;
}

int block5_2(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 2 < N && c + 1 < M) {
		result += board->at(r).at(c+1);
		result += board->at(r+1).at(c);
		result += board->at(r+1).at(c+1);
		result += board->at(r+2).at(c+1);
	}

	return result;
}

int block5_3(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 1 < N && c + 2 < M) {
		result += board->at(r).at(c+1);
		result += board->at(r+1).at(c);
		result += board->at(r+1).at(c+1);
		result += board->at(r+1).at(c+2);
	}

	return result;
}

int block5_4(vector<vector<int>> *board, int r, int c) {
	int result = 0;
	if (r + 2 < N && c + 1 < M) {
		result += board->at(r).at(c);
		result += board->at(r+1).at(c);
		result += board->at(r+1).at(c+1);
		result += board->at(r+2).at(c);
	}

	return result;
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	int tmp = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			tmp = block1_1(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block1_2(&board, i, j);
			if (answer < tmp) answer = tmp;

			tmp = block2(&board, i, j);
			if (answer < tmp) answer = tmp;

			tmp = block3_1(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block3_2(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block3_3(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block3_4(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block3_5(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block3_6(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block3_7(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block3_8(&board, i, j);
			if (answer < tmp) answer = tmp;

			tmp = block4_1(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block4_2(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block4_3(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block4_4(&board, i, j);
			if (answer < tmp) answer = tmp;

			tmp = block5_1(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block5_2(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block5_3(&board, i, j);
			if (answer < tmp) answer = tmp;
			tmp = block5_4(&board, i, j);
			if (answer < tmp) answer = tmp;
		}
	}

	return answer;
}

int main() {
	int input;
	vector<vector<int>> board;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < M; j++) {
			cin >> input;
			row.push_back(input);
		}
		board.push_back(row);
	}
	
	cout << solution(board) << endl;

	return 0;
}
