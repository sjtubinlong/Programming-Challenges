class Solution {
public:
    static vector<int> version2vec(string &version){
        vector<int> vec;
        int cur = 0;
        bool flag = false;
        for(int i = 0; i < version.size(); ++i){
            if(version[i] != '.'){
                flag = true;
                cur = cur * 10 + version[i] - '0';
            }else{
                if(flag) vec.push_back(cur);
                cur = 0;
            }
        }
        if(flag) vec.push_back(cur);
        return vec;
    }
    
    static int compareVersion(string version1, string version2) {
        vector<int> v1 = version2vec(version1);
        vector<int> v2 = version2vec(version2);
        int diff = v1.size() - v2.size();
        vector<int>* v = NULL;
        if(diff > 0) v = &v2;
        else v = &v1;
        for(int i = 0; i < abs(diff); ++i) v->push_back(0);
        for(int i = 0; i < v1.size(); ++i){
            if(v1[i] > v2[i]){
                return 1;
            }else if(v1[i] < v2[i]){
                return -1;
            }
        }
        return 0;
    }
};