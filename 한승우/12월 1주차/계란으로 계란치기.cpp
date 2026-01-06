#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 
무게가 높은 계란을 먼저 쳐버리게 되면, 다른 경우의 수를 고려할 수 없다.

7^8
*/

int n, answer;
int s[10], w[10];
int cnt;

void solve(int idx) {
    if(idx == n){
        answer = max(answer, cnt);
        return;
    }

    if(s[idx] <= 0 || cnt == n - 1){
        solve(idx + 1);
        return;
    }

    for(int i = 0; i < n; i++){
        if(i == idx || s[i] <= 0) continue;

        s[i] -= w[idx];
        s[idx] -= w[i];
        if(s[i] <= 0) cnt++;
        if(s[idx] <= 0) cnt++;
        solve(idx + 1);
        if(s[i] <= 0) cnt--;
        if(s[idx] <= 0) cnt--;
        s[i] += w[idx];
        s[idx] += w[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i] >> w[i];
    }

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve(0);
    cout << answer;
    return 0;
}