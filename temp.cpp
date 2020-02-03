#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int map[51][51];
int visited_rotate_info[6];
int N, M, K;

struct rotat_info {
	int row, col, range;
	rotat_info(int a, int b, int c) : row(a), col(b), range(c) {}
};

void do_rotate(int tm[][51], int r, int c, int range) {
	
	for (int i = 0; i < range; i++) {
		int s_x = c - i;
		int s_y = r - i;
		//2*(i+1) + 1

	}
}

void solve(vector<rotat_info> &tv) {
	int temp_map[51][51];
	memset(temp_map, 0, sizeof(temp_map));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

		}
	}

	for (int i = 0; i < K; i++) {
		int c_row = tv[i].row;
		int c_col = tv[i].col;
		int c_range = tv[i].range;
		do_rotate(temp_map, c_row, c_col, c_range);
	}
	//이후 최소값 계산
}

void select_order(vector<rotat_info> &origin, vector<rotat_info> &tv) {
	if (tv.size() == origin.size()) {
		solve(tv);
		return;
	}
	for (int i = 0; i < K; i++) {
		if (visited_rotate_info[i] == 0) {
			visited_rotate_info[i] = 1;
			tv.push_back(origin[i]);
			select_order(origin, tv);
			tv.pop_back();
			visited_rotate_info[i] = 0;
		}
	}
}

int main() {

	cin >> N >> M >> K;
	vector<rotat_info> ri;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ri.push_back(rotat_info(a, b, c));
	}

	vector<rotat_info> tv;

	//기본상태 최소값
	for (int i = 0; i < K; i++) {
		visited_rotate_info[i] = 1;
		tv.push_back(ri[i]);
		select_order(ri, tv);
		visited_rotate_info[i] = 0;
		tv.pop_back();
	}


	return 0;
}
