
/*Admin mode
    ID = admin
    Password = pass
*/

#include<bits/stdc++.h>

using namespace std;

void user_page();           //User panel
void main_page();           //Home page
void admin_page();          //Admin panel

class TourBus
{
   public:
    int bid;
    char driver[20];
	char from[50];
	char to[50];
	char depart_from[10];
	char arrival_to[10];
	int max_seats=32;
	char seat_map[8][4][10];
	int booked;             //count booked ticket
	int fare;
    void input();           //Details input
	void show();            //Bus detail
	void display();         //Passenger + Bus Detail
	void position();
	void sempty();          //Bus seat filling
	void smap();            //Bus seat maping
	int getid()
	{
	return bid;
	}
	void book()
	{
        booked++;
	}
	void cancel()
	{
        booked--;
	}
	char* getfrom()
	{
	return from;
	}
	char* getto(){
        return to;
	}
	char* getdepart_from()
	{
	return depart_from;
	}
	char* getarrival_to()
	{
	return depart_from;
	}
	int getBooked()
	{
	return booked;
	}
	int getMax()
	{
	return max_seats;
	}
	int getFare()
	{
		return fare;
	}
};


void vline(char a){
    for(int i=120;i>0;i--)
        cout<<a;
    cout<<endl;
}
void TourBus::input()
{
	cout<<"\t\t\t\tEnter bus No ";
	cin>>bid;
	cout<<"\t\t\t\tEnter driver name ";
	cin>>driver;
	cout<<"\t\t\t\tBus from   ";
	cin>>from;
	cout<<"\t\t\t\tBus to  ";
	cin>>to;
	cout<<"\t\t\t\tTime at "<<getfrom()<<"  ";
	cin>>depart_from;
	cout<<"\t\t\t\tTime at "<<getto()<<"  ";
	cin>>arrival_to;
	cout<<"\t\t\t\tEnter fare of the bus ";
	cin>>fare;
}

void TourBus::display()
{
    cout<<"BUS NO"<<"\t"<<"DRIVER"<<"\t"<<"FROM"<<"\t"<<"TO"<<"\t"<<"DEPART TIME"<<"\t"<<"ARRIVAl TIME"<<"\t"<<"BOOKED"<<"\t  "<<"REMAINING SEATS"<<"\t"<<"FARE"<<"\n";
	vline('-');
	cout<<bid<<"\t"<<driver<<"\t"<<from<<"\t"<<to<<"\t"<<depart_from<<"\t\t"<<arrival_to<<"\t\t"<<booked<<"\t\t"<<max_seats-booked<<"\t\t"<<fare<<"\n";
    vline('-');
    smap();
}
void TourBus::show()
{
     
	cout<<"BUS NO"<<"\t\t"<<"FROM"<<"\t\t"<<"TO"<<"\t\t"<<"DEPART TIME"<<"\t\t"<<"ARRIVAl TIME"<<endl;
	vline('-');
	cout<<bid<<"\t\t"<<from<<"\t\t"<<to<<"\t\t"<<depart_from<<"\t\t\t"<<arrival_to;
    cout<<endl;
}

void TourBus::sempty()
{
    for(int i=0;i<8;i++)
        for(int j=0;j<4;j++)
            strcpy(seat_map[i][j],"Empty");
    }

void TourBus::smap(){
    position();
 int a=1;
 vline('-');
 for (int i=0; i<8; i++)
 {
   for(int j=0;j<4;j++)
   {
     a++;
     if(strcmp(seat_map[i][j],"Empty")!=0)
     cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<seat_map[i][j]<<".";
   }
 }
    cout<<endl;
}

void TourBus::position(){

    int s=0,p=0;
 for (int i=0; i<8;i++)
 {
   cout<<"\n";
   for (int j=0;j<4; j++)
   {
     s++;
     if(strcmp(seat_map[i][j], "Empty")==0)
       {
         cout.width(5);
         cout.fill(' ');
         cout<<s<<".";
         cout.width(10);
         cout.fill(' ');
         cout<<seat_map[i][j];
         p++;
       }
       else
       {
       cout.width(5);
       cout.fill(' ');
       cout<<s<<".";
       cout.width(10);
       cout.fill(' ');
       cout<<seat_map[i][j];
       }
     }
   }
 cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bid<<"\n";

}

