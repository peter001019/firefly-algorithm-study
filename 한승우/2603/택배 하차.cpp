#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

/*
택배 별로 k -> h, w를 따로 저장

1. 택배 투입
2. 하차 (왼쪽, 오른쪽)
    - 하차 후보군을 찾음 (열 단위로 검사, 박스의 h만큼 탐색하며 뺼 수 있는지)
    - 하차 후보군 중 제일 작은 번호를 제외시킴 (set에 넣어놓고 제일 작은 원소 찾기)
    - 택배가 떨어짐 (행별로 검사하며, 박스의 w 만큼 탐색하며 떨어질 수 있는지)
*/

int n, m, max_box_num;
int mat[55][55];

//박스의 높이, 너비, 가장 왼쪽 위 좌표
struct Info{
    int h, w, r, c;
    bool is_load;
};
unordered_map<int, Info> box;

//박스 번호, 탐색 시작할 열 위치
bool check_down(int num){
    Info b = box[num];

    if(b.r + b.h - 1 == n) return false; //맨 아래에 위치하면 종료

    for(int i = b.c; i < b.c + b.w; i++){
        if(mat[b.r + b.h][i] != 0) return false;
    }
    return true;
}

//떨어질 수 있을 때까지 떨어트림
void fall(int num){
    for(int i = box[num].r; i < box[num].r + box[num].h; i++){
        for(int j = box[num].c; j < box[num].c + box[num].w; j++){
            mat[i][j] = 0;
        }
    }

    while(1){
        if(!check_down(num)) break;
        box[num].r++;
    }

    //다 떨어지면 행렬에 입력
    for(int i = box[num].r; i < box[num].r + box[num].h; i++){
        for(int j = box[num].c; j < box[num].c + box[num].w; j++){
            mat[i][j] = num;
        }
    }
}

//num 박스를 왼쪽으로 뺄 수 있는가
bool check_left(int num){
    Info b = box[num];

    for(int i = b.c - 1; i >= 1; i--){
        for(int j = b.r; j < b.r + b.h; j++){
            if(mat[j][i] != 0) return false;
        }
    }

    return true;
}

bool check_right(int num){
    Info b = box[num];

    for(int i = b.c + b.w; i <= n; i++){
        for(int j = b.r; j < b.r + b.h; j++){
            if(mat[j][i] != 0) return false;
        }
    }

    return true;
}

//택배 하차 처리
void remove(int num){
    Info& b = box[num];

    for(int i = b.r; i < b.r + b.h; i++){
        for(int j = b.c; j < b.c + b.w; j++){
            mat[i][j] = 0;
        }
    }

    b.is_load = false;
}

//중력 반영, 더 이상 떨어질 박스가 없을 때까지 반복
void apply_gravity(){
    while(1){
        //떨어진 것이 있는가?
        bool flag = false;

        for(int i = 1; i <= max_box_num; i++){
            if(box[i].is_load == false) continue;
            if(!check_down(i)) continue;

            flag = true;
            fall(i);
        }

        if(!flag) break;
    }
}

//택배 하차
void unload(){
    //삭제할 박스 번호
    int remove_num = 105;

    //좌측 하차
    for(int i = 1; i <= max_box_num; i++){
        //이미 하차됨
        if(box[i].is_load == false) continue;
        //왼쪽 하차 불가능
        if(!check_left(i)) continue;

        remove_num = min(i, remove_num);
    }

    if(remove_num != 105){
        remove(remove_num);
        cout << remove_num << '\n';
    }
    apply_gravity();

    //우측 하차
    remove_num = 105;
    for(int i = 1; i <= max_box_num; i++){
        //이미 하차됨
        if(box[i].is_load == false) continue;
        //우측 하차 불가능
        if(!check_right(i)) continue;

        remove_num = min(i, remove_num);
    }

    if(remove_num != 105){
        remove(remove_num);
        cout << remove_num << '\n';
    }
    apply_gravity();
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int k, h, w, c;
        cin >> k >> h >> w >> c;
        max_box_num = max(k, max_box_num);
        box[k] = {h, w, 1, c, true};
        fall(k);
    }

    while(true){
        bool is_finish = true; //더이상 하차할 박스가 없는지
        for(int i = 1; i <= max_box_num; i++)
            if(box[i].is_load){
                is_finish = false;
                break;
            }
        
        if(is_finish) break;
        else unload();
    }

    unload();

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << mat[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}