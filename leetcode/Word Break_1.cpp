#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	static bool wordBreak(string s, unordered_set<string> &dict) {
		int n = s.size();
		if (n == 0) return false;
		vector< bool > dp(n + 1, false);
		dp[0] = true;
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= i; ++j){
				string substr = s.substr(j - 1, i - j + 1);
				if (dp[j - 1] && dict.find(substr) != dict.end()){
					dp[i] = true;
				}
			}
		}
		return dp[n];
	}
};

int main(){
	int n = 0;
	unordered_set<string> dict;
	string str;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> str;
		dict.insert(str);
	}
	cin >> str;
	cout << Solution::wordBreak(str, dict) << endl;
	return 0;
}