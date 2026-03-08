#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool selected[10];
vector<int> v;

void input() {
    cin >> n >> m;
}

void dfs(int cnt) {
    if (cnt == m) {
        for (int i=0; i<v.size(); ++i) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }

    for (int i=1; i<=n; ++i) {
        if (selected[i]) continue;
        selected[i] = 1;
        v.push_back(i);
        dfs(cnt+1);
        v.pop_back();
        selected[i] = false;
    }
}

void solve() {
    input();
    dfs(0);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}