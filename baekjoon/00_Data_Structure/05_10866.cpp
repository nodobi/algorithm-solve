#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *next, *prev;
    node(int _val, node *_next, node *_prev) : val(_val), next(_next), prev(_prev) {}
};

class mDeque {
    int length;
    node *head, *tail;
public:
    mDeque() : length(0), head(nullptr), tail(nullptr) {}
    
    void push_front(int ele) {
        node* newNode = new node(ele, nullptr, nullptr);
        if(empty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = head;
            head->next = newNode;
            head = newNode;
        }
        length++;
    }
    void push_back(int ele) {
        node* newNode = new node(ele, nullptr, nullptr);
        if(empty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = tail;
            tail->prev = newNode;
            tail = newNode;
        }
        length++;
    }
    int pop_front() {
        int ret{-1};
        if(!empty()) {
            node *popNode = head;
            ret = popNode->val;
            if(head->prev == nullptr) {
                tail = nullptr;
                head = nullptr;
            } else {
                head = head->prev;
                head->next = nullptr;
            }
            delete popNode;
            length--;
        }
        return ret;
    }
    int pop_back() {
        int ret{-1};
        if(!empty()) {
            node *popNode = tail;
            ret = popNode->val;
            if(tail->next == nullptr) {
                tail = nullptr;
                head = nullptr;
            } else {
                tail = tail->next;
                tail->prev = nullptr;
            }
            delete popNode;
            length--;
        }
        return ret;
    }
    int size() {
        return length;
    }
    int empty() {
        return head == nullptr ? 1 : 0;
    }
    int front() {
        return empty() ? -1 : head->val;
    }
    int back() {
        return empty() ? -1 : tail->val;
    }
    
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    mDeque d;
    int N{0};
    cin >> N;

    string cmd;
    int arg{-1};
    while(N--) {
        cin >> cmd;
        if(cmd.compare("push_front") == 0) {
            cin >> arg;
            d.push_front(arg);
        } else if(cmd.compare("push_back") == 0) {
            cin >> arg;
            d.push_back(arg);
        } else if(cmd.compare("pop_front") == 0) {
            cout << d.pop_front() << "\n";
        } else if(cmd.compare("pop_back") == 0) {
            cout << d.pop_back() << "\n";
        } else if(cmd.compare("size") == 0) {
            cout << d.size() << "\n";
        } else if(cmd.compare("empty") == 0) {
            cout << d.empty() << "\n";
        } else if(cmd.compare("front") == 0) {
            cout << d.front() << "\n";
        } else if(cmd.compare("back") == 0) {
            cout << d.back() << "\n";
        }
    }
}