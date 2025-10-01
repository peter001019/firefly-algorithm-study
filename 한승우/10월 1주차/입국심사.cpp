#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

ll solution(int n, vector<int> times) {
    ll answer = 0;
    ll l, r;
    
    sort(times.begin(), times.end());
    
    l = 0; r = (ll)times.back() * (ll)n;
    
    while(l <= r){
        ll mid = (l + r) / 2;
        ll cnt = 0; //특정 시간에서 소화 가능한 사람 수
        
        //소화 가능한 사람 수 세기
        for(ll t: times) {
            cnt += mid / t;
            
            if(cnt >= n) break;
        }
        
        if(cnt >= n) {
            answer = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    return answer;
}