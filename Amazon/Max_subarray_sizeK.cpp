class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
       vector<int> res; 
    deque<int> q;    
    int n = arr.size();
    int i;
    for (i = 0; i < k; i++) {
        while (!q.empty() && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i); 
    }
    for (; i < n; i++) {
        res.push_back(arr[q.front()]);
        while (!q.empty() && q.front() <= (i - k))
            q.pop_front();
        while (!q.empty() && arr[i] >= arr[q.back()])
            q.pop_back();
        q.push_back(i); 
    }
    res.push_back(arr[q.front()]);
    return res;
    }
};