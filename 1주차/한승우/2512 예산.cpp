#include <bits/stdc++.h>
using namespace std;

int N, M;
int input[10000];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int high = -1;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> input[i];

        high = max(high, input[i]);
    }
    cin >> M;

    int l = 1;
    int r = high;
    int ans = -1;

    while(l <= r){
        int mid = (l + r) / 2;
        int sum = 0;

        for(int i = 0; i < N; i++){
            if(input[i] <= mid) sum += input[i];
            else sum += mid;
        }

        if(sum == M){
            ans = mid;
            break;
        }
        else if(sum < M) {
            if(ans <= sum) ans = max(ans, mid);

            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans;

    return 0;
}