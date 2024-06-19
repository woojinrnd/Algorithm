#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int N[1000];
vector<int> sum; 

// x + y + z = k  x + y = k - z --> A = B
// 3 + 5 + 10 = 18  N[2] + N[3] + N[4] = N[5]
// 3 + 5 = 18 - 10  N[2] + N[3] = N[5] - N[4] 


void input() {
    cin >> n; 
    for (int i=0; i<n; ++i) {
        cin >> N[i];
    }
}

void solution() {
    // A
    for (int i=0; i<n; ++i) {
        for (int j=i; j<n; ++j) {
            sum.push_back(N[i]+N[j]);
        }
    }
    sort(N, N+n);
    sort(sum.begin(), sum.end());

    for (int i=n-1; i>=0; --i) {
        for (int j=i; j>=0; --j) {
            int B = N[i] - N[j]; // B
            bool flag = binary_search(sum.begin(), sum.end(), B); // A==B ? 1 : 0
            if (flag) {
                cout << N[i] << '\n';
                return ;
            }
        }
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