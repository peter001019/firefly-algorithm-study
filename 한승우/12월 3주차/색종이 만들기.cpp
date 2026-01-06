#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
재귀

정의 : 잘라진 부분이 하얀색인지 파란색인지 판별한다.

base condition -> n이 1이면 색깔을 반환
각 4개가 모두 색이 같다면 해당 색깔 추가
*/

int n;
int mat[150][150];
int ans[2]; //w, b

//길이, 시작점
void sol(int len, int r, int c){
    int is_same = true;
    int tmp = mat[r][c];
    for(int i = r; i < r + len; i++){
        for(int j = c; j < c + len; j++){
            if(tmp != mat[i][j]) is_same = false;
            tmp = mat[i][j];
        }
    }

    if(is_same || len == 1){
        ans[tmp]++;
        return;
    } else {
        int half = len / 2;
        sol(half, r, c);
        sol(half, r, c + half);
        sol(half, r + half, c);
        sol(half, r + half, c + half);
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    sol(n, 0, 0);

    for(int i = 0; i < 2; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}