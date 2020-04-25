/*
* 一个巧妙的方法，需要背过：
* [ 1 ] 首先分别统计两个字符串中不同字符出现的次数，并存放到数组中 
* [ 2 ] 其次，比较从两个字符串统计到的每个字符出现的次数
*/
bool isAnagram(char * s, char * t)
{
    int ns[26] = {0};
    int nt[26] = {0};
    int i;

    while (*s) {
        ns[*s - 97] ++;
        s ++;
    }

    while (*t) {
        nt[*t - 97] ++;
        t ++;
    }

    while (i < 26) {
        if(ns[i] != nt[i]){
            return false;
        }
        ++ i;
    }

    return true;
}