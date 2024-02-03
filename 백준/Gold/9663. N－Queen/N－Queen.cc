#include <iostream>

using namespace std;

int n;
bool vis1[20]; // 열
bool vis2[20]; // / 대각선 
bool vis3[20]; // \ 대각선 
int cnt;

void func(int cur) { // 현재 퀸의 개수 cur=row 
	if (cur == n) {
		cnt++;
		return;
	}
	for (int i=0; i<n; ++i) {
		if (vis1[i] || vis2[cur+i] || vis3[cur-i+n-1])
			continue;
		vis1[i] = 1;
		vis2[cur+i] = 1;
		vis3[cur-i+n-1]  =1;
		func(cur+1);
		vis1[i] = 0;
		vis2[cur+i] = 0;
		vis3[cur-i+n-1] = 0;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	func(0);
	cout << cnt;
}