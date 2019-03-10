#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,val;
}t;
int test,sx,t1,t2,n,m,a[205],ans,che[2];
queue<node>q;
vector<int>way[205];
int main(){
//    freopen("in-Place The Guards.txt","r",stdin);
//    freopen("out-Place The Guards.txt","w",stdout);
    int i,j;
    scanf("%d",&test);
    while(test--)
    {
        ans=0;
//        printf("che=%d\n",ans);
        scanf("%d%d",&n,&m);
        fill(&a[0],&a[204],2);
        for(i=0;i<n;i++) way[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&t1,&t2);
            way[t1].push_back(t2);
            way[t2].push_back(t1);
        }
        for(i=0;i<n;i++)
        {
            t1=1e9;
            che[0]=0;
            che[1]=0;
//            printf("start=%d\n",i);
            if(a[i]==2)
            {
//                printf("che=%d\n",i);
                a[i]=0;
                che[0]++;
                q.push({i,0});
                while(!q.empty())
                {
//                    printf("%d \n",t.x);
                    t=q.front();
                    q.pop();
//                    printf("size=%d\n",way[t.x].size());
                    for(j=0;j<way[t.x].size();j++)
                    {
                        sx=way[t.x][j];
                        if(a[sx]==2)
                        {
                            q.push({sx,(t.val+1)%2});
                            a[sx]=(t.val+1)%2;
                            che[(t.val+1)%2]++;
                        }else if((t.val+1)%2!=a[sx])
                        {
                            ans=-1;
                            break;
                        }
                    }
                    if(ans==-1) break;
                }
                while(!q.empty()) q.pop();
                if(ans!=-1)
                {
                    if(che[0]<t1 && che[0]!=0) t1=che[0];
                    if(che[1]<t1 && che[1]!=0) t1=che[1];
                    ans+=t1;
                }
            }
            if(ans==-1) break;
        }
        printf("%d\n",ans);
    }
}
/*
5 5
0 1
1 2
1 4
2 3
3 4

9 16
0 1
0 2
0 3
0 4
0 6
0 7
1 3
1 8
2 8
3 6
3 7
4 5
4 6
5 6
6 7
6 8

1 0

7 13
0 3
0 4
0 6
1 2
1 3
1 4
1 5
2 3
2 4
2 5
2 6
3 5
3 6

4 2
0 2
0 3
*/
