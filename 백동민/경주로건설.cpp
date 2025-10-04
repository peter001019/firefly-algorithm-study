#include <bits/stdc++.h>


#define L_COST 100 //금액 그냥 매크로가 빠름
#define C_COST 600
#define INF 999999

using namespace std;

int dir[4][2] = { {0,-1}, {-1,0}, {0,1} , {1,0}}; // 상좌하우 방향, 세로 이동 0,2 가로이동 1,3

typedef struct Block {
    int cost; // 지금까지 누적 cost
    int x;    // 현재 x(행)
    int y;    // 현재 y(열)
    int dir;  // 이 칸으로 들어온 방향(0~3). 시작 첫발 전에는 없음
}block;

// 우선순위 큐에서 비용이 작은 것이 먼저 나오기
struct Cmp {
    bool operator()(const block& a, const block& b) const {
        return a.cost > b.cost; // 비용 작은 게 top
    }
};



int solution(vector<vector<int>> board) {
    int answer = INF;
    
    int size = board.size();
    
    vector<vector<vector<int>>> dist(
        size, vector<vector<int>>(size, vector<int>(4, INF))//4방향의 가중치값
    );
    //직선 = 100, 코너 = 100+500
    //목표 : 최소 비용 금액
    //처음에 bfs로 햇는데, 생각해보니 가중치가 생기면 쓰면 안됨
    //그래서 길찾기 알고리즘 중 다익스트라 선택
    
    
    priority_queue<block, vector<block>, Cmp> pq; //우선순위큐 (좌표, 직전 방향)
    // 시작점 (0,0)에서 처음 방향이 없으므로
    // 근처 칸들로 line 비용만 내고 ㄱㄱ
    for (int i = 0; i < 4; i++) {
        int nx = 0 + dir[i][0];
        int ny = 0 + dir[i][1];

        // 범위 체크
        if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
        // 벽 체크
        if (board[nx][ny] == 1) continue;

        dist[nx][ny][i] = L_COST;
        pq.push({L_COST, nx, ny, i});
    }
    
    // 다익스트라
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        // 이미 더 좋은 비용으로 갱신되었다면 스킵 -> 최적화
        if (cur.cost != dist[cur.x][cur.y][cur.dir]) continue;

        //방향
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dir[i][0];
            int ny = cur.y + dir[i][1];

            // 범위, 벽 체크
            if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
            if (board[nx][ny] == 1) continue;

            // 생각해보니 같은 방향인지 아닌지만 체크하면 된거네 
            int add = (i == cur.dir) ? L_COST : C_COST;
            int nc = cur.cost + add;

            if (nc < dist[nx][ny][i]) {
                dist[nx][ny][i] = nc;
                pq.push({nc, nx, ny, i});
            }
        }
    }

    // 도착 칸 최소 비용
    for (int i = 0; i < 4; i++) {
        answer = min(answer, dist[size-1][size-1][i]);
    }

    return answer;
}