class Solution {
    public int solution(int n, int k) {
        int answer = 0;
 
        String convert = Integer.toString(n,k); //진법 변환 메서드
        String parts[] = convert.split("0");
        
        for(String str: parts){
            if(str.equals("")) continue;
            
            //int형은 21억까지 저장 가능. 진법 변환하면 초과 가능성
            long num = Long.parseLong(str);
            if(isPrime(num)) answer++;    
        }
        return answer;
    }

    
    boolean isPrime(long num) {
        if(num==0 || num==1) return false; 
        
        //제곱근 활용하기
        long sqrt = (long)Math.sqrt(num);
        
        for(long i=2; i<=sqrt; i++){
            if(num%i==0) return false;
        }
        return true; 
    }
}
