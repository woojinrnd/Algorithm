#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		string a;
		cin >> a;
		stack<char> s;
		bool isValid = true;
		// '('이면 stack에 push, 
		// ')'이면 stack에서 '('를 pop
		// stack이 비어있거나 맨 위에값이 '('이 아니라면 false 
		// stack이 맨 마지막에 비어있지 않다면 false 
		for (auto c : a) {
			if (c == '(') {
				s.push(c);
			}
			else {
				if (s.empty() || s.top() != '(') {
					isValid = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) isValid = false;
		
		if (isValid) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}