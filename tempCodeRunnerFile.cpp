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

    void cycleDetection()
    {
        queue<int> q;
        vector<int> indegree(adj.size(),0);
        int check=0;
        cout<<"Topological Sort: ";
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indegree[adj[i][j]]++;
            }
        }
        for(int i=0;i<adj.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int j=0;j<adj[node].size();j++)
            {
                indegree[adj[node][j]]--;
                if(indegree[adj[node][j]]==0)
                {
                    q.push(adj[node][j]);
                }
            }
            cout<<node<<" ";
            check++;
        }
        if(check!=adj.size())
        {
            cout<<"Cycle detected in the graph";
        }
        else{
            cout<<"Cycle not present";
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
    g.cycleDetection();
    return 0;


}
