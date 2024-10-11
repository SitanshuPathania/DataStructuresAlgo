#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class graph{
    public:
    vector<vector<int>> adj;
    graph(int n)
    {
        adj.resize(n);
    }
    void addEdge(int u,int v,int direction)
    {
        //If direction=0, then undirected and if direction=1 then directed
        adj[u].push_back(v);
        if(direction==0)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for(int i=0;i<adj.size();i++)
        {
            cout<<i<<"->";
            for(int j=0;j<adj[i].size();j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(vector<vector<int>> &adj,vector<bool> &visited, int i)
    {
        queue<int> q;
        q.push(i);
        visited[i]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cout<<node<<" ";
            visited[node]=true;
            for(int j=0;j<adj[node].size();j++)
            {
                if(visited[adj[node][j]]==false)
                {
                    q.push(adj[node][j]);
                }
                
            }
        }
    }

    void bfsTraversal()
    {
        vector<bool> visited(adj.size(),false);
        cout<<"BFS Traversal of graph: ";
        for(int i=0;i<adj.size();i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                bfs(adj,visited,i);
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
    g.printGraph();
    int start=0;
    g.bfsTraversal();
    return 0;
}
