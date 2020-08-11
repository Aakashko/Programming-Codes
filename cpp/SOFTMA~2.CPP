#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>

class mark
{  int r;
public:int ch;char sname[20],remark[15],gd[5];float perc,sum,k[5];
void enter()
{clrscr();
cout<<endl<<endl<<"                              12th MARKING SYSTEM                     "<<endl;
cout<<endl<<endl<<"------------------------------------WELCOME!------------------------------------"<<endl;
 cout<<endl<<endl<<"           What would you like us to do.......    "<<endl;
cout<<" 1: INPUT DETAILS  (Inputs the details of the student) "<<endl;
cout<<" 2: SEARCH DETAILS  (Searchs for the details of the student) "<<endl;
cout<<" 3: VIEW DETAILS  (Displays the details of the students ) "<<endl;
cout<<" 4: MODIFY DETAILS (Modifies the details of the student who wish to do so) "<<endl;
cout<<" 5: DELETE DETAILS  (Deletes the details of the student from the rank list) "<<endl;
cout<<" 6: EXIT  (Exits from the software program) "<<endl;
cout<<endl<<endl<<"--------------------------------------------------------------------------------";
cout<<endl<<"       Enter your choice : 1 , 2 , 3 , 4 , 5 or 6.........."<<endl;
cout<<"          CHOICE :   ";
cin>>ch;}

void input()
{clrscr();int qa;
cout<<endl<<endl<<"               ENTER THE DETAILS OF THE STUDENTS OF COMPUTER STREAM "<<endl;
cout<<"--------------------------------------------------------------------------------";
cout<<endl<<endl<<"                 DETAILS "<<endl;
cout<<"               -----------  "<<endl;
cout<<endl<<"   Enter the name of the student : ";
gets(sname);
cout<<"   Enter the roll number : ";
cin>>r;
cout<<endl<<"        ENTER THE MARKS IN 5 SUBJECTS"<<endl;
cout<<"    Maths = ";
cin>>k[0];
cout<<"    English = ";cin>>k[1];cout<<"    Computer Science = ";cin>>k[2];
cout<<"    Physics = ";cin>>k[3];cout<<"    Chemistry = ";cin>>k[4];
cout<<endl<<"               What do you want us to do next......."<<endl;
uz: cout<<"    Press 7 to continue "<<endl<<"     Enter your choice : ";
cin>>qa;
if(qa==7)
enter();
else
{cout<<"    Sorry, wrong choice "<<endl;
goto uz;}
clrscr();}

void write()
{clrscr();
mark B;
ofstream o("class.dat",ios::binary|ios::out|ios::app);
o.open("class.dat",ios::binary|ios::in|ios::out|ios::app);
B.input();B.cal();
o.write((char *)&B,sizeof(B));

o.close();}

 void cal()
 { sum=0;
   sum=k[0]+k[1]+k[2]+k[3]+k[4];
   perc=(sum/500.0)*100.0;
if(perc>=90)
{strcpy(gd,"A+");strcpy(remark,"Outstanding");}
else if(perc<90&&perc>=80)
{strcpy(gd,"A");strcpy(remark,"Excellent");}
else if(perc<80&&perc>=70)
{strcpy(gd,"B");strcpy(remark,"Very Good");}
else if(perc<70&&perc>=60)
{strcpy(gd,"C");strcpy(remark,"Good");}
else if(perc<60&&perc>=50)
{strcpy(gd,"D");strcpy(remark,"Average");}
else if(perc<50&&perc>=40)
{strcpy(gd,"E");strcpy(remark,"Poor");}
else
{strcpy(gd,"F");strcpy(remark,"Fail");}
}


void disp()
{clrscr();int yy;
cout<<endl<<endl<<"----------------------------------VIEW DETAILS----------------------------------";
cout<<endl<<endl<<"                                    PROFILE      "<<endl;
cout<<            "                                   ---------    "<<endl;
cout<<"  Name of the student : ";
puts(sname);
cout<<"  Roll Number : "<<r<<endl;
cout<<"  Class : 12th "<<endl;
cout<<"  Stream opted : Computer Science "<<endl;
cout<<"  Sum of total marks obtained in all subjects (out of 500) : "<<sum<<endl;
cout<<"  Percentage secured : "<<perc<<endl;
cout<<"  Grade : "<<gd<<endl;
cout<<"  Remark : ";puts(remark);
 cout<<endl<<endl<<"               What do you want us to do next......."<<endl<<endl;
yx: cout<<"    Press 7 to continue "<<endl<<"     Enter your choice : ";
cin>>yy;
if(yy==7)
enter();
else
{cout<<"    Sorry, wrong choice "<<endl;
goto yx;}
 }

void read()
{clrscr();
mark C;
ifstream i3("class.dat",ios::binary|ios::in);
i3.open("class.dat",ios::binary|ios::in|ios::out);
i3.seekg(0,ios::beg);
while(!i3.eof())
{i3.read((char *)&C,sizeof(C));
int p=i3.tellg();
cout<<"fghh"<<p;
C.disp();
cout<<endl<<endl;}
i3.close();
}

void search()
{clrscr();
mark D;
int f=0,ro,mn,p2;
cout<<endl<<endl<<"------------------------------------SEARCHING-----------------------------------";
cout<<endl<<endl<<"        Enter the roll number of the student to be searched : ";
cin>>ro;
ifstream i("class.dat",ios::binary|ios::in|ios::app);
i.seekg(0);
while(!i.eof())
{i.read((char *)&D,sizeof(D));
if(ro==D.r)
{f=1;cout<<endl<<endl<<"        RECORD FOUND ";
 qh: cout<<endl<<" Press 10 for displaying the record or 11 for main menu : ";
 cin>>p2;
 if(p2==10)
 {D.disp();}
 else if(p2==11)
 {enter();}
 else
{cout<<"    Sorry, wrong choice ";
 goto qh;}
break;}}
if(f==0)
{cout<<endl<<endl<<"        The roll number has not found "<<endl;
}
i.close();
cout<<endl<<endl<<"               What do you want us to do next......."<<endl<<endl;
yu: cout<<"    Press 7 to continue "<<endl<<"     Enter your choice : ";
cin>>mn;
if(mn==7)
enter();
else
{cout<<"    Sorry, wrong choice "<<endl;
goto yu;}

}

