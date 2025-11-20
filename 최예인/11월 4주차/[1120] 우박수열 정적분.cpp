#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> seq;
    
    // 수열 구하기
    int num = k;
    seq.push_back(num);
    while(num>1){
        if(num%2==0){
            num = num/2;
        }
        else if(num%2==1){
            num = num * 3 + 1;
        }
        seq.push_back(num);
    }
    
    // 넓이 구하기
    for(int i=0;i<ranges.size();i++){
        int start = ranges[i][0];
        int end = seq.size() + ranges[i][1] -1;
        // cout<<"초항은 : "<<start<<'\n';
        // cout<<"두 번째 항은 : "<<end<<'\n';
        if(start>end){
            answer.push_back(-1);
            continue;
        }
        if(start == end){
            answer.push_back(0);
            continue;
        }
        double sum = 0;
        for(int j=start;j<end;j++){
            double weight = (seq[j] + seq[j+1])/2.0;
            sum = sum + weight;
        }
        answer.push_back(sum);
        
    }
    
    // //수열 디버깅
    // for(auto &it : seq){
    //     cout<<it<<"->";
    // }
    
    return answer;
}