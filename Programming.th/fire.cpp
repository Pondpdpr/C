// https://programming.in.th/task/rev2_problem.php?pid=1152
#include <bits/stdc++.h>
using namespace std;
int n,t2,ma;
priority_queue<int>heap;
vector<int>from[2005];
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&t2);
            from[i+j].push_back(t2);
        }
    for(i=(n-1)*2;i>0;i--)
    {
        for(j=0;j<from[i].size();j++)
        {
            heap.push(from[i][j]);
        }
        ma+=heap.top();
        heap.pop();
    }
    printf("%d",ma);
}
/*
5
50 36 10 13 2
17 5 16 42 41
49 12 38 9 25
18 4 36 31 11
30 6 3 46 50
*/
