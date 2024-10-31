class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } 

            else {
                if (stack.empty()) return false;

                char top = stack.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    stack.pop(); 
                } else {
                    return false; 
                }
            }
        }

        return stack.empty();
    }
};
