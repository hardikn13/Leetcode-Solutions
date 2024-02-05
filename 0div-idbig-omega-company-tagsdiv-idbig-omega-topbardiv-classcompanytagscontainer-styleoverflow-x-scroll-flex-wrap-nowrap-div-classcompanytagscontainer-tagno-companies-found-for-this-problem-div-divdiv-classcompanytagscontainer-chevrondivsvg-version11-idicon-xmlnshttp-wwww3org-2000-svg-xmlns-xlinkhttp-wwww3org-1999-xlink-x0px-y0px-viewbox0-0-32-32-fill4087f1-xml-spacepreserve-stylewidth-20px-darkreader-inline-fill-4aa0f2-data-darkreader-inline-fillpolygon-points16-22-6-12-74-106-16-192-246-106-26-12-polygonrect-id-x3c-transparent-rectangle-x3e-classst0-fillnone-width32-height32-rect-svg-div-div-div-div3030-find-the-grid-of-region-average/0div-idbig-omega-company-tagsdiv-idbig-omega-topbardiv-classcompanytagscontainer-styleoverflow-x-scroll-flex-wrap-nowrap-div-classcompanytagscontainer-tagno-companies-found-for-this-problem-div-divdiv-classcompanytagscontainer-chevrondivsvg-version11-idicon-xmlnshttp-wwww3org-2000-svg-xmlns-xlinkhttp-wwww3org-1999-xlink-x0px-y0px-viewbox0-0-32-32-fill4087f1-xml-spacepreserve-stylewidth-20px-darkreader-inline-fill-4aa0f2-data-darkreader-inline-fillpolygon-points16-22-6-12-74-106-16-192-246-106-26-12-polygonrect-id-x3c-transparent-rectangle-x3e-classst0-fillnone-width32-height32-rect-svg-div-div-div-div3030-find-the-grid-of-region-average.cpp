
class Solution {
public:
    bool check(int p1, int p2, vector<vector<int>>& image, int t){
        vector<int> r1={0, 0, -1, 1}, c1={1, -1, 0, 0};
        for(int i=p1-1; i<=p1+1; i++){
            for(int j=p2-1; j<=p2+1; j++){
                for(int k=0; k<4; k++){
                    int v1=i+r1[k], v2=j+c1[k];
                    if(v1>=0 && v2>=0 && v1<image.size() && v2<image[0].size() && v1>=p1-1 && v1<=p1+1 && v2>=p2-1 && v2<=p2+1){
                        
                        if(abs(image[i][j] - image[v1][v2])>t) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        
        int m=image.size(), n=image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1)), ans=vis;
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                bool chk = check(i, j, image, threshold);
                if(chk){
                    int avg=0;
                    for(int p1=i-1; p1<=i+1; p1++){
                        for(int p2=j-1; p2<=j+1; p2++){
                            avg += image[p1][p2];
                        }
                    }
                    avg /= 9;
                    vis[i][j] = avg;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int ans1=0, cnt=0;
                for(int p1=i-1; p1<=i+1; p1++){
                    for(int p2=j-1; p2<=j+1; p2++){
                        if(p1>=0 && p1<m && p2>=0 && p2<n && vis[p1][p2]!=-1) {
                            ans1 += vis[p1][p2];
                            cnt++;
                        }
                    }
                }
                if(cnt==0) ans[i][j] = image[i][j];
                else ans[i][j] = ans1/cnt;
            }
        }
        return ans;
    }
};