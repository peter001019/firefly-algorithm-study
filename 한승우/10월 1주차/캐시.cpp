#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> li;
    
    for(string c: cities){
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        
        if(cacheSize == 0){
            answer += 5;
            continue;
        }
        
        auto it = find(li.begin(), li.end(), c);
        
        //cache hit
        if(it != li.end()){
            //해당 원소 최신화
            li.erase(it);
            li.push_front(c);
            answer += 1;
        } 
        //cache miss
        else {
            if(li.size() < cacheSize) li.push_front(c);
            else {
                li.pop_back();
                li.push_front(c);
            }
            
            answer += 5;
        }
    }
    
    return answer;
}