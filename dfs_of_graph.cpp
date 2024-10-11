#include<iostream>
#include<vector>
using namespace std;

class graph{
    public:
    vector<vector<int>> adj;
    graph(int n)
    {
        adj.resize(n);
    }

    void addEdge(int u,int v,int direction)
    {
        //direction=0 if undirected and direction=1 if directed
        adj[u].push_back(v);
        if(direction==0)
        {
            adj[v].push_back(u);
        }
    }

    void print()
    {
        for(int i=0;i<adj.size();i++)
        {
            cout<<i<<"-> ";
            for(int j=0;j<adj[i].size();j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void dfs(vector<bool> &visited, int i)
    {
        visited[i]=true;
        cout<<i<<" ";
        for(int j=0;j<adj[i].size();j++)
        {
            if(visited[adj[i][j]]==false)
            {
                dfs(visited,adj[i][j]);
            }
        }
    }

    void dfsTraversal()
    {
        vector<bool> visited(adj.size(),false);
        cout<<"DFS Traversal is as follows: ";
        for(int i=0;i<adj.size();i++)
        {
            if(visited[i]==false)
            {
                dfs(visited,i);
            }
        }
    }


};

int main()
{
    int n,m;
    cout<<"Enter the no of nodes: ";
    cin>>n;
    cout<<"Enter the no of edges: ";
    cin>>m;
    graph g(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u;
        cin>>v;
        g.addEdge(u,v,0);
    }
    g.dfsTraversal();
    return 0;


}
