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

int solution(int N, vector<vector<int>> blocks) {
	int answer = 0;
	int answer2 = 0;
	int red[4][4] = {};
	int green[7][4] = {};
	int blue[4][7] = {};

	for (int i = 0; i < 4; i++) {
		green[6][i] = 1;
		blue[i][6] = 1;
	}

	for (int i = 0; i < N; i++) {
		int t = blocks[i][0];
		int r = blocks[i][1];
		int c = blocks[i][2];

		if (t == 1) {
			for (int j = 0; j < 7; j++) {
				if (green[j][c] == 1) {
					green[j - 1][c] = 1;
					break;
				}
			}
			for (int j = 0; j < 7; j++) {
				if (blue[r][j] == 1) {
					blue[r][j - 1] = 1;
					break;
				}
			}
		}
		else if (t == 2) {
			for (int j = 0; j < 7; j++) {
				if (green[j][c] == 1 || green[j][c + 1] == 1) {
					green[j - 1][c] = 1;
					green[j - 1][c + 1] = 1;
					break;
				}
			}

			for (int j = 0; j < 7; j++) {
				if (blue[r][j] == 1) {
					blue[r][j - 1] = 1;
					blue[r][j - 2] = 1;
					break;
				}
			}
		}
		else if (t == 3) {
			for (int j = 0; j < 7; j++) {
				if (green[j][c] == 1) {
					green[j - 1][c] = 1;
					green[j - 2][c] = 1;
					break;
				}
			}
			for (int j = 0; j < 7; j++) {
				if (blue[r][j] == 1 || blue[r + 1][j] == 1) {
					blue[r][j - 1] = 1;
					blue[r + 1][j - 1] = 1;
					break;
				}
			}
		}

		//가득찬 경우 제거
		for (int j = 5; j >= 2; j--) {
			bool flag = true;
			for (int k = 0; k < 4; k++) {
				if (green[j][k] == 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				answer++;
				for (int k = 0; k < 4; k++) {
					for (int m = j; m > 0; m--) {
						green[m][k] = green[m - 1][k];
					}
				}
				j++;
			}
		}
		for (int j = 5; j >= 2; j--) {
			bool flag = true;
			for (int k = 0; k < 4; k++) {
				if (blue[k][j] == 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				answer++;
				for (int k = 0; k < 4; k++) {
					for (int m = j; m > 0; m--) {
						blue[k][m] = blue[k][m - 1];
					}
				}
				j++;
			}
		}

		//연한 칸에 블록
		int nums = 0;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++) {
				if (green[j][k] == 1) {
					nums++;
					break;
				}
			}
		}
		if (nums == 1) {
			for (int j = 5; j >= 1; j--) {
				for (int k = 0; k < 4; k++) {
					green[j][k] = green[j - 1][k];
				}
			}
		}
		else if (nums == 2) {
			for (int j = 5; j >= 2; j--) {
				for (int k = 0; k < 4; k++) {
					green[j][k] = green[j - 2][k];
				}
			}
		}
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++) {
				green[j][k] = 0;
			}
		}

		nums = 0;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++) {
				if (blue[k][j] == 1) {
					nums++;
					break;
				}
			}
		}
		if (nums == 1) {
			for (int j = 5; j >= 1; j--) {
				for (int k = 0; k < 4; k++) {
					blue[k][j] = blue[k][j - 1];
				}
			}
		}
		else if (nums == 2) {
			for (int j = 5; j >= 2; j--) {
				for (int k = 0; k < 4; k++) {
					blue[k][j] = blue[k][j - 2];
				}
			}
		}
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++) {
				blue[k][j] = 0;
			}
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j] == 1) answer2++;
			if (blue[j][i] == 1) answer2++;
		}
	}

	cout << answer << endl;
	cout << answer2 << endl;

	return 0;
}

int main() {
	int input;
	int N;
	vector<vector<int>> blocks;

	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int i = 0; i < 3; i++) {
			cin >> input;
			tmp.push_back(input);
		}
		blocks.push_back(tmp);
	}

	solution(N, blocks);

	return 0;
}
