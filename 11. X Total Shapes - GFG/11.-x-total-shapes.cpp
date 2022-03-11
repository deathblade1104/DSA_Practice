// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    void DFS(int r,int c, int&n, int&m, vector<vector<bool>>&vis,vector<vector<char>>&grid)
    {
        if(r<0 or c<0 or r>=n or c>=m or vis[r][c]==true or grid[r][c]=='O')
        return;
        
        vis[r][c]=true;
        grid[r][c]='O';
        
        DFS(r+1,c,n,m,vis,grid);
        DFS(r-1,c,n,m,vis,grid);
        DFS(r,c+1,n,m,vis,grid);
        DFS(r,c-1,n,m,vis,grid);
    }
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int n =grid.size(),m=grid[0].size(),ans=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='X' and vis[i][j]==false)
                {
                    DFS(i,j,n,m,vis,grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends