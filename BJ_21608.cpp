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

int solution(int N, vector<vector<int>> students) {
	int answer = 0;
	vector<vector<int>> room;
	
	for (int i = 0; i < N; i++) {
		vector<int> tmp(N);
		room.push_back(tmp);
	}

	for (int i = 0; i < N*N; i++) {
		int most = 0;
		vector<pair<int, int>> candids;

		//step1
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (room[j][k] > 0) continue;
				int likes = 0;

				if (j - 1 >= 0) {
					for (int s = 1; s < 5; s++) {
						if (students[i][s] == room[j - 1][k]) {
							likes++;
							break;
						}
					}
				}
				if (k - 1 >= 0) {
					for (int s = 1; s < 5; s++) {
						if (students[i][s] == room[j][k - 1]) {
							likes++;
							break;
						}
					}
				}
				if (j + 1 < N) {
					for (int s = 1; s < 5; s++) {
						if (students[i][s] == room[j + 1][k]) {
							likes++;
							break;
						}
					}
				}
				if (k + 1 < N) {
					for (int s = 1; s < 5; s++) {
						if (students[i][s] == room[j][k + 1]) {
							likes++;
							break;
						}
					}
				}

				if (likes > most) {
					most = likes;
					candids.clear();
					candids.push_back(make_pair(j, k));
				}
				else if (likes == most) {
					candids.push_back(make_pair(j, k));
				}
			}
		}
		if (candids.size() == 1) {
			room[candids[0].first][candids[0].second] = students[i][0];
			continue;
		}

		//step2
		int most_blank = 0;
		vector<pair<int, int>> candids2;

		for (int j = 0; j < candids.size(); j++) {
			int r = candids[j].first;
			int c = candids[j].second;
			int blank = 0;

			if (r - 1 >= 0 && room[r - 1][c] == 0) blank++;
			if (c - 1 >= 0 && room[r][c - 1] == 0) blank++;
			if (r + 1 < N && room[r + 1][c] == 0) blank++;
			if (c + 1 < N && room[r][c + 1] == 0) blank++;
			
			if (blank > most_blank) {
				most_blank = blank;
				candids2.clear();
				candids2.push_back(make_pair(r, c));
			}
			else if (blank == most_blank) {
				candids2.push_back(make_pair(r, c));
			}
		}
		if (candids2.size() == 1) {
			room[candids2[0].first][candids2[0].second] = students[i][0];
			continue;
		}

		//step3
		int minr = candids2[0].first;
		int minc = candids2[0].second;
		for (int j = 1; j < candids2.size(); j++) {
			if (candids2[j].first < minr) {
				minr = candids2[j].first;
			}
		}
		for (int j = 1; j < candids2.size(); j++) {
			if (candids2[j].first == minr && candids2[j].second < minc) {
				minc = candids2[j].second;
			}
		}
		room[minr][minc] = students[i][0];
	}

	sort(students.begin(), students.end());
	
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int like = 0;

			if (r - 1 >= 0) {
				for (int i = 1; i < 5; i++) {
					if (students[room[r][c] - 1][i] == room[r - 1][c]) {
						like++;
						break;
					}
				}
			}
			if (c - 1 >= 0) {
				for (int i = 1; i < 5; i++) {
					if (students[room[r][c] - 1][i] == room[r][c - 1]) {
						like++;
						break;
					}
				}
			}
			if (r + 1 < N) {
				for (int i = 1; i < 5; i++) {
					if (students[room[r][c] - 1][i] == room[r + 1][c]) {
						like++;
						break;
					}
				}
			}
			if (c + 1 < N) {
				for (int i = 1; i < 5; i++) {
					if (students[room[r][c] - 1][i] == room[r][c + 1]) {
						like++;
						break;
					}
				}
			}

			if (like == 1) answer += 1;
			else if (like == 2) answer += 10;
			else if (like == 3) answer += 100;
			else if (like == 4) answer += 1000;
		}
	}

	return answer;
}

int main() {
	int input;
	int N;
	vector<vector<int>> students;

	cin >> N;

	for (int i = 0; i < N*N; i++) {
		vector<int> tmp;
		for (int i = 0; i < 5; i++) {
			cin >> input;
			tmp.push_back(input);
		}
		students.push_back(tmp);
	}

	cout << solution(N, students) << endl;

	return 0;
}
