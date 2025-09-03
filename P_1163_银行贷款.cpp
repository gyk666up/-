#include<bits/stdc++.h>
using namespace std;
#define int long long
int w0,w,m;
bool check(double x)
{
    double ans=w0+w*m;//总共要还的钱
    double a=ans/w0;
    if(pow(1+x,m)<=a)return true;
    else return false;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>w0>>w>>m;
    //应该枚举利率
    double l=0,r=3.01;
    while(r-l>1e-5)
    {
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<fixed<<setprecision(1)<<100*l<<endl;
    return 0;
}