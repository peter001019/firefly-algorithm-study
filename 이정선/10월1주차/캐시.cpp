#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    for(int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    }
    
    if(cacheSize == 0) {
        answer = cities.size() * 5;
        return answer;
    }
    
    for(const auto&city: cities) {
        auto it = find(cache.begin(), cache.end(), city);
        if(it != cache.end()) {
            answer += 1;
            cache.erase(it);
            cache.push_back(city);
        } else {
            answer += 5;
            if(cache.size() == cacheSize) {
                cache.erase(cache.begin());
                
            } 
            cache.push_back(city);
        }
    }

    return answer;
}
