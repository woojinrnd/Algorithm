#include <iostream>

using namespace std;

int n;
int arr[100005];
int dif[100005];
bool check[2000005];
int sum;
int res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> arr[i];
		check[arr[i]] = true;
	}
	cin >> sum;
	for (int i=0; i<n; ++i) {
		if (sum - arr[i] > 0 && check[sum-arr[i]] != 0 && sum - arr[i] > arr[i])
		res++;			
	}
	cout << res;
	
	return 0;
}