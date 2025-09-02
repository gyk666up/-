//浮点数二分
#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
bool check1(double x)
{
    if(a*x*x*x+b*x*x+c*x+d<0)return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>b>>c>>d;
    double l=-101,r=101;
    while(r-l>1e-4)
    {
        double mid=(l+r)/2;
        if(check1(mid))l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}