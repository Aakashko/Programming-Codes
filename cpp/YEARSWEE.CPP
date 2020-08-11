#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int d;
cout<<"Enter the number of days = ";
cin>>d;
cout<<d/365<<"years"<<(d%365)/7<<"weeks"<<(d%365)%7<<"days";
getch();
}