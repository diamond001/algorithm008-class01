class Solution {
    public:
    bool isPowerOfTwo(int n) {
        #if 0 // 法一：暴力解法
        if(0 == n) 
            return false;
        while(0 == n%2) 
            n/=2;
        return 1 == n;
        #endif

        #if 1
        return n > 0 && n == (n & -n);
        #endif 

        #if 0
        return n > 0 && !(n & (n - 1));
        #endif
    }
};