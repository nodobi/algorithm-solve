#include <bits/stdc++.h>

using namespace std;

/*
    운동기구 개수가 짝수인 경우에는 모두 2번씩
    홀수인 경우에는 마지막은 1번씩,
    두 운동기구의 합이 최소가 되는 M의 값은?

    짝수인 경우
        가장 큰 수 + 가장 작은 수
    
    홀수인 경우
        두번째로 큰 수 + 가장 작은 수

    예제1)
        입력: 1 2 3 4 5
        5, 1 + 4, 2 + 3
        M = 5

    예제2)
        입력: 5000 5999 6000, 6001
        5000 + 6001, 5999 + 6000
        M = 11999

    범위
    1 <= N <= 10,000
    0 <= t_i <= 1,000,000,000,000,000,000

    속도를 더 줄이려면?
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0};
    cin >> N;
    long long muscleLoss[N], M{-1};

    for(int i{0}; i < N; i++) {
        cin >> muscleLoss[i];
    }

    sort(muscleLoss, muscleLoss + N);
    if(N % 2) { 
        M = muscleLoss[N -1];
        N--;
    }
    for(int i{0}; i < N / 2; i++) {
        long long curLoss = muscleLoss[i] + muscleLoss[N - (i+1)];
        M = max(M, curLoss);
    }
    
    cout << M;
}