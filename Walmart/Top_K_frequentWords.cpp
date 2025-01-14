class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string, int> mp;
        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
        for(auto word: words){
            mp[word]++;
        }
        for(auto x : mp){
            pq.push(make_pair(x.second, x.first));
        }
        while(k--){
            auto res = pq.top();
            ans.push_back(res.second);
            pq.pop();
        }
        return ans;
    }
};