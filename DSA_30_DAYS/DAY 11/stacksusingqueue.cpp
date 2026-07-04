#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {

    }

    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push new element into q1
        q1.push(x);

        // Move everything back to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {

    MyStack st;

    cout << "Pushing 10\n";
    st.push(10);

    cout << "Pushing 20\n";
    st.push(20);

    cout << "Pushing 30\n";
    st.push(30);

    cout << "\nTop Element : " << st.top() << endl;

    cout << "Pop : " << st.pop() << endl;

    cout << "Top after Pop : " << st.top() << endl;

    cout << "Is Empty? " << (st.empty() ? "Yes" : "No") << endl;

    cout << "\nPushing 40\n";
    st.push(40);

    cout << "Top : " << st.top() << endl;

    cout << "\nPopping Everything:\n";

    while (!st.empty()) {
        cout << st.pop() << " ";
    }

    cout << endl;

    cout << "\nIs Empty? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}