void install()
	 {
         
        fstream F;
        TourBus b;
			F.open("tour.dat",ios::app | ios::binary);
			b.input();
			b.sempty();
			F.write((char*)&b, sizeof(b));
			F.close();
			cout<<"\t\t\t\tBus added Successfully "<<endl;

    }

    void select_bus()
    {
         
        fstream F;
        TourBus b;
			int id,chk=0;
			cout<<"\t\t\t\tEnter the Bus No ";
			cin>>id;
			F.open("tour.dat",ios::in | ios::binary);
			if(F.fail())
				cout<<"\n\n\n\t\t\t\tNo file Found "<<endl;
			else
			{
				while(F.read((char*)&b,sizeof(b)))
				{
					if(b.getid()==id)
					{
						b.display();
						chk=1;
						break;
					}
				}
				if(chk==0)
					cout<<"\t\t\t\tBus not Found"<<endl;
			}
			;
			F.close();
		}

    void all_installed()
    {
         
        fstream F;
        TourBus b;
        F.open("tour.dat",ios::in | ios::binary);
			if(F.fail())
				cout<<"\n\n\n\t\t\t\tNo file Found "<<endl;
			else
			{
				while(F.read((char*)&b,sizeof(b)))
					b.show();
			}
			F.close();
			;
    }

    void del_bus()
    {
         
        fstream G,F;
        TourBus b;
			int chk=0;
			int id;
			cout<<"\t\t\t\tEnter the Bus No to deleted ";
			cin>>id;
			F.open("tour.dat",ios::in | ios::binary);
			G.open("temp.dat",ios::out | ios::binary);
			if(F.fail())
				cout<<"\n\n\n\t\t\t\tNo file Found "<<endl;
			else
			{
				while(F.read((char*)&b,sizeof(b)))
				{
					if(b.getid()!=id)
					{
					G.write((char*)&b,sizeof(b));
					}
					else
					{
						b.show();
						chk=1;

					}
				}
				if(chk==0)
					cout<<"\t\t\t\tBus not Found"<<endl;

				else
					cout<<"\t\t\t\tBus Deleted "<<endl;
			}
			;
			F.close();
			G.close();
			remove("tour.dat");
			rename("temp.dat","tour.dat");

    }


    void allot()
    {
         
        fstream F,G;
        TourBus b;
			char cname[50];
			int seat;
			int bno;
			int chk;
			cout<<"\n\n\n\t\t\t\tEnter Bus Number ";
			cin>>bno;
			F.open("tour.dat",ios::in | ios::out | ios::binary);
			if(F.fail())
				cout<<"\n\n\n\t\t\t\tNo file Found "<<endl;
			else
			{
				while(F.read((char*)&b,sizeof(b)))
				{
					if(b.getid()==bno)
					{   b.display();
					    cout<<"\n\t\t\t\tEnter Seat No  ";
					    cin>>seat;
                        if(seat>32)
                            cout<<"\n\t\t\t\tThere are only 32 seats available in bus\n";
                        else{
                            if(strcmp(b.seat_map[seat/4][(seat%4)-1],"Empty")==0)
                            {
                                cout<<"\t\t\t\tEnter passanger's name: ";
                                cin>>cname;
                                b.book();
                                strcpy(b.seat_map[seat/4][(seat%4)-1],cname);
                                long int size=sizeof(b);
                                unsigned int c=F.tellg() - size;
                                F.seekp(c,ios::beg);
                                F.write((char*)&b,sizeof(b));
                                cout<<"\n\n\t\t\t\tTicket booked"<<endl;
                                break;
                            }
                            else
                                cout<<"\t\t\t\tSeat is already Reserved \n";
					}
				}
			}
			;
			F.close();
    }
}

