#include <string>
#include <cctype>
#include <bits/stdc++.h>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    vector<string> str1V;
    vector<string> str2V;

    for(int i = 0; i < str1.length() - 1; i++){
        if (isalpha(str1[i]) && isalpha(str1[i+1])) {  // 알파벳인 경우만
            string s; 
            s.push_back(tolower(str1[i])); 
            s.push_back(tolower(str1[i+1]));
            str1V.push_back(s);
        }
    }
    for(int i = 0; i < str2.length() - 1; i++){
        if (isalpha(str2[i]) && isalpha(str2[i+1])) {  // 알파벳인 경우만
            string s; 
            s.push_back(tolower(str2[i])); 
            s.push_back(tolower(str2[i+1]));
            str2V.push_back(s);
        }
    }
    
    // 둘 다 공집합인 경우 
    if(str1V.size() == 0 && str2V.size() == 0) {
        return 65536;
    }
    
    sort(str1V.begin(), str1V.end());
    sort(str2V.begin(), str2V.end());

    int i = 0;
    int j = 0;
    double countset1 = 0; // 교집합 세기
    double countset2 = 0; // 합집합 세기
    
    while(i < str1V.size() && j < str2V.size()) {
        if(str1V[i] == str2V[j]) { 
            // 같은 원소 찾으면 교집합, 합집합 둘다 +
            j++;
            i++;
            countset1++;
            countset2++;
        } else if(str1V[i] > str2V[j]) { 
            // str1V[i]이 더 크다면, 합집합만 늘려주고, str2V 인덱스 추가 
            j++;
            countset2++;
        } else {
            // str2V[j]이 더 크다면 합집합만 늘려주고, str1V 인덱스 추가
            i++;
            countset2++;
        }

        // 한 쪽을 전부 순회 완료했을 때 나머지 한쪽의 원소를 모두 합집합으로 세어주고, 반복문 종료
        if(i == str1V.size() && j < str2V.size()) {
            countset2 += str2V.size() - j;
            break;
        }
        if(i < str1V.size() && j == str2V.size()) {
            countset2 += str1V.size() - i;
            break;
        }
    }
    
    if(countset1 == 0) {
        return 0;
    }
  
    answer = (countset1  / countset2) * 65536;

    return answer;
}
