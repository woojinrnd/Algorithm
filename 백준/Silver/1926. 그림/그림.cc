#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 도화지 정보와 방문 여부를 저장하는 배열
    int arr[501][501];
    bool chk[501][501];

    // BFS를 위한 큐 선언
    queue<pair<int,int>> Q;

    // 행과 열의 개수 입력
    int n, m;
    cin >> n >> m;
    
    // 상하좌우 이동을 위한 배열
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    // 도화지 정보 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];    
        }       
    }
    
    int area = 0; // 그림의 넓이
    int max = 0;   // 최대 넓이
    int num = 0;   // 그림의 개수

    // 도화지를 모두 탐색
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // 이미 방문한 곳이거나 그림이 아닌 경우, 다음 칸으로 넘어감
            if(chk[i][j] || arr[i][j]==0)
                continue;

            // 현재 칸은 그림의 시작점이므로 방문 여부를 체크하고 큐에 삽입
            chk[i][j] = 1;
            Q.push({i,j});
            area = 0;
            num++; // 그림의 개수 증가
            
            // BFS를 통해 현재 그림의 넓이를 계산
            while(!Q.empty()){
                pair<int,int> cur = Q.front();
                Q.pop();
                
                area++;

                // 현재 칸에서 4방향을 확인하여 이동 가능한 칸을 큐에 삽입
                for(int dir=0; dir<4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    
                    // 범위를 벗어나거나 이미 방문한 곳이면 넘어감
                    if(nx < 0 || nx >= n || ny < 0 || ny >=m)
                        continue;
                        
                    if(chk[nx][ny] || arr[nx][ny]==0)
                        continue;
                    
                    // 방문 표시를 하고 큐에 새로운 칸을 삽입
                    chk[nx][ny]=1;
                    Q.push({nx,ny});
                }

                // 최대 넓이 갱신
                if(max < area)
                    max = area;
            }
        }
    }

    // 그림의 개수와 최대 넓이 출력
    cout << num << "\n" << max;
    
    return 0; 
}
