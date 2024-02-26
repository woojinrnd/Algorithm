#include <iostream>

using namespace std;

int n, m;
int N[10];
int isused[10];

void func(int k);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
	
	return 0;
}

void func(int k) {
	if (k == m) {
		for (int i=0; i<m; ++i) {
			cout << N[i] << ' ';
		}
		cout << '\n';
	}
	int st = 1;
	if (k != 0) st = N[k-1] + 1; // 이전 지점의 +1  
	for (int i=st; i<=n; ++i) {
		if (!isused[i]) {
			isused[i] = 1;
			N[k] = i;
			func(k+1);
			isused[i] = 0;
		}
	}
}