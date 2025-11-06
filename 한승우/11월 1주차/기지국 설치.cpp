#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
앞에서부터 그냥 깔면 되지 않나? 그리디

앞에서부터 조금 깔면 전체도 조금 깜.

1. loc으로 시작해서, 현재 시작점과 다음 가야할 점(기지국 - w)의 거리를 이용해 개수 깔고.
2. 그 다음 위치로 넘어가기.(기지국 + w)

근데 N이 2억. 실제로 기지국을 깔아서 시뮬레이션 할 수는 없음.
숫자만 가지고 해야 하나?
*/

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int loc = 1;
    double range = 2 * w + 1;
    
    for(int s: stations){
        int dist = (s - w - 1) - loc + 1;
        if(dist > 0) answer += ceil((double)dist / range);
        loc = s + w + 1;
    }
    if(loc <= n) answer += ceil((double)(n - loc + 1) / range);
    
    return answer;
}