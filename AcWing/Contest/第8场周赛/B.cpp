#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int maxn=2e5+100;
int n;
LL a[maxn],b[maxn];
map<LL,LL>mp;
int main()
{
    scanf("%d",&n);
    LL mx=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        b[i]=a[i]-i;
        mx=max(mx,a[i]);
    }
    for(int i=1;i<=n;i++){
        mp[b[i]]+=a[i];
    }
    for(auto key:mp){
        mx=max(mx,key.second);
    }
    cout<<mx<<endl;
    return 0;
    
}