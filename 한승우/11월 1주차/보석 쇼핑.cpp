#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> cnt;
    unordered_set<string> type(gems.begin(), gems.end());
    
    int r;
    for(r = 0; r < gems.size(); r++){
        cnt[gems[r]]++;
        if(cnt.size() == type.size()) break;
    }
    int min_len = r;
    answer = {1, r + 1};
    
    for(int l = 0; l < gems.size(); l++){
        while(r < gems.size() - 1 && cnt.size() != type.size()){
            r++;
            cnt[gems[r]]++;
        }
        
        if(cnt.size() == type.size()){
            if(r - l < min_len) {
                min_len = r - l;
                answer = {l + 1, r + 1};  
            }
        }
        
        cnt[gems[l]]--;
        if(cnt[gems[l]] == 0) cnt.erase(gems[l]);
    }
    
    return answer;
}