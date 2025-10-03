#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int calculatePrice(int emoticonSale, int userSale, int emoticon){
    if(emoticonSale<userSale)return 0;
    else return (emoticon*(100-emoticonSale))/100;
}

vector<int> simulate(vector<int> &emoticons, vector<int> &emoticonSale, vector<vector<int>> &users, vector<int> &answer){
        
    int totalPrice=0;
    int totalCnt=0;
        
    for(vector<int> user:users){
        int price=0;
        for(int i=0; i<emoticons.size(); i++){
            price += calculatePrice(emoticonSale[i], user[0], emoticons[i]);
        }
        if(price>=user[1]){
            totalCnt++;
        }
        else totalPrice+= price;
    }
    
    if (totalCnt>answer[0]) {
        answer[0] = totalCnt;
        answer[1] = totalPrice;  
    }
    if (totalCnt==answer[0] && totalPrice>answer[1]) {
        answer[1] = totalPrice;  
    }
        
    return answer;
}


void dfs(vector<int> &sales, int emoticonIdx, vector<int> &emoticons, vector<int> &emoticonSale, vector<vector<int>> &users, vector<int> &answer){
    
    if(emoticonIdx==emoticons.size()){
        vector<int> result = simulate(emoticons, emoticonSale, users, answer);
        return;
    }
    for(int i = 0; i < sales.size(); i++){
        emoticonSale[emoticonIdx] = sales[i];
        dfs(sales, emoticonIdx + 1, emoticons, emoticonSale, users, answer);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2, 0); 

    vector<int> emoticonSale(emoticons.size());
    vector<int> sales = {10,20,30,40};
    dfs(sales,0,emoticons,emoticonSale,users,answer);

    return answer;
}
