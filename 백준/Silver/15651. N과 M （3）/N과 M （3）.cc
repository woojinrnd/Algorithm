#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int N[10];
int isused[10];

void func(int k) {
	if (m == k) {
		for (int i=0; i<m; ++i) {
			cout << N[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i=1; i<=n; ++i) {
		isused[i] = 1;
		N[k] = i;
		func(k+1);
		isused[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
	
	return 0;
}