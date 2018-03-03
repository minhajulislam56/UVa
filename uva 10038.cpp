#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    int number[3010];
    int n;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>number[i];
        bool mark=true;
        set <int> myset;
        int tmp=n-1;
        for(int i=0;i<n-1;i++,tmp--){
            int test=abs(number[i]-number[i+1]);
            myset.insert(test);
        }
        if(myset.size()!=n-1)
            mark=false;
        else{
            for(int i=1;i<n;i++){
                if(!myset.count(i))
                    mark=false;
            }
        }
        if(mark)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
    }

    return 0;
}

