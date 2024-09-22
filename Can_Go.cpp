#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int INF = 1e18;
const int N = 1e3 + 5;

vector<pair<int, int>> v[N]; 
int dis[N];

class cmp 
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b) 
    {
        return a.second > b.second;
    }
};

void dijkstra(int src) 
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    pq.push({src, 0LL});
    dis[src] = 0LL;

    while (!pq.empty()) 
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        
        int node = parent.first;
        int cost = parent.second;

        for (pair<int, int> child : v[node]) 
        {
            int childNode = child.first;
            int childCost = child.second;
            
            if (cost + childCost < dis[childNode]) 
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int32_t main() 
{
    int n, e;
    cin >> n >> e; 

    while (e--) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c}); 
    }

    int source;
    cin >> source;

    for (int i = 1; i <= n; i++) 
    {
        dis[i] = INF;
    }

    dijkstra(source);

    int t;
    cin >> t;

    while (t--) 
    {
        int dst, mx_Cst;
        cin >> dst >> mx_Cst;
        if (dis[dst] == INF)
        {
            cout << "NO" << endl;
        }
        else if (dis[dst] <= mx_Cst) 
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}