 void del()
 {clrscr();
 mark E;
 int p1, rol,ww;
cout<<endl<<endl<<"------------------------------------DELETION------------------------------------";
cout<<endl<<endl<<" Enter the roll no. of the student whose record has to be deleted : ";
cin>>rol;
ofstream o("A.dat",ios::binary);
ifstream i1("class.dat",ios::binary);
i1.seekg(0,ios::beg);
while(!i1.eof())
{i1.read((char *)&E,sizeof(E));
if(rol==r)
{cout<<"   RECORD FOUND.  DELETION IS POSSIBLE "<<endl;
qw: cout<<endl<<" Press 10 for deletion : ";
 cin>>p1;
 if(p1==10)
 {o.write((char *)&E,sizeof(E));}
 else
 {cout<<"    Sorry, wrong choice ";
 goto qw;}
 break;}
 }
 cout<<"     REMOVED "<<endl;
  i1.close();
o.close();
 remove("class.dat");
 rename("A.dat","class.dat");

 cout<<endl<<endl<<"               What do you want us to do next......."<<endl<<endl;
yu: cout<<"    Press 7 to continue "<<endl<<"     Enter your choice : ";
cin>>ww;
if(ww==7)
enter();
else
{cout<<"    Sorry, wrong choice "<<endl;
goto yu;}


 }


 void modify()
 {clrscr();
 mark F;
 int p1;int rn,cc,o8;
 cout<<endl<<endl<<"--------------------------------MODIFICATION----------------------------------";
 cout<<endl<<endl<<" Enter the roll no. of the student whose record has to be modified : ";
 cin>>rn;
 fstream f("class.dat",ios::in|ios::out|ios::binary);
 f.open("class.dat",ios::in|ios::out);
 f.seekg(0);
 while(!f.eof())
 {int p=f.tellg();
 f.read((char *)&F,sizeof(F));
  if(F.r==rn)
{cout<<"   RECORD FOUND.  MODIFICATION IS POSSIBLE "<<endl;
op: cout<<endl<<" Press 10 for modification : ";
 cin>>p1;
 if(p1==10)
{
 f.seekg(p,ios::cur);
 F.input();
f.write((char *)&F,sizeof(F));
oil: cout<<"   Press 3 to disply the modified details or press 7 to continue : ";
cin>>o8;
if(o8==3)
F.disp();
else if(o8==7)
break;
else
{cout<<"    sorry, wrong choice ";
goto oil;}
 }
 else
 {cout<<"    sorry, wrong choice ";
 goto op;}
 break;}
 else
 {cout<<"   MODIFICATION IS NOT POSSIBLE"<<endl;
 break;}}
 f.close();
 cout<<endl<<endl<<"               What do you want us to do next......."<<endl<<endl;
oi: cout<<"    Press 7 to continue "<<endl<<"     Enter your choice : ";
cin>>cc;
if(cc==7)
enter();
else
{cout<<"    Sorry, wrong choice "<<endl;
goto oi;}

 }};

void main()
{clrscr();
mark M;int p,v,ds;
char pas[30],t='y';
wr:cout<<endl<<endl<<endl<<endl<<endl<<"                   ENTER THE PASSWORD : ";
cin>>pas;
if(strcmp(pas,"bvb12markingsys2016")==0)
{clrscr();
while(t=='y')
{M.enter();
switch(M.ch)
{case 1: M.write();
	 break;
 case 2: M.search();
	 break;
 case 3: M.read();
	 break;
 case 4: M.modify();
	 break;
 case 5: M.del();
	 break;
 case 6: exit(0);
	 break;
 default : clrscr();
	   cout<<endl<<endl<<"           SORRY, WRONG CHOICE  "<<endl;
	   ee: cout<<endl<<"         Press 6 to exit and 7 to continue : ";
	   cin>>v;
	   if(v==6)
	   exit(0);
	   else if(v==7)
	   M.enter();
	   else
	   {cout<<endl<<"         sorry, wrong choice "<<endl;
	   goto ee;}
	   break;
}}
clrscr();
cout<<endl<<endl<<"            DO YOU WANT TO CONTINUE "<<endl<<endl;
cout<<"            Press 'y' for YES and 'n' for NO : ";
cin>>t;
if(t=='n')
{cout<<"            Press 6 for exit : ";
cin>>ds;
if(ds==6)
exit(0);}
}
else
{cout<<endl<<endl<<"                SORRY, THE PASSWORD IS WRONG ";
we: cout<<endl<<endl<<"                Press 6 to exit and 7 to continue : ";
cin>>p;
if(p==6)
exit(0);
else if(p==7)
goto wr;
else
{cout<<endl<<"                sorry wrong choice ";
goto we;}}
getch();}
