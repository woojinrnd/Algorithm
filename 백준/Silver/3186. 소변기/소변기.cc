#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K; // K 초이상의 시간 동안 계속 소변기 앞에 서 있으면
int L; // L 초 동안 소변기 앞에 서있는 사림이 없다면 
int N;
char arrN[100005]; // 0 : no human / 1 : human
vector<int> startFlashTime;
bool isFlash;

void input() {
	cin >> K >> L >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arrN[i];
	}
	for (int i = N; i < N+L; ++i) {
		arrN[i] = '0';
	}
}

void solution() {
	// K초 (1의 개수)
	// L초 (0의 개수)
	int cnt_k = 0;
	int cnt_l = 0;
	bool flag_k = false;
	bool flag_l = false;
	bool seq_k = false;
	bool seq_l = false;
	for (int i = 0; i < N+L; ++i) {
		if (arrN[i] == '1') {
			seq_k = true;
			seq_l = false;
			cnt_l = 0;
			if (seq_k) {
				cnt_k++;
				if (cnt_k == K) {
					flag_k = true;
				}
			}
		}
		if (arrN[i] == '0') {
			seq_k = false;
			seq_l = true;
			cnt_k = 0;
			if (seq_l) {
				cnt_l++;
				if (cnt_l == L && flag_k==true) {
					flag_l = true;
				}
			}
		}
		if (flag_k && flag_l) { // flash on
			isFlash = true;
			startFlashTime.push_back(i+1);
			flag_k = false;
			flag_l = false;
			cnt_k = 0;
			cnt_l = 0;
		}
	}
	if (isFlash == false) {
		cout << "NIKAD" << '\n';
	}
	else {
		sort(startFlashTime.begin(), startFlashTime.end());
		for (int i : startFlashTime) {
			cout << i << '\n';
		}
	}
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