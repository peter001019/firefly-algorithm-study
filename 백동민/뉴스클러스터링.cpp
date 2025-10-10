#include <bits/stdc++.h>

// 어 문자열 문제? 
// 유사도를 구하는데 2개씩 비교 (교집합) / (합집합)
// 집합 A와 집합 B가 모두 공집합일 경우 -> 1

// 확장하니 원소의 중복을 허용하는 다중집합
// (교집합-중복x) / (합집합-중복o)
// 알파벳 + 빈도 수 -> 2차원 <키(a,b), 나오는 빈도> 배열 활용
using namespace std;


int solution(string str1, string str2) {
    int answer = 0;
    
    int ch_map1[26][26];
    int ch_map2[26][26];
    
    fill(&ch_map1[0][0], &ch_map1[0][0]+26 * 26, 0);
    fill(&ch_map2[0][0], &ch_map2[0][0]+26 * 26, 0);
    //알바벳 first, second 에 저장되는 cnt -> 0으로 초기화
    
    for(int i = 0; i < str1.size()-1; i++){
        char a = tolower(str1[i]);
        char b = tolower(str1[i+1]);
        if (isalpha(a) && isalpha(b)) {
            ch_map1[a - 'a'][b - 'a']++;
        }
    }
    for(int i = 0; i < str2.size()-1; i++){
        char a = tolower(str2[i]);
        char b = tolower(str2[i+1]);
        if (isalpha(a) && isalpha(b)) {
            ch_map2[a - 'a'][b - 'a']++;
        }
    }
    
    
    
    int interCnt = 0; //교집합
    int unionCnt = 0; //합집합
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            interCnt += min(ch_map1[i][j], ch_map2[i][j]); 
            //설명에서 다중집합 확장한 방법
            unionCnt += max(ch_map1[i][j], ch_map2[i][j]);
        }
    }
    
    if (unionCnt == 0) return 65536; //공집합이면 유사도 1
    
    //자카드 유사도 계산
    answer = floor( (interCnt*1.0 / unionCnt) * 65536);//소수점 버림
    
    return answer;
}