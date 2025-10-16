#include <string>
#include <vector>

using namespace std;

/*
1. 회전한다.
2. 회전할 때 최솟값을 찾는다.

시간복잡도 : 회전 수 10000 * 회전 400
*/

int matrix[101][101];

//x2는 사각형의 오른쪽 아래
int rotate(int x1, int y1, int x2, int y2){
    int res = 10001;
    int tmp = matrix[x1][y1];
    
    //왼쪽
    for(int i = x1; i < x2; i++) {
        matrix[i][y1] = matrix[i + 1][y1];
        res = min(res, matrix[i][y1]);
    }
    //아래
    for(int i = y1; i < y2; i++) {
        matrix[x2][i] = matrix[x2][i + 1];
        res = min(res, matrix[x2][i]);
    }
    //오른쪽
    for(int i = x2; i > x1; i--) {
        matrix[i][y2] = matrix[i - 1][y2];
        res = min(res, matrix[i][y2]);
    }
    //위
    for(int i = y2; i > y1; i--) {
        matrix[x1][i] = matrix[x1][i - 1];
        res = min(res, matrix[x1][i]);
    }
    
    matrix[x1][y1 + 1] = tmp;
    res = min(res, tmp);
    
    return res;
}

vector<int> solution(int r, int c, vector<vector<int>> queries) {
    vector<int> answer;
    
    //1. 행렬 입력
    int num = 1;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            matrix[i][j] = num++;
    
    for(const auto& v: queries){
        answer.push_back(rotate(v[0], v[1], v[2], v[3]));
    }
    
    return answer;
}