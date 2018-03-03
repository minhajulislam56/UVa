#include<bits/stdc++.h>
using namespace std;

int main()
{
	double p,q,r,s;

	while(cin>>p>>q>>r>>s){

        vector<double> up, down, up2, down2;
        for(int i=p-q+1;i<=p;i++)
            up.push_back(i);
        for(int i=1;i<=q;i++)
            down.push_back(i);

        for(int i=1;i<=s;i++)
            up2.push_back(i);
        for(int i=r-s+1;i<=r;i++)
            down2.push_back(i);

        double upper= 100000000, low=1.0,ans=1.0, ans2=1.0;

        while(true){
            if((up.size()==0 && up2.size()==0) || (down.size()==0 && down2.size()==0))
                break;
            if(ans<=low){
                if(up.size()>0){
                    ans*=up.back();
                    up.pop_back();
                }
                else{
                    ans*=up2.back();
                    up2.pop_back();
                }
            }
            else{
                if(down.size()>0){
                    ans/=down.back();
                    down.pop_back();
                }
                else{
                    ans/=down2.back();
                    down2.pop_back();
                }
            }
        }
        while(up.size()>0){
            ans*=up.back();
            up.pop_back();
        }
        while(down.size()>0){
            ans/=down.back();
            down.pop_back();
        }

        while(up2.size()>0){
            ans*=up2.back();
            up2.pop_back();
        }
        while(down2.size()>0){
            ans/=down2.back();
            down2.pop_back();
        }

        printf("%.5lf\n", ans);

	}

	return 0;
}
