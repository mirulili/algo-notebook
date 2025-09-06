// https://www.acmicpc.net/problem/14891

#include <iostream>
#include <deque>

using namespace std;

deque <int> w[4];

bool rot[4];
bool rotDir[4];


void leftChk(int idx, int dir) { // idx번째 바퀴의 왼쪽 바퀴 확인하는 재귀함수
	if (idx == 0)  // base
		return;
	if (w[idx][6] != w[idx - 1][2]) {
		rot[idx - 1] = true;
		rotDir[idx - 1] = 1 - dir;
		leftChk(idx - 1, 1 - dir);
	}
	else
		return;
}


void rightChk(int idx, int dir) { // idx번째 바퀴의 오른쪽 바퀴 확인하는 재귀함수
	if (idx == 3)  // base
		return;
	if (w[idx][2] != w[idx + 1][6]) {
		rot[idx + 1] = true;
		rotDir[idx + 1] = 1 - dir;
		rightChk(idx + 1, 1 - dir);
	}
	else
		return;
}

void doRot(int idx, int dir) { // 톱니바퀴 회전
	if (dir == 1) {
		w[idx].push_front(w[idx].back());
		w[idx].pop_back();
	}
	else {
		w[idx].push_back(w[idx].front());
		w[idx].pop_front();
	}
}

void initRot() { // 배열 초기화
	fill(rot, rot + 4, false);
}
void initRotDir() { // 배열 초기화
	fill(rotDir, rotDir + 4, false);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			w[i].push_back(c-'0');
		}
	}

	int k, idx, dir;
	cin >> k;
	for(int i = 0; i < k; i++) {
		cin >> idx >> dir;
		idx--;
		if (dir == -1)
			dir = 0;
		rot[idx] = true;
		rotDir[idx] = dir;
		leftChk(idx, dir);
		rightChk(idx, dir);
		for (int i = 0; i < 4; i++)
			if (rot[i] == true)
				doRot(i, rotDir[i]);

		initRot();
		initRotDir();

	}

	int ans = 0;
	ans += (w[0].front() + w[1].front() * 2 
		+ w[2].front() * 4 + w[3].front() * 8);
	cout << ans;

	return 0;
}       
