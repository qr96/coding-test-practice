#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int watch(int map[][50], int r, int c, int d);
void move(int* r, int* c, int d);

int N, M;

int BJ_14503() {

	int r, c, d;
	int map[50][50] = {};
	int visit[50][50] = {};
	int ans = 0;

	queue<int> que;

	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	que.push(r);
	que.push(c);
	que.push(d);

	while (1) {

		if (visit[r][c] == 0) ans++;
		visit[r][c] = 1;

		if (watch(map, r, c, (d + 3) % 4) == 0 && watch(visit, r, c, (d + 3) % 4) == 0) {
			d = (d + 3) % 4;
			move(&r, &c, d);
		}
		else if (watch(map, r, c, (d + 2) % 4) == 0 && watch(visit, r, c, (d + 2) % 4) == 0) {
			d = (d + 2) % 4;
			move(&r, &c, d);
		}
		else if (watch(map, r, c, (d + 1) % 4) == 0 && watch(visit, r, c, (d + 1) % 4) == 0) {
			d = (d + 1) % 4;
			move(&r, &c, d);
		}
		else if (watch(map, r, c, d) == 0 && watch(visit, r, c, d) == 0) {
			move(&r, &c, d);
		}
		else if (watch(map, r, c, (d + 2) % 4) == 0) {
			move(&r, &c, (d + 2) % 4);
		}
		else {
			break;
		}
	}

	cout << ans << endl;

	return 0;
}

int watch(int map[][50], int r, int c, int d) {
	switch (d) {
	case 0:
		if (r - 1 >= 0) return map[r - 1][c];
		break;
	case 1:
		if (c + 1 < M) return map[r][c + 1];
		break;
	case 2:
		if (r + 1 < N) return map[r + 1][c];
		break;
	case 3:
		if (c - 1 >= 0) return map[r][c - 1];
		break;
	}

	return 1;
}

void move(int* r, int* c, int d) {
	switch (d) {
	case 0:
		*r -= 1;
		break;
	case 1:
		*c += 1;
		break;
	case 2:
		*r += 1;
		break;
	case 3:
		*c -= 1;
		break;
	}
}
