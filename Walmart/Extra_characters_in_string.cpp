class Solution {
public:
    unordered_map<string, int> um;  
    unordered_map<int, int> memo;   

    int solve(string& s, int ind) {
        if (ind >= s.size()) {
            return 0;
        }
        if (memo.find(ind) != memo.end()) {
            return memo[ind];  
        }
        int extra = INT_MAX;
        string tmp = "";
        for (int i = ind; i < s.size(); i++) {
            tmp += s[i];
            if (um.find(tmp) != um.end()) {
                extra = min(extra, solve(s, i + 1));
            }
        }
        extra = min(extra, 1 + solve(s, ind + 1));
        memo[ind] = extra;
        return memo[ind];
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        for (auto& val : dictionary) {
            um[val]++;
        }
        return solve(s, 0); 
    }
};