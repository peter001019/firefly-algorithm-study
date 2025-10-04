#include <bits/stdc++.h>

#define HIT 1
#define MISS 5

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    // 최근 사용 앞, 오래된 거 뒤
    list<string> cache; //더블 링크드 리스트
    unordered_map<string, list<string>::iterator> idx; //도시랑, 캐쉬위치
    
    auto city = cities.begin();
    
    if (cacheSize == 0) {
        return cities.size() * MISS;
    }
    
    while(city != cities.end()){
        
        // 대소문자 구분 X
        for (char &c : *city) {
            c = (char)tolower(c);
        }
        
        auto it = idx.find(*city);
        
        if (it != idx.end()) {
            // hit시 기존 위치 제거 후 맨 앞에 재삽입
            cache.erase(it->second);// idx에 저장된 list 위치를 지우기
            cache.push_front(*city);
            idx[*city] = cache.begin();
            answer += HIT;
        } 
        else {
            // miss 시, 맨 뒤 제거
            if (cache.size() == cacheSize) {
                string last = cache.back();
                cache.pop_back();
                idx.erase(last);
            }
            cache.push_front(*city);
            idx[*city] = cache.begin();
            answer += MISS;
        }
        city++;
    }
    
    return answer;
}