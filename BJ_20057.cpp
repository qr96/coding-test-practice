#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;


int left(vector<vector<int>> &map, int &r, int &c) {
	int sand = 0;
	int alpha = 0;
	int N = 0;

	if (c - 1 >= 0) sand = map[r][c - 1];
	alpha = sand;
	N = map.size();
	c -= 1;

	if (map[r][c] > 0) {
		if (r - 1 >= 0 && c + 1 < N) map[r - 1][c + 1] += sand / 100;

		if (r + 1 < N && c + 1 < N)	map[r + 1][c + 1] += sand / 100;

		if (r - 2 >= 0) map[r - 2][c] += sand / 50;

		if (r + 2 < N) map[r + 2][c] += sand / 50;
		
		if (r - 1 >= 0) map[r - 1][c] += sand * 7 / 100;

		if(r+1<N) map[r + 1][c] += sand * 7 / 100;

		if(r-1>=0 && c-1>=0 ) map[r - 1][c - 1] += sand / 10;

		if(r+1<N && c-1>=0) map[r + 1][c - 1] += sand / 10;

		if (c - 2 >= 0) map[r][c - 2] += sand / 20;

		alpha -= sand / 100;
		alpha -= sand / 100;
		alpha -= sand / 50;
		alpha -= sand / 50;
		alpha -= sand * 7 / 100;
		alpha -= sand * 7 / 100;
		alpha -= sand / 10;
		alpha -= sand / 10;
		alpha -= sand / 20;

		if (c - 1 >= 0) map[r][c - 1] += alpha;
		map[r][c] = 0;
	}

	return 0;
}
int right(vector<vector<int>> &map, int &r, int &c) {
	int sand = map[r][c + 1];
	int alpha = sand;
	int N = map.size();

	c += 1;
	if (map[r][c] > 0) {
		if (r - 1 >= 0 && c - 1 >= 0) map[r - 1][c - 1] += sand / 100;

		if (r + 1 < N && c - 1 >= 0) map[r + 1][c - 1] += sand / 100;

		if (r - 2 >= 0) map[r - 2][c] += sand / 50;

		if (r + 2 < N) map[r + 2][c] += sand / 50;

		if (r - 1 >= 0) map[r - 1][c] += sand * 7 / 100;

		if (r + 1 < N) map[r + 1][c] += sand * 7 / 100;

		if (r - 1 >= 0 && c + 1 < N) map[r - 1][c + 1] += sand / 10;

		if (r + 1 < N && c + 1 < N) map[r + 1][c + 1] += sand / 10;

		if (c + 2 < N) map[r][c + 2] += sand / 20;

		alpha -= sand / 100;
		alpha -= sand / 100;
		alpha -= sand / 50;
		alpha -= sand / 50;
		alpha -= sand * 7 / 100;
		alpha -= sand * 7 / 100;
		alpha -= sand / 10;
		alpha -= sand / 10;
		alpha -= sand / 20;

		if (c + 1 < N) map[r][c + 1] += alpha;
		map[r][c] = 0;
	}

	return 0;
}

int up(vector<vector<int>> &map, int &r, int &c) {
	int sand = map[r-1][c];
	int alpha = sand;
	int N = map.size();

	r -= 1;
	if (map[r][c] > 0) {
		if (r + 1 < N && c + 1 < N) map[r + 1][c + 1] += sand / 100;

		if (r + 1 < N && c - 1 >= 0) map[r + 1][c - 1] += sand / 100;

		if (c - 2 >= 0) map[r][c - 2] += sand / 50;

		if (c + 2 < N) map[r][c + 2] += sand / 50;

		if (c - 1 >= 0) map[r][c - 1] += sand * 7 / 100;

		if (c + 1 < N) map[r][c + 1] += sand * 7 / 100;

		if (r - 1 >= 0 && c + 1 < N) map[r - 1][c + 1] += sand / 10;

		if (r - 1 >= 0 && c - 1 >= 0) map[r - 1][c - 1] += sand / 10;

		if (r - 2 >= 0) map[r - 2][c] += sand / 20;

		alpha -= sand / 100;
		alpha -= sand / 100;
		alpha -= sand / 50;
		alpha -= sand / 50;
		alpha -= sand * 7 / 100;
		alpha -= sand * 7 / 100;
		alpha -= sand / 10;
		alpha -= sand / 10;
		alpha -= sand / 20;

		if (r - 1 >= 0) map[r - 1][c] += alpha;
		map[r][c] = 0;
	}

	return 0;
}

int down(vector<vector<int>> &map, int &r, int &c) {
	int sand = map[r + 1][c];
	int alpha = sand;
	int N = map.size();

	r += 1;
	if (map[r][c] > 0) {
		if (r - 1 >= 0 && c + 1 < N) map[r - 1][c + 1] += sand / 100;

		if (r - 1 >= 0 && c - 1 >= 0) map[r - 1][c - 1] += sand / 100;

		if (c - 2 >= 0) map[r][c - 2] += sand / 50;

		if (c + 2 < N) map[r][c + 2] += sand / 50;

		if (c - 1 >= 0) map[r][c - 1] += sand * 7 / 100;

		if (c + 1 < N) map[r][c + 1] += sand * 7 / 100;

		if (r + 1 < N && c + 1 < N) map[r + 1][c + 1] += sand / 10;

		if (r + 1 < N && c - 1 >= 0) map[r + 1][c - 1] += sand / 10;

		if (r + 2 < N) map[r + 2][c] += sand / 20;

		alpha -= sand / 100;
		alpha -= sand / 100;
		alpha -= sand / 50;
		alpha -= sand / 50;
		alpha -= sand * 7 / 100;
		alpha -= sand * 7 / 100;
		alpha -= sand / 10;
		alpha -= sand / 10;
		alpha -= sand / 20;

		if (r + 1 < N) map[r + 1][c] += alpha;
		map[r][c] = 0;
	}

	return 0;
}

int main() {
	int N = 0;
	int answer = 0;
	int r, c;
	int allsand = 0;
	int sandsum = 0;
	vector<vector<int>> map;

	cin >> N;
	r = N / 2;
	c = N / 2;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int input = 0;
		for (int j = 0; j < N; j++) {
			cin >> input;
			allsand += input;
			tmp.push_back(input);
		}
		map.push_back(tmp);
	}

	for (int i = 0; i < (N-1)*2; i++) {
		if (i % 4 == 0) {
			for (int j = 0; j < i / 2 + 1; j++) {
				left(map, r, c);
			}
		}
		else if (i % 4 == 1) {
			for (int j = 0; j < i / 2 + 1; j++) {
				down(map, r, c);
			}
		}
		else if (i % 4 == 2) {
			for (int j = 0; j < i / 2 + 1; j++) {
				right(map, r, c);
			}
		}
		else if (i % 4 == 3) {
			for (int j = 0; j < i / 2 + 1; j++) {
				up(map, r, c);
			}
		}
	}
	for (int i = 0; i < N - 1; i++) {
		left(map, r, c);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sandsum += map[i][j];
		}
	}

	cout << allsand - sandsum << endl;

	return 0;
}
