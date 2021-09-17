#include <vector>
#include <iostream>
#include <stack>

using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int solution(vector<vector<int>> mapA, vector<vector<int>> mapB) {
	int answer = 0;
	int r = 0;
	int c = 0;
	int rotate = 0;
	int position[16][2] = {};

	stack<vector<vector<int>>> mapAs;
	stack<vector<vector<int>>> mapBs;
	vector<vector<int>> mapa;
	vector<vector<int>> mapb;
	stack<int> sharkr;
	stack<int> sharkc;
	stack<int> eats;

	mapAs.push(mapA);
	mapBs.push(mapB);

	sharkr.push(0);
	sharkc.push(0);

	eats.push(0);

	while (!mapAs.empty()) {
		int tr, tc;
		int eat;

		mapa = mapAs.top();
		mapb = mapBs.top();

		r = sharkr.top();
		c = sharkc.top();

		eat = eats.top() + mapa[r][c];
		mapa[r][c] = 0;

		mapAs.pop();
		mapBs.pop();
		sharkr.pop();
		sharkc.pop();
		eats.pop();

		if (answer < eat) answer = eat;

		for (int i = 0; i < mapa.size(); i++) {
			for (int j = 0; j < mapa[0].size(); j++) {
				if (mapa[i][j] == 0) continue;
				position[mapa[i][j] - 1][0] = i;
				position[mapa[i][j] - 1][1] = j;
			}
		}

		for (int i = 0; i < 16; i++) {
			tr = position[i][0];
			tc = position[i][1];
			if (tr == r && tc == c || mapa[tr][tc] == 0) continue;

			rotate = 0;
			while (rotate < 8) {
				mapb[tr][tc] = (mapb[tr][tc] + rotate) % 8;
				switch (mapb[tr][tc])
				{
				case 0:
					if ((tr - 1 >= 0 && tc + 1 < 4) && !(tr - 1 == r && tc + 1 == c)) {
						swap(mapa[tr][tc], mapa[tr - 1][tc + 1]);
						swap(mapb[tr][tc], mapb[tr - 1][tc + 1]);
						swap(position[i][0], position[mapa[tr][tc] - 1][0]);
						swap(position[i][1], position[mapa[tr][tc] - 1][1]);
						rotate = 10;
					}
					break;
				case 1:
					if (tr - 1 >= 0 && !(tr - 1 == r && tc == c)) {
						swap(mapa[tr][tc], mapa[tr - 1][tc]);
						swap(mapb[tr][tc], mapb[tr - 1][tc]);
						swap(position[i][0], position[mapa[tr][tc]-1][0]);
						swap(position[i][1], position[mapa[tr][tc]-1][1]);
						rotate = 10;
					}
					break;
				case 2:
					if ((tr - 1 >= 0 && tc - 1 >= 0) && !(tr - 1 == r && tc - 1 == c)) {
						swap(mapa[tr][tc], mapa[tr - 1][tc - 1]);
						swap(mapb[tr][tc], mapb[tr - 1][tc - 1]);
						swap(position[i][0], position[mapa[tr][tc]-1][0]);
						swap(position[i][1], position[mapa[tr][tc]-1][1]);
						rotate = 10;
					}
					break;
				case 3:
					if (tc - 1 >= 0 && !(tr == r && tc - 1 == c)) {
						swap(mapa[tr][tc], mapa[tr][tc - 1]);
						swap(mapb[tr][tc], mapb[tr][tc - 1]);
						swap(position[i][0], position[mapa[tr][tc]-1][0]);
						swap(position[i][1], position[mapa[tr][tc]-1][1]);
						rotate = 10;
					}
					break;
				case 4:
					if ((tr + 1 < 4 && tc - 1 >= 0) && !(tr + 1 == r && tc - 1 == c)) {
						swap(mapa[tr][tc], mapa[tr + 1][tc - 1]);
						swap(mapb[tr][tc], mapb[tr + 1][tc - 1]);
						swap(position[i][0], position[mapa[tr][tc]-1][0]);
						swap(position[i][1], position[mapa[tr][tc]-1][1]);
						rotate = 10;
					}
					break;
				case 5:
					if (tr + 1 < 4 && !(tr + 1 == r && tc == c)) {
						swap(mapa[tr][tc], mapa[tr + 1][tc]);
						swap(mapb[tr][tc], mapb[tr + 1][tc]);
						swap(position[i][0], position[mapa[tr][tc]-1][0]);
						swap(position[i][1], position[mapa[tr][tc]-1][1]);
						rotate = 10;
					}
					break;
				case 6:
					if ((tr + 1 < 4 && tc + 1 < 4) && !(tr + 1 == r && tc + 1 == c)) {
						swap(mapa[tr][tc], mapa[tr + 1][tc + 1]);
						swap(mapb[tr][tc], mapb[tr + 1][tc + 1]);
						swap(position[i][0], position[mapa[tr][tc]-1][0]);
						swap(position[i][1], position[mapa[tr][tc]-1][1]);
						rotate = 10;
					}
					break;
				case 7:
					if (tc + 1 < 4 && !(tr == r && tc + 1 == c)) {
						swap(mapa[tr][tc], mapa[tr][tc + 1]);
						swap(mapb[tr][tc], mapb[tr][tc + 1]);
						swap(position[i][0], position[mapa[tr][tc]-1][0]);
						swap(position[i][1], position[mapa[tr][tc]-1][1]);
						rotate = 10;
					}
					break;
				default:
					break;
				}
				rotate++;
			}
		}

		switch (mapb[r][c]) {
		case 0:
			for (int i = 1; i < 4; i++) {
				if (r - i >= 0 || c + i >= 4) break;
				if (mapa[r - i][c + i] == 0) continue;
				mapAs.push(mapa);
				mapBs.push(mapb);

				sharkr.push(r - i);
				sharkc.push(c + i);

				eats.push(eat);
			}
			break;
		case 1:
			for (int i = 1; i < 4; i++) {
				if (r - i < 0) break;
				if (mapa[r - i][c] == 0) continue;
				mapAs.push(mapa);
				mapBs.push(mapb);

				sharkr.push(r - i);
				sharkc.push(c);

				eats.push(eat);
			}
			break;
		case 2:
			for (int i = 1; i < 4; i++) {
				if (r - i < 0 || c - i < 0) break;
				if (mapa[r - i][c - i] == 0) continue;
				mapAs.push(mapa);
				mapBs.push(mapb);

				sharkr.push(r - i);
				sharkc.push(c - i);

				eats.push(eat);
			}
		case 3:
			for (int i = 1; i < 4; i++) {
				if (c - i < 0) break;
				if (mapa[r][c - i] == 0) continue;
				mapAs.push(mapa);
				mapBs.push(mapb);

				sharkr.push(r);
				sharkc.push(c - i);

				eats.push(eat);
			}
		case 4:
			for (int i = 1; i < 4; i++) {
				if (r + i >= 4 || c - i < 0) break;
				if (mapa[r + i][c - i] == 0) continue;
				mapAs.push(mapa);
				mapBs.push(mapb);

				sharkr.push(r + i);
				sharkc.push(c - i);

				eats.push(eat);
			}
		case 5:
			for (int i = 1; i < 4; i++) {
				if (r + i >= 4) break;
				if (mapa[r + i][c] == 0) continue;
				mapAs.push(mapa);
				mapBs.push(mapb);

				sharkr.push(r + i);
				sharkc.push(c);

				eats.push(eat);
			}
			break;
		case 6:
			for (int i = 1; i < 4; i++) {
				if (r + i >= 4 || c + i >= 4) break;
				if (mapa[r + i][c + i] == 0) continue;
				mapAs.push(mapa);
				mapBs.push(mapb);

				sharkr.push(r + i);
				sharkc.push(c + i);

				eats.push(eat);
			}
			break;
		case 7:
			for (int i = 1; i < 4; i++) {
				if (c + i >= 4) break;
				if (mapa[r][c + i] == 0) continue;
				mapAs.push(mapa);
				mapBs.push(mapb);

				sharkr.push(r);
				sharkc.push(c + i);

				eats.push(eat);
			}
			break;
		default:
			break;
		}

	}


	return answer;
}

int main() {
	int input;
	vector<vector<int>> mapa;
	vector<vector<int>> mapb;

	for (int i = 0; i < 4; i++) {
		vector<int> rowa;
		vector<int> rowb;

		for (int j = 0; j < 4; j++) {
			cin >> input;
			rowa.push_back(input);
			cin >> input;
			rowb.push_back(input);
		}
		mapa.push_back(rowa);
		mapb.push_back(rowb);
	}

	cout << solution(mapa, mapb) << endl;



	return 0;
}
