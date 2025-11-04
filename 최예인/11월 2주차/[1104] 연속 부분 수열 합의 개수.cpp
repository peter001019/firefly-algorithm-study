#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    // 한 개일 때 갯수
    set<int> s;
    s.insert(elements.begin(), elements.end());
    
    int right = 0;
    for(int dist = 1;dist<elements.size();dist++){
        for(int left=0;left<elements.size();left++){
            int sum = 0;
            right = (left+dist)%elements.size();
            //cout<<"left: "<<left<<", right: "<<right<<"\n";
            if(left<right){
                for(int i=left;i<=right;i++){
                    sum = sum+elements[i];
                }  
            }else{
                for(int i=left;i<elements.size();i++){
                    sum = sum+elements[i];
                }  
                for(int k=0;k<=right;k++){
                    sum = sum+elements[k];
                }
            }
            //cout<<"sum : "<<sum<<'\n';
            s.insert(sum);
        }
        
    }
    // for(auto &it:s){
    //     cout<<it<<" ";
    // }
    answer = s.size();
    
    return answer;
}
