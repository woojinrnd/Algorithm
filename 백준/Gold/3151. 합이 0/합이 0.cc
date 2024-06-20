#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

void input() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
}

void solution() {
    long long ans = 0;

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int target = -(v[i] + v[j]);
            auto lb = lower_bound(v.begin() + j + 1, v.end(), target);
            auto ub = upper_bound(v.begin() + j + 1, v.end(), target);

            ans += distance(lb, ub); // 두 포인터 사이의 거리를 추가하여 합이 0이 되는 경우의 수를 더함
        }
    }

    cout << ans << '\n';
}

void solve() {
    input();
    solution();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
