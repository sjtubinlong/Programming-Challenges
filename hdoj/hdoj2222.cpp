# include <stdio.h>
# include <string.h>

const int CMAX = 26;
const int KEY_LEN_MAX = 50;
const int KEY_NUM_MAX = 10000;
const int TEXT_LEN_MAX = 1000000;

struct Node{
	int count;
	Node* fail;
	Node* next[CMAX];
	Node(): count(0), fail(NULL){
		for(int i = 0; i < CMAX; ++i){
			next[i] = NULL;
		}
	}
};

int head = 0;
int tail = 0;
Node* Q[KEY_NUM_MAX*KEY_LEN_MAX];

int insert(Node* &root, const char* str){
	
	if(root == NULL){
		root = new Node();
	}
	
	Node* cur = root;
	for(int i = 0; str[i] != '\0'; ++i){
		int k = str[i] - 'a';
		if(cur->next[k] == NULL){
			cur->next[k] = new Node();
		}
		cur = cur->next[k];
	}

	cur->count++;
	return 0;
}

int build_fail(Node* root){
	
	if(root == NULL){ 
		return -1;
	}

	root->fail = NULL;
	head = tail = 0;
	for(int i = 0; i < CMAX; ++i){
		if(root->next[i] != NULL){
			root->next[i]->fail = root;
			Q[tail++] = root->next[i];
		}
	}

	while(head != tail){
		Node* cur = Q[head++];
		for(int i = 0; i < CMAX; ++i){
			if(cur->next[i] != NULL){
				Node* p = cur->fail;
				while(p != NULL){
					if(p->next[i] != NULL){
						cur->next[i]->fail = p->next[i];
						break;
					}
					p = p->fail;
				}
				if(p == NULL){
					cur->next[i]->fail = root;
				}
				Q[tail++] = cur->next[i];
			}
		}
	}
	return 0;
}

int query(Node* root, const char* str){
	if(root == NULL) return 0;
	
	int num = 0;	
	Node* cur = root;
	
	for(int i = 0; str[i] != '\0'; ++i){
		if(str[i] < 'a' || str[i] > 'z') continue;
		int k = str[i] - 'a';
		while(cur != root && cur->next[k] == NULL){
			cur = cur->fail;
		}
		cur = cur->next[k];
		if(cur == NULL) cur = root;
		Node* temp = cur;
		while(temp != root && temp->count != -1){
			num += temp->count;
			temp->count = -1;
			temp = temp->fail;
		}
	}
	return num;
}

void free_trie(Node* root){
	if(root == NULL) return;
	for(int i = 0; i < CMAX; ++i){
		if(root->next[i] != NULL){
			free_trie(root->next[i]);
		}
	}
	delete root;
}

char keyword[KEY_LEN_MAX];
char text[TEXT_LEN_MAX];

int main(){
	int N = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int M = 0;
		scanf("%d", &M);
		Node* root = NULL;
		for(int j = 0; j < M; ++j){
			scanf("%s", keyword);
			insert(root, keyword);
		}
		build_fail(root);
		scanf("%s", text);
		int result = query(root, text);
		printf("%d\n", result);
		free_trie(root);
	}
	return 0;
}