#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 10억 -> int형으로 가능
int T, n, m;
long long ans;
vector<int> N, M;
vector<int> N_sum, M_sum;

void input() {
    cin >> T >> n;
    N.resize(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> N[i];
    }
    cin >> m;
    M.resize(m+1);
    for (int i=1; i<=m; ++i) {
        cin >> M[i];
    }
}

void getSum() {
    for (int i=1; i<=n; ++i) {
        int sum = 0;
        for (int j=i; j<=n; ++j) {
            if (i == j) sum = N[i];
            else sum = sum + N[j];
            N_sum.push_back(sum);
        }
    }
    for (int i=1; i<=m; ++i) {
        int sum = 0;
        for (int j=i; j<=m; ++j) {           
            if (i == j) sum = M[i];
            else sum = sum + M[j];
            M_sum.push_back(sum);
        }
    }
    // cout << N_sum.size() <<'\n';
    // cout << M_sum.size() <<'\n';
    // for (int i : N_sum) {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    // for (int i : M_sum) {
    //     cout << i << ' ';
    // }
}


// A 연속합 + B 연속합 = T
void solution() {
    getSum();
    // cout << '\n';
    sort(M_sum.begin(), M_sum.end());
    for (int i=0; i<N_sum.size(); ++i) {
        int B = T - N_sum[i];
        auto lower = lower_bound(M_sum.begin(), M_sum.end(), B);
        auto upper = upper_bound(M_sum.begin(), M_sum.end(), B);
        // cout << "i : " << i+1 << ' ';
        // cout << "lower : " << *lower << ' ';
        // cout << "upper : " <<  *upper << ' ';
        // cout << "dis : " << distance(lower, upper) <<'\n';
        ans += distance(lower, upper);
    }
    // cout << '\n';
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