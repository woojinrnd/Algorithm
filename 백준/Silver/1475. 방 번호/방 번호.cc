#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr(10,0);

int main() {
	int N; 
	cin >> N; 
	int cnt = 0;
	for (int i=N; i>0; i/=10) { 
		arr[i%10]++;
	}
	
	// 6 or 9 포함 x
	for (int i=0; i<10; ++i) {
		if (i!=9 && i!=6) cnt = max(cnt, arr[i]);
	}	
	
	// 6 or 9 포함 o 
	cout << max(cnt, (arr[6] + arr[9] + 1) / 2);
	return 0;
}