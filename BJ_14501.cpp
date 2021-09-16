#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> day, vector<int> price) {
	int answer = 0;

	int dp[20] = {};
	int max = 0;

	for (int i = 0; i < day.size(); i++) {
		max = 0;
		for (int j = 0; j < i; j++) {
			if (max < dp[j]) {
				max = dp[j];
			}
		}
		if (dp[i + day[i] - 1] < max + price[i]) dp[i + day[i] - 1] = max + price[i];
	}

	max = 0;
	for (int i = 0; i < day.size(); i++) {
		if (max < dp[i]) max = dp[i];
	}
	answer = max;

	return answer;
}

int main() {
	int T = 0;
	vector<int> day;
	vector<int> price;
	int input;

	cin >> T;

	while (T--) {
		cin >> input;
		day.push_back(input);
		cin >> input;
		price.push_back(input);
	}

	cout << solution(day, price) << endl;

	return 0;
}

