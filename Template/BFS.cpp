//4-2-2020
#include<bits/stdc++.h>
using namespace std;

#define uu first
#define vv second
#define pii pair<int,int>

int fx[]= {1,-1,0,0};                         //Direction Array
int fy[]= {0,0,1,-1};

int cell[100][100];                         //cell[x][y]=1 hole cell Ta Block
int dis[100][100],vis[100][100];
int row,col;

void bfs(int sx,int sy)                     //source node is in [sx][sy] cell
{
    memset(vis,0,sizeof(vis));
    vis[sx][sy]=1;

    queue<pii>q;                               //A queue containing STL pairs
    q.push(pii(sx,sy));

    while(!q.empty())
    {
        pii top = q.front();
        q.pop();

        for(int k=0; k<4; k++)
        {
            int tx = top.uu + fx[k];
            int ty = top.vv + fy[k];             //Neighbor cell [tx][ty]

            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1 && vis[tx][ty]==0)
            {
                vis[tx][ty]=1;
                dis[tx][ty] = dis[top.uu][top.vv]+1;

                //Pushing a new pair in the queue
                q.push(pii(tx,ty));
            }
        }
    }
}


int main()
{

    return 0;
}
