#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int main()
{
	fstream file("judge.ini");
	int i;
	file>>i;
	string out="status"+to_string(i)+".ini";
	Sleep(1000);
	system("taskkill /F /IM temp.exe");
	freopen(out.c_str(),"w",stdout);
	cout<<1;
	return 0;
}
