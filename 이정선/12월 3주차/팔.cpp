#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string L, R;
    int answer = 0;
    
    cin >> L >> R;

    // 만약 L의 자릿수와 R의 자릿수가 다르다면 
    // 8이 나오지 않는 숫자를 만들 수 있다
    if(L.length() != R.length()){
        answer = 0;
    } else {
        // 가장 높은 자릿수부터 숫자 비교하기
        for(int i = 0; i < L.length(); i++){
            // 숫자가 일치하다면
            if(L[i] == R[i]){
                // 그게 8이라면 그 자릿수에는 무조건 8이 있어야 된다
                if(L[i] == '8'){
                    // 카운트 +1
                    answer++;
                }
                continue;
            } else {
                // 숫자가 일치하지 않는다면 그 뒷 자릿수부터는
                // 8이 되지 않는 숫자를 만들 수 있으므로 비교할 필요가 없다
                // 따라서 반복문 강제 종료
                break;
            }
        }
    }

    cout << answer;
    return 0;
}
