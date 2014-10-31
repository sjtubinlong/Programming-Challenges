# include <cstdio>
# include <cstring>
# include <queue>

using std::queue;

const int TMAX = 1001*1001;
const int WMAX = 1001;
const int CMAX = 26;

struct Position {
    short x;
    short y;
    short d;
} ans[WMAX];

struct Node {
    bool tag;
    int src;
    Node* fail;
    Node* next[CMAX];
};

char puzzle[WMAX][WMAX];

short wlen[WMAX];

int t, l, c, w;

const int off[8][2] = {
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
    {1, 0}, {1, -1}, {0, -1}, {-1, -1}
};

bool coord_valid(int x, int y)
{
    if(x < 0 || x >= l) return false;
    if(y < 0 || y >= c) return false;
    return true; 
}

struct ac_automata {

    Node* root;
    int size;

    void init()
    {
        size = 1;
        root = new Node();
    }

    void insert(const char* word, int src)
    {
        Node* cur = root;
        for(int i = 0; word[i] != '\0'; ++i){
            int k = word[i] - 'A';
            if(cur->next[k] == NULL){
                cur->next[k] = new Node();
                size++;
            }
            cur = cur->next[k];
            ++wlen[src];
        }
        cur->src = src;
        cur->tag = true;
    }

    void build_fail()
    {
        queue<Node*> Q;
        for(int i = 0; i < CMAX; ++i){
            if(root->next[i] != NULL){
                root->next[i]->fail = root;
                Q.push(root->next[i]);
            }
        }
        while(!Q.empty()){
            Node* cur = Q.front();
            Q.pop();
            for(int i = 0; i < CMAX; ++i){
                if(cur->next[i] == NULL) continue;   
                Node* p = cur->fail;
                while(p != NULL){
                    if(p->next[i] != NULL){
                        cur->next[i]->fail = p->next[i];
                        cur->next[i]->tag |= p->next[i]->tag;
                        break;
                    }
                    p = p->fail;
                }
                if(p == NULL) { 
                    cur->next[i]->fail = root;
                }
                Q.push(cur->next[i]);
            }
        }
    }

    void query(int x, int y, int d)
    {
        Node* cur = root;
        while(coord_valid(x, y)){
            int k = puzzle[x][y] - 'A';

            Node* p = cur;
            while(p != NULL){
                if(p->next[k] != NULL){
                    break;
                }
                p = p->fail;
            }
            if(p == NULL){
                x += off[d][0];
                y += off[d][1];
                cur = root;
                continue;
            }
            cur = p->next[k];
            while(p != NULL){
                if(p->next[k] != NULL && p->next[k]->src != -1){
                    if(!p->next[k]->tag) break;
                    ans[p->next[k]->src].x = x - (wlen[p->next[k]->src]-1)*off[d][0];
                    ans[p->next[k]->src].y = y - (wlen[p->next[k]->src]-1)*off[d][1];
                    ans[p->next[k]->src].d = d;
                }
                p = p->fail;
            }
            x += off[d][0];
            y += off[d][1];
        }
    }

};

void solve(ac_automata& ac_trie)
{
    for(int i = 0; i < c; ++i){
        ac_trie.query(l-1, i, 0);
        ac_trie.query(l-1, i, 1);
    }
    for(int i = 0; i < l; ++i){
        ac_trie.query(i, 0, 2);
        ac_trie.query(i, 0, 1);
        ac_trie.query(i, 0, 3);
    }
    for(int i = 0; i < c; ++i){
        ac_trie.query(0, i, 3);
    }

    for(int i = 0; i < c; ++i){
        ac_trie.query(0, i, 4);
        ac_trie.query(0, i, 5);
    }
    
    for(int i = 0; i < l; ++i){
        ac_trie.query(i, c-1, 6);
        ac_trie.query(i, c-1, 5);
        ac_trie.query(i, c-1, 7);
    }

    for(int i = 0; i < c; ++i){
        ac_trie.query(l-1, i, 7);
    }

    for(int i = 0; i < w; ++i){
        printf("%d %d %c\n", ans[i].x, ans[i].y, ans[i].d + 'A');
    }
}

int main()
{
    ac_automata ac_trie;
    ac_trie.init();
    scanf("%d%d%d", &l, &c, &w);
    for(int j = 0; j < l; ++j){
        scanf("%s", puzzle[j]);
    }
    char word[WMAX];
    for(int j = 0; j < w; ++j){
        scanf("%s", word);
        ac_trie.insert(word, j);
    }
    ac_trie.build_fail();
    solve(ac_trie);
    return 0;
}