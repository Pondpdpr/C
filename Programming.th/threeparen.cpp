// https://programming.in.th/task/rev2_problem.php?pid=1121
#include <bits/stdc++.h>
using namespace std;
char a[10][100000];
stack<char>st;
int main(){
    int che[]={1,1,1,1,1,1,1,1,1,1};
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",&a[i]);
    for(i=0;i<n;i++)
    {
        int N = strlen(a[i]);
        for(j=0;j<N;j++)
        {
            if(a[i][j] == '(' || a[i][j] == '[' || a[i][j] == '{') st.push(a[i][j]);
            else
            {
                if(!st.empty())
                {
                    if(a[i][j] == ')' && st.top() == '(' ) st.pop();
                    else if(a[i][j] == '}' && st.top() == '{' ) st.pop();
                    else if(a[i][j] == ']' && st.top() == '[' ) st.pop();
                    else che[i]=0;
                }
                else che[i]=0;
            }
            if(che[i]==0) break;
        }
        if(!st.empty()) che[i]=0;
            if(che[i]==0)
            {
                while(!st.empty()) st.pop();
            }
    }
    for(i=0;i<n;i++)
        if(che[i]==0) printf("no\n");
        else printf("yes\n");
}
/*
3
(())
(()))(()
(()())()
*/
/*
3
({])[]
[({}])
()[{}()]
*/
