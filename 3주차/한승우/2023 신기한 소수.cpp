#include <bits/stdc++.h>
using namespace std;

int N;

bool isPrime(int num){
    if(num < 2) return false;

    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) return false;
    }

    return true;
}

void dfs(int ans, int cnt){
    if(!isPrime(ans)) return;

    if(cnt == N){
        cout << ans << "\n";

        return;
    }

    for(int i = 1; i <= 9; i++){
        dfs(ans * 10 + i, cnt + 1);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);

    return 0;
}

/*
1 ~ 10^N 으로 나누며 소수인지 검사
소수를 N자리까지 구한다. -> true인지 아닌지로

backtracking으로 visited 검사

10 ^ 8
*/