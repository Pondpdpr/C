// https://programming.in.th/task/rev2_problem.php?pid=1109
#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b;
}mem[100005],temp[100005],t;
int n,t1,t2;
long long int ans;
void mix(int low,int mid,int high){
    int i=low,j=mid+1,before=0,now=low,amobe=0;
    while(i<=mid && j<=high)
    {
        if(mem[i].b>mem[j].b)
        {
            before+=i;
            amobe++;
            temp[now++]=mem[i++];
        }
        else
        {
            ans+=before;
            ans+=(amobe*mem[i].a);
            temp[now++]=mem[j++];
        }
    }
    while(i<=mid) temp[now++]=mem[i++];
    while(j<=high)
    {
            ans+=before;
            ans+=(amobe*mem[i].a);
            temp[now++]=mem[j++];
    }
    for(i=low;i<=high;i++)
        mem[i]=temp[i];
}
void split(int low,int high){
    if(low==high) return ;
    int mid=(low+high)/2;
    split(low,mid);
    split(mid+1,high);
    mix(high,mid,high);
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&t1,&t2);
        mem[t2]={t1,t2};
        printf("%d\n",mem[i].b);
    }
    split(1,n);
    printf("%lld",ans);
}
/*
6
2 1
7 6
9 3
18 4
3 2
5 5
*/
