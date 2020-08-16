//finding age from given birth date and current date

#include<bits/stdc++.h>
using namespace std;


int main()
{
	string s,e;
	int d1, m1, y1,d2,m2,y2,c=0,f=0;
	cin>>s;
	cin>>e;
	d1=stoi(s);
	d2=stoi(e);
	s.erase(0,3);
	e.erase(0,3);
	m1=stoi(s);
	m2=stoi(e);
	s.erase(0,3);
	e.erase(0,3);
	y1=stoi(s);
	y2=stoi(e);

	int M[] = { 31,28,31,30,31,30,31,31,30,31,30,31};

	if(((m1==2&&d1<=29)||(m2==2&&d2<=29))&&(y1%4==0&&y2%4==0)&&(y2>=y1))
	{
		if((d2>=d1)&&(m2>=m1)&&(y2>=y1))
		{
			c=y2-y1;
		}
		else if((m2<m1||(m2==m1&&d2<d1))&&(y2>=y1))
		{
			c=y2-y1-1;
		}
		cout<<"the age is "<<c<<endl;
		f=1;
	}

	if((d1<=M[m1-1]&&d2<=M[m2-1])&&m1<=12&&m2<=12&&(y2>=y1))	
	{

		if((d2>=d1)&&(m2>=m1)&&(y2>=y1))
		{
			c=y2-y1;
		}
		else if((m2<m1||(m2==m1&&d2<d1))&&(y2>=y1))
		{
			c=y2-y1-1;
		}
		cout<<"the age is "<<c<<endl;
		f=1;
	}
	if(f==0)
		cout<<"Invalid date\n";
	return 0;
}