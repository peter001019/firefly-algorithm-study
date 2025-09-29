#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    // works 내림차순으로 정렬
    sort(works.begin(), works.end(), greater<int>());
    
    // 남은 N시간 작업량만큼 works를 순회하여 처리
    for(int i = 0; i < n; i++) {
        
        // works 중 가장 큰 값이 0이라면 남은 작업량이 없다는 의미이므로 0을 반환 후 종료.
        if(works[0] == 0) {
            return 0;
        }
        
        // works 중 가장 큰 작업량인 works[0]에서 작업 1 처리
        works[0] = works[0] - 1;
        
        // works 벡터를 내림차순으로 유지하기 위한 반복문 실행
        int changeIndex;
        
        for(changeIndex = 1; changeIndex < works.size(); changeIndex++) {
            if(works[0] >= works[changeIndex]) {
                break;
            }
        }
        
        // 찾은 Index는 works[0]와 같거나 작은 수 중 가장 앞에 있는 index이거나, 
        // 마지막 index + 1이므로 -1을 해준다.
        changeIndex--;
        
        int temp = works[0];
        works[0] = works[changeIndex];
        works[changeIndex] = temp;

    }
    
    for(int i = 0; i < works.size(); i++) {
        answer += pow(works[i], 2);
    }
    
    return answer;
}
