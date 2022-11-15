#include <bits/stdc++.h>
using namespace std;
int main(){
	string S, S1 = "AB", S2 = "BA"; cin>>S;

	int a = S.find(S1); /// Na thakle -1 return kore, thakle first index retrun kore
	int b = S.find(S2, a + 2);
	cout<<a<<' '<<b<<'\n';
	if (a > -1 && b > -1)
	{
        cout<<"YES"<<endl;
        return 0;
    }
    a = S.find(S2);
    b = S.find(S1, a+2);
    if (a > -1 && b > -1)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;


	return 0;
}
