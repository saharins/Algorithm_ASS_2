#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int INF = 1e18;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int32_t main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edges;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u, v, c));
    }
    vector<int> dis(n + 1, INF);

    int src,t;
    cin >> src >> t;
    dis[src] = 0; 

    for (int i = 1; i <= n - 1; ++i)
    {
        for (auto j : edges)
        {
            int u = j.u;
            int v = j.v;
            int c = j.c;
            if (dis[u] != INF && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        for (auto ed : edges)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if (dis[u] != INF && dis[u] + c < dis[v])
            {
                cout << "Negative Cycle Detected" ;
                return 0;
            }
        }
    }
    while(t--)
    {
        int dest;
        cin >> dest;

        if(dis[dest] != INF)
        {
            cout << dis[dest] << endl;
        }
        else
        {
            cout << "Not Possible" << endl;
        }
    }
    return 0;
}