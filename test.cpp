#include<bits/stdc++.h>
using namespace std;
const int N=1e2+11;
int g[N][N];
int n;
int width[N];//当前深度有几个结点
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)g[i][j]=0;
            else g[i][j]=0x3f3f3f3f;
        }
    }

    for(int i=1;i<=n-1;i++)
    {
        int u,v;cin>>u>>v;
        g[u][v]=1;
        g[v][u]=2;
    }
    int u,v;cin>>u>>v;
    //距离
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i!=k)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i!=j&&k!=j&&g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
                }
            }
        }
    }
    int Max_depth=0,Max_width=0;

    //这里很聪明的做法
    for(int i=2;i<=n;i++)
    {
        int depth=g[1][i];
        Max_depth=max(Max_depth,depth);
        width[depth]++;
        Max_width=max(width[depth],Max_width);
    }
    cout<<Max_depth+1<<endl;
    cout<<Max_width<<endl;
    cout<<g[u][v];
    return 0;
}