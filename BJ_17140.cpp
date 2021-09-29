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

int solution(vector<vector<int>> arr, int r, int c, int k) {
	int answer = 0;
	int max = 0;
	map<int, int>::iterator iter;

	while (answer<=100) {
		if (r - 1 < arr.size() && c - 1 < arr[0].size() && arr[r - 1][c - 1] == k) break;

		if (arr.size() >= arr[0].size()) {
			max = 0;

			for (int i = 0; i < arr.size(); i++) {
				map<int, int> tmp;
				vector<int> row;

				for (int j = 0; j < arr[i].size(); j++) {
					iter = tmp.find(arr[i][j]);
					if (arr[i][j] == 0) continue;
					if (iter == tmp.end()) {
						tmp.insert(pair<int, int>(arr[i][j], 1));
					}
					else {
						(*iter).second++;
					}
				}

				for (iter = tmp.begin(); iter != tmp.end(); iter++) {
					row.push_back((*iter).first);
					row.push_back((*iter).second);
				}

				for (int i = 1; i < row.size(); i += 2) {
					for (int j = i + 2; j < row.size(); j += 2) {
						if (row[i] > row[j]) {
							swap(row[i], row[j]);
							swap(row[i - 1], row[j - 1]);
						}
						else if (row[i] == row[j]) {
							if (row[i - 1] > row[j - 1]) {
								swap(row[i - 1], row[j - 1]);
							}
						}
					}
				}

				arr[i] = row;
				if (max < row.size()) max = row.size();
			}

			for (int i = 0; i < arr.size(); i++) {
				for (int j = arr[i].size(); j < max; j++) {
					arr[i].push_back(0);
				}
			}
		}
		else {
			vector<vector<int>> arr2;
			vector<vector<int>> arr3;
			max = 0;

			for (int i = 0; i < arr[0].size(); i++) {
				vector<int> col;
				for (int j = 0; j < arr.size(); j++) {
					col.push_back(arr[j][i]);
				}
				arr2.push_back(col);
			}

			for (int i = 0; i < arr2.size(); i++) {
				map<int, int> tmp;
				vector<int> row;

				for (int j = 0; j < arr2[i].size(); j++) {
					iter = tmp.find(arr2[i][j]);
					if (arr2[i][j] == 0) continue;
					if (iter == tmp.end()) {
						tmp.insert(pair<int, int>(arr2[i][j], 1));
					}
					else {
						(*iter).second++;
					}
				}

				for (iter = tmp.begin(); iter != tmp.end(); iter++) {
					row.push_back((*iter).first);
					row.push_back((*iter).second);
				}

				for (int i = 1; i < row.size(); i += 2) {
					for (int j = i + 2; j < row.size(); j += 2) {
						if (row[i] > row[j]) {
							swap(row[i], row[j]);
							swap(row[i - 1], row[j - 1]);
						}
						else if (row[i] == row[j]) {
							if (row[i - 1] > row[j - 1]) {
								swap(row[i - 1], row[j - 1]);
							}
						}
					}
				}

				arr2[i] = row;
				if (max < row.size()) max = row.size();
			}

			for (int i = 0; i < arr2.size(); i++) {
				for (int j = arr2[i].size(); j < max; j++) {
					arr2[i].push_back(0);
				}
			}

			for (int i = 0; i < arr2[0].size(); i++) {
				vector<int> row;
				for (int j = 0; j < arr2.size(); j++) {
					row.push_back(arr2[j][i]);
				}
				arr3.push_back(row);
			}
			arr = arr3;
		}

		answer++;
	}

	if (answer > 100) answer = -1;

	return answer;
}

int main() {
	int input;
	int r, c, k;
	vector<vector<int>> map;

	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		vector<int> row;
		for (int j = 0; j < 3; j++) {
			cin >> input;
			row.push_back(input);
		}
		map.push_back(row);
	}

	cout << solution(map, r, c, k) << endl;

	return 0;
}
