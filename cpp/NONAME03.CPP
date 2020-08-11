#include<iostream.h>
#include<conio.h>
class book
{private:int bno,quantity;
char bname[29],publisher[20],author[20];
long int p,tp;
void cal()
{tp=p*quantity;
}
public:void issue()
{cout<<"Enter the bno = ";
cin>>bno;
cout<<"Enter the bname = ";
cin.getline(bname,29);
cout<<"Enter the author = ";
cin.getline(author,20);
cout<<"Enter the publisher = ";
cin.getline(publisher,20);
cout<<"Enter the quantity = ";
cin>>quantity;
cout<<"Enter the price = ";
cin>>p;
}
void close()
{cal();cout<<"The bname ="<<"\t";
cout.write(bname,20);cout<<"\n";cout<<"The tot p = "<<p<<"\n";

	      }};
	      void main()
	      {clrscr();
	      book b[3];
	      for(int i=0;i<3;++i)
	      {b[i].issue();
	      b[i].close();
	      }
	      getch();
	      }