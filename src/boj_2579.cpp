// https://www.acmicpc.net/problem/2579
// algorithm: DP

#include <iostream>

using namespace std;

int n;
int stairs[303];
int d[303][2];

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for (int i = 1; i <= n; i++){
        cin >> stairs[i];
        
    }
    
    d[1][0] = stairs[1];
    d[1][1] = 0;
    d[2][0] = stairs[2];
    d[2][1] = stairs[1] + stairs[2];
    
    for (int i = 3; i <= n; i++){
        d[i][0] = max(d[i-2][0], d[i-2][1]) + stairs[i];
        d[i][1] = d[i-1][0] + stairs[i];
    }
    
    int ans = max(d[n][0], d[n][1]);
    cout << ans;
    
    
    return 0;
}
