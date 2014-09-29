# include <stdio.h>
# include <string.h>

const int CMAX = 128;
const int PMAX = 501;
const int MAX_LEN_INPUT = 10001;
const int MAX_LEN_PATTERN = 100001;

bool visit[PMAX];
bool matched = false;

class ac_node{
public:
    int id;
    ac_node* fail;
    ac_node* next[CMAX];
    ac_node(): id(-1), fail(NULL){
        for(int i = 0; i < CMAX; ++i){
            next[i] = NULL;
        }
    }
};

int head = 0;
int tail = 0;
ac_node* Q[MAX_LEN_PATTERN];

int insert(ac_node* &root, const char* str, int id){
    if(!root) root = new ac_node();
    ac_node* cur = root;
    for(int i = 0; str[i] != '\0'; ++i){
        int k = str[i];
        if(cur->next[k] == NULL) {
            cur->next[k] = new ac_node();
        }
        cur = cur->next[k];
    }
    cur->id = id;
    return 0;
}

int build_fail(ac_node* root){
    if(root == NULL) return -1;
    root->fail = NULL;
    head = tail = 0;
    for(int i = 0; i < CMAX; ++i){
        if(root->next[i] != NULL){
            root->next[i]->fail = root;
            Q[tail++] = root->next[i];
        }
    }
    while(head != tail){
        ac_node* cur = Q[head++];
        for(int i = 30; i < CMAX; ++i){
            if(cur->next[i] != NULL){
                Q[tail++] = cur->next[i];
                ac_node* cur_fail = cur->fail;
                while( cur_fail != NULL){
                    if(cur_fail->next[i] != NULL){
                        cur->next[i]->fail = cur_fail->next[i];
                        break;
                    }
                    cur_fail = cur_fail->fail;
                }
                if(cur_fail == NULL){
                    cur->next[i]->fail = root;
                }
            }
        }
    }
    return 0;
}

int search(ac_node* root, const char* str){
    if(root == NULL) return -1;
    ac_node* cur = root;
    for(int i = 0; str[i] != '\0'; ++i){
        int k = str[i];
        while(cur != root && cur->next[k] == NULL){
            cur = cur->fail;
        }
        cur = cur->next[k];
        if(cur == NULL) cur = root;
        ac_node* temp = cur;
        while(temp != root && temp->id != -1){
            if(!visit[temp->id]){
                matched = true;
                visit[temp->id] = true;
            }
            temp = temp->fail;
        }
    }
    return 0;
}

void free_ac(ac_node* root){
    if(root == NULL) return;
    for(int i = 0; i < CMAX; ++i){
        if(root->next[i] != NULL){
            free_ac(root->next[i]);
        }
    }
    delete root;
}

char* fgets_wrapper(char* buffer, size_t size, FILE* fp){
    if(fgets(buffer, size, fp) != 0){
        int pos = 0;
        while(buffer[pos] != '\0') ++pos;
        if(buffer[pos-1] == '\n') buffer[pos-1] = '\0';
        return buffer;
    }
    return NULL;
}

int main(){
    int N = 0;
    char str[MAX_LEN_INPUT];
    scanf("%d", &N);
    getchar();
    ac_node* ac_automata = NULL;
    for(int i = 0; i < N; ++i){
        fgets_wrapper(str, MAX_LEN_INPUT, stdin);
        insert(ac_automata, str, i+1);
    }
    build_fail(ac_automata);
    scanf("%d", &N);
    getchar();
    int count = 0;
    for(int i = 0; i < N; ++i){
        fgets_wrapper(str, MAX_LEN_INPUT, stdin);
        matched = false;
        memset(visit, 0, sizeof(bool)*PMAX);
        search(ac_automata, str);
        if(matched){
            ++count;
            printf("web %d:", i+1);
            for(int j = 0; j < PMAX; ++j)
                if(visit[j])
                    printf(" %d", j);
            printf("\n");
        }
    }
    printf("total: %d\n", count);
    free_ac(ac_automata);
    return 0;
}