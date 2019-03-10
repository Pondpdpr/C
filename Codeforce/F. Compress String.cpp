// https://codeforces.com/problemset/problem/1121/F
#include <bits/stdc++.h>
using namespace std;
int n,a,b,mem[5005][5005],ans=1e9;
string s;
int f(int x,int y){
    if(x==0 && y==n-1) return 0;
    if(!mem[x][y])
    {
        mem[x][y]=1e9;
        int siz=y-x+1;
        string to;
        for(int i=1;i<=siz && (x-i)>=0;i++)
        {
            to=s.substr(x-i,i);
            if(i==1) mem[x][y]=min(mem[x][y],f(x-i,y)+a);
            for(int j=x;j<=(y-i+1);j++)
                if(to==s.substr(j,i))
                {
                    mem[x][y]=min(mem[x][y],f(x-i,y)+b);
                    break;
                }
        }
        for(int i=1;i<=siz && (y+i)<n;i++)
        {
            to=s.substr(y+1,i);
            if(i==1) mem[x][y]=min(mem[x][y],f(x,y+i)+a);
            for(int j=x;j<=(y-i+1);j++)
                if(to==s.substr(j,i))
                {
                    mem[x][y]=min(mem[x][y],f(x,y+i)+b);
                    break;
                }
        }
    }
    return mem[x][y];
}
int main(){
    cin >> n >> a >> b;
    cin >> s;
    for(int i=0;i<n;i++) ans=min(ans,f(0,0));
    cout << ans+a;
}
