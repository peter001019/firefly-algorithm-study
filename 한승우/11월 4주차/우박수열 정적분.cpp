#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
1. 우박 수열을 구한다. (길이 : 최대 10000개?)
2. 우박 수열 정적분 값을 구한다. (10000 * 10000 = 10^8) -> 누적합
*/

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> seq = {k};
    vector<double> integral = {0}; //누적합 용 0
    
    //1. 우박 수열 구하기
    while(k != 1){
        if(k % 2 == 0) k /= 2;
        else k = k * 3 + 1;
        seq.push_back(k);
    }
    
    //2. 정적분 구하기
    for(int i = 1; i < seq.size(); i++){
        double tmp = (double)(seq[i - 1] + seq[i]) / 2;
        integral.push_back(tmp);
    }
    
    //3. 누적합
    for(int i = 2; i < seq.size(); i++)
        integral[i] += integral[i - 1];
    
    //4. 답 구하기
    int n = seq.size() - 1;
    for(auto& v: ranges){
        v[1] += n;
        
        if(v[0] > v[1]) answer.push_back(-1.0);
        else answer.push_back(integral[v[1]] - integral[v[0]]);
    }
    
    return answer;
}