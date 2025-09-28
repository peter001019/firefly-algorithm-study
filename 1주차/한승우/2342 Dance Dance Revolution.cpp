#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int dp[100001][5][5];

int calCost(int cur, int next){
    if(cur == next) return 1;
    if(cur == 0) return 2;
    if(abs(cur - next) == 2) return 4;
    return 3;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int next = 0;
    int step = 0;

    //초기화
    memset(dp, 0x3f, sizeof(dp));

    dp[0][0][0] = 0;

    while(true){
        cin >> next;

        if(next == 0) break;

        step++;

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                int l = calCost(i, next);
                int r = calCost(j, next);

                //이전 위치가 아닌 경우
                if(dp[step - 1][i][j] >= INF) continue;

                //i -> next
                dp[step][next][j] = min(dp[step][next][j], dp[step - 1][i][j] + l);
                //j -> next
                dp[step][i][next] = min(dp[step][i][next], dp[step - 1][i][j] + r);
            }
        }
    }

    int ans = INF;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            ans = min(ans, dp[step][i][j]);
        }
    }

    cout << ans;
    
    return 0;
}