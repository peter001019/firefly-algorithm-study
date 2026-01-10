#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
앞뒤에서 과일을 두 종류 이하로 만드는데, 과일을 최대한 적게 줄여야 함.

앞뒤에서 뺀다는 특수성이 있음.

슬라이딩 윈도우
*/

int n;
int s[200002];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];

    int ans = 0;
    int type = 0; //window의 종류 갯수
    vector<int> cnt(10); //과일 종류별 갯수

    int r = -1;
    for(int l = 0; l < n; l++){
        while(r < n && type <= 2){
            r++;
            if(cnt[s[r]] == 0) type++; //없던 과일이라면 종류 추가
            cnt[s[r]]++;
        }
        
        ans = max(ans, r - l);
        if(r == n) break; 
        
        cnt[s[l]]--;
        if(cnt[s[l]] == 0) type--;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}