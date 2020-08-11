#include<iostream.h>
#include<conio.h>
void find(int a)
{int sum=0;
while(a>0)
{int r=a%10;
if(r%2==0)
sum=sum+r;
a/=10;
}
cout<<"The sum of the even digits = "<<sum<<"\n";
}
void find(int a[3][3])
{int sum=0;
for(int i=0;i<3;++i)
{for(int j=0;j<3;++j)
{if(i==j)
sum=sum+a[i][j];}}
cout<<"The sum of main diagonal elements of the 2-D integer array = "<<sum<<"\n";
}
void find(int a[5])
{int sum=0;
for(int i=0;i<5;++i)
{if(i%2!=0)
sum=sum+(a[i]*a[i]);
}
cout<<"The sum of squares of all the elements placed at odd index = "<<sum<<"\n";
}
void main()
{clrscr();
int x,y[5],z[3][3];
cout<<"Enter a number = ";
cin>>x;
cout<<"Enter the elements for (3x3) 2-D integer array = "<<"\n";
for(int i=0;i<3;++i)
{for(int j=0;j<3;++j)
cin>>z[i][j];
}
cout<<"Enter the array with 5 elements = ";
for(int m=0;m<5;++m)
{cin>>y[m];}
find(x);
find(y);
find(z);
getch();
}