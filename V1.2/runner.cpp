#include<bits/stdc++.h>
using namespace std;
int i;
string pid;
int main()
{
	ifstream inifile("judge.ini");
	inifile>>i>>pid;
	inifile.close();
	string data_route=".\\data\\"+pid+'\\';
	string file=data_route+to_string(i),ifile=file+".in",ofile=file+".out",afile=file+".ans";
	ifstream inf(file+".in");
	freopen(ifile.c_str(),"r",stdin);
	freopen(ofile.c_str(),"w",stdout);
	system(".\\code\\temp.exe");
	fclose(stdin),fclose(stdout);
	cout.clear();
	system("taskkill /F /IM TLE.exe");
	return 0;
}
