#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

int n, m;

int dx[4] = {-1, 0, 1, 0}; // row er move
int dy[4] = {0, 1, 0, -1}; // col er move

bool valid(int x, int y)
{
    // যদি সেলটি গ্রিডের মধ্যে থাকে এবং '.' হয়, তাহলে সেটি valid
    if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + dx[i]; // children er row
        int cj = sj + dy[i]; // children er column

        if (valid(ci, cj) && vis[ci][cj] == false)
        {
            vis[ci][cj] = true;
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;

    // গ্রিড ইনপুট
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    // শুরু এবং গন্তব্য সেলের ইনডেক্স ইনপুট
    int start_i, start_j, end_i, end_j;
    cin >> start_i >> start_j >> end_i >> end_j;

    // যদি শুরু বা গন্তব্য সেল '-' হয়, তাহলে সরাসরি NO প্রিন্ট
    if (graph[start_i][start_j] == '-' || graph[end_i][end_j] == '-')
    {
        cout << "NO" << endl;
        return 0;
    }

    // DFS চালানো শুরু সেল থেকে
    dfs(start_i, start_j);

    // যদি গন্তব্য সেল ভিজিট করা হয়ে থাকে তাহলে YES, না হলে NO
    if (vis[end_i][end_j])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
