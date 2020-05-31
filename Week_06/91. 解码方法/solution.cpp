class Solution {
    public:
    int numDecodings(string s) {
        if(s.empty() || (s[0] == '0'))
            return 0;
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 :1;
        for(int i = 2; i <= n; i++)
        {
            int t = (i > 1 && (s[i-2] == '1' || (s[i-2]== '2' && s[i-1] <= '6')));
            int l = (s[i-1] != '0')?1:0;
            dp[i] = l*dp[i-1] + dp[i-2]*t;
        }
        return dp[n];


    }
};