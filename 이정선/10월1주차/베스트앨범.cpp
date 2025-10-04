#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int> > > list;
    // (장르, [(INDEX, PLAYS 값), ...])
    for(int i = 0; i < genres.size(); i++) {
        list[genres[i]].push_back({plays[i], i});
    }
    
    map<int, string, greater<int>> ordergenre; 
    
    for(const auto&i: list) {
        int sum = 0;
        vector<pair<int, int> > temp = i.second;
        for(const auto&t: temp) {
            sum += t.second;
        }
        ordergenre.insert({sum, i.first});
        
    }
 
    for(const auto&o: ordergenre) {
        string genre = o.second;
        cout << genre << endl;
        auto &v = list[genre];
        
        sort(v.begin(), v.end(),
             [](const pair<int,int> &a, const pair<int,int> &b){
                 if (a.first != b.first) return a.first > b.first; // 재생수 desc
                 return a.second < b.second;                       // 인덱스 asc
             });

        answer.push_back(v[0].second);
        if ((int)v.size() > 1) answer.push_back(v[1].second);
    }
    return answer;
}
