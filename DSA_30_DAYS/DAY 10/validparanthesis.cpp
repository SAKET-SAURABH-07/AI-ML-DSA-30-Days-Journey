#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> s;

public:
    // Push element
    void push(int val) {

        if (s.empty()) {
            s.push({val, val});
        }
        else {
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }

    // Remove top element
    void pop() {

        if (!s.empty()) {
            s.pop();
        }
    }

    // Return top element
    int top() {

        if (!s.empty()) {
            return s.top().first;
        }

        return -1; // Stack is empty
    }

    // Return minimum element
    int getMin() {

        if (!s.empty()) {
            return s.top().second;
        }

        return -1; // Stack is empty
    }

    // Check if stack is empty
    bool empty() {

        return s.empty();
    }
};

int main() {

    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Top Element : " << st.top() << endl;
    cout << "Minimum Element : " << st.getMin() << endl;

    st.pop();

    cout << "\nAfter Pop\n";

    cout << "Top Element : " << st.top() << endl;
    cout << "Minimum Element : " << st.getMin() << endl;

    st.pop();

    cout << "\nAfter Another Pop\n";

    cout << "Top Element : " << st.top() << endl;
    cout << "Minimum Element : " << st.getMin() << endl;

    return 0;
}