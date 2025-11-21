#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
큐를 이용하여 {반납 시간, 서버 수} 를 저장하고, 매 시각 마다 갱신해줌.

매 시각마다
1. 큐가 있고, 반납 시간이라면 현재 서버 수를 업데이트한다.
2. 필요 서버 수를 구한다. (사람 / m)
3. 서버가 부족하다면, 채우고, 큐에 넣는다.
*/

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int server = 0;
    queue<pair<int, int>> q; //반납 시간, 서버 수
    
    for(int i = 0; i < 24; i++){
        if(!q.empty() && i == q.front().first){
            server -= q.front().second;
            q.pop();
        }
        
        int needs = players[i] / m;
        if(server < needs){
            q.push({i + k, needs - server});
            answer += needs - server;
            server = needs;
        }
    }
    
    return answer;
}