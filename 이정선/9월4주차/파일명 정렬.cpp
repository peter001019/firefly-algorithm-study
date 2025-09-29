#include <string>
#include <vector>
#include <cctype> 
#include <regex>

using namespace std;

struct File {
    string name;
    string head;
    string number;
    string tail;
};

// 정렬 기준 함수
bool cmp(const File& a, const File& b){
    // head가 동일하면 뒤의 number을 숫자 기준으로 오름차순 정렬
    if (a.head == b.head){
        return stoi(a.number) < stoi(b.number);
    }else{
        // head가 다르면 문자열 사전순 정렬
        return a.head < b.head;
    }
}

vector<string> solution(vector<string> files) 
{
    vector<string> answer;
    
    // 정규표현식 객체 생성
    // \D+: 숫자 제외의 문자가 1번 이상(+) 반복된다. => head
    // \d+: 숫자가 1번 이상 반복된다. => number
    // .: 임의의 한 문자.
    // *: 앞의 요소가 0번 이상 반복된다.
    // .*: 임의의 문자를 나타낸다. => tail
    regex re("(\\D+)(\\d+)(.*)");
    smatch matches;
    
    // 파일명 File 구조체로 파싱해서 백터에 다시 넣기 
    vector<File> flist;
    
    for (auto file : files){
        if (regex_match(file, matches, re)){
            string temp = "";
            for (auto ch : matches[1].str()) 
                temp += tolower(ch);  // HEAD 소문자화
            flist.push_back(File{matches[0].str(), temp, matches[2].str(), matches[3].str()});
        }
    }
    
    // File 구조체 백터를 정렬
    stable_sort(flist.begin(), flist.end(), cmp);
    for (auto ele : flist) answer.push_back(ele.name);
    return answer;
}
