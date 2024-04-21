#include <iostream>
#include <stack>

using namespace std;

stack<char> st;
string s;
int ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	stack<char> st;
	for (int i=0; i<s.length(); ++i) {
		// '('이면 stack push 
		if (s[i] == '(') st.push(s[i]);
		// ')' 이면 
		else {
			// 직전 값이 '('이면 레이저 
			if (s[i-1] == '(') {
				st.pop();
				ans += st.size();
			}
			// 직전 값이 '('아니라면 막대기 끝 
			else {
				st.pop();
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}