#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end()); 
    long long lo = 0;
    long long hi = (long long)times.back() * n;
    
    while(lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long sum = 0;
        for (int i = 0; i < times.size(); i++) {
            sum += mid / times[i];
        }
        if(sum >= n) {
            answer = mid;
            hi = mid - 1;
        } else {
           lo = mid + 1;
        }
    }
    return answer;
}

