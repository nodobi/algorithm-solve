#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *next, *prev;
    node(int _val, node *_next, node *_prev) : val(_val), next(_next), prev(_prev) {}
};

struct mQueue {
private:
    int length;
    node* head;
    node* tail;
public:
    mQueue() : length(0), head(nullptr), tail(nullptr) { }
    void push(int ele) {
        node* newNode = new node(ele, nullptr, nullptr);
        if(empty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
        length++;
    }
    int pop() {
        int ret{-1};
        if(!empty()) {
            node* cur = head;
            ret = cur->val;
            head = cur->next;
            if(cur->next != nullptr) head->prev = nullptr;
            else tail = nullptr;
            delete cur;
            length--;
        }
        return ret;
    }
    int size() {
        return length;
    }
    int empty() {
        return (head == nullptr ? 1 : 0);
    }
    int front() {
        return head == nullptr ? -1 : head->val;
    }
    int back() {
        return tail == nullptr ? -1 : tail->val;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    mQueue q;
    int N{0};
    cin >> N;

    string cmd;
    int arg{-1};
    while(N--) {
        cin >> cmd;
        if(cmd.compare("push") == 0) {
            cin >> arg;
            q.push(arg);
        } else if(cmd.compare("pop") == 0) {
            cout << q.pop() << "\n";
        } else if(cmd.compare("size") == 0) {
            cout << q.size() << "\n";
        } else if(cmd.compare("empty") == 0) {
            cout << q.empty() << "\n";
        } else if(cmd.compare("front") == 0) {
            cout << q.front() << "\n";
        } else if(cmd.compare("back") == 0) {
            cout << q.back() << "\n";
        }
    }
}