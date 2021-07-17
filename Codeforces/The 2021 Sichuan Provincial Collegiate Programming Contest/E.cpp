#include "bits/stdc++.h"
using namespace std;
const int maxn=1e5+100;
int n,m,T;
vector<int>g[maxn];
int vis[maxn],nxt,cnt;
void dfs(int u){
    nxt++;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]) continue;
        if(v==nxt){
            vis[nxt]=1;
            dfs(nxt);
        }else{
            cnt++;
            vis[nxt]=1;
            dfs(nxt);
            i--;
        }
    }
    if(u==1){
        while(nxt<=n){
            vis[nxt]=1;
            dfs(nxt);
            cnt++;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<=n;i++) {
            g[i].clear();
            vis[i]=0;
        }
        cnt=0,nxt=1;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x<y) g[x].push_back(y);
            if(y<x) g[y].push_back(x);
        }
        for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
        vis[1]=1;
        dfs(1);
        printf("%d\n",cnt);
    }
    return 0;
}