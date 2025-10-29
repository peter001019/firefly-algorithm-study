#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// diff(난이도)<=level(숙련도) -> 안틀림 + time_cur사용
// diff > level -> (diff-level 틀린 만큼 * time_prev + time_cur) + time_cur
// limit내  숙련도 최소값

long long countTime(int level, vector<int> diffs, vector<int> times, long long limit){
    long long count = times[0];
    for(int i=1;i<diffs.size();i++){
        if(diffs[i]<=level){
            count +=times[i];
        }
        if(diffs[i]>level){
            count += (diffs[i]-level)*(times[i-1]+times[i])+times[i];
        }
        if(count>limit){
            return count;
        }
    }
    return count;
    
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
   
    // 1. 최대 + 최소 / 2 = level 로 설정
    int right = *max_element(diffs.begin(),diffs.end());
    int left = 1;
    int answer = right;
    
    while(left<=right){
        int mid = (left+right)/2;
        long long count = countTime(mid,diffs,times,limit);
        
        if(count<=limit){
            right = mid-1;
            answer = mid;
            
        }else{
            left = mid+1;
        }
    }
    
    
    return answer;
}