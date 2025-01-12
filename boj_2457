// https://www.acmicpc.net/problem/2457
// 백준 2457번 공주님의 정원
// 언어: C++
// https://github.com/hjmiru

#include <iostream>
#include <algorithm>

using namespace std;

pair <pair<int,int>,pair<int,int>> p[100000]; // 꽃이 피어있는 날짜 배열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> p[i].first.first >> p[i].first.second;
        cin >> p[i].second.first >> p[i].second.second;
    }
    
    sort(p, p+n); // 정렬하기 위한 시간복잡도 O(NlogN)

    pair <int,int> s = {3,1};
    pair <int,int> f = {11,30};
    
    int ans = 0;
    
    pair<int, int> current_date = s; // 현재 날짜
    int idx = 0; // 꽃 배열의 인덱스
    
    while (current_date <= f) {
        pair<int, int> next_date = current_date;
        // 현재 날짜에 피어있는 꽃들 중 가장 늦게 지는 꽃 찾기
        while (idx < n && p[idx].first <= current_date) {
            next_date = max(next_date, p[idx].second);
            idx++;
            // idx가 증가하기 때문에 n개의 꽃 배열을 한번 순회한다. 따라서 시간복잡도는 O(N)
        }
    
        if (next_date == current_date) { 
            // 더 이상 꽃이 필 수 없는 경우
            ans = 0;
            break;
        }
    
        current_date = next_date; // 날짜 갱신
        ans++; // 사용한 꽃 수 증가
    }

    if (current_date <= f) ans = 0; // 11월 30일까지 꽃이 피어있지 못한 경우
    // 현재 날짜가 11월 30일이면, 꽃은 29일까지 피어있으므로 (현재 날짜 <= 11월 30일)일 때 0을 리턴하게 됨
    
    cout << ans;
    
    return 0;
}
