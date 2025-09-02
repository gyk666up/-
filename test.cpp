#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
int a[N];
bool check(int num,int x)
{
    if(num<x)return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(m--){
        int x;cin>>x;
        int l=0,r=n+1;
        while(l+1<r)
       {
            int mid=(l+r)/2;
            if(check(a[mid],x))
             {
              l=mid;
              }
             else r=mid;
        }
        if(a[r]==x)cout<<r<<" ";
        else cout<<"-1 ";
    }
    return 0;
}