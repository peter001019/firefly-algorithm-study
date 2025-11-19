#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> count;
    
    for(auto &p : players){
         for(auto &c:count){
            c--;
        }
        count.erase(remove(count.begin(), count.end(), 0), count.end());
        
        int z = p/m;
        cout<<"현재 이용자 수는 : "<<p<<"명\n";
        int current = count.size();
        if(current<z){
            cout<<z-current<<"대 만큼 서버 증설됨\n";
            answer = answer + z-current;
            
               for(int i=0;i<z-current;i++){
                   count.push_back(k);
               }
            }
        cout<<"현재 서버 수는 : "<<count.size()<<"대\n";
    
    }
    return answer;
}


// queue를 이용했다면?
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>

// using namespace std;

// int solution(vector<int> players, int m, int k) {
//     int answer = 0;

//     queue<int> counts;
    
//     for(int i=0;i<players.size();i++){
//         int p = players[i];
        
//         while(!counts.empty() && counts.front()==i){
//             counts.pop();
//         }
        
//         int z = p/m;
//         int server = 0;
        
//         int cur_server = counts.size();
        
        
//         if(cur_server<z){
//             for(int j=0;j<z-counts.size();j++){
//                 counts.push(i+k);
//             }
//             answer = answer + (z-cur_server);
//         }
//     }
    
    
//     return answer;
// }