#include <bits/stdc++.h>
#define NUM 1000001

using namespace std;

typedef long long ll;

int N, M, K;
ll input[NUM - 1];
ll tree[NUM * 4];

ll init(int start, int end, int node){
    if(start == end) return tree[node] = input[start];
    int mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, ll dif){
    if(index < start || index > end) return;

    tree[node] += dif;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) cin >> input[i];

    init(0, N - 1, 1);

    ll a, b, c;
    for(int i = 0; i < M + K; i++){
        cin >> a >> b >> c;

        if(a == 1){
            ll dif = c - input[b - 1];
            input[b - 1] = c;
            update(0, N - 1, 1, b - 1, dif);
        }

        else
            cout << sum(0, N - 1, 1, b - 1, c - 1) << "\n";
    }

    return 0;
}