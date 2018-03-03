#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[1600], ug1, ug2, ug3, pre;
    arr[0]=1;
    int p1=0;
    int p2=0;
    int p3=0;
    for(int i=1;i<1501;i++){
        pre=arr[i-1];
        while(arr[p1]*2<=pre)
            p1++;
        while(arr[p2]*3<=pre)
            p2++;
        while(arr[p3]*5<=pre)
            p3++;
        ug1=arr[p1]*2;
        ug2=arr[p2]*3;
        ug3=arr[p3]*5;
        arr[i]=min(ug1, min(ug2, ug3));
    }
    cout<<"The 1500'th ugly number is "<<arr[1499]<<"."<<endl;

    return 0;
}
