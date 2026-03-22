//2026,xiangyin zhan
/*****************************************************************

//LeetCode ,栈和队列


//LeetCode, Evaluate Reverse Polish Notation
//描述

    Evaluate the value of an arithmetic expression in Reverse Polish Notation.
    Valid operators are +, -, *, /. Each operand may be an integer or another expression.
    Some examples:
        ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
        ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

//分析

   无


******************************************************************/

//代码


//LeetCode, Evaluate Reverse Polish Notation
//递归，时间复杂度O(n)，空间复杂度O(logn)

class Solution{
    public:
    int evalRPN(vector<string> &tokens){
        int x, y;
        auto token = tokens.back(); tokens.pop_back();
        if(is_operator(token)){
            y = evalRPN(tokens);
            x = evalRPN(tokens);
            if(token[0] == '+')       x += y;
            else if(token[0] == '-')  x -= y;
            else if(token[0] == '*')  x *= y;
            else                      x /= y;
        } else {
                size_t i;
                x = stoi(token, &i);
        }
        return x;
    }
    private:
    bool is_operator(const string &op) {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }

};

//LeetCode, Evaluate Reverse Polish Notation
//迭代版，时间复杂度O(n)，空间复杂度O(logn)

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> s;
        for (auto token : tokens) {
            if (!is_operator(token)) {
                s.push(token);
            } else {
                int y = stoi(s.top());
                s.pop();
                int x = stoi(s.top());
                s.pop();
                if (token[0] == '+')       x += y;
                else if (token[0] == '-')  x -= y;
                else if (token[0] == '*')  x *= y;
                else                       x /= y;
                s.push(to_string(x));
            }
        }
        return stoi(s.top());
    }
private:
    bool is_operator(const string &op) {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }
};
