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

int solution(vector<int> belt, int K){
	int answer = 1;
	int tmp = 0;
	int N = belt.size() / 2;
	int count = 0;
	vector<int> robots;

	while (1) {
		//step1
		tmp = belt.back();
		for (int i = belt.size() - 1; i > 0; i--) {
			belt[i] = belt[i - 1];
		}
		belt[0] = tmp;

		for (int i = 0; i < robots.size(); i++) {
			robots[i]++;
		}

		if (!robots.empty() && robots[0] == N - 1) robots.erase(robots.begin());

		//step2
		for (int i = 0; i < robots.size(); i++) {
			if (belt[robots[i] + 1] > 0) {
				if (i == 0) {
					robots[i]++;
					belt[robots[i]]--;
				}
				else if (robots[i] + 1 != robots[i - 1]) {
					robots[i]++;
					belt[robots[i]]--;
				}
				
				if (robots[i] == N - 1) {
					robots.erase(robots.begin() + i);
					i--;
				}
			}
		}

		//step3
		if (belt[0] > 0) {
			robots.push_back(0);
			belt[0]--;
		}

		//step4
		count = 0;
		for (int i = 0; i < belt.size(); i++) {
			if (belt[i] == 0) count++;
		}
		if (count >= K) break;
		answer++;
	}

	return answer;
}

int main() {
	int input;
	int N, K;
	vector<int> belt;
	

	cin >> N >> K;

	for (int i = 0; i < 2 * N; i++) {
		cin >> input;
		belt.push_back(input);
	}

	cout << solution(belt, K) << endl;

	return 0;
}
