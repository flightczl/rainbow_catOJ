#include<bits/stdc++.h>
using namespace std;
int residx;
int main()
{
	string f=".\\result\\result.ini";
	freopen(f.c_str(),"r",stdin);
	cin>>residx;
	fclose(stdin);
	cin.clear();
	freopen(f.c_str(),"w",stdout);
	cout<<0;
	fclose(stdout);
	cout.clear();	
	for(int i=1;i<=residx;i++)
	{
		string del="del .\\result\\result"+to_string(i)+".txt";
		system(del.c_str());
	}
	return 0;
}
