#include <bits/stdc++.h>

using namespace std;

int main() {
    int flag{1}, ret{0};
    string line;
    stack<string> s;
    
    cin >> line;
    stack<char> check;

    for(auto ele : line) {
        if(ele == '(' || ele == '[') check.push(ele);
        else {
            if(ele == ')') {
                if(check.empty() || check.top() != '('){
                    flag = 0;
                    break;
                }
                else check.pop();
                
            } else if(ele == ']') {
                if(check.empty() || check.top() != '[') {
                    flag = 0;
                    break;
                }
                else check.pop();
            }
        }
    }
    if(!check.empty()) flag = 0;

    if(flag == 1) {
        for(int i{0}; i < line.size(); i++) {
            if(line[i] == '(') {
                if(line[i+1] == ')') {
                    s.push("2");
                    i++;
                } 
                else s.push("(");
            }
            else if(line[i] == '[') {
                if(line[i+1] == ']') {
                    s.push("3");
                    i++;
                }
                else s.push("[");
            }
            else if(line[i] == ')') {
                int sum{0};
                while(s.top() != "(") {
                    sum += stoi(s.top());
                    s.pop();
                }
                s.pop();
                s.push(to_string(sum * 2));
            }
            else if(line[i] == ']') {
                int sum{0};
                while(s.top() != "[") {
                    sum += stoi(s.top());
                    s.pop();
                }
                s.pop();
                s.push(to_string(sum * 3));
            }
        }
        while(!s.empty()) {
            ret += stoi(s.top());
            s.pop();
        }
    }
    cout << ret;
    return 0;
}