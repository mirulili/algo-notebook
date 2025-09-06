// https://www.acmicpc.net/problem/14499

#include <iostream>
#include <deque>

using namespace std;

int n, m, x, y, k;
int board[22][22];
int dir[1002];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int upper, bottom;
deque <int> diceX;
deque <int> diceY;

void moveDice(int d) {

	if (d == 1) {
		diceY.push_front(diceY.back());
		diceY.pop_back();
		diceX[1] = diceY[1];
		diceX[3] = diceY[3];
	}
	if (d == 2) {
		diceY.push_back(diceY.front());
		diceY.pop_front();
		diceX[1] = diceY[1];
		diceX[3] = diceY[3];
	}
	if (d == 3) {
		diceX.push_front(diceX.back());
		diceX.pop_back();
		diceY[1] = diceX[1];
		diceY[3] = diceX[3];
		
	}
	if (d == 4) {
		diceX.push_back(diceX.front());
		diceX.pop_front();
		diceY[1] = diceX[1];
		diceY[3] = diceX[3];
	}
	
	//cout << diceX[1] << " " << diceY[1] << "\n";
	bottom = diceX[1];
	upper = diceX[3];

}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < k; i++)
		cin >> dir[i];

	int curX = x;
	int curY = y;

	for (int i = 0; i < 4; i++) 
		diceX.push_back(0);
	for (int i = 0; i < 4; i++)
		diceY.push_back(0);

	for (int tmp = 0; tmp < k; tmp++) {
		int nx = curX + dx[dir[tmp] - 1];
		int ny = curY + dy[dir[tmp] - 1];
		
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		moveDice(dir[tmp]);

		if (board[nx][ny] == 0) {
			board[nx][ny] = bottom;
		}
		else if (board[nx][ny] != 0) { // else를 쓸 것! (앞의 if문에서 보드 칸이 0이 아니게 되어 다음 if문에 또 걸릴 가능성이 있음.)
			diceX[1] = board[nx][ny];
			diceY[1] = board[nx][ny];
			board[nx][ny] = 0;
		}
		curX = nx;
		curY = ny;
		cout << upper << '\n';
	}


	return 0;
}       
