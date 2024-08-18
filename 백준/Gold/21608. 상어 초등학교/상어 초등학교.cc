#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    int num;
    int Friend[4];
};

struct position {
    int x;
    int y;
    int near_empty;
    int near_friend;
};

int n, ans;
int N[25][25];
student stu_arr[25 * 25];
vector<student> stu_vec;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input() {
    cin >> n;
    for (int i=0; i<n*n; ++i) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        stu_vec.push_back({a, {b, c, d, e}});
        stu_arr[a].num = a;
        stu_arr[a].Friend[0] = b;
        stu_arr[a].Friend[1] = c;
        stu_arr[a].Friend[2] = d;
        stu_arr[a].Friend[3] = e;
    }
}

// 1. 좋아하는 친구 수
// 2. 비어있는 칸 개수
// 3. 행 작 열 작
bool compare(position A, position B) {
    if (A.near_friend >= B.near_friend) {
        if (A.near_friend == B.near_friend) {
            if (A.near_empty >= B.near_empty) {
                if (A.near_empty == B.near_empty) {
                    if (A.x <= B.x) {
                        if (A.x == B.x) {
                            if (A.y < B.y) {
                                return true;
                            }
                            return false;
                        }
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void set_position() {
    for (int i=0; i<stu_vec.size(); ++i) {
        vector<position> pos;
        int stu_num = stu_vec[i].num;
        for (int x=0; x<n; ++x) {
            for (int y=0; y<n; ++y) {
                if (N[x][y] != 0) continue;
                int near_friend = 0;
                int near_empty = 0;
                for (int k=0; k<4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx<0||nx>=n||ny<0||ny>=n) continue;
                    if (N[nx][ny]==0) near_empty++;
                    else {
                        for (int j=0; j<4; ++j) {
                            int friend_num = stu_vec[i].Friend[j];
                            if (N[nx][ny]==friend_num) {
                                near_friend++;
                                break;
                            }
                        }
                    }
                }
                pos.push_back({x, y, near_empty, near_friend});
            }
        }
        sort(pos.begin(), pos.end(), compare);
        int pos_x = pos[0].x;
        int pos_y = pos[0].y;
        N[pos_x][pos_y] = stu_num;
    }
}

int calculate(int F) {
    if (F == 0) return 0;
    if (F == 1) return 1;
    if (F == 2) return 10;
    if (F == 3) return 100;
    if (F == 4) return 1000;
}

void calc_satisfy() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            int stu_num = N[i][j];
            int Friend = 0;
            for (int k=0; k<4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx<0||nx>=n||ny<0||ny>=n) continue;
                for (int l=0; l<4; ++l) {
                    int friend_num = stu_arr[stu_num].Friend[l];
                    if (N[nx][ny]==friend_num) {
                        Friend++;
                        break;
                    }
                }
            }
            ans += calculate(Friend);
        }
    }
}

void solution() {
    set_position();
    calc_satisfy();
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