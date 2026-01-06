
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int A, B;
		cin >> A >> B;
        vector<int> AVector(A), BVector(B);
       
        for(int i = 0; i < A; i++){
            cin >> AVector[i];
        }
         for(int i = 0; i < B; i++){
            cin >> BVector[i];
        }
        
        if(B > A){
            swap(A, B);
            swap(AVector, BVector);
        }
        int sIndex = 0;
        long long maxValue = 0;
        long long currentSum = 0;
        
        while(sIndex + B - 1 < A){
            for(int i = 0; i < B; i++){
                currentSum += BVector[i] * AVector[sIndex + i];
            }
            maxValue = max(maxValue, currentSum);
            currentSum = 0;
            sIndex++;
        }
        cout << "#" << test_case << " " << maxValue << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
