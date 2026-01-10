#include<iostream>

using namespace std;

/*
n과 b가 주어지고, 원소들의 합으로 b보다 크면서 최소인 탑의 높이는?

20명 -> 2^20 
*/

int n, b;
int h[25];
int ans = 1e9;

void sol(int sum, int idx){
    if(idx == n){
        if(sum >= b) ans = min(ans, sum - b);
        return;
    }

    sol(sum, idx + 1); //skip
    sol(sum + h[idx], idx + 1); //포함
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n >> b;
        for(int i = 0; i < n; i++) cin >> h[i];
        
        sol(0, 0);
        
        cout << '#' << test_case << ' ' << ans << '\n';

        ans = 1e9;
	}
	return 0;
}