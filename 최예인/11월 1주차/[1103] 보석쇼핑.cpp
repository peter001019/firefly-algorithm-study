#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string, int> count;
    
    set<string> s(gems.begin(), gems.end());
    
    int total_count = s.size();
    int distinct = 0;
    int left = 0;
    int min = 100000;
    int start = 0;
    int end = 0;
    
    for(int right = 0;right<gems.size();right++){
        count[gems[right]]++;
        if(count[gems[right]]==1){
            distinct ++;
        }
        while(distinct==total_count){
            if(right-left<min){
                min = right-left;
                start = left;
                end = right;
            }
            count[gems[left]]--;
             if(count[gems[left]]==0){
                distinct --;
            }
            left++;
        }       
        
    }
    answer[0] = start+1;
    answer[1] = end+1;
    
    
    return answer;
}