void del_seat()
{
     
    fstream G,F;
    TourBus b;
    int id;
    char cname[50];
    cout<<"Enter bus no  ";
    cin>>id;
    F.open("tour.dat",ios::in | ios::out | ios::binary);
    while(F.read((char*)&b,sizeof(b)))
    {
        if(b.bid==id)
         {
            cout<<"Enter the Passenger Name  ";
            cin>>cname;
            for(int i=0;i<8;i++){
                for(int j=0;j<4;j++){
                    if(strcmp(b.seat_map[i][j],cname)==0)
                    {
                        strcpy(b.seat_map[i][j],"Empty");
                        F.seekp(-1 * sizeof(b),ios::cur);
                        b.cancel();
                        F.write((char*)&b,sizeof(b));
                        cout<<"Ticket Canceled";

                    }

                }
            }
         }
    ;
    }
  F.close();
}

void admin_login(){
    int i=0;
    char id[20],pass[20],c=' ';
    cout<<"\n\n\t\t\t\t\t\tEnter your ID  ";
    cin>>id;
    cout<<"\n\t\t\t\t\t\tEnter your Password  ";
    cin>>pass;
    if(strcmp(pass,"pass")==0){
        cout<<"\t\t\t\t\t\tWelcome to Admin Mode"<<endl;
        vline('-');
        admin_page();
    }
    else{
        cout<<"Wrong ID Password";
        main_page();
    }
}

void main_page()
{
     
    system("Color 0A");
    cout << "\n\n\n\n\n\t\t\t\t\tWelcome to BUS Management System" << endl;
    vline('-');
    cout<<"\t\t\t\t\t\tMAIN MENU\n\n\t\t\t\t\t\t1-USER MODE\n\t\t\t\t\t\t2-ADMIN MODE\n\t\t\t\t\t\t0-Exit";
    int ch=0;
    cout<<endl;
    vline('-');
    cin>>ch;
    switch(ch)
    {
    case 0:
        break;
    case 1:
        user_page();
        break;
    case 2:
        admin_login();
        break;
    default:
        cout<<"\n\n\t\t\t\t\t\tInvalid Input";
        ;
        main_page();
    }

}

void user_page()
{
         
         
        int ch;
        cout<<"\n\n\n\n\n\t\t\t\t\t\tUSER MODE\n"<<endl;
        cout<<"\t\t\t\t\t1 - Display All Buses"<<endl;
		cout<<"\t\t\t\t\t2 - Book a ticket "<<endl;
		cout<<"\t\t\t\t\t3 - Cancel a ticket "<<endl;
		cout<<"\t\t\t\t\t4 - Return to main page "<<endl;
		cout<<"\t\t\t\t\t5 - Exit "<<endl;
		cin>>ch;
		switch(ch)
		{
        case 1:
		    all_installed();
		    user_page();
		    break;

		case 2:
		    allot();
		    user_page();
		    break;
        case 3:
		    del_seat();
		    user_page();
		    break;
        case 4:
            main_page();
		default:
		    break;
    }

}

void admin_page(){
         
         
        int ch;
        cout<<"\n\n\n\n\n\t\t\t\t\t\tADMIN MODE"<<endl;
        vline('-');
        cout<<"\n";
		cout<<"\t\t\t\t\t1 - Add a New Bus"<<endl;
		cout<<"\t\t\t\t\t2 - Show Selected Bus"<<endl;
		cout<<"\t\t\t\t\t3 - Display All Buses"<<endl;
		cout<<"\t\t\t\t\t4 - Delete a Bus"<<endl;
		cout<<"\t\t\t\t\t5 - Book a ticket "<<endl;
		cout<<"\t\t\t\t\t6 - Cancel a ticket "<<endl;
		cout<<"\t\t\t\t\t7 - Return to main page "<<endl;
		cout<<"\t\t\t\t\t8 - Exit "<<endl;
		vline('-');
		cin>>ch;
		switch(ch){
		case 1:
		    install();
		    admin_page();
		    break;

		case 2:
		    select_bus();
		    admin_page();
		    break;

		case 3:
		    all_installed();
		    admin_page();
		    break;

		case 4:
		    del_bus();
		    admin_page();
		    break;

		case 5:
		    allot();
		    admin_page();
		    break;
        case 6:
		    del_seat();
		    admin_page();
		    break;
		case 7:
            main_page();

       default:
            break;

		}

}

int main()
{
    main_page();
}