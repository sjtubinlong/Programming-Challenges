#include <stdio.h>
#include <string.h>
using namespace std;

int d[2001];
int r[2][2001];

int max(int a, int b){
	return a > b ? a : b;
}

int main() {
	
	// your code here
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &d[i]);
	}
	memset(r, 2*2001*sizeof(int), 0);
    for(int i = 0; i < n; ++i) r[0][i] = n * d[i];
    int k = 1;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(j + i >= n) break;
            int y = n - (i + 1) + 1;
            int s1 = y * d[j] + r[!k][j+1];
            int s2 = y * d[j+i] + r[!k][j];
            r[k][j] = max(s1, s2);
        }
        k = !k;
    }
    printf("%d\n", r[!k][0]);
	return 0;
}
