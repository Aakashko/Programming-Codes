#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
void main()
{clrscr();
int a[10],n,d,f=0;
cout<<"Enter the size = ";
cin>>n;
cout<<"Enter the array = ";
for(int i=0;i<n;++i)
{cin>>a[i];}
cout<<"enter no. = ";
cin>>d;
for(int j=0;j<n;++j)
{if(d==a[j])
{cout<<"found";f=1;break;} }
if(f==1)
{cout<<endl<<"modified array"<<endl;
for(int p=j;p<n-1;++p)
{a[p]=a[p+1];
for(int r=0;r<n-1;++r)
cout<<a[r];cout<<endl;}
}
if(f==0)
cout<<"not found";
  getch();
 }