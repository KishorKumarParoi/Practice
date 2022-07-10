#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int>graph[N];
bool visited[N];
int color[N];
int time_in[N];
int time_out[N];

int dfs_timer = 0;;

void dfs(int src)
{
    time_in[src] = dfs_timer++;
    color[src] = 1;
    visited[src] = 1;

    for(int v : graph[src])
        if(color[v]==0)
            dfs(v);

    color[src] = 2;
    time_out[src] = dfs_timer++;

}
