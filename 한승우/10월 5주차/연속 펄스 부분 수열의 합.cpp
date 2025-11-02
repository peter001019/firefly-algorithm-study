#include <string>
#include <vector>

using namespace std;

typedef long long ll;

/*
연속 펄스 부분 수열의 합이 제일 크려면, 큰 숫자가
d -d d -d 이런식으로 되어야 하겠네
*/

long long solution(vector<int> seq) {
    long long answer = 0;
    
    ll sum1 = 0;
    ll sum2 = 0;
    
    for(int i = 0; i < seq.size(); i++){
        int pulse = (i % 2 == 0) ? -1 : 1;
        
        sum1 = max(sum1 + seq[i] * pulse, (ll)seq[i] * pulse);
        sum2 = max(sum2 + seq[i] * -pulse, (ll)seq[i] * -pulse);
        
        answer = max(answer, max(sum1, sum2));
    }
    
    return answer;
}