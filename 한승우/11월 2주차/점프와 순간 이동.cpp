#include <iostream>
using namespace std;

/*
순간이동(위치*2) or k만큼 이동

거리 10억

그냥 거꾸로 가면 최소 아닌가...
*/

int solution(int n)
{
    int ans = 0;
    
    while(n > 0){
        if(n % 2 == 0) n /= 2;
        else {
            ans++;
            n--;
        }
    }

    return ans;
}
