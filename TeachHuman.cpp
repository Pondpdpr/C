#include<bits/stdc++.h>

using namespace std;


struct net
{
    int val,x;
    bool operator < (net t) const{
        return val > t.val;
    }
};

vector<net> v[100005];
priority_queue<net> pq;
bool check[100005];
int a[100005],ans = 0;

int main()
{
    int n,m,i,t1,t2;
    cin >> n;
    for(i=1;i<=n;i++)
    {
      cin >> a[i];
    }
    cin >> m;
    for(i=0;i<m;i++)
    {
        cin >> t1 >> t2;
        v[t1].push_back({a[t1]+a[t2],t2});
        v[t2].push_back({a[t1]+a[t2],t1});
    }
    pq.push({0,1});
    net l;
    while(!pq.empty())
    {
        l = pq.top();
        pq.pop();
        if(check[l.x]) continue;
        check[l.x] = true;
        for(i=0;i<v[l.x].size();i++)
        {
            //cout << check[v[l.x][i].x] << endl;
            if(!check[v[l.x][i].x])
            {
                pq.push({v[l.x][i].val,v[l.x][i].x});
        // cout << l.x << " " << v[l.x][i].x << endl;
            }
        }
        ans += l.val;
    }
    cout << ans;
}