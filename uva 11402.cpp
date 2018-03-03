#include<bits/stdc++.h>
using namespace std;
#define MAX 1024007
int tree[4*MAX], lazy[4*MAX];
string mst;
void segment(int node, int b, int e)
{
    if(b==e){
        tree[node]=mst[b]-'0';
        //cout<<"Testing: "<<node<<" "<<arr[b]<<" "<<b<<endl;
        return;
    }
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    segment(left,b,mid);
    segment(right,mid+1,e);
    //cout<<node<<" "<<left<<" "<<tree[left]<<" "<<right<<" "<<tree[right]<<endl;
    tree[node]=tree[left]+tree[right];
}
void update(int node,int b, int e, int l, int r, int mark)
{
    if(lazy[node]){
        if(mark==1)
            tree[node]+=(e-b+1);
        else if(mark==2)
            tree[node]=0;
        else
            tree[node]=(e-b+1)-tree[node];
        //tree[node]+=(e-b+1)*lazy[node];
        if(b!=e){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(l>e || r<b || b>e)
        return;
    if(b>=l && e<=r){
        if(mark==1)
            tree[node]+=(e-b+1);
        else if(mark==2)
            tree[node]=0;
        else
            tree[node]=(e-b+1)-tree[node];
        //tree[node]+=(e-b+1)*num;
        if(b!=e){
            lazy[node*2]+=1;
            lazy[node*2+1]+=1;
        }
        return;
    }

    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    update(left,b,mid,l,r,mark);
    update(right,mid+1,e,l,r,mark);
    tree[node]=tree[left]+tree[right];
}
int query(int node, int b, int e, int l, int r)
{
    if(l>e || r<b || b>e)
        return 0;
    if(lazy[node]){
        tree[node]=(e-b+1);
        if(b!=e){
            lazy[node*2]=1;
            lazy[node*2+1]=1;
        }
        lazy[node]=0;
    }
    if(b>=l && e<=r)
        return tree[node];
    int left,right,mid;
    left=node*2;
    right=node*2+1;
    mid=(b+e)/2;
    return query(left,b,mid,l,r)+query(right,mid+1,e,l,r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc,ca=1;
    cin>>tc;
    while(tc--){
        int m;
        mst="f";
        cin>>m;
        while(m--){
            int t;
            string st;
            cin>>t>>st;
            for(int i=0;i<t;i++){
                mst+=st;
            }
        }
        int len=mst.length();
        cout<<len<<endl;
        segment(1,1,len-1);
        //cout<<tree[5]<<" "<<tree[6]<<endl;
        for(int i=1;i<=10;i++)
            cout<<tree[i]<<" ";
        cout<<endl<<"jfkd"<<endl;
        int qu;
        cin>>qu;
        for(int i=0;i<qu;i++){
            int a,b;
            char ch;
            cin>>ch>>a>>b;
            if(ch=='F'){
                update(1,1,len-1,a+1,b+1,1);
                for(int i=1;i<=10;i++)
                    cout<<tree[i]<<" ";
                cout<<endl<<"jfkd"<<endl;
                //cout<<tree[5]<<" "<<tree[6]<<endl;
            }
            else if(ch=='E'){
                update(1,1,len-1,a+1,b+1,2);
                for(int i=1;i<=10;i++)
                    cout<<tree[i]<<" ";
                cout<<endl<<"jfkd"<<endl;
            }
            else if(ch=='I'){
                update(1,1,len-1,a+1,b+1,3);
                for(int i=1;i<=10;i++)
                    cout<<tree[i]<<" ";
                cout<<endl<<"jfkd"<<endl;
            }
            else{
                cout<<query(1,1,len-1,a+1,b+1)<<endl;
            }
        }
    }



    return 0;
}
