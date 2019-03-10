// https://codeforces.com/problemset/problem/505/C
#include <bits/stdc++.h>
using namespace std;
int n,d,a[32005],t1,t2,ma,ans,nc,nw;
struct from{
    int x,val;
};
vector<from>v[32005];
int main(){
    int i,j,k,l;
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++) scanf("%d",&t1),a[t1]++,ma=max(ma,t1);
    v[d].push_back({d,a[d]});
    for(i=d;i<=ma;i++)
    {
        for(j=0;j<v[i].size();j++)
        {
//            printf("at %d from %d have %d to",i,(v[i][j].x),v[i][j].val);
            for(k=-1;k<=1;k++)
            {
                t2=0;
                if(k==-1 && v[i][j].x==1) continue;
                nw=(i+v[i][j].x+k);
                nc=(v[i][j].val+a[nw]);
                for(l=0;l<v[nw].size();l++)
                    if((v[nw][l].x==(v[i][j].x+k)) && (v[nw][l].x+2==(v[i][j].x+k)) && (v[nw][l].x-2==(v[i][j].x+k)) && v[nw][l].val>=nc)
                    {
                        t2=1;
                        break;
                    }
                if(t2) continue;
                v[nw].push_back({(v[i][j].x+k),nc});
                ans=max(ans,nc);
            }
//            printf("\n");
        }
    }
//    for(i=0;i<=ma;i++)
//    {
//        printf("a[%d]=%d have",i,a[i]);
//        for(j=0;j<v[i].size();j++) printf(" %d",(i-v[i][j].x));
//        printf("\n");
//    }
    printf("%d",ans);
}
