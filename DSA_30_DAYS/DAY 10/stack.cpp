
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Create a stack of integers
    stack<int> st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    // Display top element
    cout << "Top Element: " << st.top() << endl;

    // Display size
    cout << "Size: " << st.size() << endl;

    // Remove top element
    st.pop();

    cout << "After Pop:" << endl;
    cout << "Top Element: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;

    // Check if stack is empty
    if (st.empty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is Not Empty" << endl;

    return 0;
}