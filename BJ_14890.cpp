#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> map, int L) {
	int answer = 0;

	for (int i = 0; i < map.size(); i++) {
		vector<int> diff;
		bool possible = true;
		for (int j = 1; j < map[0].size(); j++) {
			diff.push_back(map[i][j] - map[i][j - 1]);
		}

		for (int j = 0; j < diff.size(); j++) {
			if (diff[j] > 1 || diff[j] < -1) {
				possible = false;
				break;
			}
		}

		int prev = -1;
		for (int j = 0; j < diff.size(); j++) {
			if (diff[j] == 1) {
				if (j - prev < L) {
					possible = false;
					break;
				}
				prev = j;
			}
		}
		prev = diff.size();
		for (int j = diff.size()-1; j >= 0; j--) {
			if (diff[j] == -1) {
				if (prev - j < L) {
					possible = false;
					break;
				}
				prev = j;
			}
		}

		int hole = -1;
		for (int j = 0; j < diff.size(); j++) {
			if (diff[j] == -1) hole = j;
			if (hole >= 0 && diff[j] == 1) {
				if (j - hole < 2 * L) {
					possible = false;
					break;
				}
			}
		}

		if (possible) {
			answer++;
		}
	}

	for (int i = 0; i < map.size(); i++) {
		vector<int> diff;
		bool possible = true;
		for (int j = 1; j < map[0].size(); j++) {
			diff.push_back(map[j][i] - map[j - 1][i]);
		}

		for (int j = 0; j < diff.size(); j++) {
			if (diff[j] > 1 || diff[j] < -1) {
				possible = false;
				break;
			}
		}

		int prev = -1;
		for (int j = 0; j < diff.size(); j++) {
			if (diff[j] == 1) {
				if (j - prev < L) {
					possible = false;
					break;
				}
				prev = j;
			}
		}
		prev = diff.size();
		for (int j = diff.size() - 1; j >= 0; j--) {
			if (diff[j] == -1) {
				if (prev - j < L) {
					possible = false;
					break;
				}
				prev = j;
			}
		}

		int hole = -1;
		for (int j = 0; j < diff.size(); j++) {
			if (diff[j] == -1) hole = j;
			if (hole >= 0 && diff[j] == 1) {
				if (j - hole < 2 * L) {
					possible = false;
					break;
				}
			}
		}

		if (possible) {
			answer++;
		}
	}

	return answer;
}

int main() {
	int N, L;
	int input;
	vector<vector<int>> map;

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			cin >> input;
			row.push_back(input);
		}
		map.push_back(row);
	}

	cout << solution(map, L) << endl;

	return 0;
}
