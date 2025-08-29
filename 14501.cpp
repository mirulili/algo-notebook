// https://www.acmicpc.net/problem/14501
// algorithm: DP

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[17];
int T[17];
int P[17];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        cin >> T[i] >> P[i];
    }
    for (int i = 1; i <= n; i++){
        if (i + T[i] > n+1) continue;
        dp[i] = P[i];
        // dp[i] = i번째 날 마지막 상담을 시작할 때, 총 상담의 최대 수익
        // i번째 날 이전에 끝나는 상담 중 최대 수익 dp[j]를 구한다. 이때 dp[j]의 값은 이미 저장되어 있다.
        for (int j = 1; j <= i; j++){
            if (j + T[j] <= i){
                dp[i] = max(dp[j] + P[i], dp[i]);
            }
        }
    }
    
    cout << *max_element(dp+1, dp+n+1);

    return 0;
}
