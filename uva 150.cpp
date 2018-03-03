#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[20001],i,l,r,pv,h,max,f;
    for(i=0;i<20000;i++)
    a[i]=0;max=0;
    freopen("input.txt", "r", stdin);
    while(scanf("%d%d%d",&l,&h,&r)!=EOF){
        if(l==-1)break;
        for(i=l;i<r;i++){
            if(a[i]<h)a[i]=h;
            if(r>max)max=r;
        }
}
       for(int i=0;)
       printf("\n");


 return 0;
}
