//USING STL STACKS


stack<int> sortStack(stack<int> st) {
    stack<int> s2;
    int n = 0;
    while (!st.empty()) {
        n = st.top();
        st.pop();
        while (!s2.empty() && s2.top() > n) {
            st.push(s2.top());
            s2.pop();
        }
        s2.push(n);
    }
    return s2;
}

bool checkPalindrome(string str) {
    stack<char> s1;
    stack<char> s2;

    int j = str.length() - 1;
    for (int i = 0; i < str.length(); i++) {
        s1.push(str[i]);
        s2.push(str[j]);
        j--
    }
    while (!s1.emptyy()) {
        if (s1.top() != s2.top()) {
            return false;
        }
        s1.pop();
        s2.pop();
    }
    return true;
}

void sortStack(stack<int> &s) {
    stack<int> tempStack;
    while (!s.empty()) {
        int temp = s.top();
        s.pop();
        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

bool validParentheses(string str) {
    stack<char> s;
    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char t = s.top();
            if ((ch == ')' && t == '(') || (ch == '}' && t == '{') || (ch == ']' && t == '[')) s.pop();
            else return false;
        }
    }
    return s.empty();
}

string infixToPostfix(string exp) {
    string res = "";
    stack<int> s;

    for (char ch : exp) {
        if (ch >= '0' && ch <= '9') res += ch;
        else if (ch == '(') s.push(ch);
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                res += (char)s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        } else {
            while (!s.empty() && s.top() != '(' && 
                ((ch == '+' || ch == '-') || (s.top() == '*' || s.top() == '/'))) {
                res += (char)s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        res += (char)s.top();
        s.pop();
    }
    return res;
}

string postfixToInfix(string exp) {
    stack<string> s;
    string str = "";

    for (int i = 0; i < exp.length(); i++) {
        if (isdigit(exp[i])) {
            s.push(exp.substr(i, 1));
        } else {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();

            str = "(" + op1 + exp[i] + op2 + ")";

            s.push(str);
        }
    }
    return s.top();
}


int evaluatePostfix(string exp) {
    stack<int> s;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}


class MinStack{
    private:
        stack<int> s;
        stack<int> minStack;
    public:
        MinStack() {}

        void push(int x) {
            s.push(x);
            if (minStack.empty() || x <= minStack.top()) {
                minStack.push(x);
            }
        }
        void pop() {
            if (s.top() == minStack.top()) {
                minStack.pop();
            }
            s.pop();
        }
        int top() {
            return minStack.top();
        }
};




struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {};
};

class StackAsLL{
    private:
        Node* top;
    public:
        StackAsLL(){
            top = nullptr;
        }
        void push(int val) {
            Node* newNode = new Node(val);
            newNode->next = top;
            top = newNode;
        }
}



string reverseString(string s) {
    stack<char> charStack;

    for (int i = 0; i < s.length(); i++) {
        charStack.push(s[i]);
    }

    for (int i = 0; i < s.length(); i++) {
        s[i] = charStack.top();
        charStack.pop();
    }

    return s;
}