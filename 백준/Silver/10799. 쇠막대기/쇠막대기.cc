#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

string s;
ll ans = 0;
int cnt = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int sz = s.length();

    for (int i = 0; i < sz; i++) {
        if (s[i] == '(') {
            cnt++;
        } else {  // s[i] == ')'
            if (s[i - 1] == '(') {  // 레이저일 경우
                cnt--;
                ans += cnt;
            } else {  // 막대의 끝일 경우
                cnt--;
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
