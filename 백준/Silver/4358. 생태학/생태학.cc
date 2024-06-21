#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> m;

void solution() {
    string str;
    int cnt = 0;
    while(getline(cin, str)) {
        m[str]++, cnt++;
    }
    cout << fixed;
    cout.precision(4);

    for (auto i : m) {
        cout << i.first << ' ' << i.second*100/(double)cnt << '\n';
    }
}

void solve() {
    solution();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}

