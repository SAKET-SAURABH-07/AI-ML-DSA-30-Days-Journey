#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long mn;

public:

    // Push element
    void push(int x) {

        if (st.empty()) {

            st.push(x);
            mn = x;

        }
        else if (x < mn) {

            st.push(2LL * x - mn);
            mn = x;

        }
        else {

            st.push(x);

        }
    }

    // Pop element
    void pop() {

        if (st.empty()) {

            cout << "Stack is Empty!\n";
            return;

        }

        if (st.top() < mn) {

            mn = 2 * mn - st.top();

        }

        st.pop();
    }

    // Return Top
    int top() {

        if (st.empty()) {

            cout << "Stack is Empty!\n";
            return -1;

        }

        if (st.top() < mn)
            return mn;

        return st.top();
    }

    // Return Minimum
    int getMin() {

        if (st.empty()) {

            cout << "Stack is Empty!\n";
            return -1;

        }

        return mn;
    }

    bool empty() {

        return st.empty();

    }
};

int main() {

    MinStack ms;

    int choice, value;

    while (true) {

        cout << "\n========== MIN STACK ==========\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Get Minimum\n";
        cout << "5. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter Value : ";
            cin >> value;

            ms.push(value);

            cout << value << " pushed successfully.\n";

            break;

        case 2:

            ms.pop();

            break;

        case 3:

            if (!ms.empty())
                cout << "Top Element : " << ms.top() << endl;

            break;

        case 4:

            if (!ms.empty())
                cout << "Minimum Element : " << ms.getMin() << endl;

            break;

        case 5:

            cout << "Program Ended.\n";
            return 0;

        default:

            cout << "Invalid Choice!\n";

        }
    }

    return 0;
}