#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;

    // 1. 알파벳 바꾸는 최소 움직임 횟수 구하기
    for(const auto&c: name) {
        answer += min((int)c - 'A', 26 - ((int)c - 'A'));
    }

    // 2. 좌우로 커서를 바꾸는 최소 횟수 구하기
    int minMove = name.length() - 1; // 한 방향으로 움직인다고 가정할 때 n-1만큼은 움직여야 함
    for(int i = 0; i < name.length(); i++) {
        int next = i + 1;
        while(next < name.length() && name[next] == 'A') next++;
        minMove = min(minMove, 2 * i + (int)name.length() - next ); 
        // 오른쪽으로 i만큼 갔다가 다시 백
        minMove = min(minMove, i + 2 * ((int)name.length() - next )); 
        // 왼쪽으로 A가 나오기 전(name.length() - next)만큼 갔다가 다시 백 후, i만큼 더 가기
    }
    answer += minMove;
    return answer;
}
