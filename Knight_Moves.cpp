#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e2 + 5;

int n, m , ki,kj,pi,pj;
int vis[N][N];
int drow[] = {1,1,-1,-1,2,-2,2,-2};
int dcol[] = {2,-2,2,-2,1,1,-1,-1};

bool is_valid(int i,int j)
{
    return (i>=0 && i<n && j>=0 && j <m && !vis[i][j]);
}
void bfs()
{
    queue<pair<int,int>> q;
    if(ki == pi && kj == pj)
    {
        cout << 0 << endl;
        return;
    }

    q.push({ki,kj});
    vis[ki][kj] = true;
    int ans = 0;

    while(!q.empty())
    {
        int size = q.size();
        ans++;

        while(size--)
        {
            pair<int,int> crnt = q.front();
            q.pop();

            int x = crnt.first;
            int y = crnt.second;

            for(int i=0;i<8;i++)
            {
                int nx = x + drow[i];
                int ny = y + dcol[i];

                if(nx == pi && ny == pj)
                {
                    cout << ans << endl;
                    return;
                }
                if(is_valid(nx,ny))
                {
                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }
    cout << -1 << endl;
}
int32_t main()
{
    int t;
    cin >> t;

    while(t--)
    {
        for(int i=0;i<=N;i++)
        {
            for(int j = 0;j<=N;j++)
            {
                vis[i][j] = false;
            }
        }
        cin >> n >> m;
        cin >> ki >> kj >> pi >> pj;

        bfs();
    }
    return 0;
}