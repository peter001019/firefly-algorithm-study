#include <string>
#include <vector>

using namespace std;

typedef long long ll;

/*
diff > level
-> (diff - level) * (time_cur + time_prev) + time_cur //틀리고, 맞고
*/

ll cal(ll level, const vector<int>& diffs, const vector<int>& times){
    ll time = times[0];
    
    for(int i = 1; i < diffs.size(); i++){
        int time_prev = times[i - 1];
        int time_cur = times[i];
        
        if(diffs[i] <= level)
            time += time_cur;
        else 
            time += (diffs[i] - level) * (time_cur + time_prev) + time_cur;
    }
    
    return time;
}

int solution(vector<int> diffs, vector<int> times, ll limit) {
    ll st = 1, end = 1e15;
    
    while(st < end){
        ll mid = (st + end) / 2;
        
        if(cal(mid, diffs, times) <= limit) end = mid;
        else st = mid + 1;
    }
    
    return st;
}s