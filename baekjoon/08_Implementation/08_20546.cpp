#include <bits/stdc++.h>

using namespace std;

struct Trader {
    int cash{0};
    int share{0};

    void buyAll(int price) {
        share += cash / price;
        cash -= (share * price);
    }
    void sellAll(int price) {
        cash += (price * share);
        share = 0;
    }
    int getAsset(int price) {
        return cash + (price * share);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int cash{0}, prevPrice{-1}, streak{0};
    Trader june, sung;

    cin >> cash;
    june.cash = sung.cash = cash;

    for(int i{0}; i < 14; i++) {
        int price{0};
        cin >> price;
        if(price <= june.cash) {
            june.buyAll(price);
        }

        if(prevPrice) {
            if(prevPrice < price) {
                if(streak < 0) streak = 0;
                streak++;
            }
            else if(prevPrice > price) {
                if(streak > 0) streak = 0;
                streak--;
            }
            else {
                streak = 0;
            }
        }
        
        if(streak >= 3) {
            sung.sellAll(price);
        } else if(streak <= -3) {
            sung.buyAll(price);
        }

        prevPrice = price;
    }

    if(sung.getAsset(prevPrice) < june.getAsset(prevPrice)) cout << "BNP";
    else if(sung.getAsset(prevPrice) > june.getAsset(prevPrice)) cout << "TIMING";
    else cout << "SAMESAME";
}