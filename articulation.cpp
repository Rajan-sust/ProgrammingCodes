void art(int u,int pre)
{
    vis[u]=true;
    tim[u]=timer++;
    low[u]=tim[u];
    int cnt=0;
    for(int i=0;i<v[u].size();i++)
    {
        int x=v[u][i];
        if(x==pre)
            continue;
        if(!vis[x])
        {
            cnt++;
            art(x,u);
            low[u]=min(low[u],low[x]);
            if(low[x]>=tim[u] && pre!=0)
                s.insert(u);
        }
        else
            low[u]=min(low[u],tim[x]);
    }
    if(pre==0 && cnt>1)
        s.insert(u);
    return;
}
/* 
In a tree all node without leaf and root all are AP .
At first parent discover then child.
So for being AP a parent node dis[child]>dis[parent]
But it is possible dis[child]<dis[parent] when backedge exixt 
*/