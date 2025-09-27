#include <bits/stdc++.h>
using namespace std;

int A, B, C;
bool visited[201][201][201];
set<int> ans;

void dfs(int a, int b, int c){
    if(visited[a][b][c]) return;

    if(a == 0) {
        ans.insert(c);
    }

    visited[a][b][c] = true;

    int aGap = A - a;
    int bGap = B - b;
    int cGap = C - c;

    //C -> A
    if(c > 0) dfs(a + min(aGap, c), b, max(0, c - aGap));
    //C -> B
    if(c > 0) dfs(a, b + min(bGap, c), max(0, c - bGap));
    //A -> C
    if(a > 0) dfs(max(0, a - cGap), b, c + min(cGap, a));
    //A -> B
    if(a > 0) dfs(max(0, a - bGap), b + min(bGap, a), c);
    //B -> A
    if(b > 0) dfs(a + min(aGap, b), max(0, b - aGap), c);
    //B -> C
    if(b > 0) dfs(a, max(0, b - cGap), c + min(cGap, b));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> A >> B >> C;

    dfs(0, 0, C);

    for(int a: ans) cout << a << " ";

    return 0;
}