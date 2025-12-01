#include <bits/stdc++.h>
using namespace std;

void rotate(string &target, int dir){
    if(dir == 1){
        target = target[7] + target.substr(0, 7);
    } else if(dir == -1){
        target = target.substr(1, 7) + target[0];
    }
}

// true 면 다른 방향으로 회전
// false 면 회전 X
bool compare(string &targetone, string &targettwo){
    if(targetone[2] == targettwo[6]){
        return false;
    } else {
        return true;
    }
}

void rotateRec(vector<string> &four, int index, int dir){
    vector<string> copyFour = four;
    
    if(index == 0) {
        rotate(four[0], dir);
        
        if(compare(copyFour[0], copyFour[1])) {
            rotate(four[1], -dir);
            
        } else {
            copyFour = four;
            return;
        }
        if(compare(copyFour[1], copyFour[2])) {
            rotate(four[2], dir);
        } else {
            copyFour = four;
            return;
        }
        if(compare(copyFour[2], copyFour[3])) {
            rotate(four[3], -dir);
        } else {
            copyFour = four;
            return;
        }
            
    } else if (index == 1) {
        rotate(four[1], dir);

        if(compare(copyFour[0], copyFour[1])) {
            rotate(four[0], -dir);
        } 
        if(compare(copyFour[1], copyFour[2])) {
            rotate(four[2], -dir);
        } else {
            copyFour = four;
            return;
        }
        if(compare(copyFour[2], copyFour[3])) {
            rotate(four[3], dir);
        } else {
            copyFour = four;
            return;
        }
        
    } else if (index == 2) {
        rotate(four[2], dir);

        
        if(compare(copyFour[1], copyFour[2])) {
            rotate(four[1], -dir);
            
            if(compare(copyFour[0], copyFour[1])) {
                rotate(four[0], dir);
            } 
        }
        if(compare(copyFour[2], copyFour[3])) {
            rotate(four[3], -dir);
        } 

        copyFour = four;
        return;
        
    } else if (index == 3) {
        rotate(four[3], dir);
        
        if(compare(copyFour[2], copyFour[3])) {
            rotate(four[2], -dir);
        } else {
            copyFour = four;
            return;
        }
        if(compare(copyFour[1], copyFour[2])) {
            rotate(four[1], dir);
        } else {
            copyFour = four;
            return;
        }
        if(compare(copyFour[0], copyFour[1])) {
            rotate(four[0], -dir);
        } else {
            copyFour = four;
            return;
        }
    }
}

int main() {
    vector<string> four;
    
    for(int i = 0; i < 4; i ++) {
        string s;
        cin >> s;
        four.push_back(s);
    }
    int count;
    cin >> count;

    vector<pair<int, int> > rotateV;
    for(int i = 0; i < count; i++){
        int a, b;

        cin >> a >> b;
        rotateRec(four, a-1, b);
    }

    int answer = 0;
    for(int i = 0; i < 4; i++){
        if(four[i][0] == '1'){
            answer += pow(2, i);
        }
        // cout << four[i] << endl;
    }
    
    
    cout << answer;
    return answer;
}
