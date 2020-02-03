#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int map[8][8];
int visited[8][8];
int N, M;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int maxV = 0;

struct pos{
	int y, x, cnt;
	pos(int a, int b, int c) : y(a), x(b), cnt(c) {}
};

void solve(){
	queue<pos> virus;
	int temp_map[8][8];
	int temp_visited[8][8];
	memset(temp_map,0,sizeof(temp_map));
	memset(temp_visited,0,sizeof(temp_visited));

	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			if(map[i][j] == 2){
				virus.push(pos(i,j,0));
			}
		}
	}

	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			temp_map[i][j] = map[i][j];
			temp_visited[i][j] = visited[i][j];
		}
	}

	while(!virus.empty()){
		int cx = virus.front().x;
		int cy = virus.front().y;
		virus.pop();
		for(int i = 0; i<4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if(temp_visited[ny][nx])
				continue;
			if(temp_map[ny][nx] == 0 && temp_visited[ny][nx] == 0){
				temp_visited[ny][nx] = 1;
				temp_map[ny][nx] = 2;
				virus.push(pos(ny,nx,0));
			}
		}
	}

	int ans = 0;

	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			if(temp_map[i][j] == 0){
				ans++;
			}
		}
	}

	maxV = max(ans,maxV);

}

void dfs(int y, int x, int cnt){
	if(cnt == 3){
		solve();
	}
	for(int i = y; i<N; i++){
		for(int j = 0; j<M; j++){
			if(map[i][j] == 0 && visited[i][j] == 0) 
			{
				visited[i][j] = 1;
				map[i][j] = 1;
				dfs(i,j, cnt + 1);
				visited[i][j] = 0;
				map[i][j] = 0;
			}
		}
	}
}

int main(){

	cin >> N >> M;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			cin >> map[i][j];
			/*if(map[i][j] == 2){
				q.push(pos(i,j,0));
			}*/
		}
	}

	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			if(map[i][j] == 0) 
			{
				visited[i][j] = 1;
				map[i][j] = 1;
				dfs(i,j, 1);
				visited[i][j] = 0;
				map[i][j] = 0;
			}
		}
	}

	cout << maxV << endl;


	return 0;
}
