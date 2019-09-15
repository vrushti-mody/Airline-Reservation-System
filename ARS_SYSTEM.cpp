#include<iostream>
#include<conio.h>
#include<string.h>
#include<cctype>
#include<iomanip>
#include<conio.h>
#include<string>
#include<windows.h>
#include<iomanip>
#include<fstream>
#include<iostream>
#include<ctype.h>
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/timeb.h>
#include<sys/utime.h>
#include<unistd.h>
#include<string.h>
#include<fstream>
#include<limits>
#include<iostream>

using namespace std;

class Passenger
{
    public:
        string flights;
        char username[20],mail[30];
        int choice,pay,tktno,pass1,pass2,pass3;
        double pno;
        fstream ofs;
 void register1()//Registration for host
    {
        int flag = 0;
        cout<<"Enter your name:"<<endl;
        cin>>username;
        mail1:
        cout<<"Enter your email id:"<<endl;
        cin>>mail;
        for(int f=0;f<sizeof(mail);f++)
            {
                if(mail[f]=='@' || mail[f]=='.')
                {
                    flag+=1;
                }
            }
                if(flag>1)
                {
                    goto phone;
                }
                else if(flag< 2)
                {
                    cout<<"Please enter a valid email address"<<endl;
                    goto mail1;
                }
        phone:
            do
            {
        cout<<"Enter your phone no:"<<endl;
        cin>>pno;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
    while(true);
            if(7000000000<=pno && pno<=9999999999)
                {
                    goto Password1;
                }
        else
        {
            cout<<"Please enter a valid phone number!"<<endl;
            goto phone;
        }
        do
        {
            Password1:
                do
                {

        cout<<"Enter password:\n(Password should be a four digit number)"<<endl;
         cin>>pass1;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
    while(true);
         if(pass1>=1000 && pass1<=9999)
         {
             do
             {
        cout<<"\nConfirm password:"<<endl;
        cin>>pass2;
           if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
    while(true);
         }
         else
            {
                cout<<"Your password must be a four digit number!"<<endl;
                goto Password1;
            }

        }
        while(pass1!=pass2);
    }

    void write_account()//store data
    {
	Passenger h1;
	ofstream outFile;
	outFile.open("A.txt",ios::app|ios::binary);
	h1.register1();
	outFile.write(reinterpret_cast<char *> (&h1), sizeof(Passenger));
	outFile.close();
    }

    int returnpassword() const
    {
        return pass1;
    }

    void login()
    {
        int n,i;
        char name[50];
        cout<<"Enter your name:"<<endl;
        cin>>name;
        repeat5:
        cout<<"Enter your password:"<<endl;
        do
        {
        cin>>n;
           if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
    while(true);
        Passenger h1;
        bool flag=false;
        ifstream inFile;
        inFile.open("A.txt",ios::binary);
        if(!inFile)
        {
		cout<<"Account could not be open !! Press any Key...";
		exit(0);
	}
        while(inFile.read(reinterpret_cast<char *> (&h1), sizeof(Passenger)))
	{
		if(h1.returnpassword()==n)
		{
		    flag=true;
			h1.show_account();

		}
	}
	inFile.close();
	if(flag==false)
    {
		cout<<"Incorrect password\n";
		goto repeat5;
    }
}

    void show_account()
    {
	cout<<"\nLogin Successful"<<endl;
	//create_event();
    }
    void view_flights()
    {
        ifstream File;
        int u=0;
        cout<<"FlightNo  Airline               Route         Time(24 Hr System)"<<endl;
         ifstream myfile ("Flights.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,flights) )
    {
        u++;
      cout <<u<<"\t"<< flights<< '\n';
    }
    myfile.close();
  }
  else
    cout << "Unable to open file";
    }
    void bookflights()
    {
        error:
        int a;
        do
        {
        cout<<"Enter Flight number";
        cin>>a;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"Error!"<<endl;
        }
        else{break;}
        }
        while(true);

        int p=0,u=0;
    ifstream file;
    ofstream ofs;
        switch(a)
        {
            case 1: {int seating[6][10];
                file.open("1.txt");
            while(!file.eof())
            {
                file>>seating[p][u];
                u++;
                if(u>9)
                {
                    p++;
                    u=0;
                }
            }
                file.close();
                 cout<<"0: available, 1:unavailable"<<endl;
                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        cout<<seating[i][j]<<"\t";
                    }
                    if (i==2)
                    {
                        cout<<endl;
                    }
                    cout<<endl;
                }
                int seatno;
                seat:
                    do
                    {
                cout<<"Enter seat number you want to book"<<endl;
                cin>>seatno;
                if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
    while(true);
                if(seating[(seatno/10)][(seatno%10)]==1 || seatno>60 || seatno<0)
                {
                    cout<<"Seat already booked!\nEnter an available seat";
                    goto seat;
                }
                else
                {
                    int r,s;
                    r=seatno/10;
                    //r=r-1;
                    s=seatno%10;
                    //s=s-1;
                    seating[r][s]=1;
                }

                      ofs.open("1.txt", ios::out | ios::trunc);
                    for(int k = 0 ; k < 6 ; k++){
                        for(int l = 0 ; l < 10 ; l++){
                            ofs<<seating[k][l]<<endl;
                           // cout<<"Hi!"<<endl;
                        }
                    }
                    ofs.close();

                string name,age,address;
                cout<<"Enter name of passenger"<<endl;
                cin>>name;
                cout<<"Enter age of passenger"<<endl;
                cin>>age;
                cout<<"Enter address of passenger"<<endl;
                cin>>address;
                cout<<"...........Booking Ticket..............\n";
                Sleep(5000);
                cout<<"Ticket Booked Successfully"<<endl;
                cout<<"Total Amount for ticket: Rs 5000"<<endl;

                    ofs.open("Passenger.txt", ios::out | ios::app);

                            ofs<<name<<"\t"<<age<<"\t"<<address<<"\t"<<a<<"\t\t"<<seatno<<endl;

                    ofs.close();
                    break;
                    }
                    case 2: {int seating[6][10];
                file.open("2.txt");
            while(!file.eof())
            {
                file>>seating[p][u];
                u++;
                if(u>9)
                {
                    p++;
                    u=0;
                }
            }
                file.close();
                 cout<<"0: available, 1:unavailable"<<endl;
                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        cout<<seating[i][j]<<"\t";
                    }
                    if (i==2)
                    {
                        cout<<endl;
                    }
                    cout<<endl;
                }
                int seatno;
                seat1:
                    do
                    {
                cout<<"Enter seat number you want to book"<<endl;
                cin>>seatno;
                if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
    while(true);
                if(seating[(seatno/10)][(seatno%10)]==1 || seatno>60 || seatno<0)
                {
                    cout<<"Seat already booked!\nEnter an available seat";
                    goto seat1;
                }
                else
                {
                    int r,s;
                    r=seatno/10;
                    //r=r-1;
                    s=seatno%10;
                    //s=s-1;
                    seating[r][s]=1;
                }

                      ofs.open("2.txt", ios::out | ios::trunc);
                    for(int k = 0 ; k < 6 ; k++){
                        for(int l = 0 ; l < 10 ; l++){
                            ofs<<seating[k][l]<<endl;
                           // cout<<"Hi!"<<endl;
                        }
                    }
                    ofs.close();

                string name,age,address;
                cout<<"Enter name of passenger"<<endl;
                cin>>name;
                cout<<"Enter age of passenger"<<endl;
                cin>>age;
                cout<<"Enter address of passenger"<<endl;
                cin>>address;
                cout<<"...........Booking Ticket..............\n";
                Sleep(5000);
                cout<<"Ticket Booked Successfully"<<endl;
                cout<<"Total Amount for ticket: Rs 5000"<<endl;

                    ofs.open("Passenger.txt", ios::out | ios::app);

                            ofs<<name<<"\t"<<age<<"\t"<<address<<"\t"<<a<<"\t\t"<<seatno<<endl;

                    ofs.close();
                    break;
                    }
                case 3: {int seating[6][10];
                file.open("3.txt");
            while(!file.eof())
            {
                file>>seating[p][u];
                u++;
                if(u>9)
                {
                    p++;
                    u=0;
                }
            }
                file.close();
                 cout<<"0: available, 1:unavailable"<<endl;
                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        cout<<seating[i][j]<<"\t";
                    }
                    if (i==2)
                    {
                        cout<<endl;
                    }
                    cout<<endl;
                }
                int seatno;
                seat2:
                    do
                    {
                cout<<"Enter seat number you want to book"<<endl;
                cin>>seatno;
                if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
    while(true);
                if(seating[(seatno/10)][(seatno%10)]==1 || seatno>60 || seatno<0)
                {
                    cout<<"Seat already booked!\nEnter an available seat";
                    goto seat2;
                }
                else
                {
                    int r,s;
                    r=seatno/10;
                    //r=r-1;
                    s=seatno%10;
                    //s=s-1;
                    seating[r][s]=1;
                }

                      ofs.open("3.txt", ios::out | ios::trunc);
                    for(int k = 0 ; k < 6 ; k++){
                        for(int l = 0 ; l < 10 ; l++){
                            ofs<<seating[k][l]<<endl;
                           // cout<<"Hi!"<<endl;
                        }
                    }
                    ofs.close();

                string name,age,address;
                cout<<"Enter name of passenger"<<endl;
                cin>>name;
                cout<<"Enter age of passenger"<<endl;
                cin>>age;
                cout<<"Enter address of passenger"<<endl;
                cin>>address;
                cout<<"...........Booking Ticket..............\n";
                Sleep(5000);
                cout<<"Ticket Booked Successfully"<<endl;
                cout<<"Total Amount for ticket: Rs 5000"<<endl;

                    ofs.open("Passenger.txt", ios::out | ios::app);

                            ofs<<name<<"\t"<<age<<"\t"<<address<<"\t"<<a<<"\t\t"<<seatno<<endl;

                    ofs.close();
                    break;
                    }
                case 4: {int seating[6][10];
                file.open("4.txt");
            while(!file.eof())
            {
                file>>seating[p][u];
                u++;
                if(u>9)
                {
                    p++;
                    u=0;
                }
            }
                file.close();
                 cout<<"0: available, 1:unavailable"<<endl;
                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        cout<<seating[i][j]<<"\t";
                    }
                    if (i==2)
                    {
                        cout<<endl;
                    }
                    cout<<endl;
                }
                int seatno;
                seat4:
                    do
                    {
                cout<<"Enter seat number you want to book"<<endl;
                cin>>seatno;
                if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
    while(true);
                if(seating[(seatno/10)][(seatno%10)]==1 || seatno>60 || seatno<0)
                {
                    cout<<"Seat already booked!\nEnter an available seat";
                    goto seat4;
                }
                else
                {
                    int r,s;
                    r=seatno/10;
                    //r=r-1;
                    s=seatno%10;
                    //s=s-1;
                    seating[r][s]=1;
                }

                      ofs.open("4.txt", ios::out | ios::trunc);
                    for(int k = 0 ; k < 6 ; k++){
                        for(int l = 0 ; l < 10 ; l++){
                            ofs<<seating[k][l]<<endl;
                           // cout<<"Hi!"<<endl;
                        }
                    }
                    ofs.close();

                string name,age,address;
                cout<<"Enter name of passenger"<<endl;
                cin>>name;
                cout<<"Enter age of passenger"<<endl;
                cin>>age;
                cout<<"Enter address of passenger"<<endl;
                cin>>address;
                cout<<"...........Booking Ticket..............\n";
                Sleep(5000);
                cout<<"Ticket Booked Successfully"<<endl;
                cout<<"Total Amount for ticket: Rs 5000"<<endl;

                    ofs.open("Passenger.txt", ios::out | ios::app);

                            ofs<<name<<"\t"<<age<<"\t"<<address<<"\t"<<a<<"\t\t"<<seatno<<endl;

                    ofs.close();
                    break;
                    }
                    case 5: {int seating[6][10];
                file.open("5.txt");
            while(!file.eof())
            {
                file>>seating[p][u];
                u++;
                if(u>9)
                {
                    p++;
                    u=0;
                }
            }
                file.close();
                 cout<<"0: available, 1:unavailable"<<endl;
                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        cout<<seating[i][j]<<"\t";
                    }
                    if (i==2)
                    {
                        cout<<endl;
                    }
                    cout<<endl;
                }
                int seatno;
                seat5:
                    do
                    {
                cout<<"Enter seat number you want to book"<<endl;
                cin>>seatno;
                if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
    while(true);
                if(seating[(seatno/10)][(seatno%10)]==1 || seatno>60 || seatno<0)
                {
                    cout<<"Seat already booked!\nEnter an available seat";
                    goto seat5;
                }
                else
                {
                    int r,s;
                    r=seatno/10;
                    //r=r-1;
                    s=seatno%10;
                    //s=s-1;
                    seating[r][s]=1;
                }

                      ofs.open("5.txt", ios::out | ios::trunc);
                    for(int k = 0 ; k < 6 ; k++){
                        for(int l = 0 ; l < 10 ; l++){
                            ofs<<seating[k][l]<<endl;
                           // cout<<"Hi!"<<endl;
                        }
                    }
                    ofs.close();

                string name,age,address;
                cout<<"Enter name of passenger"<<endl;
                cin>>name;
                cout<<"Enter age of passenger"<<endl;
                cin>>age;
                cout<<"Enter address of passenger"<<endl;
                cin>>address;
                cout<<"...........Booking Ticket..............\n";
                Sleep(5000);
                cout<<"Ticket Booked Successfully"<<endl;
                cout<<"Total Amount for ticket: Rs 5000"<<endl;

                    ofs.open("Passenger.txt", ios::out | ios::app);

                            ofs<<name<<"\t"<<age<<"\t"<<address<<"\t"<<a<<"\t\t"<<seatno<<endl;

                    ofs.close();
                    break;
                    }
                    default: "Error! Enter Accurate flight Number\n";
                    goto error;

        }
    }
    void feedback()
    {
        string name,airline,comments;
        cout<<"............Feedback form....................."<<endl;
        cout<<"Passenger name:"<<endl;
        cin>>name;
        cout<<"Airline:"<<endl;
        cin>>airline;
        cout<<"Comments:"<<endl;
        cin>>comments;
        ofs.open("Feedback.txt", ios::out | ios::app);

                            ofs<<"Passenger name:"<<name<<"\n"<<"Airline:"<<airline<<"\n"<<"Comments:"<<comments<<"\n----------------------------------------------\n";

                    ofs.close();

    }
    void instructions()
    {
        int a;
        inst:
        string flights;
        cout<<"---------------------------------------Beginner's Guide to Traveling in a plane---------------------------------------\n1.Prior to Flight Date\n2.Before the flight\n3.In flight\n4.After the flight\n5.Exit"<<endl;
    do
    {
        cin>>a;
        system("cls");
        if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
    while(true);
    switch(a)
    {

    case 1:{
        ifstream myfile ("Prior.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,flights) )
    {

      cout <<"\n"<<flights<<"\n";
    }
    myfile.close();
    }
    Sleep(1000);
    goto inst;

    }
      case 2:{
        ifstream myfile ("Before.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,flights) )
    {

      cout <<"\n"<<flights<<"\n";
    }
    myfile.close();
    }
    Sleep(1000);
    goto inst;

    }
      case 3:{
        ifstream myfile ("In.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,flights) )
    {

      cout <<"\n"<<flights<<"\n";
    }
    myfile.close();
    }
    Sleep(1000);
    goto inst;

    }
      case 4:{
        ifstream myfile ("After.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,flights) )
    {

      cout <<"\n"<<flights<<"\n";
    }
    myfile.close();
    }
    Sleep(1000);
    goto inst;

    }
      case 5:{
        break;

    }
    default: {"Error\n";
                goto inst;}
    }


    }


};

