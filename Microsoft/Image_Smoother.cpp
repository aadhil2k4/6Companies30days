class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                int sum=0;
                int count =0;
                for(int x=row-1; x<=row+1; x++){
                    for(int y=col-1; y<=col+1; y++){
                        if(x>=0 && x<m && y>=0 && y<n){
                            sum+=img[x][y];
                            count++;
                        }
                    }
                }
                ans[row][col] = sum/count;
            }
        }
        return ans;
    }
};