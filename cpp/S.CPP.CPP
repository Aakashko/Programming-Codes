 #include<conio.h>
 #include<stdio.h>
 #include<stdlib.h>
 #include<graphics.h>
 #include<dos.h>
 #include<string.h>
 #include<fstream.h>
 int a=0,x;
 char c;
 class passenger
 {
 char name[20],address[25],uname[20],pass[12],rpass[12],gender;
 int age;
 long pn;
 public:
 void input()
 {
 clrscr();
 cout<<"  Enter:-\n";
 cout<<"  Name:";
 gets(name);
 cout<<"  Gender(Male:m or Female:f):";
 cin>>gender;
 cout<<"  Age:";
 cin>>age;
 cout<<"  Address:";
 gets(address);
 cout<<"  Phone:";
 cin>>pn;
 cout<<"  User name:";
 gets(uname);
 cout<<"  Choose your password:";
 gets(pass);
 cout<<"  Retype passsword:";
 gets(rpass);
 a=0;
 while(a==0)
 {if(strcmpi(pass,rpass)==0)
 {
 ++a;
 }
 else
 {
 textcolor(4);
 cprintf("  Sorry password mismatch");
 cout<<"\n";
 textcolor(15);
 cprintf("  Enter the password again:");
 gets(pass);
 cout<<"  Retype password:";
 gets(rpass);
 }
 }
 }
 void sign()
 {
 randomize();
 int gm=DETECT,gd;
 initgraph(&gm,&gd,"c:\\turboc3\\BGI");
 setcolor(WHITE);
 settextstyle(2,HORIZ_DIR,7);
 outtextxy(250,210,"LOADING......");
 rectangle(180,240,450,240);
 setcolor(BLUE);
 for(int i=240;i<=450;++i)
 {
 rectangle(180,240,i,240);
 delay(10);
 }
 closegraph();
 clrscr();
 passenger p1;
 int ar=1+random(14);
 textcolor(ar);
 cprintf("                             --:SIGNUP:--");cout<<"\n";
 textcolor(15);cprintf(" ");
 p1.input();
 ofstream o("pass.dat",ios::app|ios::binary);
 o.write((char*)&p1,sizeof(p1));
 cout<<"\n  sign up successfull\n";
 int gm1=DETECT,gd1;
 initgraph(&gm1,&gd1,"c:\\turboc3\\BGI");
 setcolor(WHITE);
 settextstyle(2,HORIZ_DIR,7);
 outtextxy(250,210,"REDIRECTING......");
 rectangle(180,240,450,240);
 setcolor(RED);
 for(int i1=240;i1<=450;++i1)
 {
 rectangle(180,240,i1,240);
 delay(10);
 }
 closegraph();
 clrscr();
 o.close();
 }
 void signin()
 {
 randomize();
 int gm=DETECT,gd;
 initgraph(&gm,&gd,"c:\\turboc3\\BGI");
 setcolor(WHITE);
 settextstyle(2,HORIZ_DIR,7);
 outtextxy(250,210,"LOADING......");
 rectangle(180,240,450,240);
 setcolor(BLUE);
 for(int i=240;i<=450;++i)
 {
 rectangle(180,240,i,240);
 delay(10);
 }
 closegraph();
 clrscr();
 char un[20],ps[12];
 passenger p2;
 int ae=1+random(14);
 textcolor(ae);
 cprintf("                             --:SIGNIN:--");cout<<"\n\n";
 textcolor(15);
 cprintf("  Username:");
 gets(un);
 cout<<"\n  Password:";
 gets(ps);
 ifstream i7("pass.dat",ios::binary);
 while(!i7.eof())
 {
 i7.read((char*)&p2,sizeof(p2));
 if(strcmpi(un,p2.uname)==0 && strcmp(ps,p2.pass)==0)
 a=1;
 }
 if(a==1)
 {
 textcolor(10);
 cprintf("\n  Sign in successfull");cout<<"\n";
 textcolor(15);
 cprintf(" ");
 delay(600);
 int gm=DETECT,gd;
 initgraph(&gm,&gd,"c:\\turboc3\\BGI");
 setcolor(WHITE);
 settextstyle(2,HORIZ_DIR,7);
 outtextxy(250,210,"REDIRECTING......");
 rectangle(180,240,450,240);
 setcolor(GREEN);
 for(int i=240;i<=450;++i)
 {
 rectangle(180,240,i,240);
 delay(10);
 }
 closegraph();
 }
 else
 {
 textcolor(4);
 cprintf("  Sorry username & password mismatch");
 textcolor(15);
 cprintf(" ");
 delay(700);
  exit(0);}
 }

 };
 class details
 {
 public:
 long tno;
 char tname[20],from[12],to[12];
 int arvtime,deptime,distance;
 };
 class train:public details
 {
 int seatf,seatt;
 double date;
 char CLASS[17],berth[10];
 public:
 char pfrom[12],pto[12];
 int ticno,ad,cd,sc,fare;
 int sef()
 {
 return seatf;
 }
 int set()
 {
 return seatt;
 }
 double dat()
 {
 return date;
 }
 int enter1()
 {
 textcolor(15);
cprintf("  Enter the Class|");
 textcolor(9);
 cprintf(" 1:SLEEPER");
 textcolor(10);
 cprintf(" 2:3rd AC");
 textcolor(11);
 cprintf(" 3:2nd AC");
 textcolor(12);
 cprintf(" 4:1st AC");
 textcolor(13);
 cprintf(" 5:2nd SEATING");
 textcolor(15);
 cprintf("|");
 cout<<"\n";
 cprintf("                    |");
 textcolor(14);
 cprintf("  6:AC CHAIR CAR");
 textcolor(3);
 cprintf("  7:FIRST CLASS");
 textcolor(5);
 cprintf("  8:AC ECONOMY");
 textcolor(15);
 cprintf("|");
  while(a==1)
 {
 cout<<"\n  Choice=";
 cin>>x;
 switch(x)
 {
 case(1):{strcpy(CLASS,"SLEEPER");++a;return 500;}break;
 case(2):{strcpy(CLASS,"3rd AC");++a;return 750;}break;
 case(3):{strcpy(CLASS,"2nd AC");++a;return 1000;}break;
 case(4):{strcpy(CLASS,"1st AC");++a;return 1500;}break;
 case(5):{strcpy(CLASS,"2nd SEATING");++a;return 250;}break;
 case(6):{strcpy(CLASS,"AC CHAIR CAR");++a;return 450;}break;
 case(7):{strcpy(CLASS,"FIRST CLASS");++a;return 1500;}break;
 case(8):{strcpy(CLASS,"3rd AC ECONOMY");++a;return 750;}break;
 default:cout<<"Invalid choice";
 }
 }

 }
 void enter2()
 {
 a=1;
 while(a==1)
 {
 cout<<"\n  Choice=";
 cin>>x;
 switch(x)
 {
 case(1):{strcpy(berth,"LOWER");++a;}break;
 case(2):{strcpy(berth,"MIDDLE");++a;}break;
 case(3):{strcpy(berth,"UPPER");++a;}break;
 case(4):{strcpy(berth,"SIDE UPPER");++a;}break;
 case(5):{strcpy(berth,"SIDE LOWER");++a;}break;
 default:cout<<"Invalid choice";
  }
 }
 }
 void booking()
 {
 randomize();
 int gm=DETECT,gd;
 initgraph(&gm,&gd,"c:\\turboc3\\BGI");
 setcolor(WHITE);
 settextstyle(2,HORIZ_DIR,7);
 outtextxy(250,210,"LOADING......");
 rectangle(180,240,450,240);
 setcolor(BLUE);
 for(int i=240;i<=450;++i)
 {
 rectangle(180,240,i,240);
 delay(10);
 }
 closegraph();
 clrscr();
 a=0;
 long h,da;
 int te;
 char f[20],t[20];
 details d;
 train t1;
 ifstream i1("details.dat",ios::binary);
 int ad=1+random(14);
 textcolor(ad);
 cprintf("                             ===:BOOKING:===");
 cout<<"\n\n";
 textcolor(15);
 cprintf("  From:");
 gets(f);
 cout<<"\n  To:";
 gets(t);
 cout<<"\n  Date(DDMMYYYY):";
 cin>>da;
 cout<<"\n  Time(HHMM):";
 cin>>te;
 while(!i1.eof())
 {
 i1.read((char*)&d,sizeof(d));
 if(te<=d.deptime && d.deptime>=te+500)
 {cout<<"\n";
 textcolor(9);
 cprintf("TRAIN NO:");
 cout<<d.tno;
 textcolor(3);
 cprintf("Train name:");
 cout<<d.tname;
 textcolor(15);
 cprintf(" Arrival time:");cout<<d.arvtime<<" Departure time:"<<d.deptime<<"\n";
 a=1;
 }}
 i1.close();
 if(a==0)
 cout<<"\n  NO TRAINS AVAILABLE";
 else if(a==1)
 {
 strcpy(t1.pfrom,f);
 strcpy(t1.pto,t);
 textcolor(4);
 cout<<"\n";
 cprintf("  Select a train by entering the Train No:");
 textcolor(15);
 cin>>h;
 clrscr();
 int fr=t1.enter1();
 t1.fare=fr;
 cout<<"\n";
 cout<<"  Enter the number of passenger--";cout<<"\n";
 cout<<"\n  ADULT:";cin>>t1.ad;
 cout<<"\n  CHILDREN:";cin>>t1.cd;
 cout<<"\n  SENIOR CITIZEN:";cin>>t1.sc;
 cout<<"\n  Enter the berth(";
 textcolor(9);
 cprintf(" 1:LOWER");
 textcolor(10);
 cprintf(" 2:MIDDLE");
 textcolor(11);
 cprintf(" 3:UPPER");
 textcolor(12);
 cprintf(" 4:SIDE UPPER");
 textcolor(13);
 cprintf(" 5:SIDE LOWER");
 textcolor(15);
 cprintf(")");
 t1.enter2();
 t1.fare=(t1.fare*(t1.ad+t1.sc+t1.cd))-(t1.cd*50)-(t1.sc*50);
 t1.date=da;
 ifstream i2("details.dat",ios::binary);
 a=0;
 while(!i2.eof())
 {
 i2.read((char*)&d,sizeof(d));
 if(h==d.tno)
 {
 a=1;
 t1.tno=h;
 strcpy(t1.tname,d.tname);
 t1.arvtime=d.arvtime;
 t1.deptime=d.deptime;
 t1.distance=d.distance;
 strcpy(t1.from,d.from);
 strcpy(t1.to,d.to);
 t1.ticno=h+random(2000);
 t1.seatf=50+random(100);
 t1.seatt=t1.ad+t1.sc+t1.cd+t1.seatf-1;
 }
 }
 if(a==0)
 {textcolor(4);
 cprintf("INVALID TRAIN No.");
 textcolor(15);
 cprintf(" ");
 delay(800);
 exit(0);}
 ofstream o4("train.dat",ios::app|ios::binary);
 o4.write((char*)&t1,sizeof(t1));
 o4.close();
 clrscr();
 for(int j=0;j<20;++j)
 {
 if(j%5==0)
 {textcolor(5);delay(100);}
 else if(j%3==0)
 {textcolor(2);delay(100);}
 else if(j%2==0)
 {textcolor(1);delay(100);}
 else
 {textcolor(4);delay(100);}
 gotoxy(31,12);
  cprintf("***BOOKING***");
  delay(100);
 }
 i2.close();
 textcolor(15);
 clrscr();
 cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------";
 cout<<"\n";
 textcolor(10);
 cprintf("   BOOKING SUCCESSFULL");
 textcolor(14);
 cout<<"\n";
 cprintf("  Please note your PNR no.");
 cout<<"\n   Your PNR NUMBER:"<<t1.ticno<<"\n   Seating\n   "<<t1.seatf<<"-"<<t1.seatt<<"\n  TOTAL FARE=Rs"<<t1.fare<<"\n\n";
 cprintf("            *******WISH YOU A HAPPY JOURNEY*******");
 textcolor(15);
 cprintf(" ");
 }
 }
 void cancel()
 {
 randomize();
 int gm=DETECT,gd;
 initgraph(&gm,&gd,"c:\\turboc3\\BGI");
 setcolor(WHITE);
 settextstyle(2,HORIZ_DIR,7);
 outtextxy(250,210,"LOADING......");
 rectangle(180,240,450,240);
 setcolor(BLUE);
 for(int i=240;i<=450;++i)
 {
 rectangle(180,240,i,240);
 delay(10);
 }
 closegraph();
 clrscr();
 train t4;
 int tc;
 int ac=1+random(14);
 textcolor(ac);
 cprintf("                             ==:CANCEL TICKET:==");cout<<"\n\n";
 textcolor(15);
 cout<<"  Enter the PNR No. to be cancelled:";
 cin>>tc;
 cout<<"  ARE YOU SURE (";
 textcolor(10);
 cprintf("yes-y");
 cout<<"||";
 textcolor(12);
 cprintf("no-n");
 textcolor(15);
 cprintf("):");
 cin>>c;
 while(c=='y')
 {
 ifstream i4("train.dat",ios::binary);
 ofstream o4("t.dat",ios::binary||ios::app);
 while(!i4.eof())
 {
 i4.read((char*)&t4,sizeof(t4));
 if(t4.ticno!=tc)
 o4.write((char*)&t4,sizeof(t4));
 }
 i4.close();
 o4.close();
 remove("train.dat");
 rename("t.dat","train.dat");
 textcolor(4);
 cprintf("  ..CANCELLED..");
 textcolor(15);
 cprintf(" ");
 c='n';
 }
 }
 void modify()                         ///////fn to modify///////////
 {
 randomize();
 int gm7=DETECT,gd7;
 initgraph(&gm7,&gd7,"c:\\turboc3\\BGI");
 setcolor(WHITE);
 settextstyle(2,HORIZ_DIR,7);
 outtextxy(250,210,"LOADING......");
 rectangle(180,240,450,240);
 setcolor(BLUE);
 for(int i=240;i<=450;++i)
 {
 rectangle(180,240,i,240);
 delay(10);
 }
 closegraph();
 clrscr();
 long l;
 details d1,d2;
 train t2,t3,t4;
 double dae;
 int u,tie;
 char fm[12],tp[12];
 int ab=1+random(14);
 textcolor(ab);
 cprintf("                             --:MODIFY TICKET:--");
 cout<<"\n  Enter the PNR no to be modified:";      ////////////////////////
 cin>>u;
 ifstream z("train.dat",ios::binary);
 a=0;
 while(!z.eof())
 {
 z.read((char*)&t4,sizeof(t4));
 if(t4.ticno==u)
 a=1;
 }
 z.close();
 if(a==0)
 {
  textcolor(1);
  cprintf("  INVALID PNR NO.");
  textcolor(15);
 }
 else if(a==1)
 {
 t2.ticno=u;
 cout<<"\n  From:";
 gets(fm);
 cout<<"\n  To:";
 gets(tp);
 cout<<"\n  Date(DDMMYYYY):";
 cin>>dae;
 cout<<"\n  Time(HHMM):";
 cin>>tie;
 ifstream g("details.dat",ios::binary);
 a=0;
 while(!g.eof())
 {
 g.read((char*)&d1,sizeof(d1));
 if(tie<=d1.deptime && d1.deptime>=tie+500)                              //////333//////////////////////
 {
 cout<<"\n";
 textcolor(9);
 cprintf("TRAIN NO:");
 cout<<d1.tno;
 textcolor(3);
 cprintf("Train name:");
 cout<<d1.tname;
 textcolor(15);
 cprintf(" Arrival time:");cout<<d1.arvtime<<" Departure time:"<<d1.deptime<<"\n";
 a=1;
 }
 }
 if(a==0)
 cout<<"\n  NO TRAINS AVAILABLE";
 else if(a==1)
 {
 strcpy(t2.pfrom,fm);
 strcpy(t2.pto,tp);
 textcolor(4);
 cout<<"\n";
 cprintf("  Select a train by entering the Train No:");
 textcolor(15);
 cin>>l;
 clrscr();
 int fr=t2.enter1();
 clrscr();
 textcolor(15);
 cprintf(" ");
 t2.fare=fr;
 cout<<"\n  Enter the number of passenger--\n ";
 cout<<"\n  ADULT:";cin>>t2.ad;
 cout<<"\n  CHILDREN:";cin>>t2.cd;
 cout<<"\n  SENIOR CITIZEN:";cin>>t2.sc;
 cout<<"\n  Enter the berth(";
 textcolor(9);
 cprintf(" 1:LOWER");
 textcolor(10);
 cprintf(" 2:MIDDLE");
 textcolor(11);
 cprintf(" 3:UPPER");
 textcolor(12);
 cprintf(" 4:SIDE UPPER");
 textcolor(13);
 cprintf(" 5:SIDE LOWER");
 textcolor(15);
 cout<<" ";
 cprintf(")");
 t2.enter2();
 t2.fare=(t2.fare*(t2.ad+t2.sc+t2.cd))-(t2.cd*50)-(t2.sc*50);
 t2.date=dae;
 ifstream p("details.dat",ios::binary);
 a=0;
 while(!p.eof())
 {
 p.read((char*)&d2,sizeof(d2));
 if(l==d2.tno)
 {
 t2.tno=l;
 strcpy(t2.tname,d2.tname);
 t2.arvtime=d2.arvtime;
 t2.deptime=d2.deptime;
 t2.distance=d2.distance;
 strcpy(t2.from,d2.from);
 strcpy(t2.to,d2.to);
 t2.seatf=50+random(100);
 t2.seatt=t2.ad+t2.sc+t2.cd+t2.seatf-1;
 }
 }
 fstream f("train.dat",ios::binary|ios::in|ios::out);
 a=0;
 while(c=='y')
 {
 f.read((char*)&t3,sizeof(t3));
 if(t3.ticno==u)
 {
  c='n';
  textcolor(128+2);
  cout<<"\n                 ";
  cprintf("****SUCCESSFULL****");
 textcolor(15);
 f.seekp(0,ios::cur);
 f.seekp(f.tellg()-sizeof(t2));
 f.write((char*)&t2,sizeof(t2));
 }
 }
 f.close();
 }
 }
 }
 void search()
 {
 randomize();
 int gm=DETECT,gd;
 initgraph(&gm,&gd,"c:\\turboc3\\BGI");
 setcolor(WHITE);
 settextstyle(2,HORIZ_DIR,7);
 outtextxy(250,210,"LOADING......");
 rectangle(180,240,450,240);
 setcolor(BLUE);
 for(int i=240;i<=450;++i)
 {
 rectangle(180,240,i,240);
 delay(10);
 }
 closegraph();
 clrscr();
 int aa=1+random(14);
 textcolor(aa);
 cprintf("                             ==:STATUS:==");cout<<"\n\n";
 textcolor(15);
 cprintf(" ");
 a=0;
 train t5;
 int q;
 cout<<"  Enter your PNR number:";
 cin>>q;
 ifstream i5("train.dat",ios::binary);
 while(!i5.eof())
 {
 i5.read((char*)&t5,sizeof(t5));
 if(t5.ticno==q)
 {
 a=1;
 cout<<"  PNR no:"<<t5.ticno<<"\n  Train no:"<<t5.tno<<"\n  Train name:"<<t5.tname<<"\n  Date of journey:"<<t5.dat();
 cout<<"\n  Arrival time:"<<t5.arvtime<<"\n  Departure time:"<<t5.deptime<<"\n  From:"<<t5.pfrom<<"\n  To:";
 cout<<t5.pto<<"\n  Seat:"<<t5.sef()<<"-"<<t5.set()<<"\n  Fare:RS"<<t5.fare;break;
 }
 }
 if(a==0)
 {textcolor(4);
 cprintf("INVALID PNR NO");
 textcolor(15);
 cprintf(" ");
 }
 }
 };
 void main()
 {
 clrscr();
 passenger p;
 train tr;
 textcolor(12);
 cprintf("###############################################################################");cout<<"\n";
 cprintf("*******************************************************************************");cout<<"\n";
 textcolor(15);
 cout<<"************************";
 textcolor(1);
 cprintf("WELCOME TO RAILWAY RESERVATION SYSTEM");
 textcolor(128+15);
 cout<<"******************"<<"\n";
 textcolor(2);
 cprintf("*******************************************************************************");cout<<"\n";
 cprintf("###############################################################################");cout<<"\n";
 textcolor(128+13);
 cout<<"\n\n";cprintf("                                 ENTER YOUR CHOICE");
 textcolor(15);
 cout<<"\n\n";cprintf("        <1>.CREATE ACCOUNT                                   <2>.SIGN IN");
 cout<<"\n\n                                     <3>.EXIT";
 cout<<"\n\n";
 while(a==0)
 {
 cout<<"\n  Choice=";
 cin>>x;
 switch(x)
 {
 case(1):{p.sign();++a;}break;
 case(2):{p.signin();++a;}break;
 case(3):{clrscr();gotoxy(12,11);textcolor(9);cprintf("       --**************THANK YOU**************--");delay(800);exit(0);++a;}break;
 default:cout<<"Invalid choice";
 }
 }
 c='y';
 while(c=='y')
 {
 clrscr();
 textcolor(12);
 cprintf("###############################################################################");cout<<"\n";
 cprintf("*******************************************************************************");cout<<"\n";
 textcolor(15);
 cout<<"************************";
 textcolor(1);
 cprintf("WELCOME TO RAILWAY RESERVATION SYSTEM");
 textcolor(128+15);
 cout<<"******************"<<"\n";
 textcolor(2);
 cprintf("*******************************************************************************");cout<<"\n";
 cprintf("###############################################################################");cout<<"\n";
 textcolor(128+13);
 cout<<"\n\n";cprintf("                              ENTER YOUR CHOICE");
 textcolor(15);
 cout<<"\n\n";cprintf("       <1>.BOOKING                                        <2>.MODIFICATION");
 cout<<"\n\n       <3>.CANCELLATION                                   <4>.TICKET STATUS";
 cout<<"\n\n                                   <5>.EXIT";
 a=0;
 while(a==0)
 {
 cout<<"\n  Choice=";
 cin>>x;
 switch(x)
 {
 case(1):{tr.booking();++a;}break;
 case(2):{tr.modify();++a;}break;
 case(3):{tr.cancel();++a;}break;
 case(4):{tr.search();++a;}break;
 case(5):{clrscr();gotoxy(12,11);textcolor(9);cprintf("       --**************THANK YOU**************--");delay(800);exit(0);++a;}break;
 default:cout<<"Invalid choice";}
 cout<<"\n\n  Do you wish to continue (";
 textcolor(2);
 cprintf("yes-y");
 textcolor(15);
 cprintf("||");
 textcolor(4);
 cprintf("no-n");
 textcolor(15);
 cprintf("):");
 cin>>c;
 }}
 clrscr();
 gotoxy(12,11);
 textcolor(9);
 cprintf("       --**************THANK YOU**************--");
 delay(800);
 }