
# include <stdio.h>
# include <string.h>

const int CMAX = 26;
const int PMAX = 50001;
const int P_LEN_MAX = 51;
const int T_LEN_MAX = 2000001;

class AcNode{
public:
	int id;
	int count;
	AcNode* fail;
	AcNode* next[CMAX];
	AcNode(): id(-1), count(0), fail(NULL){
		for(int i = 0; i < CMAX; ++i){
			next[i] = NULL;
		}
	}
};

void insert(AcNode* &root, const char* str, int id){
	if(root == NULL) root = new AcNode();
	AcNode* cur = root;
	for(int i = 0; str[i] != '\0'; ++i){
		int k = str[i] - 'A';
		if(cur->next[k] == NULL){
			cur->next[k] = new AcNode();
		}
		cur = cur->next[k];
	}
	cur->id = id;
	cur->count++;
}

int head = 0;
int tail = 0;
AcNode* Q[PMAX];

void build_fail(AcNode* root){
	head = tail = 0;
	root->fail = NULL;
	for(int i = 0; i < CMAX; ++i){
		if(root->next[i] != NULL){
			root->next[i]->fail = root;
			Q[tail++] = root->next[i];
		}
	}
	while(head != tail){
		AcNode* cur = Q[head++];
		for(int i = 0; i < CMAX; ++i){
			if(cur->next[i] != NULL){
				Q[tail++] = cur->next[i];
				AcNode* p = cur->fail;
				while(p != NULL){
					if(p->next[i] != NULL){
						cur->next[i]->fail = p->next[i];
						break;
					}
					p = p->fail;
				}
				if(p == NULL) cur->next[i]->fail = root;
			}
		}
	}
}

int ans[PMAX];
char pattern[PMAX][P_LEN_MAX];

void query(AcNode* root, const char* str){
	AcNode* cur = root;
	for(int i = 0; str[i] != '\0'; ++i){
		if(str[i] < 'A' || str[i] > 'Z'){
			cur = root;
			continue;
		}
		int k = str[i] - 'A';
		while(cur != root && cur->next[k] == NULL){
			cur = cur->fail;
        }
        cur = cur->next[k];
		if(cur == NULL) cur = root;
		AcNode* temp = cur;
		while(temp != root){
			if(temp->count > 0){
				ans[temp->id]++;
            }
            temp = temp->fail;
		}
	}
}

void free_ac(AcNode* root){
    if(root == NULL) return;
    for(int i = 0; i < CMAX; ++i){
        if(root->next[i] != NULL){
            free_ac(root->next[i]);
        }
    }
    delete root;
}

char str[T_LEN_MAX];

int main(){
	int N = 0;
	while( scanf("%d", &N) != EOF ){
		AcNode* root = NULL;
		for(int i = 0; i < N; ++i){
			scanf("%s", pattern[i]);
			insert(root, pattern[i], i);
		}
		build_fail(root);
		scanf("%s", str);
		memset(ans, 0, PMAX*sizeof(int));
		query(root, str);
		for(int i = 0; i < N; ++i){
			if(ans[i] > 0){
				printf("%s: %d\n", pattern[i], ans[i]);
			}
		}
		free_ac(root);
	}
	return 0;
}
