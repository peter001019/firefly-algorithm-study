#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//할인율 조합
vector<int> rates;

int max_plus;
int max_sale;

void cal(vector<vector<int>>& users, vector<int>& emojis){
    int plus = 0;
    int sale = 0;
    
    for(auto& u: users){
        int sum = 0;
        
        for(int i = 0; i < emojis.size(); i++){
            //특정 비율 이상이면 구매
            if(u[0] <= rates[i]){
                sum += emojis[i] * (100 - rates[i]) / 100;
            }
        }
        
        //특정 금액 이상이면 플러스 가입
        if(sum >= u[1]){
            plus++;
        } else { //아니면 판매액
            sale += sum;
        }
    }
    
    if(max_plus < plus){
        max_plus = plus;
        max_sale = sale;
    } else if(max_plus == plus){ 
        max_sale = max(max_sale, sale);
    }
}

void perm(int start, vector<vector<int>>& users, vector<int>& emojis){
    if(rates.size() == emojis.size()){
        cal(users, emojis);
        return;
    }
    
    //40 30 20 10 순
    for(int i = 40; i >= 10; i -= 10){
        rates.push_back(i);
        perm(i, users, emojis);
        rates.pop_back();
    }
}

vector<int> solution(vector<vector<int>> u, vector<int> e) {
    vector<int> answer;
    
    sort(e.begin(), e.end());
    
    perm(40, u, e);
    
    answer.push_back(max_plus);
    answer.push_back(max_sale);
    
    return answer;
}