class Admin
{
     fstream ofs;
 ifstream File;

    public:
    char username[20],mail[30],source[30],destination[30];
     int choice,pay,tktno,pass1,pass2,pass3;
      double pno;

 void register1()//Registration for host
    {
        int flag = 0;
        cout<<"Enter your name:"<<endl;
        cin>>username;
        mail1:
        cout<<"Enter your email id:"<<endl;
        cin>>mail;
        for(int f=0;f<sizeof(mail);f++)
            {
                if(mail[f]=='@' || mail[f]=='.')
                {
                    flag+=1;
                }
            }
                if(flag>1)
                {
                    goto phone;
                }
                else if(flag< 2)
                {
                    cout<<"Please enter a valid email address"<<endl;
                    goto mail1;
                }
        phone:
        cout<<"Enter your phone no:"<<endl;
        do
        {
        cin>>pno;
        if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
            while(true);
        if(7000000000<=pno && pno<=9999999999)
            {
                goto Password;
            }
        else
        {
            cout<<"Please enter a valid phone number!"<<endl;
            goto phone;
        }
        do
        {
            Password:
        cout<<"Enter password:\n(Password should be a four digit number)"<<endl;
        do
        {
         cin>>pass1;
         if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
            while(true);
         if(pass1>=1000 && pass1<=9999)
         {
             do
             {
        cout<<"\nConfirm password:"<<endl;
        cin>>pass2;
        if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
              while(true);
         }

         else
            {
                cout<<"Your password must be a four digit number!"<<endl;
                goto Password;
            }

        }
        while(pass1!=pass2);
    }

    void write_account()//store data
    {
	Admin h1;
	ofstream outFile;
	outFile.open("Account.txt",ios::app|ios::binary);
	h1.register1();
	outFile.write(reinterpret_cast<char *> (&h1), sizeof(Admin));
	outFile.close();
    }

    int returnpassword() const
    {
        return pass1;
    }

    void login()
    {
        int n;
        char name[50];
        cout<<"Enter your name:"<<endl;
        cin>>name;
        repeat1:
            do
            {
        cout<<"Enter your password:"<<endl;
        cin>>n;
         if(cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout<<"Error!"<<endl;
            }
            else
            {
                break;
            }
            }
    while(true);

        Admin h1;
        bool flag=false;
        ifstream inFile;
        inFile.open("Account.txt",ios::binary);
        if(!inFile)
        {
		cout<<"Account could not be open !! Press any Key...";
		exit(0);
	}
        while(inFile.read(reinterpret_cast<char *> (&h1), sizeof(Admin)))
	{
		if(h1.returnpassword()==n)
		{
		    flag=true;
			h1.show_account();

		}
	}
	inFile.close();
	if(flag==false)
     {
	 	cout<<"Incorrect password\n";
		goto repeat1;
     }
    }

    void show_account()
    {
	cout<<"\nLogin Successful"<<endl;
	//create_event();
    }

    void create_flights()
    {
      string source,destination,time,airline;
      cout<<"Enter source and destination"<<endl;
      cin>>source>>destination;
      cout<<"Enter the departure time(24hr System)"<<endl;
      cin>>time;
      cout<<"Airline Name:"<<endl;
      cin>>airline;
	 ofs.open("Flights.txt", ios::out | ios::app);

                            ofs<<airline<<"\t\t"<<source<<"-------->"<<destination<<"\t\t"<<time<<endl;

                    ofs.close();
                    cout<<"Flight Added"<<endl;
    }
    void ViewPassengers()
    {

        int u=0;
        string flights;
        cout<<"SrNo    Name    Age     Address    Flight No   SeatNo"<<endl;
         ifstream myfile ("Passenger.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,flights) )
    {
        u++;
      cout <<u<<"\t"<< flights<< '\n';
    }
    myfile.close();
    }
    }
    void viewfeedback()
    {
        int u=0;
        string flights;
        cout<<"...............Passenger Feedback..............."<<endl;
         ifstream myfile ("Feedback.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,flights) )
    {

      cout <<"\n"<<flights<<"\n";
    }
    myfile.close();
    }
    }

};
    int main()
{
    system("color 5f");
 cout<<"\n\n\n\n\n\n\n\n\n\n\t\t     WELCOME TO AIRWAYS RESERVATION SYSTEM";
 Sleep(2500);
 system ("cls");
 cout<<"\n\n\n\n\n\n\n\t\t          Developed by :";
 Sleep(500);
 cout<<" Vrushti Mody";
 Sleep(500);
 system("cls");
     int choice1,choice,choice2,n,p;
     string name,guestname,password;
     char ch;
     Admin h1;
     Passenger p1;
     initial:
         do
         {
     cout<<"Login as\n1.Admin\n2.Passenger\n3.Exit"<<endl;
     cin>>choice;
     if(cin.fail())
        {
            //Clear the fail state.
            cin.clear();
            //Ignore the rest of the wrong user input, till the end of the line.
            cin.ignore(std::numeric_limits<std::streamsize>::max(),\
                                                    '\n');
            cout<<"Error!"<<endl;
        }
        else
        {
            break;
        }
         }
    while(true);
    system("cls");

      switch(choice)
        {
        case 1:
                char ch;
                cout << "Enter Admin Authentication Key\n";
                    ch = _getch();
                    while(ch != 13){//character 13 is enter
                        password.push_back(ch);
                        cout << '*';
                        ch = _getch();
                        }
                            if(password == "5977"){
                            cout << "\nAccess granted.....\n";
                             Sleep(500);
                            system("cls");
                            }
                            else    {
                                cout << "\nAccess aborted...\n";
                                Sleep(500);
                            system("cls");
                            goto initial;
            }
            start:
                do
                {
            cout<<"1.Sign up\n2.Login\n3.Back"<<endl;
            cin>>choice1;
             if(cin.fail())
        {
            //Clear the fail state.
            cin.clear();
            //Ignore the rest of the wrong user input, till the end of the line.
            cin.ignore(std::numeric_limits<std::streamsize>::max(),\
                                                    '\n');
            cout<<"Error!"<<endl;
        }
         else
        {
            break;
        }
         }
    while(true);
            switch(choice1)
                {
                    case 1:
                        h1.write_account();
                        system("cls");
                        cout<<"........LOGIN........"<<endl;
                        goto login;
                        break;
                    case 2:
                        login:
                        h1.login();
                        int a;
                        s:
                            do
                            {

                        cout<<"What would you like to do?\n1.Add Flights\n2.View Passengers\n3.View Passenger Feedback\n4.Logout"<<endl;
                        cin>>a;
                        system("cls");
                         if(cin.fail())
                        {
                            cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                    cout<<"Error!"<<endl;
                        }
                         else
                            {
                                break;
                            }
                            }
                        while(true);
                        switch(a)
                        {
                         case 1:   h1.create_flights();
                                    system("cls");
                                     goto s;

                         case 2: h1.ViewPassengers();
                                  //system("cls");
                                    goto s;
                        case 3: h1.viewfeedback();
                                // system("cls");
                                    goto s;
                        case 4:   system("cls");
                                    goto initial;
                        default: cout<<"Error!Enter a correct option\n";
                                goto s;
                        }
                        break;
                    case 3:
                        system("cls");
                        goto initial;
                        break;
                        default: cout<<"Error";
                        goto start;
                        }
                        break;
        case 2: //Passenger
            start1:
                do
                {
            cout<<"1.Sign up\n2.Login\n3.Back"<<endl;
            cin>>choice2;
             if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"Error!"<<endl;
        }
        else
        {
            break;
        }
         }
    while(true);
            switch(choice2)
                {
                    case 1:
                        p1.write_account();
                        system("cls");
                        cout<<"........LOGIN........"<<endl;
                        goto login1;
                        break;
                    case 2:
                        login1:
                        int a;
                        p1.login();
                        s1:
                            do
                            {
                        cout<<"What would you like to do?\n1.View Flights\n2.Feedback\n3.Beginners Guide To Travel In a Plane\n4.Logout"<<endl;
                        cin>>a;
                               if(cin.fail())
                                {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                    cout<<"Error!"<<endl;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            while(true);
                        switch(a)
                        {
                         case 1: {
                                    int a;
                                    p1.view_flights();
                                    do
                                    {
                                    d:
                                    cout<<"Do you want to\n1.Book Flight Ticket\n2.Go back to Home Screen\n3.Logout"<<endl;
                                    cin>>a;
                                           if(cin.fail())
                                                    {
                                                        cin.clear();
                                                        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                                                        cout<<"Error!"<<endl;
                                                    }
                                            else
                                            {
                                                break;
                                            }
                                    }
                                            while(true);
                                    switch(a)
                                    {
                                        case 1: p1.bookflights();
                                                goto d;
                                        case 2:system("cls");
                                            goto s1;
                                        case 3:system("cls");
                                                goto initial;
                                        default:"Error";
                                                goto d;
                                    }
                                    }
                                    break;
                         case 2: system("cls");
                            p1.feedback();
                            cout<<"\nFeedback Recorded!"<<endl;
                            Sleep(1000);
                            goto s1;

                             case 3: p1.instructions();
                             system("cls");
                                    goto s1;

                                 case 4:
                             system("cls");
                             goto initial;
                        }
                    case 3:
                            system("cls");
                            goto initial;
                            break;
                        default: cout<<"Error";
                    goto start1;
                }
                        break;
        case 3: break;

        default: cout<<"Error";
                goto initial;
        }


}
