#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<char> lc(30, '.');
vector<char> rc(30, '.');

void preorder(char v){
    if(v == '.') return;

    cout << v;
    preorder(lc[v - 'A']);
    preorder(rc[v - 'A']);
}

void inorder(char v){
    if(v == '.') return;

    inorder(lc[v - 'A']);
    cout << v;
    inorder(rc[v - 'A']);
}

void postorder(char v){
    if(v == '.') return;

    postorder(lc[v - 'A']);
    postorder(rc[v - 'A']);
    cout << v;
}

void solve() {
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        char n, l, r;
        cin >> n >> l >> r;
        lc[n - 'A'] = l;
        rc[n - 'A'] = r;
    }

    preorder('A'); cout << '\n';
    inorder('A'); cout << '\n';
    postorder('A'); cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}