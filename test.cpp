#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;cin>>s;
    int n=s.size();
    vector<int>matched(n+1,-1);
    stack<pair<char,int>>stk;
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(c=='('||c=='[')
        {
            stk.push({c,i});
        }
        else 
        {
            if(stk.size())
            {
                auto t=stk.top();

                if(c==')'&&t.first=='('||c==']'&&t.first=='[')
                {
                    matched[i]=t.second;
                    matched[t.second]=i;
                    stk.pop();//已经匹配好 
                }
                //如何没有对应的左括号vector对应仍然保持-1
            }
        }
    }
    string res="";
    for(int i=0;i<n;i++)
    {
        if(matched[i]!=-1)
        {
            res+=s[i];
        }
        else
        {
            //如果是左括号的话 先加本身再加右括号 注意不同的左括号对应不同的右括号
            if(s[i]=='('||s[i]=='[')
            {
                res+=s[i];
                res+=(s[i]=='('?')':']');
            }
            else
            {
                res+=(s[i]==']'?'[':'(');
                res+=s[i];
            }
        }
    }
    cout<<res;
    return 0;
}
