// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    struct Node{
        int r, c,cost;
        
        Node(int x, int y, int z)
        {
            r=x;
            c=y;
            cost=z;
        }
    };
    
    struct mycomp{
        bool operator()(const Node&a, const Node&b)
        {
            return a.cost>b.cost;
        }
    };
    
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        priority_queue<Node, vector<Node>,mycomp>pq;
        Node temp(0,0,grid[0][0]);
        vis[0][0]=true;
        
        pq.push(temp);
        vector<vector<int>>dim={{1,0},{-1,0},{0,1},{0,-1}};
        
        while(pq.size()>0)
        {
            Node t=pq.top();
            pq.pop();
            // cout<<t.r<<" "<<t.c<<"->"<<t.cost<<endl;
            
            for(int i=0;i<4;i++)
            {
                int a=dim[i][0]+t.r,b=dim[i][1]+t.c;
                if(a>=0 and a<n and b>=0 and b<m and vis[a][b]==false)
                {   
                    if(a==n-1 and b==m-1)
                    return t.cost+grid[a][b];
                    
                    vis[a][b]=true;
                    
                    Node temp(a,b,t.cost+grid[a][b]);
                    pq.push(temp);
                }
            }
        }
        
        return -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends