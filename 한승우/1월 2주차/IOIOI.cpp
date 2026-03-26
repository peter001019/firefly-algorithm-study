#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
string s;

void solve() {
    cin >> n >> m;
    cin >> s;

    int ans = 0;
    int cnt = 0; //연속된 IOI의 개수
    int i = 1;

    while(i < m - 1){
        //연속된 IOI의 개수 찾기
        while(i < m - 1 && s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I'){
            cnt++;
            i += 2;

            if(cnt == n) {
                ans++;
                cnt = 0;
            }
        }

        i++;
        cnt = 0;
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