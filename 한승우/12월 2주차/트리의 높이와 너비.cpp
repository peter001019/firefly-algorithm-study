#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
이진 트리가 주어졌을 때, 행렬에 그려보고, 가장 너비가 큰 level을 찾는다.

level 최대 -> 13 정도

1. inorder 순회를 하며 행, 열 위치를 행렬에 기록
2. level마다 너비 계산은? -> 완전탐색

---
메모리 초과 -> mat을 어떻게 표현할 것인가?

1. lvl 별로 제일 왼쪽, 오른쪽 값만 저장한다.
2. lvl 별로 위치한 원소들의 column list를 저장한다.
*/

const int MAX = 10005;

int max_level, max_width, n;
int lc[MAX];
int rc[MAX];
int parent[MAX];
vector<int> mat[MAX]; //트리를 그릴 행렬

int col = 1;
//inorder 순회
void dfs(int cur, int level){
    if(lc[cur] != -1) dfs(lc[cur], level + 1);
    mat[level].push_back(col++);
    if(rc[cur] != -1) dfs(rc[cur], level + 1);
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int num, l, r;
        cin >> num >> l >> r;
        lc[num] = l;
        rc[num] = r;
        parent[l] = num;
        parent[r] = num;
    }

    int head = -1;
    for(int i = 1; i <= n; i++){
        if(parent[i] == 0) {
            head = i;
            break;
        }
    }

    //트리 그리기
    dfs(head, 1);

    //너비 찾기
    for(int r = 1; r < MAX; r++){
        if(mat[r].empty()) break;

        sort(mat[r].begin(), mat[r].end());
        int width = mat[r].back() - mat[r].front() + 1;

        if(max_width < width){
            max_width = width;
            max_level = r;
        }
    }

    cout << max_level << ' ' << max_width;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}