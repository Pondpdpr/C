// https://www.codecube.in.th/task/41
#include <bits/stdc++.h>
using namespace std;
int n,t,a[1000005],mid1=1,mid2=1,bot1,bot2,top1=1e9,top2=1e9,ma;
int ex(int x){
		if(x<ma) return t-1;
		int i,ene=0,j=0,k=0;
		for(i=0;i<n;i++)
		{
			if(ene<a[i])ene=x,k++;
			ene-=a[i];
		}
	return k;
}
int main(){
	int i,j;
	scanf("%d%d",&n,&t);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		ma=max(a[i],ma);
	}
	if(t==1)
	{
		printf("-1");
		return 0;
	}
	bot1=ma;
	bot2=ma;
	while(1)
	{
		mid1=(bot1 + top1)/2;
		if(ex(mid1-1)!=t && ex(mid1)==t) break;
		else if(ex(mid1)<t || ex(mid1)==t) top1=mid1-1;
		else if(ex(mid1)>t) bot1=mid1+1;
		//printf("mid1 = %d\n",mid1);
	}
	while(1)
	{
	   mid2=(bot2 + top2)/2;
		if(ex(mid2-1)==t && ex(mid2)!=t) break;
		else if(ex(mid2)<t) top2=mid2-1;
		else if(ex(mid2)>t || ex(mid2)==t) bot2=mid2+1;
		//printf("mid2 = %d\n",mid2);
	}
	printf("%d",mid2-mid1);
}
/*
4 1
2 5 9 12
*/
