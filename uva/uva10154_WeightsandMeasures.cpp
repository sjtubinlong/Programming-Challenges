// DP, LIS
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

struct box{
    int w; // weight
    int s; // strength
    box(int w_, int s_): w(w_), s(s_){}
};

bool cmp(const box & a, const box & b){
    if(a.s < b.s) return true;
    if(a.s == b.s) return a.w < b.w;
    return false;
}

int search_lower_bound(vector<int> &src, int target){
    int low = 0, high = src.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(src[mid] == target){
            high = mid;
            if(high == low) break;
        }else if(src[mid] > target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

int solve(vector<box> & d){
    int n = d.size();
    if(n == 0) return 0;

    sort(d.begin(), d.end(), cmp);
    vector<int> sum;
    sum.push_back(d[0].w);
    for(int i = 1; i < n; ++i){
        int pos = sum.size();
        if(d[i].s - d[i].w >= sum.back()){
            sum.push_back(sum.back() + d[i].w);
        }else{
            pos = search_lower_bound(sum, d[i].s - d[i].w);
        }
        for(int j = pos; j >= 1; --j){
            if(sum[j-1] <= d[i].s - d[i].w){
                sum[j] = min(sum[j], sum[j-1] + d[i].w);
            }
        }
        sum[0] = min(sum[0], d[i].w);
    }
    return sum.size();
}

int main(){
    vector<box> d;
    int s, w;
    while(cin >> w >> s){
        d.push_back(box(w, s));
    }
    cout << solve(d) << endl;
    return 0;
}
