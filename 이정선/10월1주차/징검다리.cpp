#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    vector<int> distances(rocks.size()+1);
    int left = 0;
    int right = distance;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int count = 0;
        int prev = 0;
        for(int i = 0; i < rocks.size(); i++) {
            if(rocks[i] - prev < mid) {
                count ++;
            }else {
                prev = rocks[i];
            }
        }
        if (distance - prev < mid) count++;
        if(count > n) {
            right = mid-1;
        } else {
            answer = mid;
            left = mid + 1;
        }
    }
   
    return answer;
}
