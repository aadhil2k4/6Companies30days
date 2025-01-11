class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count =0;
        unordered_map<int,int>mp;
        for(int n: nums){
            mp[n]++;
        }
        for(auto [num, fq]: mp){
            if(k==0){
                if(fq>1) count++;
            }else{
                if(mp.find(num+k)!=mp.end()){
                    count++;
                }
            }
        }
        return count;
    }
};