#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    cin >> input;

    int ret{0};
    int nums[3];
    int sequence[3] = {0, 1, 2};
    
    istringstream iss(input);
    for(int i{0}; i < 3; i++) {
        string buf;
        getline(iss, buf, ':');
        nums[i] = stoi(buf);
    }

    do {
        if((nums[sequence[0]] < 1 || nums[sequence[0]] > 12) 
        || nums[sequence[1]] > 59 || nums[sequence[2]] > 59)
            continue;
        ret++;
    } while(next_permutation(sequence, sequence + 3));

    cout << ret;
}