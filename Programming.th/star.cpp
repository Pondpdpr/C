// https://programming.in.th/task/rev2_problem.php?pid=0022
#include <bits/stdc++.h>
using namespace std;
int n,ans[1005][1005],bot,mid,kob;
int main(){
    int i,j;
    scanf("%d",&n);
    if((n%2)==1) kob=n,mid=(n/2);
    else kob=n-1,mid=(n/2)-1;
    for(i=0;i<=mid;i++) ans[i][mid+i]=ans[i][mid-i]=1;
    for(i=0;i<=mid;i++) ans[n-i-1][mid+i]=ans[n-i-1][mid-i]=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<kob;j++) printf("%c",ans[i][j]?'*':'-');
        printf("\n");
    }
}