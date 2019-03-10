#include <bits/stdc++.h>
using namespace std;
int t1,t2,x,y,test,n,m,h[30005],amo[30005],ma;
int head(int x){
    if(x==h[x]) return x;
    else return h[x]=head(h[x]);
}
int main(){
    scanf("%d",&test);
    while(test--)
    {
        int i;
        ma=1;
        scanf("%d%d",&n,&m);
        for(i=0;i<=n;i++)
        {
            h[i]=i;
            amo[i]=1;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            t1=head(x);
            t2=head(y);
            if(t1!=t2)
            {
//                printf("h1=%d h2=%d\nt1=%d t2=%d\n",t1,t2,amo[t1],amo[t2]);
                amo[t2]+=amo[t1];
//                printf("t1=%d t2=%d\n",amo[t1],amo[t2]);
                h[t1]=y;
                ma=max(ma,amo[t2]);
            }
        }
        printf("%d\n",ma);
    }
}
/*
2
3 2
1 2
2 3
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 1
1 2
9 10
8 9
*/
