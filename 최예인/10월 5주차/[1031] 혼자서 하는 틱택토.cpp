#include <string>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

// int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool checkLine(vector<string> board, char c){
    // 가로
    for(int i=0;i<3;i++){
        if(board[i][0]==c&&board[i][1]==c&&board[i][2]==c){
            return true;
        }
    }
    
    //세로
    for(int i=0;i<3;i++){
        if(board[0][i]==c&&board[1][i]==c&&board[2][i]==c){
            return true;
        }
    }
    
    // 대각선
    if(board[0][0]==c&&board[1][1]==c&&board[2][2]==c){
        return true;
    }
    if(board[0][2]==c&&board[1][1]==c&&board[2][0]==c){
        return true;
    }
    return false;
    
    
    
//     int dist[3][3] = {0};
//     queue<pair<int, int>>Q;
//     int flag = 0;
    
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
            
//             if(board[i][j]=='O'){
//                     Q.push({i, j});
//                     dist[i][j] = 1;
//                     flag = 1;
//                     break;
//                  }
            
//         }
//         if(flag==1){
//             break;
//         }
//     }
    
//     while(!Q.empty()){
//         pair<int, int>cursor = Q.front();
//         Q.pop();
        
//         for(int dir=0;dir<8;dir++){
//             int nx = cursor.X + dx[dir];
//             int ny = cursor.Y + dy[dir];
            
//             if(nx<0||nx>=3||ny<0||ny>=3){
//                 continue;
//             }
//             if(dist[nx][ny]==0 && board[nx][ny]=='O'){
//                 Q.push({nx, ny});
//                 dist[nx][ny] = dist[cursor.X][cursor.Y]+1;
//             }           
            
//         }
//     }
//     int check = 0;
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             if(dist[i][j]==3){
//                 check = 1;
//             }
//         }
//     }
//     if(check==1){
//         return true;
//     }else{
//         return false;
//     }
       
}


int solution(vector<string> board) {
    int answer = -1;
    int zero_count = 0;
    int x_count = 0;
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].length();j++){
            if(board[i][j]=='O'){
                zero_count++;
            }
            if(board[i][j]=='X'){
                x_count++;
            }
        }
    }
    
    answer = 0;
    bool check_zero = checkLine(board, 'O');
    bool check_x = checkLine(board, 'X');
    
    // 1. board에 아무것도 없으면 result = 1
    if(x_count==0&&zero_count==0){
        answer = 1;
    }
    
    // 2. 갯수가 똑같을 때
    else if(!check_zero&& x_count==zero_count){
        answer = 1;
    }
    
    // 3. 0이 더 많을 때 
    else if(zero_count-x_count==1 && !check_x){
        answer = 1;
    }
   
    
    return answer;  
}