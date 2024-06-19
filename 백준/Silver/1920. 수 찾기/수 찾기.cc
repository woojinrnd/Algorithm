#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100005

int n, m;
vector<int> N;
vector<int> M;

void input() {
    cin >> n;
    N.resize(n);
    for (int i=0; i<n; ++i) {
        cin >> N[i];
    }
    
    cin >> m;
    M.resize(m);
    for (int i=0; i<m; ++i) {        
        cin >> M[i];
    }

    sort(N.begin(), N.end());
}

void solution() {
    for (int i=0; i<m; ++i) {
        bool flag = binary_search(N.begin(), N.end(), M[i]);
        cout << flag << '\n';
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