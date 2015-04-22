class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2) return n;
        int i = 0, j = 1;
        while(j < n){
            int count = 0;
            while(j < n && A[j] == A[i]) {
                ++count;
                if(count == 1) A[++i] = A[j];
                ++j;
            }
            if(j >= n) break;
            A[++i] = A[j++];
        }
        return i + 1;
    }
};
