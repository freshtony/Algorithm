#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int main()
{
    ll a,b;
    while(cin>>n>>k)
    {
        a=n/k;
        if(a&1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
