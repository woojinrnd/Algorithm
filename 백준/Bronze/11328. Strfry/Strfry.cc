#include <iostream>
#include <algorithm>

using namespace std;

int T;
string A, B;
int freqA[26], freqB[26];

void input() {
    cin.ignore();
    cin >> A >> B;
}

void solution() {
    fill(&freqA[0], &freqA[0] + 26, 0);
    fill(&freqB[0], &freqB[0] + 26, 0);

    string res = "Possible";
    for (char i : A) {
        freqA[i-'a']++;
    }
    for (char i : B) {
        freqB[i-'a']++;
    }
    for (int i=0; i<26; ++i) {
        if (freqA[i] != freqB[i]) {
            res = "Impossible";
            break;
        }
    }
    cout << res << '\n';
}

// void solution() {
//     int res = A.size();
//     for (int i=0; i<A.size(); ++i) {
//         for (int j=0; j<B.size(); ++j) {
//             if (A[i] == B[j]) res--;
//         }
//     }
//     if (res == 0) {
//         cout << "Possible" << '\n';
//     }
//     else {
//         cout << "Impossible" << '\n';
//     }
// }

void solve() {
    cin >> T;
    for (int i=0; i<T; ++i) {
        input();
        solution();
    }  
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}