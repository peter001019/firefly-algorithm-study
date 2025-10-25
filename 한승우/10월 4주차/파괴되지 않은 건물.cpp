#include <string>
#include <vector>

using namespace std;

/*
1. 시뮬레이션
10^6 * 25만 => 시간 초과

최종적으로 파괴되지 않은 건물만 구하면 된다.
skill마다 겹쳐서 한번에 적용해보자.

- 겹치는 걸 어떻게 구현할까?
0 -2 -2 0 -> 0 -2 0 2

- 2차원

0 -2 -2 0    0,1 ~ 1,2
0 -2 -2 0
0  0  0 0

0 -2  0  2   0,1과 1 + 1, 2 + 1 = -2 그리고 0,2 + 1과 0, 2 + 1 = 2
0  0  0  0
0  2  0 -2

끝일 때는
0 1 1 1 -> 0 1 0 0

0   0
1   1
1   0
1 ->0 
*/

int diff[1000][1000];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int N = board.size();
    int M = board[0].size();
    
    //변화량 겹치기
    for(const auto& v: skill){
        int type = v[0], r1 = v[1], c1 = v[2], r2 = v[3], c2 = v[4], degree = v[5];
        
        if(type == 1) degree = -degree;
        diff[r1][c1] += degree;
        if(r2 < N - 1 && c2 < M - 1) diff[r2 + 1][c2 + 1] += degree;
        if(c2 < M - 1) diff[r1][c2 + 1] -= degree;
        if(r2 < N - 1) diff[r2 + 1][c1] -= degree;
    }
    
    //누적합
    //1. 열
    for(int i = 0; i < N; i++)
        for(int j = 1; j < M; j++)
            diff[i][j] += diff[i][j - 1];
    //2. 행
    for(int i = 1; i < N; i++)
        for(int j = 0; j < M; j++)
            diff[i][j] += diff[i - 1][j];
    
    //변화량 적용
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            board[i][j] += diff[i][j];
            
            if(board[i][j] > 0) answer++;
        }
    }
    
    return answer;
}