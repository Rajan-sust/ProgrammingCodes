#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cout<<#x<<" is "<<(x)<<'\n'
 
 
int aray[100005],tree[4*100005];
 
 
void build(int node,int l,int r)
{
    if(l==r){
        tree[node] = aray[l];
        return;
    }
    int mid = (l+r)>>1;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
 
    tree[node] = min(tree[2*node],tree[2*node+1]);
}
 
 
 
int query(int node,int L,int R,int l,int r)
{
    if(R<l or r<L) return numeric_limits<int>::max();
 
    if(l<=L and R<=r)
        return tree[node];
 
    int mid = (L+R)>>1;
 
    return min(query(2*node,L,mid,l,r),query(2*node+1,mid+1,R,l,r));
}
 
int main()
{
    int test,kase = 1;
    scanf("%d",&test);
 
 
    while(test--){
 
        printf("Case %d:\n",kase++);
 
        int n,q;
        scanf("%d %d",&n,&q);
 
        for(int i=1;i<=n;i++)scanf("%d",&aray[i]);
 
        build(1,1,n);
 
        while(q--)
        {
            int l,r;
            scanf("%d %d",&l,&r);
 
 
            printf("%d\n",query(1,1,n,l,r));
        }
    }  
    return 0;
}
