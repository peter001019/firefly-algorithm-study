#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[1001];
int height[1001];

int find_parent(int n){
    if(parent[n] == n) return n;
    return parent[n] = find_parent(parent[n]);
}

void union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if(height[a] > height[b]) swap(a, b);

    parent[a] = b;
    height[b]++;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> M;

    for(int i = 1; i <= N; i++) parent[i] = i;

    int isConnect;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> isConnect;

            if(isConnect) union_parent(i, j);
        }
    }

    int path;
    cin >> path;

    int root = find_parent(path);
    bool flag = true;

    for(int i = 0; i < M - 1; i++){
        cin >> path;
        if(root != find_parent(path)) flag = false;
    }

    if(flag) cout << "YES";
    else cout << "NO";

    return 0;
}

/*
e -> a -> b -> c
       -> d

같은 그래프(집합)에 속하는가? -> union find
*/