# include <iostream>
# include <vector>
# include <queue>
# include <string>

using namespace std;

const int CMAX = 128;
const int PMAXN = 100001;

bool visited[PMAXN];

int total = 0;

struct Ac_Automoton {
    struct TNode {
        int id;
        TNode* fail;
        TNode* next[CMAX];
        TNode(): id(0), fail(NULL)
        {
            for(int i = 0; i < CMAX; ++i){
                next[i] = NULL;
            }
        }
    };

    TNode* root;
    int size;

    void init()
    {
        root = new TNode();
        size = 1;
    }

    void insert(const string& str, int id)
    {
        TNode* cur = root;
        for(int i = 0; str[i] != '\0'; ++i){
            int k = str[i];
            if(cur->next[k] == NULL){
                cur->next[k] = new TNode();
                ++size;
            }
            cur = cur->next[k];
        }
        cur->id = id;
    }

    void build_fail()
    {
        queue<TNode*> Q;
        for(int i = 0; i < CMAX; ++i){
            if(root->next[i] != NULL){
                root->next[i]->fail = root;
                Q.push(root->next[i]);
            }
        }

        while(!Q.empty()){
            TNode* cur = Q.front();
            Q.pop();
            for(int i = 0; i < CMAX; ++i){
                if(cur->next[i] != NULL){
                    TNode* p = cur->fail;
                    while(p != NULL){
                        if(p->next[i] != NULL){
                            cur->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == NULL) cur->next[i]->fail = root;
                    Q.push(cur->next[i]);
                }
            }
        }
    }

    void query(const string& buff, int cid)
    {
        bool matched = false;
        memset(visited, false, sizeof(visited));
        TNode* cur = root;
        for(int i = 0; buff[i] != '\0'; ++i){
            int k = buff[i];
            TNode* p = cur;
            while(p != NULL){
                if(p->next[k] != NULL) break;
                p = p->fail;
            }
            if(p == NULL) {
                cur = root;
                continue;
            }
            cur = p->next[k];
            while(p != NULL){
                if(p->next[k] && p->next[k]->id){
                    if(visited[p->next[k]->id]) break;
                    matched = true;
                    visited[p->next[k]->id] = true;
                }
                p = p->fail;
            }
        }
        if(matched) {
            ++total;
            cout << "web " << cid << ":";
            for(int i = 0; i < PMAXN; ++i){
                if(visited[i]){
                    cout << " "<< i;
                }
            }
            cout << endl;
        }
    }

};

int main()
{
    int n;
    string buff;
    Ac_Automoton ac_trie;
    ac_trie.init();

    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>buff;
        ac_trie.insert(buff, i + 1);
    }
    ac_trie.build_fail();
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>buff;
        ac_trie.query(buff, i + 1);
    }
    cout << "total: "<<total<<endl;
    return 0;
}