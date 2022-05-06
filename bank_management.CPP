/*=================================
Project Name: BANK Directory
Created by: Abhishek
Class: 
School:
Year:
==================================*/

//Starting of program (BANK Directory)

//Declaration of Header files

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>

void mainmenu();

class customer
{
   // For Taking Employee Number
   int cno;
   // For Taking Employee First Name
   char firstname[20];
   // For Taking Employee Last Name
   char lastname[20];
   // For Taking Employee Age
   int age;
   // For Taking Employee Gender
   char gender[10];
   // For Taking Employee Address
   char address[100];
   // For Taking Employee Phone Number
   char phone[10];
   // For Taking Employee Pincode
   char pcode[10];
   // For Taking The Email Address
   char email[30];
   // For Taking The Salary of Employee
   double salary;
   //For Taking The Post in Bank
   char post[20];
   public:
    /* ------------------------------------------------------------------
		  Function to take the customer details
       ------------------------------------------------------------------*/
   void cdetails()
     {
       // Taking Details of Customer
       gotoxy(3,3);
       cputs("=========================================================");
       gotoxy(5,5);
       cputs("Enter Employee's serial number");
       gotoxy(40,5);
       cin>>cno;
       gotoxy(5,7);
       cputs("Enter Employee's firstname");
       gotoxy(40,7);
       gets(firstname);
       gotoxy(5,9);
       cputs("Enter Employee's lastname");
       gotoxy(40,9);
       gets(lastname);
       gotoxy(5,11);
       cputs("Enter age");
       gotoxy(40,11);
       cin>>age;
       gotoxy(5,13);
       cputs("Enter gender");
       gotoxy(8,14);
       cputs("F-for Female   M-for Male");
       gotoxy(40,13);
       gets(gender);
       gotoxy(5,15);
       cputs("Enter address");
       gotoxy(40,15);
       gets(address);
       gotoxy(5,17);
       cputs("Enter pincode");
       gotoxy(40,17);
       gets(pcode);
       gotoxy(5,19);
       cputs("Enter phone numbers");
       gotoxy(40,19);
       gets(phone);
       gotoxy(5,21);
       cputs("Enter Email Address");
       gotoxy(40,21);
       gets(email);
       gotoxy(5,23);
       cputs("Enter Salary ");
       gotoxy(40,23);
       cin>>salary;
       gotoxy(5,25);
       cputs("Enter Post ");
       gotoxy(40,25);
       gets(post);
       gotoxy(3,27);
       cputs("=========================================================");

     }
   /* -------------------------------------------------------------------
	       Function to display the details of Customer
   --------------------------------------------------------------------*/
   void display()
       {
       clrscr();
       gotoxy(3,3);
       cputs("=========================================================");
       gotoxy(5,5);
       cputs("Employee's serial number");
       gotoxy(40,5);
       cout<<cno;
       gotoxy(5,7);
       cputs("Employee's firstname");
       gotoxy(40,7);
       cout<<firstname;
       gotoxy(5,9);
       cputs("Employee's lastname");
       gotoxy(40,9);
       cout<<lastname;
       gotoxy(5,11);
       cputs("Employee's age");
       gotoxy(40,11);
       cout<<age;
       gotoxy(5,13);
       cputs("Employee's gender");
       gotoxy(40,13);
       cout<<gender;
       gotoxy(5,15);
       cputs("Employee's address");
       gotoxy(40,15);
       cout<<address;
       gotoxy(5,17);
       cputs("Employee's pincode");
       gotoxy(40,17);
       puts(pcode);
       gotoxy(5,19);
       cputs("Employee's phone numbers");
       gotoxy(40,19);
       cout<<phone;
       gotoxy(5,21);
       cputs("Employee's Email Address");
       gotoxy(40,21);
       cout<<email;
       gotoxy(5,23);
       cputs("Employee's Salary ");
       gotoxy(40,23);
       cout<<salary;
       gotoxy(5,25);
       cputs("Employee's Post ");
       gotoxy(40,25);
       cout<<post;
       gotoxy(3,27);
       cputs("=========================================================");
       }
     int rcno()
      {
      return cno;
      }
     char *rfirstname()
      {
      return firstname;
      }
     char *rlastname()
      {
      return lastname;
      }
     char *rphonenumber()
      {
      return phone;
      }
     char *remail()
      {
      return email;
      }
     int rsalary()
      {
      return salary;
      }
     char *rpost()
      {
      return post;
      }

    };
   /* -------------------------------------------------------------------
		Function to accept the details of customer
   --------------------------------------------------------------------*/
   void write()
    {
      clrscr();
      customer c;
      fstream f1;
      f1.open("bank.dat",ios::app|ios::binary);
      char ch;
      do
	{
	  clrscr();
	  c.cdetails();
	  f1.write((char*)&c,sizeof(c));
	  clrscr();
	  gotoxy(20,9);
	  cputs("===================================================");
	  gotoxy(25,10);
	  cputs("THE RECORD IS SAVED");
	  gotoxy(20,11);
	  cputs("===================================================");
	  delay(1000);
	  clrscr();
	  gotoxy(20,9);
	  cputs("===================================================");
	  gotoxy(25,10);
	  cputs("Do you want to add more details y/n");
	  gotoxy(20,11);
	  cputs("===================================================");
	  gotoxy(67,10);
	  cin>>ch;
	}
	while(ch!='n');
      f1.close();
    }

   /* -------------------------------------------------------------------
	       Function to display the details of customer
   --------------------------------------------------------------------*/
   void read()
    {
    clrscr();
      customer c;
      fstream f1;
      f1.open("bank.dat",ios::in|ios::binary);
      while(f1.read((char*)&c,sizeof(c)))
	{
	 c.display();

      getch();
      }
      f1.close();
    }
    /* -----------------------------------------------------------------
	      Function to search a record from the directory
     -----------------------------------------------------------------*/
   void search()
    {
      customer c;
      fstream f1;
      f1.open("bank.dat",ios::in|ios::binary);
      int n,flag=0;
      clrscr();
      gotoxy(20,9);
      cputs("===================================================");
      gotoxy(25,10);
      cputs("Enter Customer's serial number for Search:");
      gotoxy(20,11);
      cputs("===================================================");
      gotoxy(67,10);
      cin>>n;
      while( f1.read((char*)&c, sizeof(c)))
	{

	  if(c.rcno()==n)
	    {
	      clrscr();
	      gotoxy(20,9);
	      cputs("========================================");
	      gotoxy(25,10);
	      cputs("!!!Record found!!!");
	      gotoxy(20,11);
	      cputs("========================================");
	      delay(1000);
	      clrscr();
	      c.display();
	      getch();
	      flag=1;
	    }
	    }
	  if(!flag)
	  clrscr();
	  gotoxy(20,9);
	  cputs("========================================");
	  gotoxy(30,10);
	  cputs("Sorry!!! Record not found");
	  gotoxy(20,11);
	  cputs("========================================");
	  f1.close();

    }
   /* -----------------------------------------------------------------
		Function to delete a record from the directory
     -----------------------------------------------------------------*/
   void del()
    {
      clrscr();
      customer c;
      fstream f1,f2;
      f2.open("temp.dat",ios::out|ios::binary);
      f1.open("bank.dat",ios::in|ios::binary);
      int n,flag=0;
      clrscr();
      gotoxy(20,9);
      cputs("===================================================");
      gotoxy(25,10);
      cputs("Enter Customer's serial number for delete:");
      gotoxy(20,11);
      cputs("===================================================");
      gotoxy(67,10);
      cin>>n;
      while(!f1.eof())
	{
	  f1.read((char*)&c,sizeof(c));
	  if(c.rcno()!=n)
	    {
	      f2.write((char*)&c,sizeof(c));
	    }
	  else
	  flag=1;
	}
      if(!flag)
      {
      clrscr();
      gotoxy(20,9);
      cputs("========================================");
      gotoxy(30,10);
      cputs("Sorry!!! Record not found");
      gotoxy(20,11);
      cputs("========================================");
      delay(1000);
      }
      else
      {
		clrscr();
		 gotoxy(20,9);
		 cputs("========================================");
		 gotoxy(20,10);
		 cputs("Congratulation!!!Record is deleted ");
		 gotoxy(20,11);
		 cputs("========================================");
		 getch();
      }
      f1.close();
      f2.close();
      remove("bank.dat");
      rename("temp.dat","bank.dat");
    }
    /* -----------------------------------------------------------------
	      Function to Modify/Update a record in the directory
     -----------------------------------------------------------------*/
   void update()
    {
      clrscr();
      customer c;
      fstream f1;
      f1.open("bank.dat",ios::in|ios::out|ios::binary);
      int n,flag=0,record=0;
      clrscr();
      gotoxy(20,9);
      cputs("============================================");
      gotoxy(25,10);
      cputs(" Enter Customer's serial number for update:");
      gotoxy(20,11);
      cputs("============================================");
      gotoxy(67,10);
      cin>>n;
      while(!f1.eof())
	  {
	  f1.read((char*)&c,sizeof(c));
	  record++;
	  if(c.rcno()==n)
	    {
	      flag=1;
	      clrscr();
	      gotoxy(20,9);
	      cputs("========================================");
	      gotoxy(30,10);
	      cputs("Please enter new record");
	      gotoxy(20,11);
	      cputs("========================================");
	      delay(500);
	      c.cdetails();
	      f1.seekp((record-1)*sizeof(c));
	      f1.write((char*)&c,sizeof(c));
	      break;
	    }
	}
      if(!flag)
      {
      clrscr();
      gotoxy(20,9);
      cputs("========================================");
      gotoxy(30,10);
      cputs("Sorry!!! Record not found");
      gotoxy(20,11);
      cputs("========================================");
      delay(1000);
      }
      f1.close();
    }
    void mainmenu()
    {
    char ch,ch4,ch5;
      int ch1,ch3;
      do
      {
      clrscr();
      gotoxy(18,5);
      cputs("   ========================================");
      gotoxy(22,6);
      cputs("      *-*-*-*-* 2015 - 2016 *-*-*-*-*");
      gotoxy(18,7);
      cputs("   ========================================");
      delay(500);
      gotoxy(18,8);
      cputs("=========================================================");
      delay(150);
      gotoxy(25,10);
      cputs( "*-*-*-*-*-*-MAIN MENU-*-*-*-*-*-*-");
      delay(150);
      gotoxy(25,12);
      delay(150);
      cputs("1. Add a new record");
      delay(150);
      gotoxy(25,14);
      cputs("2. Display all the records");
      delay(150);
      gotoxy(25,16);
      cputs("3. Search a record");
      delay(150);
      gotoxy(25,18);
      cputs("4. Delete a record");
      delay(150);
      gotoxy(25,20);
      cputs("5. Update or modify previous record");
      delay(150);
      gotoxy(25,22);
      cputs("6. Exit");
      delay(150);
      gotoxy(18,24);
      cputs("=========================================================");
      delay(250);
      gotoxy(20,26);
      cout<<"\n ENTER YOUR CHOICE:\t";
      gotoxy(43,26);
      cin>>ch1;
      switch(ch1)
	 {
	  case 1:
	    {
	      write();

	      break;
	    }
	  case 2:
	    {
	       clrscr();
	       read();
	       break;
	    }
	  case 3:
	    {
		clrscr();
		search();
		break;
	     }
	  case 4:
	     {
		 clrscr();
		 del();
		 break;
	      }
	  case 5:
	      {
		 update();
		 break;
	       }
	  case 6:
	       {
		  exit(0);
		}
	  default:
		{
		    clrscr();
		    gotoxy(20,9);
		    cputs("========================================");
		    gotoxy(30,10);
		    cputs("Invalid option");
		    gotoxy(20,11);
		    cputs("========================================");
		    delay(1000);
		    clrscr();
		    gotoxy(20,9);
		    cputs("========================================");
		    gotoxy(30,10);
		    cputs("Do you wish to continue");
		    gotoxy(20,11);
		    cputs("========================================");
		    gotoxy(54,10);
		    cin>>ch;
		 }
	 }

      }

    while(ch!='n');
 }

