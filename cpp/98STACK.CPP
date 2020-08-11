#include<iostream.h>
#include<conio.h>
struct stack
{char name[20];
int rno;
stack *p;};
stack *top=NULL;
void push()
{ stack *s=new stack;
cout<<"Enter roll no:"<<"\t";
cin>>s->rno;
cout<<"Enter name:"<<"\t";
cin>>s->name;
s->p=NULL;
if(top==NULL)
top=s;
else
{s->p=top;
top=s;}}
void pop()
{if(top==NULL)
cout<<"\n stack empty \n";
else
{stack *q=top;
top=top->p;
delete q;}}
void disp()
{if(top==NULL)
cout<<"\n stack is empty ";
else
{stack *q=top;
while(q!=NULL)
{cout<<"Roll no: "<<q->rno<<endl;
cout<<"Name : "<<q->name<<endl;
q=q->p;}}}
void main()
{clrscr();
char c='y';
int x;
while(c=='y')
{cout<<" 1.Insertion \n 2.Deletion \n 3.Display \n";
cout<<"\n Enter the task \n";
cin>>x;
switch(x)
{case 1:push();break;
case 2:pop(); break;
case 3:disp();break;
default: cout<<"Invalid";}
cout<<"Do you wish to continue (y/n) ? ";
cin>>c;
cout<<"\n";
}
getch();
}

