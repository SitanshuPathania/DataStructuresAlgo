#include<iostream>
#include<vector>
#include<stack>
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
    void dfs(vector<bool> &visited,int i,stack<int> &st)
    {
        visited[i]=true;
        
        for(int j=0;j<adj[i].size();j++)
        {
            if(visited[adj[i][j]]==false)
            {
                dfs(visited,adj[i][j],st);
            }
        }
        st.push(i);//impo step
    }
    void toposort()
    {
        vector<bool> visited(adj.size(),false);
        stack<int> st;
        for(int i=0;i<adj.size();i++)
        {
            if(visited[i]==false)
            {
                dfs(visited,i,st);
            }
        }
        cout<<"Topological Sort: ";
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
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
    g.toposort();
    return 0;
}