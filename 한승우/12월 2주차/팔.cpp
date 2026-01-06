#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
8이 가장 적게 들어있는 수?

1. 그냥 탐색 -> 2 * 10 ^ 9 (시간 초과)
2. 그리디

- 8을 포함시켜야 하는 경우는, 자리수가 동일할때 각 자리수가 둘다 8일 떄만. 88 888
- 둘다 8이 아니라면 무조건 제외됨. 자리수가 다르다면 무조건 0으로 제외됨.
- 자리수의 앞에서부터 8이 같은 경우에만 무조건 포함됨 -> 8888 9988 1888 1889
*/

void solve() {
    string l, r; 
    cin >> l >> r;

    int ans = 0;
    if(l.size() == r.size()){
        for(int i = 0; i < l.size(); i++){
            if(l[i] != r[i]) break;
            if(l[i] == '8') ans++;
        }
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