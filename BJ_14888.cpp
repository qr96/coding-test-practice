#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

vector<int> solution(vector<int> A, vector<int> operators) {
	int max = -1000000005;
	int min = 1000000005;
	vector<int> answer;

	int now = 0;
	int depth = 0;
	vector<int> remain;
	vector<int> remaintmp;

	queue<int> que;
	queue<int> depths;
	queue<vector<int>> remains;

	que.push(A[0]);
	depths.push(0);
	remains.push(operators);

	while (!que.empty()) {
		now = que.front();
		depth = depths.front();
		remain = remains.front();

		que.pop();
		depths.pop();
		remains.pop(); 

		if (depth == A.size() - 1) {
			if (max < now) max = now;
			if (min > now) min = now;
			continue;
		}

		if (remain[0] > 0) {
			remaintmp = remain;
			remaintmp[0]--;
			que.push(now + A[depth + 1]);
			depths.push(depth + 1);
			remains.push(remaintmp);
		}
		if (remain[1] > 0) {
			remaintmp = remain;
			remaintmp[1]--;
			que.push(now - A[depth + 1]);
			depths.push(depth + 1);
			remains.push(remaintmp);
		}
		if (remain[2] > 0) {
			remaintmp = remain;
			remaintmp[2]--;
			que.push(now * A[depth + 1]);
			depths.push(depth + 1);
			remains.push(remaintmp);
		}
		if (remain[3] > 0) {
			remaintmp = remain;
			remaintmp[3]--;
			que.push(now / A[depth + 1]);
			depths.push(depth + 1);
			remains.push(remaintmp);
		}

	}

	answer.push_back(max);
	answer.push_back(min);

	return answer;
}

int main() {
	int input;
	int N;
	vector<int> A;
	vector<int> operators;

	cin >> N;

	while (N--) {
		cin >> input;
		A.push_back(input);
	}
	for (int i = 0; i < 4; i++) {
		cin >> input;
		operators.push_back(input);
	}

	cout << solution(A, operators)[0] << endl;
	cout << solution(A, operators)[1] << endl;

	return 0;
}
