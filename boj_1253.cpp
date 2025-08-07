// https://www.acmicpc.net/problem/1253

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int ans = 0;

  // 투 포인터 알고리즘
	for (int k = 0; k < n; k++) { 
		int find = v[k];
		int i = 0; 
		int j = n - 1;     
		while (i < j) {
			if (v[i] + v[j] == find) {    
				if (i != k && j != k) {    
					ans++;
					break;
				}
				else if (i == k)    
					i++;    // 포인터 값 1 증가
				else if (j == k)
					j--;    // 포인터 값 1 감소
			}
			else if (v[i] + v[j] < find)    
				i++;                         
			else if (v[i] + v[j] > find)    
				j--;                          
		}
	}

	cout << ans;
	return 0;
}
