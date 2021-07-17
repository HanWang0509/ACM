#include "bits/stdc++.h"
using namespace std;
const int maxn=2e5+10;
int n,m,k,p[maxn],dis[maxn],vis[maxn],cnt[maxn];
vector<int>g[maxn];
void BFS(int s,int t){
    queue<pair<int,int>>que;
    que.push(make_pair(t,0));
    dis[t]=0;
    while(!que.empty()){
        auto info = que.front(); que.pop();
        int u=info.first;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v:g[u]){
            if(!vis[v]&&dis[v]>dis[u]+1) dis[v]=dis[u]+1,cnt[v]=1,que.push(make_pair(v,dis[v]));
            else if(dis[v]==dis[u]+1) cnt[v]++;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
    for(int i=1;i<=m;i++){
        int x,y; scanf("%d%d",&x,&y);
        g[y].push_back(x);
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++) scanf("%d",&p[i]);
    int s=p[1],t=p[k];
    BFS(s,t);
    int mx=0,mi=0;
    for(int i=1;i<k;i++){
        if(dis[p[i]]!=dis[p[i+1]]+1) mx++,mi++;
        else if(cnt[p[i]]>1) mx++;
    }
    printf("%d %d\n",mi,mx);
    return 0;
}