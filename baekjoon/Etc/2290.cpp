#include <bits/stdc++.h>

using namespace std;

void drawTop(string field[], int start, int s) {
    for(int i{0}; i < s; i++) {
        field[0][start + i + 1] = '-';
    }
}
void drawLeftTop(string field[], int start, int s) {
    for(int i{0}; i < s; i++) {
        field[i + 1][start] = '|';
    }
}
void drawLeftDown(string field[], int start, int s) {
    for(int i{0}; i < s; i++) {
        field[i + s + 2][start] = '|';
    }
}
void drawMiddle(string field[], int start, int s) {
    for(int i{0}; i < s; i++) {
        field[s + 1][start + i + 1] = '-';
    }
}
void drawRightTop(string field[], int start, int s) {
    for(int i{0}; i < s; i++) {
        field[i + 1][start + s + 1] = '|';
    }
}
void drawRightDown(string field[], int start, int s) {
    for(int i{0}; i < s; i++) {
        field[i + s + 2][start + s + 1] = '|';
    }
}
void drawBottom(string field[], int start, int s) {
    for(int i{0}; i < s; i++) {
        field[2 + s*2][start + i + 1] = '-';
    }
}

void _draw(string field[], int &start, int s, int num) {
    queue<int> q;
    switch(num) {
        case 8:
            drawMiddle(field, start, s);
        case 0:
            drawTop(field, start, s);
            drawLeftTop(field, start, s);
            drawLeftDown(field, start, s);
            drawRightTop(field, start, s);
            drawRightDown(field, start, s);
            drawBottom(field, start, s);
            break;
        case 7:
            drawTop(field, start, s);
        case 1:
            drawRightTop(field, start, s);
            drawRightDown(field, start, s);
            break;
        case 9:
            drawTop(field, start, s);
            drawBottom(field, start, s);
        case 4:
            drawLeftTop(field, start, s);
            drawMiddle(field, start, s);
            drawRightTop(field, start, s);
            drawRightDown(field, start, s);
            break;
        case 6:
            drawLeftDown(field, start, s);
        case 5:
            drawTop(field, start, s);
            drawLeftTop(field, start, s);
            drawMiddle(field, start, s);
            drawRightDown(field, start, s);
            drawBottom(field, start, s);
            break;
        case 2:
            drawTop(field, start, s);
            drawLeftDown(field, start, s);
            drawMiddle(field, start, s);
            drawRightTop(field, start, s);
            drawBottom(field, start, s);
            break;
        case 3:
            drawTop(field, start, s);
            drawMiddle(field, start, s);
            drawRightTop(field, start, s);
            drawRightDown(field, start, s);
            drawBottom(field, start, s);
            break;
    }
    start += s+3;
}

int main() {
    int s{0};
    string input;
    cin >> s >> input;

    char space[(s+2) * input.size() + input.size()-1 + 1];
    memset(space, ' ', sizeof(space));
    space[(s+2) * input.size() + input.size()-1] = '\0';

    string field[2*s + 3];
    for(int i{0}; i < s*2 + 3; i++) {
        field[i] = space;
    }

    int start{0};
    for(auto ele : input) {
        _draw(field, start, s, ele - '0');
    }
    for(int i {0}; i < 2*s + 3; i++) {
        cout << field[i] << '\n';
    }
    
}