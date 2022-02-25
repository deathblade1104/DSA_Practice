// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{  
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>cost(V,-1);
        
        auto mycomp = [](pair<int,int>a,pair<int,int>b)
        {
            if(a.second!=b.second)
                return (a.second>b.second);
                
            return (a.first>b.first);
        };
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(mycomp)>pq(mycomp);
        pq.push({S,0});
        int i=0;
        
        while(pq.size()>0)
        {
            pair<int,int>p=pq.top();
            pq.pop();
            
            if(cost[p.first]==-1)
            {
                cost[p.first]=p.second;
                vector<vector<int>>neighbours=adj[p.first];
                
                for(int i=0;i<neighbours.size();i++)
                {
                    int nv=neighbours[i][0],nc=neighbours[i][1]+p.second;
                    if(cost[nv]==-1)
                    pq.push({nv,nc});
                }
            }
        }
        
        return cost;
        
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends