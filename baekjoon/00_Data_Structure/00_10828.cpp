#include <bits/stdc++.h>

using namespace std;

struct mStack {
private:
    int container[10001];   
    int length{0};
public:
    mStack() : length(0) {}
    void push(int ele) {
        container[length++] = ele;
    }
    int pop() {
        return length == 0 ? -1 : container[--length];
    }
    int size() {
        return length;
    }
    int empty() {
        return length == 0 ? 1 : 0;
    }
    int top() {
        return length == 0 ? -1 : container[length - 1];
    }
};

int main() {
    int size{0}, N{0};
    cin >> N;
    
    mStack s;
    string cmd;
    
    int arg{-1};
    while(N--) {
        cin >> cmd;
        if(cmd.compare("push") == 0) {
            cin >> arg;
            s.push(arg);
        }else if(cmd.compare("pop") == 0) {
            cout << s.pop() << endl;
        }else if(cmd.compare("size") == 0) {
            cout << s.size() << endl;
        }else if(cmd.compare("empty") == 0) {
            cout << s.empty() << endl;
        }else if(cmd.compare("top") == 0) {
            cout << s.top() << endl;
        }
    }
}