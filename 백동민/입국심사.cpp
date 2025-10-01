#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// mid 시간 안에 n명을 처리 가능한지 판별
bool bs(const vector<int>& times, int n, long long mid) {
    long long done = 0;
    for (int i = 0; i < (int)times.size(); ++i) {
        done += mid / (long long)times[i];
        if (done >= n) return true; // 조기 종료로 오버플로/불필요 연산 방지
    }
    return false;
}

long long solution(int n, vector<int> times) {
    long long left = 1;

    // max_time = 가장 느린 심사관 시간
    long long max_time = 0;
    for (int i = 0; i < (int)times.size(); ++i) {
        if ((long long)times[i] > max_time) max_time = times[i];
    }

    // 탐색 상한: 최악의 경우
    long long right = max_time * (long long)n;
    long long answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (bs(times, n, mid)) {
            answer = mid;        // 가능  더 작은 시간으로 줄여봄
            right = mid - 1;
        } else {
            left = mid + 1;      // 불가능  시간을 늘림
        }
    }
    return answer;
}
