// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <deque>
#include <queue>

using namespace std;


int n, k, l;

int board[101][101];
deque <pair<int, int>> snake;
queue <pair<int, char>> dir;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int sec; 
int d = 1; // 처음에 동쪽을 향함


void go() {

	while (true) {

		sec++; // N초가 지난 후에 방향을 전환하므로, 미리 초를 셈


		auto cur = snake.front(); // 현재 뱀의 머리
		int nx = cur.first + dx[d];
		int ny = cur.second + dy[d];
		 

		if (nx < 1 || nx > n || ny < 1 || ny > n)
			break;
			
		if (board[nx][ny] == 2)
			break;


		if (board[nx][ny] == 0) { // 사과가 없으면 꼬리 pop;
			auto tail = snake.back();
			board[tail.first][tail.second] = 0;
			snake.pop_back();
		}

		 // 큐에 입력받은 초만큼 지났을 때, 방향 전환
		auto cur_dir = dir.front();
		if (sec == cur_dir.first) {
			if (cur_dir.second == 'L')
				d = (d + 1) % 4;
			else
				d = (d + 3) % 4;
			dir.pop();
		}


		snake.push_front({ nx,ny });
		board[nx][ny] = 2;

	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}


	cin >> l;	
	for (int i = 0; i < l; i++) {
		int x; char c;
		cin >> x >> c;
		dir.push({ x,c });
	}


	snake.push_front({ 1,1 });
	board[1][1] = 2;


	go();


	cout << sec;


	return 0;
}
