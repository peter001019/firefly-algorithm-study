#include <string>
#include <vector>
#include <algorithm> // max 사용

using namespace std;

// a[i] = max(a[i].left,a[i].right) : 1. 점화식 세우기 
// 누적 합 계열 : 이차원 배열, dist[][] //누적으로 각 열마다 혹은 행마다 되어야함!
// 1
// 2 3
// 4 5 6
// 7 8 9 10

// 이미 배열이 할당 되어 있잖아 -> 기존 꺼 쓰면 돼
 
int solution(vector<vector<int>> triangle) {
    int answer = 0; // 최대값 저장해야함
    int height = triangle.size();

    for (int i = 1; i < height; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                // 맨 왼쪽, 위에서 바로 
                triangle[i][j] += triangle[i - 1][j];
            } 
            else if (j == triangle[i].size() - 1) 
            {
                // 맨 오른쪽, 위에서 오른쪽 대각선
                triangle[i][j] += triangle[i - 1][j - 1];
            } 
            else {
                // 중간, 2개 중 큰 거
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
    }

    // 마지막에서 최댓값 
    for (int i = 0; i < triangle[height - 1].size(); i++) {
        answer = max(answer, triangle[height - 1][i]);
    }

    return answer;
}