// https://codeforces.com/problemset/problem/1016/C
#include <bits/stdc++.h>
using namespace std;
int n,mx,my,ma,a[2][300005],cx=1,cy,x,y;
bool t1;
long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    cin >> n;
    for(i=0;i<2;i++)
        for(j=0;j<n;j++)
        {
            cin >> a[i][j];
            if(a[i][j] > ma && (i!=0 || j!=0))
            {
                ma=a[i][j];
                mx=i;
                my=j;
            }
        }
    for(i=1;i<(n*2);i++)
    {
//        printf("at %d %d\n",x,y);
        if(!t1 && (x+1)%2==mx && (y==my || y+1==my)) t1=true,cx=0,cy=1;
        if(!t1)
        {
            x=(x+cx)%2;
            y=y+cy;
            cx=!cx;
            cy=!cy;
            ans+=(1ll*a[x][y]*i);
        }
        else
        {
            y=y+cy;
            if(y==n)
            {
                cy=-1;
                x=(x+1)%2;
                y=n-1;
            }
            ans+=(1ll*a[x][y]*i);
        }
    }
    cout << ans;
}
