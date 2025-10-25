#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> type;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(const auto& v: clothes) type[v[1]]++;
    for(const auto& kv: type) answer *= kv.second + 1;
    answer--;
    
    return answer;
}