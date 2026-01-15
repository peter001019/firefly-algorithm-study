#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int N;
	int L;
	string s;
	int count = 0;
	cin>>N>>L>>s;

	// 두 번째 접근 : OI비교하기
	for (int i=0;i<(L-1);i++)
	{
		int pCount = 0;
		if (s[i]=='I')
		{
			while (s[i+1]=='O'&&s[i+2]=='I')
			{
				pCount++;
				i+=2;

				if (pCount>=N)
				{
					count++;
				}
			}
		}
	}

	// 첫 번째 접근 : 문자열 만들어서 비교하기
	// int slice = N*2+1;
	// string s1 = "I";
	// for (int i=0;i<slice-1;i++)
	// {
	// 	if(i%2==0)
	// 	{
	// 		s1+="O";
	// 	}else
	// 	{
	// 		s1+="I";
	// 	}
	// }
	// //cout<<"s1 : "<<s1<<'\n';
	// for (int i=0;i<L;i++)
	// {
	// 	string s2 = s.substr(i,slice);
	// 	//cout<<s2<<'\n';
	// 	if (s1==s2)
	// 	{
	// 		count++;
	// 	}
	// }
	cout<<count;
}