#if 0 // 法一：分步骤解决
class Solution
{
    public:
    int myAtoi(string str)
    {
        int res = 0;
        int i = 0;
        int flag = 1;
        while (' ' == str[i])  // 1. 处理空格
            i++;
        if ('-' == str[i])    // 2. 处理正负号
            flag = -1;
        if ('-' == str[i] || '+' == str[i])
            i++;
        while (i < str.size() && isdigit(str[i])) // 3. 处理数字逻辑
        {
            int r = str[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) // 4. 处理溢出
            {
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + r;
            i++;
        }
        return flag > 0 ? res : -res;
    }
};
#endif

#if 1 // 法二：自动机[有限状态机]
class Automaton
{
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}};

    int get_col(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

    public:
    int sign = 1;
    long long ans = 0;

    void get(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution
{
    public:
    int myAtoi(string str)
    {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};
#endif