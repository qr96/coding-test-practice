#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int south(int* dice);
int north(int* dice);
int east(int* dice);
int west(int* dice);

int BJ_14499() {
	int N, M;
	int r, c;
	int K;
	int d;
	int dice[6] = { 0, }; //dice[2] bottom, dice[5] top

	int map[20][20];

	cin >> N >> M >> r >> c >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (K--) {
		cin >> d;

		switch (d) {
		case 1:
			if (c + 1 < M) {
				c++;
				east(dice);
			}
			else continue;
			break;
		case 2:
			if (c - 1 >= 0) {
				c--;
				west(dice);
			}
			else continue;
			break;
		case 3:
			if (r - 1 >= 0) {
				r--;
				north(dice);
			}
			else continue;
			break;
		case 4:
			if (r + 1 < N) {
				r++;
				south(dice);
			}
			else continue;
			break;
		default:
			break;
		}

		if (map[r][c] == 0) {
			map[r][c] = dice[2];
		}
		else {
			dice[2] = map[r][c];
			map[r][c] = 0;
		}
		cout << dice[5] << endl;
	}

	return 0;
}

int south(int* dice) {
	int tmp = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[4];
	dice[4] = dice[5];
	dice[5] = tmp;

	return 0;
}

int north(int* dice) {
	int tmp = dice[0];
	dice[0] = dice[5];
	dice[5] = dice[4];
	dice[4] = dice[2];
	dice[2] = tmp;

	return 0;
}

int east(int* dice) {
	int tmp = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[3];
	dice[3] = dice[5];
	dice[5] = tmp;

	return 0;
}

int west(int* dice) {
	int tmp = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[3];
	dice[3] = dice[2];
	dice[2] = tmp;

	return 0;
}