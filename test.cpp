#include<bits/stdc++.h>
using namespace std;
const int N=302;
char g[N][N];
int n,m;
int s1,s2,e1,e2;
typedef pair<int,int>PII;
map<char,vector<PII>>mp;
int dist[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int bfs(int x,int y)
{
    dist[x][y]=0;
    queue<PII>q;
    q.push({x,y});
    while(q.size())
    {
        int x=q.front().first,y=q.front().second;
        q.pop();
        if(x==e1&&y==e2)
        {
            return dist[e1][e2];
        }
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m)continue;
            //if(dist[xx][yy]<dist[x][y]+1)continue;
            if(g[xx][yy]=='#')continue;

            //dist[xx][yy]=dist[x][y]+1;
            if(isupper(g[xx][yy]))
            {
                PII other;
                for(auto t:mp[g[xx][yy]])
                {
                    if(t.first!=xx||t.second!=yy)
                    {
                        other=t;
                        break;
                    } 
                }xx=other.first,yy=other.second;
            }
            if(dist[xx][yy]>dist[x][y]+1)
            {
                dist[xx][yy]=dist[x][y]+1;
                q.push({xx,yy});
            }
            

        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='@')
            {
                s1=i,s2=j;
            }
            else if(g[i][j]=='=')
            {
                e1=i,e2=j;
            }
            else if(isupper(g[i][j]))
            {
                mp[g[i][j]].push_back({i,j});
            }
        }
    }
    memset(dist,0x3f,sizeof dist);
    cout<<bfs(s1,s2);
    
    return 0;
}