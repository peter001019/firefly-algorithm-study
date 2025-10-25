#include <string>
#include <vector>

using namespace std;

/*
퀸들은 같은 행에 놓을 수 없음
행마다 어느 열에 놓아야 하나?

1. 열마다 놓였는지 = c
2. 오른쪽 위 대각선 = r + c
3. 오른쪽 아래 대각선 = r - c + n - 1
*/

int answer = 0;
int is_used1[30];
int is_used2[30];
int is_used3[30];

void cnt(int r, int n){
    if(r == n){
        answer++;
        return;
    }
    
    for(int c = 0; c < n; c++){
        if(is_used1[c] || is_used2[r + c] || is_used3[r - c + n - 1]) continue;
        
        is_used1[c] = 1; is_used2[r + c] = 1; is_used3[r - c + n - 1] = 1;
        cnt(r + 1, n);   
        is_used1[c] = 0; is_used2[r + c] = 0; is_used3[r - c + n - 1] = 0;
    }
}

int solution(int n) {
    cnt(0, n);
    
    return answer;
}