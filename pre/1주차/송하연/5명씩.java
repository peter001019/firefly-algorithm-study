class Solution {
    public String[] solution(String[] names) {
        int size = (names.length + 4) / 5;
        String[] answer = new String[size];
        
        int cnt = 0;
        for(int i = 0; i < names.length; i += 5){
            answer[cnt] = names[i];
            cnt++;
        }
        return answer;
    }
}
