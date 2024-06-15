#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M, V; // node, edge, starting node
int MAP[1001][1001];
bool vist[1001];

void input() {
	cin >> N >> M >> V;
	for (int i=0; i<M; ++i) {
		int start, end;
		cin >> start >> end;
		MAP[start][end] = 1;
		MAP[end][start] = 1;
	}
}

void dfs(int x) {
	vist[x] = true;
	cout << x << ' ';
	for (int i=1; i<=N; ++i) {
		if (MAP[x][i] == 1 && vist[i] == false) dfs(i);
	}
}

void bfs() {
	queue<int> q;
	q.push(V);
	vist[V] = true;
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		cout << x << ' ';
		for (int i=1; i<=N; ++i) {
			if (MAP[x][i] == 1 && vist[i] == false) {
				vist[i] = true;
				q.push(i);
			}
		}
	}
}

void solution() {
	dfs(V);
	memset(vist, false, sizeof(vist));
	cout << '\n';
	bfs();
}

void solve() {
	input();
	solution();
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}