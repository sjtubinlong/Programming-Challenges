# include <iostream>
using namespace std;

class Solution {
public:
    const int CMAX = 28;
    class node{
        int id;
        node* next[CMAX];
        node(): id(-1){
            for(int i = 0; i < CMAX; ++i){
                next[i] = NULL;
            }
        }
    }
    int map_char(char c){
        if(c >= 'a' && c <= 'z') return c - 'a';
        if(c == '.') return 'z' - 'a' + 1;
        if(c == '*') return 'z' - 'a' + 2;
        return -1;
    }

    node* build_trie(const char* p){
        if(p == NULL) return NULL;
        node* root = new node();
        node* cur = root;
        for(int i = 0; p[i] != '\0'; ++i){
            int k = map_char(p[i]);
            if(cur->next[k])
        }
    }
    
    bool isMatch(const char *s, const char *p) {
    }
};
