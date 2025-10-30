#include <string>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void removeMargin(vector<string> &board, string x){
    int vis[52][52] = {0};
    queue<pair<int, int>> Q;
    Q.push({0,0});
    vis[0][0] = 1;
    
    while(!Q.empty()){
        pair<int, int> cursor = Q.front();
        Q.pop();
        
        for(int dir = 0;dir<4;dir++){
            int nx = cursor.X+dx[dir];
            int ny = cursor.Y+dy[dir];
            
            if(nx<0||nx>=board.size()||ny<0||ny>=board[0].length()){
                continue;
            }
            if(board[nx][ny]=='0'&&vis[nx][ny]==0){
                Q.push({nx, ny});
                vis[nx][ny] = 1;
            }
            if(board[nx][ny]==x[0]&&vis[nx][ny]==0){
                board[nx][ny] = '0';
                vis[nx][ny] = 1;
            }
        }
    }

}

void removeAll(vector<string> &storage, string x){
    for(int i=0;i<storage.size();i++){
        for(int j=0;j<storage[0].size();j++){
            if(storage[i][j]==x[0]){
                storage[i][j] = '0';
            }
        }
    }
}

int countContainer(vector<string> board){
    int count = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]!='0'){
                count ++;
            }
        }
    }
    
    return count;
}



int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    vector<string> board;
    int storage_length = storage[0].length();
    
    // 바깥쪽 0으로 채우기
    board.push_back(string(storage_length+2, '0'));
    for(auto &row : storage){
        board.push_back("0"+row+"0");
    }
    board.push_back(string(storage_length+2,'0'));
    

    for(auto it : requests){
        int length = it.length();
        
        // request 길이가 1일 때 
        if(length==1){
            removeMargin(board, it);  
        }
        // request 길이가 2일 때
        else{
             removeAll(board, it);
        }
    }
    
    // 남은 컨테이너 수 세기
    answer = countContainer(board); 
   
    return answer;
}