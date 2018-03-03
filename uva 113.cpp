#include<bits/stdc++.h>
using namespace std;

int main() {
	double base, num;

	while(scanf("%lf\n%lf",&base,&num)!=EOF){
		printf("%.0lf\n",pow(num,base));
	}

	return 0;
}
