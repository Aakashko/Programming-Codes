#include<iostream.h>
#include<conio.h>
struct queue
{int d;
queue *p;};
queue *front=NULL;
queue *rear=NULL;
void insert()
{queue *s=new queue;
cout<<"Enter the data : ";
cin>>s->d;
s->p=NULL;
if(rear==NULL)
{rear=s;front=s;}
else
{rear->p=s;
rear=s;}}
void del()
{if(front==NULL)
cout<<"Oops! Queue is empty "<<endl;
else
{queue *T=front;
front=front->p;
cout<<"Deleted element is "<<T->d<<endl;
delete T;}}
void disp()
{if(front==NULL)
cout<<"Oops! Queue is empty "<<endl;
else
{cout<<"Elements are : ";
queue *T=front;
while(T!=NULL)
{cout<<T->d<<"\t";
T=T->p;}
cout<<endl;}}
void main()
{clrscr();
char c='y';
int x;
while(c=='y')
{cout<<" 1.Insertion \n 2.Deletion \n 3.Display \n";
cout<<"\n Enter the task \n";
cin>>x;
switch(x)
{case 1:insert();break;
case 2:del(); break;
case 3:disp();break;
default: cout<<"Invalid";}
cout<<"Do you wish to continue (y/n) ? ";
cin>>c;
cout<<"\n";
}
getch();
}