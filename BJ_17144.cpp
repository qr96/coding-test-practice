#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> map, int T) {
	int answer = 0;
	int ar = 0;
	int ac = 0;

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			if (map[i][j] == -1) {
				ar = i;
				ac = j;
				break;
			}
		}
		if (ar > 0 || ac > 0) break;
	}

	while (T--) {
		vector<vector<int>> tmp = map;
		
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[0].size(); j++) {
				if (map[i][j] > 0) {
					if (i - 1 >= 0 && map[i-1][j] != -1) {
						tmp[i - 1][j] += map[i][j] / 5;
						tmp[i][j] -= map[i][j] / 5;
					}
					if (i + 1 < map.size() && map[i + 1][j] != -1) {
						tmp[i + 1][j] += map[i][j] / 5;
						tmp[i][j] -= map[i][j] / 5;
					}
					if (j - 1 >= 0 && map[i][j - 1] != -1) {
						tmp[i][j - 1] += map[i][j] / 5;
						tmp[i][j] -= map[i][j] / 5;
					}
					if (j + 1 < map[0].size() && map[i][j + 1] != -1) {
						tmp[i][j + 1] += map[i][j] / 5;
						tmp[i][j] -= map[i][j] / 5;
 					}
				}
			}
		}

		for (int i = ac - 1; i > 0; i--) {
			tmp[ar][i] = tmp[ar][i - 1];
			tmp[ar + 1][i] = tmp[ar + 1][i - 1];
		}

		for (int i = ar - 1; i > 0; i--) {
			tmp[i][0] = tmp[i - 1][0];
		}
		for (int i = ar + 2; i < tmp.size() - 1; i++) {
			tmp[i][0] = tmp[i + 1][0];
		}

		for (int i = 0; i < tmp[0].size() - 1; i++) {
			tmp[0][i] = tmp[0][i + 1];
			tmp[tmp.size() - 1][i] = tmp[tmp.size() - 1][i + 1];
		}

		for (int i = 0; i < ar; i++) {
			tmp[i][tmp[0].size() - 1] = tmp[i + 1][tmp[0].size() - 1];
		}
		for (int i = tmp.size() - 1; i > ar + 1; i--) {
			tmp[i][tmp[0].size() - 1] = tmp[i - 1][tmp[0].size() - 1];
		}

		for (int i = tmp[0].size() - 1; i > ac + 1; i--) {
			tmp[ar][i] = tmp[ar][i - 1];
			tmp[ar + 1][i] = tmp[ar + 1][i - 1];
		}

		tmp[ar][ac + 1] = 0;
		tmp[ar + 1][ac + 1] = 0;

		map = tmp;
	}

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			if (map[i][j] > 0) answer += map[i][j];
		}
	}

	return answer;
}

int main() {
	int R, C, T;
	int input;
	vector<vector<int>> map;

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		vector<int> row;
		for (int j = 0; j < C; j++) {
			cin >> input;
			row.push_back(input);
		}
		map.push_back(row);
	}

	cout << solution(map, T) << endl;

	return 0;
}
