class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n; 
        
        int prev1 = 0; 
        int prev2 = 1; 
        
        for (int i = 2; i <= n; i++) {
            int current = prev1 + prev2; 
            prev1 = prev2; 
            prev2 = current; 
        }
        
        return prev2; 
    }
};
