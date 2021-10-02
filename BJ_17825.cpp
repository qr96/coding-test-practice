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



int solution(vector<int> dice) {
	int answer = 0;
	int now_dice = 0;
	int position = 0;

	stack<vector<int>> states;
	stack<pair<int, int>> dfs;
	stack<int> score;

	int scores[] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0,
					13, 16, 19,	25, 30, 35, 22, 24, 28, 27, 26 };
	int next[] = { 1, 2, 3, 4, 5, 22, 7, 8, 9, 10, 28, 12, 13, 14, 15, 30, 17, 18, 19, 20, 21, 21,
					23, 24, 25, 26, 27, 20, 29, 25, 31, 32, 25 };
	//100 : goal

	dfs.push(make_pair(0, 0));

	score.push(0);

	states.push(vector<int>(4, 0));

	while (!dfs.empty()) {
		int now = dfs.top().first;
		int depth = dfs.top().second;
		vector<int> state = states.top();
		int s = score.top();

		dfs.pop();
		states.pop();
		score.pop();

		now_dice = dice[depth];
		position = state[now];

		while (now_dice--) {
			position = next[position];
			if (position == 21) break;
		}

		bool flag = false;

		for (int i = 0; i < 4; i++) {
			if (now != i && position != 21 && position == state[i]) flag = true;
		}

		if (flag) continue;

		state[now] = position;
		s += scores[position];

		if (depth < 9) {
			if (state[0] != 21) {
				dfs.push(make_pair(0, depth + 1));
				states.push(state);
				score.push(s);
			}
			if (state[1] != 21) {
				dfs.push(make_pair(1, depth + 1));
				states.push(state);
				score.push(s);
			}
			if (state[2] != 21) {
				dfs.push(make_pair(2, depth + 1));
				states.push(state);
				score.push(s);
			}
			if (state[3] != 21) {
				dfs.push(make_pair(3, depth + 1));
				states.push(state);
				score.push(s);
			}
		}
		else {
			if (answer < s) answer = s;
		}
	}

	return answer;
}

int main() {
	int input;
	vector<int> dice;

	for (int i = 0; i < 10; i++) {
		cin >> input;
		dice.push_back(input);
	}
	
	cout << solution(dice) << endl;

	return 0;
}
