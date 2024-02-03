#include <iostream>

using namespace std;

int n, s;
int cnt;
int arr[40];

void func(int k, int total) {
	if (k == n) {
		if (total==s) {
			cnt++;	
		}
		return;		
	}
	// 현재 수를 포함 안시키고 다음 
	func(k+1, total);
	func(k+1, total+arr[k]);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i=0; i<n; ++i) {
		cin >> arr[i];
	}
	func(0, 0);
	if (s==0) cnt--;
	cout << cnt;
	
	return 0;
}