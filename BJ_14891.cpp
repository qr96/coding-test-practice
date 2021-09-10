#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
void rotate(int* gear, int w);

int BJ_14891() {
	int gear[4][8] = {};

	int K = 0;
	int g, w;
	int score = 0;

	int gaeSSibal = 0;

	for (int i = 0; i < 4; i++) {
		cin >> gaeSSibal;
		for (int j = 7; j >= 0; j--) {
			gear[i][j] = gaeSSibal % 10;
			gaeSSibal /= 10;
		}
	}

	cin >> K;

	while (K--) {
		cin >> g >> w;
		int rotates[4] = {};
		int wtmp = w;
		g--;

		rotates[g] = w;
		for (int i = g; i > 0; i--) {
			if (gear[i][6] == gear[i - 1][2]) break;
			wtmp *= -1;
			rotates[i - 1] = wtmp;
		}

		wtmp = w;
		for (int i = g; i < 3; i++) {
			if (gear[i][2] == gear[i + 1][6]) break;
			wtmp *= -1;
			rotates[i + 1] = wtmp;
		}

		for (int i = 0; i < 4; i++) {
			rotate(gear[i], rotates[i]);
		}
	}

	if (gear[0][0] == 1) score += 1;
	if (gear[1][0] == 1) score += 2;
	if (gear[2][0] == 1) score += 4;
	if (gear[3][0] == 1) score += 8;

	cout << score << endl;

	return 0;
}

void rotate(int* gear, int w) {
	int tmp = 0;
	if (w == 1) {
		tmp = gear[7];
		for (int i = 7; i > 0; i--) gear[i] = gear[i - 1];
		gear[0] = tmp;
	}
	else if (w == -1) {
		tmp = gear[0];
		for (int i = 0; i < 7; i++) gear[i] = gear[i + 1];
		gear[7] = tmp;
	}
}