#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    
    // 2개 시간초과 발생! -> 100만 x 100만 => 1억 O(N^2)
    // for(int i=0;i<numbers.size();i++){
    //     int num = numbers[i];
    //     int plag = 0;
    //     for(int j=i+1;j<numbers.size();j++){
    //         if(num<numbers[j]){
    //             answer.push_back(numbers[j]);
    //             plag = 1;
    //             break;
    //         }
    //     }
    //     if(plag==0){
    //         answer.push_back(-1);
    //     }
    // }
    
    // stack 구조 이용하기
    vector<int> answer(numbers.size(), -1);
    stack<int> s;
    
    for(int i=0;i<numbers.size();i++){
        while(!s.empty()&&numbers[i]>numbers[s.top()]){
            answer[s.top()] = numbers[i];
            s.pop();
        }
        s.push(i);
    }
       
    
    return answer;
}
