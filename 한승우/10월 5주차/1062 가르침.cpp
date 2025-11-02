#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, answer;
vector<string> words;
int atoz[26];

int count(){
    int cnt = 0;

    for(const auto& s: words){
        bool flag = true;

        for(const auto& c: s){
            if(atoz[c - 'a'] == 0){
                flag = false;
                break;
            } 
        }

        if(flag) cnt++;
    }

    return cnt;
}

void comb(int start, int len){
    if(len == k) {
        answer = max(answer, count());
        return;
    }

    for(int i = start; i < 26; i++){
        if(atoz[i] == 1) continue;
        atoz[i] = 1;
        comb(i + 1, len + 1);
        atoz[i] = 0;
    }
}

void solve() {
    int ans = 0;

    cin >> n >> k;
    while(n--){
        string s; cin >> s;
        words.push_back(s);
    }

    atoz['a' - 'a'] = 1;
    atoz['n' - 'a'] = 1;
    atoz['t' - 'a'] = 1;
    atoz['i' - 'a'] = 1;
    atoz['c' - 'a'] = 1;
    k -= 5;

    comb(0, 0);
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Tc = 1;
    // cin >> Tc;
    while (Tc--) solve();
    return 0;
}