#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int> > room;

// 0 -> 북
// 1 -> 동
// 2 -> 남
// 3 -> 서
int movex[] = {-1, 0, 1, 0};
int movey[] = {0, 1, 0, -1};

// 현재 R, C 기준으로 좌우양옆 칸 확인 후 
// 청소안된 곳이 있으면 true, 다 청소되었으면 false
bool checkAround(int currentR, int currentC){
    for(int i = 0; i < 4; i++){
        int newR = currentR + movex[i];
        int newC = currentC + movey[i];
        
        if(newR >= N || newR < 0 || newC >= M || newC < 0) {
            continue;
        }
        
        if(room[newR][newC] == 0){
            return true;
        }
    }
    return false;
}

// 주변 다 청소가 되어있을 경우 (2단계에 해당)
bool backward(int &currentR, int &currentC, int dir){
    
    int newR = currentR + (movex[dir] * -1);
    int newC = currentC + (movey[dir] * -1);

    if(room[newR][newC] == 1) return false;
    else {
        currentR = newR;
        currentC = newC;
        return true;
    }
}

void forward(int &currentR, int &currentC, int &dir){
    for(int i = 0; i < 4; i++){
        dir -= 1;
        if(dir < 0) {
            dir = 3;
        }
        
        int newR = currentR + (movex[dir]);
        int newC = currentC + (movey[dir]);
        
        if(room[newR][newC] == 0) {
            currentR = newR;
            currentC = newC;
            return;
        } else {
            continue;
        }
    }
}

int main() {
    int currentR, currentC, dir;
    int count = 0;
    cin >> N >> M;
    cin >> currentR >> currentC >> dir;

    room.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> room[i][j];
        }
    }

    while(1){
        if(room[currentR][currentC] == 0){
            room[currentR][currentC] = -1;
            count++;
        }
        if(!checkAround(currentR, currentC)){
            if(!backward(currentR, currentC, dir)){
                break;
            } else {
                continue;
            }
        } else {
            forward(currentR, currentC, dir);
        }
    }
    cout << count << endl;
    return 0;
}
