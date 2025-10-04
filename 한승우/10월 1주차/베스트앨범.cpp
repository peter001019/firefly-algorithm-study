#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;
typedef pair<string, int> si;

//장르 -> 재생 횟수
unordered_map<string, int> play_per_genre;
//장르 -> {재생 횟수, 고유 번호}
unordered_map<string, vector<pair<int, int>>> musics;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    //초기화
    for(int i = 0; i < genres.size(); i++){
        play_per_genre[genres[i]] += plays[i];
        musics[genres[i]].push_back({plays[i], i});
    }
    
    //정렬
    vector<pair<string, int>> v(play_per_genre.begin(), play_per_genre.end());
    sort(v.begin(), v.end(), [](si a, si b){
        return a.second > b.second;
    });
    
    for(auto& kv: musics){
        vector<pair<int, int>>& v = kv.second;
        sort(v.begin(), v.end(), [](ii a, ii b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
    }
    
    //저장
    for(si p: v){
        string genre = p.first;
        
        //음악 두 곡 삽입
        int cnt = 2;
        for(int i = 0; i < musics[genre].size() && cnt > 0; i++){
            answer.push_back(musics[genre][i].second);
            cnt--;
        }
    }
    
    return answer;
}