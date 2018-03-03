#include<bits/stdc++.h>
using namespace std;
#define MAX 100007
int arr[MAX], cnt[MAX], fapp[MAX];
/*void segment(int node, int b, int e)
{
    if(b==e){
        arr[node]=cnt[arr[b]];
        return;
    }
    int left,right,mid;
    left=node*2+1;
    right=left+1;
    mid=(b+e)/2;
    segment(left,b,mid);
    segment(right,mid+1,e);
    arr[node]=max(arr[left],arr[right]);
}*/
void segment(int nodeNumber , int s, int e ){
 if( s == e ) {
  arr[ nodeNumber ] = cnt[ arr[ s ] ];
  return ;
 }
 int md = ( s + e ) / 2;
 int n1 = ( 2 * nodeNumber ) + 1;
 int n2 = n1 + 1;
 segment( n1, s , md ) ;
 segment( n2, md + 1, e );
 if( arr[ n1 ] >= arr[ n2 ] ) arr[ nodeNumber ] = arr[ n1 ];
 else arr[ nodeNumber ] = arr[ n2 ];
}

int query(int node, int b, int e, int i, int j)
{
    int res;
    if(i>e || j<b)
        return -1;
    if(b>=i && e<=j)
        return arr[node];
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    int v1=query(left,b,mid,i,j);
    int v2=query(right,mid+1,e,i,j);
    if(v1==-1) res=v2;
    if(v2==-1) res=v1;
    res=max(v1,v2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    while(cin>>n>>q && n){
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr[i]+=100000;
            cnt[arr[i]]++;
            //cout<<arr[i]<<' '<<cnt[arr[i]]<<endl;
            if(cnt[arr[i]]==1){
                fapp[arr[i]]=i;
            }
        }
        segment(0,0,n-1);
        while(q--){
            int a,b;

            cin>>a>>b;
            a--,b--;

            int v1,v2,ans;
            v1=cnt[arr[a]]-a+fapp[a];
            v2=b-fapp[arr[b]]+1;
            cout<<v1<<" "<<v2<<endl;
            ans=min(v1,v2);
            int r1=fapp[arr[a]]+cnt[arr[a]];
            int r2=fapp[arr[b]]-1;
            if(r1<=r2){
                int xx=query(0,0,n-1,r1,r2);
                ans=max(ans,xx);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
