#include <bits/stdc++.h>
using namespace std;

int dist[100002]; // 각 위치까지의 최단 이동 거리를 저장하는 배열
int n, k; // 수빈이의 위치와 동생의 위치

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> k;
  
  fill(dist, dist + 100001, -1); // dist 배열을 -1로 초기화
  dist[n] = 0; // 수빈이의 위치까지의 최단 이동 거리는 0
  queue<int> Q;
  Q.push(n); // 초기 위치를 큐에 넣음
  
  while (dist[k] == -1) { // 동생의 위치까지의 최단 이동 거리가 계산될 때까지 반복
    int cur = Q.front();
    Q.pop();
    
    // 현재 위치에서 -1, +1, 2*cur 위치로 이동하는 경우 고려
    for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
      if (nxt < 0 || nxt > 100000) continue; // 범위를 벗어나면 무시
      if (dist[nxt] != -1) continue; // 이미 방문한 위치면 무시
      
      dist[nxt] = dist[cur] + 1; // 최단 이동 거리 갱신
      Q.push(nxt); // 큐에 추가
    }
  }
  
  cout << dist[k]; // 동생의 위치까지의 최단 이동 거리 출력
  return 0;
}
