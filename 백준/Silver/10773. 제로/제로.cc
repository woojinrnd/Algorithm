#include <iostream>
#include <stack>

using namespace std;

int K;
stack<int> s;
int res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K;
	for (int i=0; i<K; ++i) {
		int num;
		cin >> num;
		if (num == 0) {
			s.pop();
			continue;
		}
		s.push(num);
	}
	while(!s.empty()) {
		int a = s.top();
		res += a;
		s.pop();
	}
	cout << res;
	
	return 0;
}