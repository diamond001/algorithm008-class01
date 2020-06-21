#if 1 法二：利用数组
class Solution {
    public:
    int firstUniqChar(string s) {
        if(0 == s.size()) return -1;
        int *count = new int[26]();
        for (auto c : s)  
            count[c-'a']++;
        for (int i = 0; i < s.size(); i++) 
            if (1 == count[s[i]-'a'])
            {
                delete[] count;
                return i;   
            }
        delete[] count;
        return -1;
    }

};
#endif


#if 0 // 法一：利用map或者set
class Solution {
    public:
    int firstUniqChar(string s) {
        if(0 == s.size()) return -1;
        unordered_map<char, int> hash;
        for(int i=0; i<s.size(); i++)
            ++hash[s[i]];
        for(int j=0; j<s.size(); j++)
            if(1 == hash[s[j]]) return j;
        return -1;
    }
};
#endif