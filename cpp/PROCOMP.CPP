#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
int ch;
class mark
{
public:int ch,r,k[5];char sname[20],q;
 void enter()
{ cout<<endl<<endl<<"                             12th MARKING SYSTEM                 "<<endl;
cout<<endl<<endl<<"               WELCOME!                  "<<endl;
cout<<endl<<endl<<"	       What would you like us to do.......      "<<endl;
cout<<" 1: INPUT & SEARCH DETAILS  (Inputs & searchs for the details of the student) "<<endl;
cout<<" 2: VIEW DETAILS  (Displays the details of the student inputed) "<<endl;
cout<<" 3: MODIFY DETAILS  (Modifies the details of the student who wish to do so) "<<endl;
cout<<" 4: DELETE DETAILS  (Delete the details of the student from the rank list) "<<endl;
cout<<" 5: EXIT  (Exits from the software program) "<<endl;
cout<<endl<<endl<<"       Enter your choice : 1 , 2 , 3 , 4 or 5.........."<<endl;
cout<<"          CHOICE :   ";
cin>>ch;}
void input()
{clrscr();
cout<<endl<<endl<<"              ENTER THE DETAILS OF 5 STUDENTS OF COMPUTER SCIENCE STREAM "<<endl;

for(int i=0;i<5;++i)
{
cout<<"Enter the name of the student to be searched : ";
gets(sname);
cout<<"Enter the roll number : ";
cin>>r;
cout<<"       ENTER THE MARKS IN 5 SUBJECTS"<<endl;
cout<<"Maths = ";
cin>>k[0];
cout<<"English = ";cin>>k[1];
cout<<"Computer science = ";cin>>k[2];
cout<<"Physics = ";cin>>k[3];
cout<<"Chemistry = ";cin>>k[4];} }
void search()
{int a;
clrscr();
mark M;
int ro,f=0;
input();
ofstream o("class.dat",ios::binary);
o.write((char *)&M,sizeof(M));
o.close();
cout<<endl<<endl<<endl<<"       Enter the roll number of the student to be searched : ";
cin>>ro;
ifstream i("class.dat",ios::binary);
while(!i.eof())
{i.read((char *)&M, sizeof(M));
if(ro==r)
{f=1;cout<<endl<<endl<<"        RECORD FOUND "<<endl;break;}
if(f==0)
{cout<<endl<<endl<<"      The roll number has not found "<<endl;}}
cout<<endl<<endl<<"            What do you want us to do next = ";
cin>>ch;}};
 void main()
{clrscr();
mark M;
int p;
char pas[30];
cout<<endl<<endl<<endl<<endl<<endl<<"                    ENTER THE PASSWORD : ";
cin>>pas;
if(strcmp(pas,"bvb12markingsys2016")==0)
{clrscr();M.enter(); M.search();
 }
else
{cout<<endl<<endl<<"                SORRY, THE PASSWORD IS WRONG ";
we: cout<<endl<<endl<<"                Press 1 to exit : ";
 cin>>p;}
 if(p==1)
exit(0);
else
{cout<<endl<<"                sorry wrong choice ";
goto we;}

 getch(); }