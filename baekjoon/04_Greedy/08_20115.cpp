#include <bits/stdc++.h>

using namespace std;

/*
    N개의 서로 다른 에너지드링크 중에서 2개를 골라 한쪽에 부어
    1개가 남을때까지 반복. 단, 부울때 절반은 사라짐. 이떄 최대량은 ?
    오차는 10^(-5)까지 허용
    a b c 의 드링크가 있고 각각의 양을 A B C 라고 했을때 
    c를 b로, b를 a로 붓게 된다면 
    = A + (B + C/2) / 2
    = A + B/2 + C/2^2
    
    c를 b로, a를 b로 붓게 된다면,
    = (B + C/2) + A/2
    = B + (A + C)/2

    예제1)
    입력 : 3 2 10 9 6
    내림차순으로 정렬하면
    10 9 6 3 2
    이를 위의 정리대로 식을 변환하면
    10 + 9/2 + 6/(2^2) + 3/2^(3) + 2/2^(4)
    = 10 + 4.5 + 1.5 + 3/8 + 1/8
    = 10 + 6 + 0.5 = 16.5

    이렇게 한꺼번에 생각하지 말고, 그 순간순간만 생각해보자.

    A > B > C 라고 했을때, A B 를 먼저 비교하면 최대는 (A + B/2)
    그걸 C 하고 비교하면 (A + B/2) + C
    이 방식으로 예제를 보면

    예제2)
    입력 : 3 2 10 9 6
    정렬하지 않고 바로 한다면
    3 2
    4 10
    12 9
    16.5 6
    = 19.5
    

    나눌때 손실률을 기준으로 해보기 ? 
    예를 들어, 10 하고 나머지 것들을 더해볼떄 손실률이 제일 작은건 2, 그 다음은 3
    
    예제1)
    입력 : 3 2 10 9 6
    10, 2
    11, 3
    12.5 6
    15.5 9
    20? OK

    예제2
    입력 : 100 9 77 65 39 27 45 1 80 495
    495을 제외한 나머지 수를 오른차순으로 정렬했을 떄
    495 100 80 77 65 45 39 27 9 1
    495 1 9 27 39 45 65 77 80 100
    495 + 0.5
    495.5 + 4.5
    ...
    716.5 OK

    범위 확인
    2 <= N <= 100,000
    1 <= x_i <= 1,000,000,000

    입력이
    10
    1000000000 1000000000 ...  1000000000 인 경우
    1000000000 + (1000000000 + ... + 1000000000) / 2

    N, x_i 모두 최대값일땐
    1000000000 + 1000000000 / 2 * 99999

    속도를 더 줄이려면, 입력받는 동시에 계산
    음료량을 저장할 필요가 없다면 배열도 사용 X
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N{0}, max{-1}, drink{0};
    double total{0};
    cin >> N;

    for(int i{0}; i < N; i++) {
        cin >> drink;
        total += drink / 2.0;
        if(drink > max) {
            max = drink;
        }
    }
    total += max / 2.0;

    cout << total;
    
}