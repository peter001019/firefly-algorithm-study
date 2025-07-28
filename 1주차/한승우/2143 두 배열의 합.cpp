#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int A[1000];
int B[1000];
int n, m;
vector<int> A_sum;
vector<int> B_sum;

void cul_sum(){
    for(int i = 0; i < n; i++){
        int tmp = A[i];
        A_sum.push_back(tmp);
        for(int j = i + 1; j < n; j++){
            tmp += A[j];
            A_sum.push_back(tmp);
        }
    }
    
    for(int i = 0; i < m; i++){
        int tmp = B[i];
        B_sum.push_back(tmp);
        for(int j = i + 1; j < m; j++){
            tmp += B[j];
            B_sum.push_back(tmp);
        }
    }
}

void sol(){
    ll ans = 0;

    cul_sum();
    
    sort(A_sum.begin(), A_sum.end());
    sort(B_sum.begin(), B_sum.end());

    int a = 0;
    int b = B_sum.size() - 1;

    while(a < A_sum.size() && b >= 0){
        int sum = A_sum[a] + B_sum[b];

        if(sum > T) b--;
        else if(sum < T) a++;
        else{
            ll cntA = 0, cntB = 0;
            int tmpA = A_sum[a], tmpB = B_sum[b];

            while(a < A_sum.size() && A_sum[a] == tmpA){
                a++; cntA++;
            }
            while(b >= 0 && B_sum[b] == tmpB){
                b--; cntB++;
            }

            ans += cntA * cntB;
        }
    }
    
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> T;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> B[i];

    sol();

    return 0;
}