#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, int> map;
    string line;
    int ret{0};
    vector<int> vec;

    cin >> line;
    vec.reserve(301);
    map.insert({'q', 0});
    map.insert({'u', 1});
    map.insert({'a', 2});
    map.insert({'c', 3});
    map.insert({'k', 4});
    for(int i{0}; i < line.size(); i++) {
        bool isExist{false};
        if(map[line[i]] == 0) {
            for(auto &ele : vec) {
                if(ele % 5)
                    continue;
                ele++;
                isExist = true;
                break;
            }
            if(!isExist) {
                vec.push_back(1);
                ret = ret < vec.size() ? vec.size() : ret;
            }
        } else {
            for(auto &ele : vec) {
                if(map[line[i]] == (ele % 5)) {
                    ele++;
                    isExist = true;
                    break;
                }
            }
            if(!isExist) {
                cout << -1;
                return 0;
            }
        }
    }
    for(auto ele : vec) {
        if(ele % 5 != 0) {
            cout << -1;
            return 0;
        }
    }
    
    cout << ret;
}
