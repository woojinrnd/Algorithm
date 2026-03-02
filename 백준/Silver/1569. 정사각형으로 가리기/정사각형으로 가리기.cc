#include <iostream>
#include <algorithm>
using namespace std;

int N;
struct point {
    int x, y;
};
point pts[51];

bool check(int sx, int sy, int L) {
    for (int i = 0; i < N; ++i) {
        int px = pts[i].x;
        int py = pts[i].y;

        if (!(px == sx || px == sx + L ||
              py == sy || py == sy + L)) {
            return false;
        }

        // 정사각형 범위 밖이면 실패
        if (px < sx || px > sx + L ||
            py < sy || py > sy + L) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> pts[i].x >> pts[i].y;

    int xmin = pts[0].x, xmax = pts[0].x;
    int ymin = pts[0].y, ymax = pts[0].y;

    for (int i = 1; i < N; ++i) {
        xmin = min(xmin, pts[i].x);
        xmax = max(xmax, pts[i].x);
        ymin = min(ymin, pts[i].y);
        ymax = max(ymax, pts[i].y);
    }

    int L = max(xmax - xmin, ymax - ymin);

    // 4가지 경우 검사
    if (check(xmin, ymin, L) ||
        check(xmin, ymax - L, L) ||
        check(xmax - L, ymin, L) ||
        check(xmax - L, ymax - L, L)) {
        cout << L;
    } else {
        cout << -1;
    }

    return 0;
}