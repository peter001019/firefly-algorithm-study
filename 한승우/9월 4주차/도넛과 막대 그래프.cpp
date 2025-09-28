#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int MAX = 1000001;

//in, out degree
int degree[MAX][2];

// edges_rows는 2차원 배열 edges의 행 길이, edges_cols는 2차원 배열 edges의 열 길이입니다.
int* solution(int** edges, size_t edges_rows, size_t edges_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(4);
    int start = 0, donut = 0, bar = 0, eight = 0;
    
    for(int i = 0; i < edges_rows; i++){
        //out
        degree[edges[i][0]][1]++;
        //in
        degree[edges[i][1]][0]++;
    }
    
    for(int i = 1; i < MAX; i++){
        if(degree[i][0] == 0 && degree[i][1] >= 2) start = i;
        else if(degree[i][0] >= 2 && degree[i][1] == 2) eight++;
        else if(degree[i][0] >= 1 && degree[i][1] == 0) bar++;
    }
    
    donut = degree[start][1] - eight - bar;
    
    answer[0] = start;
    answer[1] = donut;
    answer[2] = bar;
    answer[3] = eight;
    
    return answer;
}