#include <iostream>
#include <stack>
using namespace std;

class MinStack {

public:

    stack<pair<int, int>> s;

    // Constructor
    MinStack() {

    }

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

    // Pop element
    void pop() {

        if (!s.empty()) {

            s.pop();

        }
        else {

            cout << "Stack is Empty!" << endl;

        }
    }

    // Return Top
    int top() {

        if (!s.empty()) {

            return s.top().first;

        }

        cout << "Stack is Empty!" << endl;
        return -1;
    }

    // Return Minimum
    int getMin() {

        if (!s.empty()) {

            return s.top().second;

        }

        cout << "Stack is Empty!" << endl;
        return -1;
    }

    // Display Stack
    void display() {

        stack<pair<int, int>> temp = s;

        cout << "\nTop\n";

        while (!temp.empty()) {

            cout << "(" << temp.top().first << ", "
                 << temp.top().second << ")" << endl;

            temp.pop();
        }

        cout << "Bottom\n";
    }
};

int main() {

    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    st.display();

    cout << "\nTop Element : " << st.top() << endl;
    cout << "Minimum Element : " << st.getMin() << endl;

    st.pop();

    cout << "\nAfter Pop\n";

    st.display();

    cout << "Top Element : " << st.top() << endl;
    cout << "Minimum Element : " << st.getMin() << endl;

    st.pop();

    cout << "\nAfter Another Pop\n";

    st.display();

    cout << "Top Element : " << st.top() << endl;
    cout << "Minimum Element : " << st.getMin() << endl;

    return 0;
}