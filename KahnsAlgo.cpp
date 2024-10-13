#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class graph{
    public:
    vector<vector<int>> adj;
    graph(int n)
    {
        adj.resize(n);
    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);//Only valid for directed graph so no need for direction
    }
    void topoSort()
    {
        vector<int> indegree(adj.size(),0);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        cout<<"Topological Sort: ";
        for(int i=0;i<adj.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int check=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cout<<node<<" ";
            check++;
            for(int j=0;j<adj[node].size();j++)
            {
                indegree[adj[node][j]]--;
                if(indegree[adj[node][j]]==0)
                {
                    q.push(adj[node][j]);
                }
            }
        }
        if(check!=adj.size())
        {
            cout<<"Cycle existsi= in the graph";
        }
    }
};

int main()
{
    int n;
    int m;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    graph g(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u;
        cin>>v;
        g.addEdge(u,v);
    }
    g.topoSort();
    return 0;
}