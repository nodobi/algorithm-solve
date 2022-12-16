#include <bits/stdc++.h>

using namespace std;

struct Tower{
    int number;
    int height;
    Tower(int _number, int _height) : number(_number), height(_height) {}
};
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    cin >> N;

    stack<Tower> s;

    for(int i {1}; i <= N; i++) {
        int curHeight{0};
        cin >> curHeight;  

        while(!s.empty()) {
            if(s.top().height < curHeight) 
                s.pop();
            else if(s.top().height > curHeight) {
                cout << s.top().number << ' ';
                break;
            }
        }
        if(s.empty()) cout << '0' << ' ';
        s.push(Tower(i, curHeight));
    }

}