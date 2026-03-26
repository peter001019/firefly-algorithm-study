#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pii pair<int, int>
#define X first
#define Y second

/*
투입 -> 이동 -> 결과

미생물 구조체 -> {넓이, isDivided}

1. 투입
행렬에 그리고
두 영역으로 나누어진 미생물 확인 후 삭제 -> bfs

2. 이동
넓이가 큰 미생물 순으로 정렬 -> 따로 sort (pair로 묶어서)
우선순위 미생물부터 x,y 좌표로 이동 (이중 for문)
넣을 수 없다면 제거

3. 결과
인접쌍 넓이 곱해서 모두 더함. -> 전체 bfs하면서 쌍을 set에다가 넣는다.
*/

int n, q;
int mat[20][20];
int mat2[20][20];
//x가 행, y가 열
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

bool in_range(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

struct Info{
    int area; //영역 크기
    bool isDivided; //쪼개졌는지
};
unordered_map<int, Info> microbes;

//디버깅용 행렬 출력
void print(){
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
}

int visited[20][20];
//영역 크기를 계산해서 반환
int bfs(int r, int c){
    queue<pii> q;
    int area = 1;
    int num = mat[r][c]; //현재 미생물 번호

    visited[r][c] = 1;
    q.push({r, c});

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!in_range(nx, ny) || visited[nx][ny]) continue;
            if(mat[nx][ny] != num) continue; //같은 미생물만 탐색
            area++;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    return area;
}

void remove(){
    for(int i = 0; i < n; i++) fill(visited[i], visited[i] + n, 0);
    unordered_set<int> remove_num; //삭제되어야 할 미생물 번호

    //삭제 번호 찾기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0 || visited[i][j]) continue;

            int num = mat[i][j]; //미생물 번호
            int area = bfs(i, j);
            //영역 크기 다르면 삭제
            if(area != microbes[num].area){
                remove_num.insert(num);
                microbes[num].isDivided = true;
            }
        }
    }

    //삭제 처리
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0) continue;
            if(remove_num.find(mat[i][j]) != remove_num.end()){
                mat[i][j] = 0;
            }
        }
    }
}

void insert(int r1, int c1, int r2, int c2, int num){
    //삽입
    for(int i = c1; i < c2; i++){
        for(int j = r1; j < r2; j++){
            //삽입하는 곳이 다른 미생물이라면 넓이 감소
            if(mat[i][j] > 0 && mat[i][j] != num){
                microbes[mat[i][j]].area--;
            }
            mat[i][j] = num;
        }
    }

    //나눠진 것 삭제
    remove();
}

bool can_move(int x, int y){
    
}

//현재까지 미생물 번호를 받아 이동 처리
void move(int max_num){
    //영역, 미생물 번호 
    vector<pair<int, int>> microbes_to_move;
    //이동할 미생물 찾기
    for(int i = 1; i <= max_num; i++){
        Info info = microbes[i];
        //분해된 미생물이면 스킵
        if(info.isDivided) continue;
        microbes_to_move.push_back({-info.area, i});
    }
    sort(microbes_to_move.begin(), microbes_to_move.end());

    for(auto* p: microbes_to_move){
        bool is_moved = false;

        //이동 자리 찾기
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //다른 미생물이 이미 있음
                if(mat2[i][j] != 0) continue;
                //자리가 안됨
                if(!can_move(i, j)) continue;

                is_moved = true;
            }
        }
    }
}

void result(){}

int main() {
    cin >> n >> q;

    for(int i = 1; i <= q; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        int area = (c2 - c1) * (r2 - r1);
        microbes[i] = {area, false};
        insert(r1, c1, r2, c2, i);
        move(i);
        result();
    }

    print();

    return 0;
}