#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> curve(vector<int> t, vector<int> pivot);

int BJ_15685() {
	int map[101][101] = {};

	int N = 0;
	int x, y, d, g;
	int ans = 0;

	vector<vector<int>> dragons;
	vector<int> tmp;

	cin >> N;

	while (N--) {
		dragons.clear();
		tmp.clear();

		cin >> x >> y >> d >> g;

		tmp.push_back(x);
		tmp.push_back(y);

		dragons.push_back(tmp);
		tmp.clear();

		if (d == 0) {
			tmp.push_back(x + 1);
			tmp.push_back(y);
		}
		else if (d == 1) {
			tmp.push_back(x);
			tmp.push_back(y - 1);
		}
		else if (d == 2) {
			tmp.push_back(x - 1);
			tmp.push_back(y);
		}
		else if (d == 3) {
			tmp.push_back(x);
			tmp.push_back(y + 1);
		}

		//printf("%d %d\n", tmp[0], tmp[1]);

		dragons.push_back(tmp);
		tmp.clear();

		while (g--) {
			int dsize = dragons.size();
			vector<int> pivot = dragons.back();
			for (int i = dsize - 1; i >= 0; i--) {
				dragons.push_back(curve(dragons[i], pivot));
			}
		}

		for (int i = 0; i < dragons.size(); i++) {
			map[dragons[i][0]][dragons[i][1]] = 1;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			//cout << map[j][i] << "";
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) ans++;
		}
		//cout << endl;
	}

	cout << ans << endl;

	return 0;
}

vector<int> curve(vector<int> t, vector<int> pivot) {
	vector<int> tt;

	tt.push_back(pivot[0] + pivot[1] - t[1]);
	tt.push_back(pivot[1] - pivot[0] + t[0]);

	return tt;
}
