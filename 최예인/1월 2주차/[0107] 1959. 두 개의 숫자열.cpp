#include<iostream>
#include<algorithm>
 
using namespace std;
 
int n, m;
int a[20];
int b[20];
 
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
 
     
    cin >> T;
     
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int j = 0; j < m; j++) {
            cin >> b[j];
        }
        int sum=0;
        int maxN = -2e9;
        if (n < m) {
            for (int i = 0; i <=m-n; i++) {
                int k = i;
                sum = 0;
                for (int j = 0; j < n; j++) {
                    sum = sum + a[j] * b[k];
                    k++;
                    if (k >= m) {
                        break;
                    }
                }
                maxN = max(sum, maxN);
            }
        }
        else {
            for (int i = 0; i <= n-m; i++) {
                int k = i;
                sum = 0;
                for (int j = 0; j < m; j++) {
                    sum = sum + a[k] * b[j];
                    k++;
                    if (k >= n) {
                        break;
                    }
                }
                maxN = max(sum, maxN);
            }
        }
        cout << '#' << test_case << ' ' << maxN << '\n';
 
 
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
