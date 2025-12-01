#include <bits/stdc++.h>
using namespace std;

int N, M;

// 1: 윗 면
// 2: 왼쪽 면
// 3: 오른쪽 면
// 4: 아랫 면
// 5: 앞 면
// 6: 뒷 면

void move(vector<int> &cube, vector<vector<int> > &map, int dir, int &x, int &y){
    vector<int> copyCube = cube;
    if(dir == 1){
        if(y >= M - 1){
            return;
        } else {
            
            copyCube[3] = cube[1];
            copyCube[4] = cube[3];
            copyCube[2] = cube[4];
            copyCube[1] = cube[2];

            if(map[x][y + 1] == 0){
                map[x][y + 1] = copyCube[4];
            } else {
                copyCube[4] = map[x][y + 1];
                map[x][y + 1] = 0;
            }
            y = y+1;
            cube = copyCube;
        }
    }
    else if(dir == 2){
        if(y <= 0){
            return;
        } else {
            copyCube[2] = cube[1];
            copyCube[4] = cube[2];
            copyCube[3] = cube[4];
            copyCube[1] = cube[3];

            if(map[x][y - 1] == 0){
                map[x][y - 1] = copyCube[4];
            } else {
                copyCube[4] = map[x][y - 1];
                map[x][y - 1] = 0;
            }
            y = y-1;
            cube = copyCube;
        }
    } 
    else if(dir == 3){
        if(x <= 0){
            return;
        } else {
            copyCube[5] = cube[1];
            copyCube[4] = cube[5];
            copyCube[6] = cube[4];
            copyCube[1] = cube[6];

            if(map[x - 1][y] == 0){
                map[x - 1][y] = copyCube[4];
            } else {
                copyCube[4] = map[x - 1][y];
                map[x - 1][y] = 0;
            }
            x = x-1;
            cube = copyCube;
        }
    } 
    else if(dir == 4){
        if(x >= N - 1){
            return;
        } else {
            copyCube[6] = cube[1];
            copyCube[4] = cube[6];
            copyCube[5] = cube[4];
            copyCube[1] = cube[5];

            if(map[x + 1][y] == 0){
                map[x + 1][y] = copyCube[4];
            } else {
                copyCube[4] = map[x + 1][y];
                map[x + 1][y] = 0;
            }
            x = x+1;
            cube = copyCube;
        }
    }
    cout << cube[1] << endl;
}

int main() {
    int x, y, K;
    cin >> N >> M >> x >> y >> K;

    // 주사위 0으로 초기화
    vector<int> cube(7, 0);
    
    vector<vector<int> > map(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < K; i++){
        int t;
        cin >> t;
        move(cube, map, t, x, y);
    }
    
    return 0;
}
