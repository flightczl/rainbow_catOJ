#include<bits/stdc++.h>
#include<windows.h>
#define cls system("cls")
using namespace std;
string pid;
int datanum,score,stime[1000000];
string res[1000000];
void color(int x)
{
	if(x>=0&&x<=15)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
int main()
{
	fstream input("input.ini");
	input>>pid;
	input.close();
	string data_route=".\\data\\"+pid+'\\',config_route=data_route+"config.ini";
	ifstream ini(config_route);
	ini>>datanum;
	ini.close();
	cout<<"Compiling...\n";
	bool complie_status=system("g++ .\\code\\temp.cpp -o .\\code\\temp.exe -O2 -pipe -std=c++14 -s -static");
	if(complie_status)
	{
		cls;
		for(int i=1;i<=datanum;i++)res[i]="Compile Error";
		goto __;
	}
	cout<<"Judging...\n";
	for(int i=1;i<=datanum;i++)
	{
		string file=data_route+to_string(i),ifile=file+".in",ofile=file+".out",afile=file+".ans";
		string fc="fc "+ofile+' '+afile,del="del "+ofile;
		ofstream inifile("judge.ini");
		inifile<<i<<' '<<pid;
		inifile.close();
		fstream out("status"+to_string(i)+".ini");
		out<<0;
		int st=clock();
		system("start .\\runner.exe");
		system(".\\TLE.exe");
		stime[i]=clock()-st;
		if(!system("taskkill /F /IM WerFault.exe"))
		{
			res[i]="Runtime Error";
			system(del.c_str());
			cls;
			continue;
		}
		fstream status("status"+to_string(i)+".ini");
		int _status=0;
		status>>_status;
		status<<0;	
		if(_status)
		{
			res[i]="Time Limit Exceeded";
			system(del.c_str());
			continue;
		}	
		int fc_res=system(fc.c_str());
		if(fc_res==0)res[i]="Accepted";
		else res[i]="Wrong Answer";
		system(del.c_str());
		cls;
	}
	__:cls;
	for(int i=1;i<=datanum;i++)
	{
		string delini="del .\\status"+to_string(i)+".ini";
		system(delini.c_str());
		if(res[i]=="Accepted")score+=100/datanum;
	}
	cls;
	cout<<"pid:"<<pid<<'\n';
	cout<<"score:"<<score<<'\n';
	for(int i=1;i<=datanum;i++)
	{
		if(res[i]=="Accepted")color(10),cout<<'#'<<i<<':'<<res[i];
		if(res[i]=="Compile Error")color(14),cout<<'#'<<i<<':'<<res[i];
		if(res[i]=="Wrong Answer")color(12),cout<<'#'<<i<<':'<<res[i];
		if(res[i]=="Runtime Error")color(13),cout<<'#'<<i<<':'<<res[i];
		if(res[i]=="Time Limit Exceeded")color(15),cout<<'#'<<i<<':'<<res[i];
		cout<<' '<<stime[i]<<"ms\n";
		color(1000);
	}
	int residx;
	string f=".\\result\\result.ini";
	freopen(f.c_str(),"r",stdin);
	cin>>residx;
	fclose(stdin);
	cin.clear();
	freopen(f.c_str(),"w",stdout);
	cout<<++residx;
	fclose(stdout);
	cout.clear();	
	string resfile=".\\result\\result"+to_string(residx)+".txt";
	freopen(resfile.c_str(),"w",stdout);
	cout<<"pid:"<<pid<<'\n';
	cout<<"score:"<<score<<'\n';
	for(int i=1;i<=datanum;i++)cout<<'#'<<i<<':'<<res[i]<<' '<<stime[i]<<"ms\n";
	fclose(stdout);
	cout.clear();
	Sleep(1000);
	return 0;
}
