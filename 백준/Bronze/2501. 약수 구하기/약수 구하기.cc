#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> N;

void input() {
    cin >> n >> k;
}

void solution() {
    for (int i=1; i<=n; ++i) {
        if (n % i ==0 ) {
            if (n % i == 0) {
                N.push_back(i);
            }
        }
    }
    if (N.size() < k) {
            cout << 0 << '\n';
    }
    
    else 
    {
        cout << N[k-1] << '\n';
    }
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