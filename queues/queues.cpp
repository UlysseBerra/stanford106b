#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseQueueRec(queue<int> &q);
void reverseQueueStack(queue<int> &q);

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // reverseQueueRec(q);
    reverseQueueStack(q);

    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
  std::cout << std::endl;

    return 0;
}

void reverseQueueRec(queue<int> &q) {
    if (q.empty()) return;
    else {
        int front = q.front();
        q.pop();
        reverseQueueRec(q);
        q.push(front);
        return;
    }
}

// This problem would be much easier using a stack

void reverseQueueStack(queue<int> &q) {
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}