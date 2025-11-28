#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

/*
x^2 + y^2 = r^2

y = root(r^2 - x^2)
*/

long long solution(int r1, int r2) {
    ll answer = 0;
    
    for(int x = 1; x <= r2; x++){
        if(x <= r1){
            int y1 = ceil(sqrt((ll)r1*r1 - (ll)x*x));
            int y2 = floor(sqrt((ll)r2*r2 - (ll)x*x));
            
            answer += y2 - y1 + 1;
        } else {
            answer += floor(sqrt((ll)r2*r2 - (ll)x*x)) + 1;
        }
    }
    
    return answer * 4;
}