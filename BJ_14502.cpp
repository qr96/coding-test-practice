#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int safe(int map[][8], int N, int M, vector<int> virus);

int BJ_14502() {
	int N, M;
	int ans = 0;
	int map[8][8] = {};
	vector<int> virus;

	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back(i);
				virus.push_back(j);
			}
		}
	}

	for (int i = 0; i < N*M; i++) {
		if (map[i / M][i%M] == 0) {
			map[i / M][i%M] = 1;
		}
		else continue;
		for (int j = i + 1; j < N*M; j++) {
			if (map[j / M][j%M] == 0) {
				map[j / M][j%M] = 1;
			}
			else continue;
			for (int k = j + 1; k < N*M; k++) {
				if (map[k / M][k%M] == 0) {
					map[k / M][k%M] = 1;
					int tmp = safe(map, N, M, virus);
					if (tmp > ans) {
						ans = tmp;
					}
					map[k / M][k%M] = 0;
				}
			}
			map[j / M][j%M] = 0;
		}
		map[i / M][i%M] = 0;
	}

	cout << ans << endl;

	return 0;
}

int safe(int map[][8], int N, int M, vector<int> virus) {
	int num = 0;
	int visit[8][8] = {};
	int r, c;
	queue<int> que;

	for (int i = 0; i < virus.size(); i++) {
		que.push(virus[i]);
	}

	while (!que.empty()) {
		r = que.front();
		que.pop();
		c = que.front();
		que.pop();

		visit[r][c] = 1;

		if (r - 1 >= 0 && map[r - 1][c] == 0 && visit[r - 1][c] == 0) { // top
			que.push(r - 1);
			que.push(c);
		}
		if (r + 1 < N && map[r + 1][c] == 0 && visit[r + 1][c] == 0) { // down
			que.push(r + 1);
			que.push(c);
		}
		if (c - 1 >= 0 && map[r][c - 1] == 0 && visit[r][c - 1] == 0) { // left
			que.push(r);
			que.push(c - 1);
		}
		if (c + 1 < M&&map[r][c + 1] == 0 && visit[r][c + 1] == 0) { // right
			que.push(r);
			que.push(c + 1);
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0 && map[i][j] == 0) {
				num++;
			}
		}
	}

	return num;
}
