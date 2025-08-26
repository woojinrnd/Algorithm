#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int fee[105]; // 주차 요금
int Ws[2005]; // 차량 무게
queue<int> q_in; // Seq In
queue<int> q_wait; // Seq Wait
bool isEmpty[105]; // 주차 가능하면 true, 주차불가능하면 false
int sumFee;
int car2parkidx[2005]; // 현재 차량이 주차장 idx
bool isAllFull; // 주차자리가 꽉찼음

void input() {
	memset(isEmpty, true, sizeof(isEmpty));
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> fee[i];
	}

	for (int i = 1; i <= M; ++i) {
		cin >> Ws[i];
	}
	for (int i = 1; i <= 2 * M; ++i) {
		int tmp = 0;
		cin >> tmp;
		q_in.push(tmp);
	}
}

void solution() {
	// 주차장에 차량을 넣어야돼 
	// 비어있는지 확인
	// 꽉찼는지도 확인
	while (!q_in.empty()) {
		isAllFull = true;
		for (int i = 1; i <= N; ++i) {
			if (isEmpty[i] == true) {
				isAllFull = false;
				break;
			}
		}
		int now_car = 0;
		if (isAllFull == true && q_in.front() > 0) {
			q_wait.push(q_in.front());
			q_in.pop();
			continue;
		}
		else if (isAllFull == true && q_in.front() < 0) {
			now_car = q_in.front();
			q_in.pop();
		}
		else if (isAllFull == false && q_wait.empty() == false) {
			now_car = q_wait.front();
			q_wait.pop();
		}
		else if (isAllFull == false && q_wait.empty() == true) {
			now_car = q_in.front();
			q_in.pop();
		}

		// 출차
		// now_car 가 주차한 자리?
		if (now_car < 0) {
			isEmpty[car2parkidx[-now_car]] = true;
			continue;
		}

		for (int i = 1; i <= N; ++i) {
			if (isEmpty[i] == true) {
				isEmpty[i] = false;
				car2parkidx[now_car] = i;
				sumFee += (fee[i] * Ws[now_car]);
				break;
			}
		}
	}

	cout << sumFee << '\n';
}

void solve() {
	input();
	solution();
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}