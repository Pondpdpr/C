// https://www.codecube.in.th/task/119
#include <bits/stdc++.h>
using namespace std;
struct mo{
    int val,pos;
    bool operator <(mo a)const
    {
        return a.val>val;
    }
};
priority_queue<mo>heap;
int n,m,a[100][10000],ma,t2=1,k;
int main(){
    int i,j,l,t;
    scanf("%d%d%d",&n,&m,&k);
    t2=max(t2,k);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<n;i++)
    {
        while(!heap.empty())
        {
            //printf("TOP = %d(%d)\n",heap.top().val,heap.top().pos);
            heap.pop();
        }
        for(j=0;j<m;j++)
        {
            if(j==0)for(l=0;l<=k;l++)heap.push({a[i-1][j+l],j+l});
            else if(j+k<m)heap.push({a[i-1][j+k],j+k});
            while(1)
            {
                if(heap.top().pos >= j-k && heap.top().pos <= j+k)
                {
                    //printf("top = %d(%d)\n",heap.top().val,heap.top().pos);
                    a[i][j]+=heap.top().val;
                    break;
                }
                else
                {
                    //printf("pop %d\n",heap.top().val);
                    heap.pop();
                }
            }
        }
        /*for(j=0;j<m;j++)
            printf("%d ",a[i][j]);
        printf("\n");*/
    }

    /*if(m%2==0)
    {
        if(k==0)k=1;
        for(i=m/2-k;i<=m/2+k-1;i++)
            ma=max(ma,a[n-1][i]);
    }else
    {
        for(i=m/2-k;i<=m/2+k;i++)
            ma=max(ma,a[n-1][i]);
    }*/
    for(i=0;i<m;i++)ma=max(ma,a[n-1][i]);
    printf("%d",ma);
}
/*
8 5 2
0 0 5 4 0
2 0 7 0 0
0 8 0 3 0
9 0 0 0 0
0 0 1 9 0
0 0 0 0 9
0 0 0 0 9
9 0 1 0 0
*/
