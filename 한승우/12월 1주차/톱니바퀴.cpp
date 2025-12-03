#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
1. 회전시킬 방향을 정한다.
2. 회전시킨다.
3. 점수를 계산한다.
*/

string saw[5];

void rotate(int num, int dir){
    char tmp;

    if(dir == 0) return;
    else if(dir == 1){
        tmp = saw[num][7];

        for(int i = 7; i >= 1; i--)
            saw[num][i] = saw[num][i - 1];

        saw[num][0] = tmp;
    } 
    else{
        tmp = saw[num][0];

        for(int i = 0; i < 7; i++)
            saw[num][i] = saw[num][i + 1];
        
        saw[num][7] = tmp;
    }
}

void solve() {
    int num, dir;
    cin >> num >> dir;

    vector<int> dirs(5, 0);
    //회전시킬 방향 정하기
    dirs[num] = dir;

    //1. 오른쪽
    for(int i = num + 1; i <= 4; i++){
        if(saw[i - 1][2] == saw[i][6]) break;

        dirs[i] = -dirs[i - 1];
    }

    //2. 왼쪽
    for(int i = num - 1; i >= 1; i--){
        if(saw[i + 1][6] == saw[i][2]) break;

        dirs[i] = -dirs[i + 1];
    }
    
    for(int i = 1; i <= 4; i++)
        rotate(i, dirs[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 1; i <= 4; i++)
        cin >> saw[i];

    int Tc;
    cin >> Tc;
    while (Tc--) solve();

    int answer = 0;
    for(int i = 1; i <= 4; i++)
        answer += (saw[i][0] - '0') * pow(2, i - 1);
    cout << answer << '\n';

    // for(int i = 1; i <= 4; i++)
    //     cout << saw[i] << '\n';

    return 0;
}