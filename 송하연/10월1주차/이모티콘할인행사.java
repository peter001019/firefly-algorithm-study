import java.util.*;

class Solution {
    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = new int[2];
        
        //이모티콘 할인 조합
        int[] emoticonSale = new int[emoticons.length];
        int[] sales = {10,20,30,40};
        dfs(sales,0,emoticons,emoticonSale,users,answer);
        return answer;

    }
    
    
    //할인율 조합 만들기 -> (10,10) (10,20) (10,30) (10,40) (20,10) (20,20) (20,30) (20,40)....
    void dfs(int[] sales, int emoticonIdx, int[] emoticons, int[] emoticonSale, int[][] users, int[] answer){
    
        if(emoticonIdx==emoticons.length){
            int[] result = simulate(emoticons, emoticonSale, users, answer);
            //System.out.println(Arrays.toString(result));
            return;
        }
        for(int sale: sales){
             emoticonSale[emoticonIdx] = sale;
             dfs(sales, emoticonIdx+1, emoticons, emoticonSale, users, answer);
         }
    }
    
    
    //할인율에 따른 결과
    int[] simulate(int[] emoticons, int[] emoticonSale, int[][] users, int[] answer){
        
        int totalPrice=0;
        int totalCnt=0;
        
        //유저별 구매 결과
        for(int[] user:users){
            int price=0;
            for(int i=0; i<emoticons.length; i++){
                price += calculatePrice(emoticonSale[i], user[0], emoticons[i]);
            }
            if(price>=user[1]){
                totalCnt++;
            }
            else totalPrice+= price;
        }
        
        //결과 업데이트 판별
        if (totalCnt>answer[0]) {
            answer[0] = totalCnt;
            answer[1] = totalPrice;  
        }
        if (totalCnt==answer[0] && totalPrice>answer[1]) {
             answer[1] = totalPrice;  
        }
            
        return answer;
    }

    int calculatePrice(int emoticonSale, int userSale, int emoticon){
        if(emoticonSale<userSale)return 0;
        else return (emoticon*(100-emoticonSale))/100;
    }
}
