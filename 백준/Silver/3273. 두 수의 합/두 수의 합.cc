/*
하나는 원소 체크(기록)을 해서 배열의 원소 
a에 대해서 x-a가 배열에 있는 지 체크하는 법

또 하나는 정렬 후 투포인터를 이용하는 법.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, x, tmp;
int num[100001];
int cnt[2000001]; 


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> tmp;
		num[i] = tmp;
		cnt[tmp] = 1;
	}
	cin >> x;
	int sum =0;
	for (int i=0; i<n; ++i) {
		if (x-num[i]>0 && cnt[x-num[i]] != 0 && x-num[i]>num[i])
			sum+=1;
	}
	cout << sum;

	return 0;
}