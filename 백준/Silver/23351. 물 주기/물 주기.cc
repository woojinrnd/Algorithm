#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 화분 갯수
int K; // 수분
int A; // 물주는 화분수
int B; // 물
vector<int> ary_k;
int day;

void input() {
	cin >> N >> K >> A >> B;
}


void GiveWater() {
	for (int i = 0; i < A; ++i) {
		ary_k[i] += B;
	}
}

void MinusWater() {
	for (int i = 0; i < N; ++i) {
		ary_k[i] -= 1;
	}
}

void solution() {
	// 1. A개에 B만큼 물준다
	// 2. ary_k는 1씩 감소
	// 3. ary_k = 0이 되면 죽는다.

	for (int i = 0; i < N; ++i) {
		ary_k.push_back(K);
	}
	while (ary_k[0]!=0) {
		GiveWater();
		MinusWater();
		sort(ary_k.begin(), ary_k.end());
		day++;
	}
	cout << day;
}

void solve() {
	input();
	solution();
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}
