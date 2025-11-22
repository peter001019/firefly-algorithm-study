#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(auto &it : s){
    // find, erase 반복으로 인해 시간초과 발생
//         int count = 0;
//         while(1){
//             int pos = it.find("110");
//             if(pos==string::npos){
//                 break;
//             }
//             it.erase(pos, 3);
//             count++;
            
//         }
        int count = 0;
        string t;
        t.reserve(it.size());
        for(auto c : it){
            t.push_back(c);
            int n=t.size();
            if(n>=3 && t[n-3]=='1' && t[n-2]=='1'&&t[n-1]=='0'){
                t.erase(n-3, 3);
                count++;
            }
        }
        it = t;
        
        // 문자열을 하나로 만들면 사이즈 재할당으로 인해 시간초과 발생
        // string tmp = "";
        // for(int j=0;j<count;j++){
        //     tmp = tmp + "110";
        // }
        
        int flag = 1;
        string ss = "";
        ss.reserve(t.size()+count*3);
        for(int i=it.length()-1;i>=0;i--){
            if(it[i]=='0'){
                ss = ss + it.substr(0, i+1);
                while(count--){
                    ss += "110";
                }
                ss += it.substr(i+1);
                flag = 0;
                break;
            }
        }
        if(flag ==1){
            while(count--){
                ss += "110";
            }
            ss += it;
        }
        answer.push_back(ss);
        //cout<<it<<'\n';
    }
    
    return answer;
}