void main()
    {
    clrscr();
   // password
      textbackground(LIGHTBLUE);
      char str[6];
      gotoxy(25,10);
      textcolor(YELLOW);
      cputs("==============================");
      gotoxy(28,11);
      textcolor(LIGHTGREEN);
      cputs("Enter your password:");
      gotoxy(25,12);
      textcolor(YELLOW);
      cputs("==============================");
      gotoxy(48,11);
      textcolor(WHITE);
      str[0]=getch();
      cputs("*");
      textcolor(RED);
      str[1]=getch();
      cout<<"*";
      textcolor(WHITE);
      str[2]=getch();
      cputs("*");
      textcolor(RED);
      str[3]=getch();
      cout<<"*";
      textcolor(WHITE);
      str[4]=getch();
      cout<<"*";
      str[5]=getch();
      cout<<"*";
      str[6]='\0';
      //Checking Password

      clrscr();
      gotoxy(20,9);
      cputs("========================================");
      gotoxy(30,10);
      cputs("Please Wait for a while.......");
      gotoxy(20,11);
      cputs("========================================");
      delay(1000);
      clrscr();
      gotoxy(20,9);
      cputs("========================================");
      gotoxy(30,10);
      cputs("Confirming Password");
      gotoxy(20,11);
      cputs("========================================");
      delay(1000);
      if(str[0]=='a'&&str[1]=='b'&&str[2]=='h'&&str[3]=='i'&&str[4]=='s'&&str[5]=='k'&&str[6]=='\0')
      {
      clrscr();
      gotoxy(20,9);
      cputs("========================================");
      gotoxy(30,10);
      cputs("Password Matched");
      gotoxy(20,11);
      cputs("========================================");
      delay(1000);
      clrscr();
      gotoxy(20,9);
      cputs("========================================");
      gotoxy(30,10);
      cputs("Loading File in your account");
      gotoxy(20,11);
      cputs("========================================");
      delay(500);
      gotoxy(30,13);
      cputs("LOADING");
      gotoxy(10,15);
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      cputs("�");
      gotoxy(10,15);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      cputs("�");
      delay(150);
      clrscr();
      gotoxy(47,20);
      delay(150);
      clrscr();
      gotoxy(20,10);
      cputs("  *-*-*-*-*-* ICICI BANK *-*-*-*-*-*");
      gotoxy(20,15);
      cputs("========================================");
      gotoxy(30,16);
      cputs("Press any Key to Continue..");
      gotoxy(20,17);
      cputs("========================================");
      getch();
      mainmenu();
      getch();
      }
     else
     {
      clrscr();
      gotoxy(20,9);
      cout<<"========================================";
      gotoxy(30,10);
      cout<<"Please check your password";
      gotoxy(20,11);
      cout<<"========================================";
      delay(2000);
      clrscr();
      gotoxy(20,9);
      cputs("========================================");
      gotoxy(30,10);
      cputs("PASSWORD IS INCORRECT");
      gotoxy(20,11);
      cputs("========================================");
      delay(1000);
      clrscr();
      gotoxy(20,10);
      textcolor(WHITE);
      cputs("YOU WILL BE OUT IN 10 SECONDS");
      delay(900);
      clrscr();
      gotoxy(20,10);
      textcolor(WHITE);
      cputs("YOU WILL BE OUT IN 9 SECONDS");
      delay(900);
      clrscr();
      gotoxy(20,10);
      textcolor(WHITE);
      cputs("YOU WILL BE OUT IN 8 SECONDS");
      delay(900);
      clrscr();
      gotoxy(20,10);
      textcolor(WHITE);
      cputs("YOU WILL BE OUT IN 7 SECONDS");
      delay(900);
      clrscr();
      gotoxy(20,10);
      textcolor(WHITE);
      cputs("YOU WILL BE OUT IN 6 SECONDS");
      delay(900);
      clrscr();
      gotoxy(20,10);
      textcolor(WHITE);
      cputs("YOU WILL BE OUT IN 5 SECONDS");
      delay(900);
      clrscr();
      gotoxy(20,10);
      textcolor(WHITE);
      cputs("YOU WILL BE OUT IN 4 SECONDS");
      delay(900);
      clrscr();
      gotoxy(20,10);
      textcolor(WHITE);
      cputs("YOU WILL BE OUT IN 3 SECONDS");
      delay(900);
      clrscr();
      gotoxy(20,10);
      textcolor(WHITE);
      cputs("YOU WILL BE OUT IN 2 SECONDS");
      delay(900);
      clrscr();
      gotoxy(20,10);
      textcolor(WHITE);
      cputs("YOU WILL BE OUT IN 1 SECONDS");
      delay(900);
      }

}

