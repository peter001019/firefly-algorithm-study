#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
    
    if(get<0>(a)!=get<0>(b)){
        return get<0>(a)>get<0>(b);
    }
    if(get<1>(a)!=get<1>(b)){
        return get<1>(a)>get<1>(b);
    }
    return get<2>(a)>get<2>(b);
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int score[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
    vector<tuple<int, int, int>> d;
    
    int total = picks[0] + picks[1] + picks[2];
    int limit = min((int)minerals.size(), total * 5);
    
    int start = 0;
    while(start<limit){
        int dia = 0;
        int iron = 0;
        int stone = 0;
        
        for(int i=start;i<start+5;i++){
            if(i>=minerals.size()){
                break;
            }
            if(minerals[i]=="diamond"){
                dia ++;
            }
            if(minerals[i]=="iron"){
                iron ++;
            }
            if(minerals[i]=="stone"){
                stone ++;
            }
        }
        
        d.push_back({dia, iron, stone});
        
        start = start + 5;

    }
    
    sort(d.begin(), d.end(), cmp);
    
    int c = 0;
    for(int i=0;i<picks.size();i++){
        int num = picks[i];
        for(int j=0;j<num;j++){
            if(c>=d.size()){
                return answer;
            }
            int di = score[i][0]*get<0>(d[c]);
            int ir = score[i][1]*get<1>(d[c]);
            int st = score[i][2]*get<2>(d[c]);
            
            answer = answer + di + ir + st;
            c++;
        }
    }
    
    //디버깅
    for(auto & it : d){
        cout<<"첫 번째 : "<<get<0>(it)<<"\n";
        cout<<"두 번째 : "<<get<1>(it)<<"\n";
        cout<<"세 번째 : "<<get<2>(it)<<"\n";
    }
    return answer;
}