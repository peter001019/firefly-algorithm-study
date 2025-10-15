#include <string>
#include <vector>
#include <set>

using namespace std;

bool check(set<int>& cards1, set<int>& cards2, int n){
    for(int i: cards1){
        auto it = cards2.find(n + 1 - i);
        
        if(it != cards2.end()){
            cards1.erase(i);
            cards2.erase(*it);
            return true;
        }
    }
    
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 1;
    int n = cards.size();
    
    set<int> get; //현재 가진 카드
    set<int> pay; //구매할 수 있는 카드
    
    //초기 카드덱
    for(int i = 0; i < n / 3; i++){
        get.insert(cards[i]);
    }
    
    for(int idx = n / 3; idx < n; idx += 2){
        pay.insert(cards[idx]);
        pay.insert(cards[idx + 1]);
        
        //1. 손에 든 카드에서 선택
        if(check(get, get, n)) answer++;
        //2. 손에 든 카드 1 + 뽑을 카드 1
        else if(coin >= 1 && check(get, pay, n)){
            coin--;
            answer++;
        }
        //3. 뽑을 카드 2
        else if(coin >= 2 && check(pay, pay, n)){
            coin -= 2;
            answer++;
        } 
        else break;
    }
    
    return answer;
}