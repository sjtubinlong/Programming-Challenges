/*
Problem: Leetcode - Implement strStr()
Author: 靖难
Tag: KMP, string match, DFA
Difficulty: 1 (from 1 to 5)
*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // edge case
        if(needle == NULL || needle[0] == '\0') return haystack;
        if(haystack == NULL || haystack[0] == '\0') return NULL;
        // start kmp
        int n = strlen(haystack);
        int m = strlen(needle);
        // build next function
        int* next = new int[m+1];
        next[0] = -1;
        int p = -1;
        for(int i = 1; i < m; ++i){
            while(p != -1 && needle[p+1] != needle[i]){
                p = next[p];
            }
            if(needle[p+1] == needle[i]){
                p = p + 1;
            }
            next[i] = p;
        }
        // query and match
        p = -1;
        int i = 0;
        for(; i < n; ++i){
            while(p != -1 && needle[p+1] != haystack[i]){
                p = next[p];
            }
            if(needle[p+1] == haystack[i]){
                p = p + 1;
            }
            if(p == m-1) break;
        }
        //recycle memory
        delete [] next;
        //return answer
        return p != m-1 ? NULL : haystack + i - m + 1;
    }
};
