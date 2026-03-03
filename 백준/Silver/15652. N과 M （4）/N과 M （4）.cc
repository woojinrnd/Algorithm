#include <iostream>

using namespace std;

int n, m;
int N[10];


void func(int k) {
	if (k == m) {
		for (int i=0; i<m; ++i) {
			cout << N[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	// 1st case : k = 0; N[k] = 1
	// After 	: k = N[k-1]
	int st = 1;
	if (k!=0) st=N[k-1];
	for (int i=st; i<=n; ++i) {
		N[k] = i;
		func(k+1);	
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	func(0);
	
	return 0;
}