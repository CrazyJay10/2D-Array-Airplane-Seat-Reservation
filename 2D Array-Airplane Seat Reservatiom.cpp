#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


int main(){
	int row, col, mainchoice, tclass;
	char seatplan[10][6], reserveagain, reserveagain2;
	
	for(int x=0 ; x<10; x++)
		for(int y=0; y<6; y++)
			seatplan[x][y]= '*';
	
	do{
	Main:
	system("cls");
	cout<<"\n\t---------------------------------------------------------------------------------------- \n";
	cout<<"\t||||||||||||||||||||||||||||||| WELCOME TO J & J AIRLINE ||||||||||||||||||||||||||||||| ";	
	cout<<"\n\t---------------------------------------------------------------------------------------- \n"<<endl;
	cout<<endl;
	cout<<"\t[1] SEAT RESERVATION "<<endl;
	cout<<"\t[2] DISPLAY SEAT PLAN\n"<<endl;
	cout<<"\t[3] EXIT THE AIRLINE"<<endl;
	cout<<endl;
	cout<<"\tEnter Choice: ";
	cin>>mainchoice;
	
	if(mainchoice!=1 && mainchoice!=2 && mainchoice!=3){
		cout<<"\n\tInvalid choice\n\t";
		system("pause");
		goto Main;
	}
	//Seat Reservation layout
	if(mainchoice==1){
	wrongclass:
		system("cls");		
		cout<<"\n\t---------------------------------------------------------------------------------------- \n";
		cout<<"\t||||||||||||||||||||||||||||||| WELCOME TO J & J AIRLINE ||||||||||||||||||||||||||||||| ";	
		cout<<"\n\t---------------------------------------------------------------------------------------- \n"<<endl;
		cout<<endl;
		
		cout<<"\tRow 1-2 = First Class\t	Row 3-4 = Business Class\tRow 5-10 = Economy Class\n"<<endl;
		cout<<"\tCHOOSE TICKET TYPE"<<endl;
		cout<<"\t[1] First Class"<<endl;
		cout<<"\t[2] Business Class"<<endl;
		cout<<"\t[3] Economy Class"<<endl;
		cout<<endl;
		cout<<"\tEnter Choice: ";
		cin>>tclass;
			if(tclass!=1 && tclass!=2 && tclass!=3){
			cout<<"\n\tINVALID CHOICE FOR TICKET CLASS\n\t";
			system("pause");
			goto wrongclass;
			}
		cout<<"\n\tPlease Enter your preffered seat by using the coordinate Row[space]Column. Ex. (1 3)\n"<<endl;
				cout<<"\t         1     2     3     4     5     6\n";
				cout<<"\t      +-----+-----+-----+-----+-----+-----+\n";
				cout<<"\tRow 1 |     |     |  O  |     |     |     |\n"<<endl;
				cout<<"\tEnter Seat Coordinate: ";
				cin>> row >> col;
		
		if(col<1 || col>6){
			cout << "\n1\t--------------------------------\n";
			cout<<"\tINVALID COLUMN, YOU ARE OUTSIDE OF THE PLANE, TAKE CARE!"<<endl;
			cout << "\t--------------------------------\n\t";
			system("pause");
			goto wrongclass;
		}
	
		
		switch(tclass){
			case 1 : 	if (row != 1 && row != 2)
				{
					cout << "\n\t--------------------------------\n";
					cout<<"\tINVALID SEAT NUMBER FOR FIRST CLASS!"<<endl;
					cout << "\t--------------------------------\n\t";
					system("pause");
					goto wrongclass;
				}
				else if(seatplan[row-1][col-1]=='X'){
					cout << "\n\t-----------------------------";
					cout << "\n\tThis seat is already occupied.";
					cout << "\n\t-----------------------------\n\t";
					system("pause");
					goto wrongclass;
				} 
				else{seatplan[row-1][col-1]='X';
				cout << "\n\t--------------------------------"<<endl;
				cout<<"\t| Your seat has been reserved. |";
				cout << "\n\t--------------------------------\n"<<endl;
				}
				break;
			case 2 : 	if (row != 3 && row != 4)
				{	
					cout << "\n\t--------------------------------\n"<<endl;
					cout<<"\tINVALID SEAT NUMBER FOR BUSINESS CLASS!"<<endl;
					cout << "\t--------------------------------\n\t"<<endl;
					system("pause");
					goto wrongclass;
				}
				else if(seatplan[row-1][col-1]=='X'){
					cout << "\n\t-----------------------------";
					cout << "\n\tThis seat is already occupied.";
					cout << "\n\t-----------------------------\n\t";
					system("pause");
					goto wrongclass;
				} 
				else{seatplan[row-1][col-1]='X';
				cout << "\n\t-----------------------------"<<endl;
				cout<<"\tYour seat has been reserved. "<<endl;
				cout << "\n\t-----------------------------\n"<<endl;
				}
				break;
			case 3 :	if (row != 5 && row != 6 && row != 7 && row != 8 && row != 9 && row != 10)
				{	
					cout << "\n\t--------------------------------\n";
					cout<<"\tINVALID SEAT NUMBER FOR ECONOMY CLASS!"<<endl;
					cout << "\t--------------------------------\n\t";
					system("pause");
					goto wrongclass;
				}
				
				else if(seatplan[row-1][col-1]=='X'){
					cout << "\n\t-----------------------------";
					cout << "\n\tThis seat is already occupied.";
					cout << "\n\t-----------------------------\n\t";
					system("pause");
					
				} 
				 
				else{seatplan[row-1][col-1]='X';
				cout << "\n\t-----------------------------"<<endl;
				cout<<"\tYour seat has been reserved. "<<endl;
				cout << "\n\t-----------------------------\n"<<endl;
				 	
				}
				break;
		}
		//try again
	exitreservation:	
		cout<<endl;
		cout<<"\tDo you want to reserve again? [Y/N]: ";
		cin>>reserveagain;
		
		if(reserveagain!='y' && reserveagain!='Y' && reserveagain!='n'  && reserveagain!='N'   ){
			cout<<"Invalid choice!";
			goto exitreservation;
	}
		if(reserveagain=='y' || reserveagain=='Y'){
			goto wrongclass;
		}
		else{goto Main;
		}
	
		//
	}
	//display of array
	else if(mainchoice==2){
		system("cls");
		cout<<"\n\t---------------------------------------------------------------------------------------- \n";
		cout<<"\t||||||||||||||||||||||||||||||| WELCOME TO J & J AIRLINE ||||||||||||||||||||||||||||||| ";	
		cout<<"\n\t---------------------------------------------------------------------------------------- "<<endl;
		cout<<"\t'*' = AVAILABLE"<<endl;
		cout<<"\t'X' = OCCUPIED"<<endl;
		
		cout<<"\t           1       2       3       4       5       6\n";
		for(int i=0; i<10; i++){
			cout<<"\t      +--------+-------+-------+-------+-------+-------+\n";
			cout << left << "\tRow " << setw(2) << i+1<< "| ";
			for(int j=0; j<6; j++){
					cout << right << setw(4)<<seatplan[i][j] << "   |";
			}
			cout<<endl;
		}	
		cout<<"\t      +--------+-------+-------+-------+-------+-------+\n";
		cout<<"\n";
		
	
	
	exitdisplay:	
		cout<<"\tDo you want to reserve again? [Y/N]: ";
		cin>>reserveagain2;
		
		if(reserveagain2!='y' && reserveagain2!='Y' && reserveagain2!='n'  && reserveagain2!='N'   ){
			cout<<"\tInvalid choice!\n";
			goto exitdisplay;
	}
		if(reserveagain2=='y' || reserveagain2=='Y'){
			goto wrongclass;
		}
		else{goto Main;
		}
	}
	
	
	//end of display
	else if(mainchoice==3){
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |";
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[                           YOUR   FLIGHT   SAFE   WITH   US      ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                            ||"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[                         YOUR   FLIGHT   SAFE   WITH   US        ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                           __|"<<endl;
		cout<<"\t|                                                                                                          |u |"<<endl;
		cout<<"\t|                                                                                                            -|"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[                       YOUR   FLIGHT   SAFE   WITH   US          ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                            _|"<<endl;
		cout<<"\t|                                                                                                         __/[|"<<endl;
		cout<<"\t|                                                                                                        |u   |"<<endl;
		cout<<"\t|                                                                                                          ---|"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[                     YOUR   FLIGHT   SAFE   WITH   US            ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                          ___|"<<endl;
		cout<<"\t|                                                                                                       __/[] |"<<endl;
		cout<<"\t|                                                                                                      |u     |"<<endl;
		cout<<"\t|                                                                                                        -----|"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[                   YOUR   FLIGHT   SAFE   WITH   US              ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                        _____|"<<endl;
		cout<<"\t|                                                                                                     __/[]   |"<<endl;
		cout<<"\t|                                                                                                    |u       |"<<endl;
		cout<<"\t|                                                                                                      -------|"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[                 YOUR   FLIGHT   SAFE   WITH   US                ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                      _______|"<<endl;
		cout<<"\t|                                                                                                   __/[]     |"<<endl;
		cout<<"\t|                                                                                                  |u         |"<<endl;
		cout<<"\t|                                                                                                    ---------|"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[               YOUR   FLIGHT   SAFE   WITH   US                  ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                    _________|"<<endl;
		cout<<"\t|                                                                                                 __/[]      [|"<<endl;
		cout<<"\t|                                                                                                |u           |"<<endl;
		cout<<"\t|                                                                                                  -----------|"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[             YOUR   FLIGHT   SAFE   WITH   US                    ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                  ___________|"<<endl;
		cout<<"\t|                                                                                               __/[]      [][|"<<endl;
		cout<<"\t|                                                                                              |u             |"<<endl;
		cout<<"\t|                                                                                                -------------|"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[           YOUR   FLIGHT   SAFE   WITH   US                      ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                _____________|"<<endl;
		cout<<"\t|                                                                                             __/[]      [][][|"<<endl;
		cout<<"\t|                                                                                            |u              _|"<<endl;
		cout<<"\t|                                                                                              -------------*-|"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[         YOUR   FLIGHT   SAFE   WITH   US                        ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                              _______________|"<<endl;
		cout<<"\t|                                                                                           __/[]      [][][][|"<<endl;
		cout<<"\t|                                                                                          |u              ___|"<<endl;
		cout<<"\t|                                                                                            -------------*-__|"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[       YOUR   FLIGHT   SAFE   WITH   US                          ]\n\n\n\n\t";
		
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                            _________________|"<<endl;
		cout<<"\t|                                                                                         __/[]      [][][][][|"<<endl;
		cout<<"\t|                                                                                        |u              _____|"<<endl;
		cout<<"\t|                                                                                          -------------*-__-_|"<<endl;
		cout<<"\t|                                                                                                             | "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[     YOUR   FLIGHT   SAFE   WITH   US                            ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                          ___________________|"<<endl;
		cout<<"\t|                                                                                       __/[]      [][][][][][|"<<endl;
		cout<<"\t|                                                                                      |u              _______|"<<endl;
		cout<<"\t|                                                                                        -------------*-__-__-|"<<endl;
		cout<<"\t|                                                                                                           -_| "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[   YOUR   FLIGHT   SAFE   WITH   US                              ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                            _|"<<endl;
		cout<<"\t|                                                                                        _____________________|"<<endl;
		cout<<"\t|                                                                                     __/[]      [][][][][][][|"<<endl;
		cout<<"\t|                                                                                    |u              _________|"<<endl;
		cout<<"\t|                                                                                      -------------*-__-__-__|"<<endl;
		cout<<"\t|                                                                                                         -__-| "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[ YOUR   FLIGHT   SAFE   WITH   US                                ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                          __-|"<<endl;
		cout<<"\t|                                                                                      _______________________|"<<endl;
		cout<<"\t|                                                                                   __/[]      [][][][][][][][|"<<endl;
		cout<<"\t|                                                                                  |u              ___________|"<<endl;
		cout<<"\t|                                                                                    -------------*-__-__-__-_|"<<endl;
		cout<<"\t|                                                                                                       -__-__| "<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[OUR   FLIGHT   SAFE   WITH   US                                  ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                        __-__|"<<endl;
		cout<<"\t|                                                                                    _________________________|"<<endl;
		cout<<"\t|                                                                                 __/[]      [][][][][][][][][|"<<endl;
		cout<<"\t|                                                                                |u              _____________|"<<endl;
		cout<<"\t|                                                                                  -------------*-__-__-__-__-|"<<endl;
		cout<<"\t|                                                                                                     -__-__-_| "<<endl;
		cout<<"\t|                                                                                                            -|"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[R   FLIGHT   SAFE   WITH   US                                    ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                      __-__-_|"<<endl;
		cout<<"\t|                                                                                  ___________________________|"<<endl;
		cout<<"\t|                                                                               __/[]      [][][][][][][][][][|"<<endl;
		cout<<"\t|                                                                              |u              ______________ |"<<endl;
		cout<<"\t|                                                                                -------------*-__-__-__-__-__|"<<endl;
		cout<<"\t|                                                                                                   -__-__-__-| "<<endl;
		cout<<"\t|                                                                                                          -__|"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[  FLIGHT   SAFE   WITH   US                                      ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                            _|"<<endl;
		cout<<"\t|                                                                                                    __-__-__-|"<<endl;
		cout<<"\t|                                                                                _____________________________|"<<endl;
		cout<<"\t|                                                                             __/[]      [][][][][][][][][][] |"<<endl;
		cout<<"\t|                                                                            |u              ______________   |"<<endl;
		cout<<"\t|                                                                              -------------*-__-__-__-__-__-_|"<<endl;
		cout<<"\t|                                                                                                 -__-__-__-__| "<<endl;
		cout<<"\t|                                                                                                        -__-_|"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[FLIGHT   SAFE   WITH   US                                        ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                          __-|"<<endl;
		cout<<"\t|                                                                                                  __-__-__-__|"<<endl;
		cout<<"\t|                                                                              _______________________________|"<<endl;
		cout<<"\t|                                                                           __/[]      [][][][][][][][][][]  J|"<<endl;
		cout<<"\t|                                                                          |u              ______________   Ai|"<<endl;
		cout<<"\t|                                                                            -------------*-__-__-__-__-__-__-|"<<endl;
		cout<<"\t|                                                                                               -__-__-__-__-_| "<<endl;
		cout<<"\t|                                                                                                      -__-__-|"<<endl;
		cout<<"\t|                                                                                                             |\n\n\n"<<endl;
		cout<<"\t\t\t[IGHT   SAFE   WITH   US                                          ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                        __--_|"<<endl;
		cout<<"\t|                                                                                                __-__-__-__- |"<<endl;
		cout<<"\t|                                                                            _________________________________|"<<endl;
		cout<<"\t|                                                                         __/[]      [][][][][][][][][][]  J &|"<<endl;
		cout<<"\t|                                                                        |u              ______________   Airl|"<<endl;
		cout<<"\t|                                                                          -------------*-__-__-__-__-__-__---|"<<endl;
		cout<<"\t|                                                                                             -__-__-__-__-__ | "<<endl;
		cout<<"\t|                                                                                                    -__-__-__|"<<endl;
		cout<<"\t|                                                                                                           -_|\n\n\n"<<endl;
		cout<<"\t\t\t[HT   SAFE   WITH   US                                            ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                      __--_--|"<<endl;
		cout<<"\t|                                                                                              __-__-__-__-   |"<<endl;
		cout<<"\t|                                                                          ___________________________________|"<<endl;
		cout<<"\t|                                                                       __/[]      [][][][][][][][][][]  J & J|"<<endl;
		cout<<"\t|                                                                      |u              ______________   Airlin|"<<endl;
		cout<<"\t|                                                                        -------------*-__-__-__-__-__-__-----|"<<endl;
		cout<<"\t|                                                                                           -__-__-__-__-__   | "<<endl;
		cout<<"\t|                                                                                                  -__-__-__-_|"<<endl;
		cout<<"\t|                                                                                                         -__-|\n\n\n"<<endl;
		cout<<"\t\t\t[   SAFE   WITH   US                                              ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                             |"<<endl;
		cout<<"\t|                                                                                                    __--_--- |"<<endl;
		cout<<"\t|                                                                                            __-__-__-__-    /|"<<endl;
		cout<<"\t|                                                                        ___________________________________/_|"<<endl;
		cout<<"\t|                                                                     __/[]      [][][][][][][][][][]  J & J  |"<<endl;
		cout<<"\t|                                                                    |u              ______________   Airline |"<<endl;
		cout<<"\t|                                                                      -------------*-__-__-__-__-__-__-------|"<<endl;
		cout<<"\t|                                                                                         -__-__-__-__-__     | "<<endl;
		cout<<"\t|                                                                                                -__-__-__-__ |"<<endl;
		cout<<"\t|                                                                                                       -__-__|\n\n\n"<<endl;
		cout<<"\t\t\t[ SAFE   WITH   US                                                ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                            _|"<<endl;
		cout<<"\t|                                                                                                  __--_--- / |"<<endl;
		cout<<"\t|                                                                                          __-__-__-__-    /  |"<<endl;
		cout<<"\t|                                                                      ___________________________________/___|"<<endl;
		cout<<"\t|                                                                   __/[]      [][][][][][][][][][]  J & J   -|"<<endl;
		cout<<"\t|                                                                  |u              ______________   Airline   |"<<endl;
		cout<<"\t|                                                                    -------------*-__-__-__-__-__-__-------**|"<<endl;
		cout<<"\t|                                                                                       -__-__-__-__-__       | "<<endl;
		cout<<"\t|                                                                                              -__-__-__-__   |"<<endl;
		cout<<"\t|                                                                                                     -__-__--|\n\n\n"<<endl;
		cout<<"\t\t\t[AFE   WITH   US                                                  ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                          ___|"<<endl;
		cout<<"\t|                                                                                                __--_--- /  ||"<<endl;
		cout<<"\t|                                                                                        __-__-__-__-    /   ||"<<endl;
		cout<<"\t|                                                                    ___________________________________/____||"<<endl;
		cout<<"\t|                                                                 __/[]      [][][][][][][][][][]  J & J   ---|"<<endl;
		cout<<"\t|                                                                |u              ______________   Airline   _-|"<<endl;
		cout<<"\t|                                                                  -------------*-__-__-__-__-__-__-------**  |"<<endl;
		cout<<"\t|                                                                                     -__-__-__-__-__         | "<<endl;
		cout<<"\t|                                                                                            -__-__-__-__     |"<<endl;
		cout<<"\t|                                                                                                   -__-__---_|\n\n\n"<<endl;
		cout<<"\t\t\t[E   WITH   US                                                    ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                        ___  |"<<endl;
		cout<<"\t|                                                                                              __--_--- /  |  |"<<endl;
		cout<<"\t|                                                                                      __-__-__-__-    /   |  |"<<endl;
		cout<<"\t|                                                                  ___________________________________/____|_ |"<<endl;
		cout<<"\t|                                                               __/[]      [][][][][][][][][][]  J & J   -----|"<<endl;
		cout<<"\t|                                                              |u              ______________   Airline   _--*|"<<endl;
		cout<<"\t|                                                                -------------*-__-__-__-__-__-__-------**    |"<<endl;
		cout<<"\t|                                                                                   -__-__-__-__-__           | "<<endl;
		cout<<"\t|                                                                                          -__-__-__-__       |"<<endl;
		cout<<"\t|                                                                                                 -__-__---__ |\n\n\n"<<endl;
		cout<<"\t\t\t[  WITH   US                                                      ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                      ___    |"<<endl;
		cout<<"\t|                                                                                            __--_--- /  |    |"<<endl;
		cout<<"\t|                                                                                    __-__-__-__-    /   |    |"<<endl;
		cout<<"\t|                                                                ___________________________________/____|_   |"<<endl;
		cout<<"\t|                                                             __/[]      [][][][][][][][][][]  J & J   -------|"<<endl;
		cout<<"\t|                                                            |u              ______________   Airline   _--**||"<<endl;
		cout<<"\t|                                                              -------------*-__-__-__-__-__-__-------**      |"<<endl;
		cout<<"\t|                                                                                 -__-__-__-__-__             | "<<endl;
		cout<<"\t|                                                                                        -__-__-__-__         |"<<endl;
		cout<<"\t|                                                                                               -__-__---__   |\n\n\n"<<endl;
		cout<<"\t\t\t[WITH   US                                                        ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                    ___      |"<<endl;
		cout<<"\t|                                                                                          __--_--- /  |    --|"<<endl;
		cout<<"\t|                                                                                  __-__-__-__-    /   |      |"<<endl;
		cout<<"\t|                                                              ___________________________________/____|_     |"<<endl;
		cout<<"\t|                                                           __/[]      [][][][][][][][][][]  J & J   -------| |"<<endl;
		cout<<"\t|                                                          |u              ______________   Airline   _--**|  |"<<endl;
		cout<<"\t|                                                            -------------*-__-__-__-__-__-__-------**        |"<<endl;
		cout<<"\t|                                                                               -__-__-__-__-__               | "<<endl;
		cout<<"\t|                                                                                      -__-__-__-__           |"<<endl;
		cout<<"\t|                                                                                             -__-__---__     |\n\n\n"<<endl;
		cout<<"\t\t\t[TH   US                                                          ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                  ___        |"<<endl;
		cout<<"\t|                                                                                        __--_--- /  |    --- |"<<endl;
		cout<<"\t|                                                                                __-__-__-__-    /   |        |"<<endl;
		cout<<"\t|                                                            ___________________________________/____|_       |"<<endl;
		cout<<"\t|                                                         __/[]      [][][][][][][][][][]  J & J   -------|   |"<<endl;
		cout<<"\t|                                                        |u              ______________   Airline   _--**|    |"<<endl;
		cout<<"\t|                                                          -------------*-__-__-__-__-__-__-------**          |"<<endl;
		cout<<"\t|                                                                             -__-__-__-__-__                 | "<<endl;
		cout<<"\t|                                                                                    -__-__-__-__             |"<<endl;
		cout<<"\t|                                                                                           -__-__---__     __|\n\n\n"<<endl;
		cout<<"\t\t\t[   US                                                          ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                ___          |"<<endl;
		cout<<"\t|                                                                                      __--_--- /  |    ---   |"<<endl;
		cout<<"\t|                                                                              __-__-__-__-    /   |          |"<<endl;
		cout<<"\t|                                                          ___________________________________/____|_         |"<<endl;
		cout<<"\t|                                                       __/[]      [][][][][][][][][][]  J & J   -------|     |"<<endl;
		cout<<"\t|                                                      |u              ______________   Airline   _--**|      |"<<endl;
		cout<<"\t|                                                        -------------*-__-__-__-__-__-__-------**            |"<<endl;
		cout<<"\t|                                                                           -__-__-__-__-__                   | "<<endl;
		cout<<"\t|                                                                                  -__-__-__-__               |"<<endl;
		cout<<"\t|                                                                                         -__-__---__     __  |\n\n\n"<<endl;
		cout<<"\t\t\t[ US                                                            ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                              ___            |"<<endl;
		cout<<"\t|                                                                                    __--_--- /  |    ---   - |"<<endl;
		cout<<"\t|                                                                            __-__-__-__-    /   |            |"<<endl;
		cout<<"\t|                                                        ___________________________________/____|_           |"<<endl;
		cout<<"\t|                                                     __/[]      [][][][][][][][][][]  J & J   -------|       |"<<endl;
		cout<<"\t|                                                    |u              ______________   Airline   _--**|        |"<<endl;
		cout<<"\t|                                                      -------------*-__-__-__-__-__-__-------**              |"<<endl;
		cout<<"\t|                                                                         -__-__-__-__-__                     | "<<endl;
		cout<<"\t|                                                                                -__-__-__-__                 |"<<endl;
		cout<<"\t|                                                                                       -__-__---__     __   _|\n\n\n"<<endl;
		cout<<"\t\t\t[S                                                              ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                            ___              |"<<endl;
		cout<<"\t|                                                                                  __--_--- /  |    ---   -   |"<<endl;
		cout<<"\t|                                                                          __-__-__-__-    /   |             _|"<<endl;
		cout<<"\t|                                                      ___________________________________/____|_             |"<<endl;
		cout<<"\t|                                                   __/[]      [][][][][][][][][][]  J & J   -------|         |"<<endl;
		cout<<"\t|                                                  |u              ______________   Airline   _--**|         -|"<<endl;
		cout<<"\t|                                                    -------------*-__-__-__-__-__-__-------**                |"<<endl;
		cout<<"\t|                                                                       -__-__-__-__-__                      _| "<<endl;
		cout<<"\t|                                                                              -__-__-__-__                   |"<<endl;
		cout<<"\t|                                                                                     -__-__---__     __   _  |\n\n\n"<<endl;
		cout<<"\t\t\t[                                                             YO]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                          ___                |"<<endl;
		cout<<"\t|                                                                                __--_--- /  |    ---   -   - |"<<endl;
		cout<<"\t|                                                                        __-__-__-__-    /   |             ___|"<<endl;
		cout<<"\t|                                                    ___________________________________/____|_              _|"<<endl;
		cout<<"\t|                                                 __/[]      [][][][][][][][][][]  J & J   -------|           |"<<endl;
		cout<<"\t|                                                |u              ______________   Airline   _--**|         ---|"<<endl;
		cout<<"\t|                                                  -------------*-__-__-__-__-__-__-------**                  |"<<endl;
		cout<<"\t|                                                                     -__-__-__-__-__                      ___| "<<endl;
		cout<<"\t|                                                                            -__-__-__-__                   --|"<<endl;
		cout<<"\t|                                                                                   -__-__---__     __   _    |\n\n\n"<<endl;
		cout<<"\t\t\t[                                                           YOUR]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                        ___                  |"<<endl;
		cout<<"\t|                                                                              __--_--- /  |    ---   -   -  -|"<<endl;
		cout<<"\t|                                                                      __-__-__-__-    /   |             _____|"<<endl;
		cout<<"\t|                                                  ___________________________________/____|_              ___|"<<endl;
		cout<<"\t|                                               __/[]      [][][][][][][][][][]  J & J   -------|             |"<<endl;
		cout<<"\t|                                              |u              ______________   Airline   _--**|         -----|"<<endl;
		cout<<"\t|                                                -------------*-__-__-__-__-__-__-------**                   _|"<<endl;
		cout<<"\t|                                                                   -__-__-__-__-__                      _____| "<<endl;
		cout<<"\t|                                                                          -__-__-__-__                   ----|"<<endl;
		cout<<"\t|                                                                                 -__-__---__     __   _    __|\n\n\n"<<endl;
		cout<<"\t\t\t[                                                         YOUR  ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                      ___                    |"<<endl;
		cout<<"\t|                                                                            __--_--- /  |    ---   -   -  ---|"<<endl;
		cout<<"\t|                                                                    __-__-__-__-    /   |             _______|"<<endl;
		cout<<"\t|                                                ___________________________________/____|_              _____|"<<endl;
		cout<<"\t|                                             __/[]      [][][][][][][][][][]  J & J   -------|               |"<<endl;
		cout<<"\t|                                            |u              ______________   Airline   _--**|         -------|"<<endl;
		cout<<"\t|                                              -------------*-__-__-__-__-__-__-------**                   ___|"<<endl;
		cout<<"\t|                                                                 -__-__-__-__-__                      _______| "<<endl;
		cout<<"\t|                                                                        -__-__-__-__                   ------|"<<endl;
		cout<<"\t|                                                                               -__-__---__     __   _    ____|\n\n\n"<<endl;
		cout<<"\t\t\t[                                                       YOUR   F]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                    ___                      |"<<endl;
		cout<<"\t|                                                                          __--_--- /  |    ---   -   -  -----|"<<endl;
		cout<<"\t|                                                                  __-__-__-__-    /   |             _________|"<<endl;
		cout<<"\t|                                              ___________________________________/____|_              _______|"<<endl;
		cout<<"\t|                                           __/[]      [][][][][][][][][][]  J & J   -------|               --|"<<endl;
		cout<<"\t|                                          |u              ______________   Airline   _--**|         ---------|"<<endl;
		cout<<"\t|                                            -------------*-__-__-__-__-__-__-------**                   _____|"<<endl;
		cout<<"\t|                                                               -__-__-__-__-__                      _________| "<<endl;
		cout<<"\t|                                                                      -__-__-__-__                   --------|"<<endl;
		cout<<"\t|                                                                             -__-__---__     __   _    ______|\n\n\n"<<endl;
		cout<<"\t\t\t[                                                     YOUR   FLI]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                  ___                        |"<<endl;
		cout<<"\t|                                                                        __--_--- /  |    ---   -   -  -------|"<<endl;
		cout<<"\t|                                                                __-__-__-__-    /   |             ___________|"<<endl;
		cout<<"\t|                                            ___________________________________/____|_              _________|"<<endl;
		cout<<"\t|                                         __/[]      [][][][][][][][][][]  J & J   -------|               ----|"<<endl;
		cout<<"\t|                                        |u              ______________   Airline   _--**|         -----------|"<<endl;
		cout<<"\t|                                          -------------*-__-__-__-__-__-__-------**                   _______|"<<endl;
		cout<<"\t|                                                             -__-__-__-__-__                      ___________| "<<endl;
		cout<<"\t|                                                                    -__-__-__-__                   ----------|"<<endl;
		cout<<"\t|                                                                           -__-__---__     __   _    ________|\n\n\n"<<endl;
		cout<<"\t\t\t[                                                   YOUR   FLIGH]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                ___                          |"<<endl;
		cout<<"\t|                                                                      __--_--- /  |    ---   -   -  ---------|"<<endl;
		cout<<"\t|                                                              __-__-__-__-    /   |             _____________|"<<endl;
		cout<<"\t|                                          ___________________________________/____|_              ___________|"<<endl;
		cout<<"\t|                                       __/[]      [][][][][][][][][][]  J & J   -------|               ------|"<<endl;
		cout<<"\t|                                      |u              ______________   Airline   _--**|         -------------|"<<endl;
		cout<<"\t|                                        -------------*-__-__-__-__-__-__-------**                   _________|"<<endl;
		cout<<"\t|                                                           -__-__-__-__-__                      _____________| "<<endl;
		cout<<"\t|                                                                  -__-__-__-__                   ------------|"<<endl;
		cout<<"\t|                                                                         -__-__---__     __   _    __________|\n\n\n"<<endl;
		cout<<"\t\t\t[                                                 YOUR   FLIGHT ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                              ___                            |"<<endl;
		cout<<"\t|                                                                    __--_--- /  |    ---   -   -  -----------|"<<endl;
		cout<<"\t|                                                            __-__-__-__-    /   |             _______________|"<<endl;
		cout<<"\t|                                        ___________________________________/____|_              _____________|"<<endl;
		cout<<"\t|                                     __/[]      [][][][][][][][][][]  J & J   -------|               --------|"<<endl;
		cout<<"\t|                                    |u              ______________   Airline   _--**|         ---------------|"<<endl;
		cout<<"\t|                                      -------------*-__-__-__-__-__-__-------**                   ___________|"<<endl;
		cout<<"\t|                                                         -__-__-__-__-__                      _______________| "<<endl;
		cout<<"\t|                                                                -__-__-__-__                   --------------|"<<endl;
		cout<<"\t|                                                                       -__-__---__     __   _    ____________|\n\n\n"<<endl;
		cout<<"\t\t\t[                                               YOUR   FLIGHT   ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                            ___                              |"<<endl;
		cout<<"\t|                                                                  __--_--- /  |    ---   -   -  -----------  |"<<endl;
		cout<<"\t|                                                          __-__-__-__-    /   |             _________________|"<<endl;
		cout<<"\t|                                      ___________________________________/____|_              _______________|"<<endl;
		cout<<"\t|                                   __/[]      [][][][][][][][][][]  J & J   -------|               ----------|"<<endl;
		cout<<"\t|                                  |u              ______________   Airline   _--**|         ---------------  |"<<endl;
		cout<<"\t|                                    -------------*-__-__-__-__-__-__-------**                   _____________|"<<endl;
		cout<<"\t|                                                       -__-__-__-__-__                      ________________ | "<<endl;
		cout<<"\t|                                                              -__-__-__-__                   ----------------|"<<endl;
		cout<<"\t|                                                                     -__-__---__     __   _    ______________|\n\n\n"<<endl;
		cout<<"\t\t\t[                                             YOUR   FLIGHT   IS]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                          ___                                |"<<endl;
		cout<<"\t|                                                                __--_--- /  |    ---   -   -  -----------    |"<<endl;
		cout<<"\t|                                                        __-__-__-__-    /   |             ___________________|"<<endl;
		cout<<"\t|                                    ___________________________________/____|_              _________________|"<<endl;
		cout<<"\t|                                 __/[]      [][][][][][][][][][]  J & J   -------|               ------------|"<<endl;
		cout<<"\t|                                |u              ______________   Airline   _--**|         ---------------   _|"<<endl;
		cout<<"\t|                                  -------------*-__-__-__-__-__-__-------**                   _______________|"<<endl;
		cout<<"\t|                                                     -__-__-__-__-__                      ________________ --| "<<endl;
		cout<<"\t|                                                            -__-__-__-__                   ------------------|"<<endl;
		cout<<"\t|                                                                   -__-__---__     __   _    ________________|\n\n\n"<<endl;
		cout<<"\t\t\t[                                           YOUR   FLIGHT   IS  ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                        ___                                  |"<<endl;
		cout<<"\t|                                                              __--_--- /  |    ---   -   -  -----------      |"<<endl;
		cout<<"\t|                                                      __-__-__-__-    /   |             _____________________|"<<endl;
		cout<<"\t|                                  ___________________________________/____|_              _________________  |"<<endl;
		cout<<"\t|                               __/[]      [][][][][][][][][][]  J & J   -------|               --------------|"<<endl;
		cout<<"\t|                              |u              ______________   Airline   _--**|         ---------------   ___|"<<endl;
		cout<<"\t|                                -------------*-__-__-__-__-__-__-------**                   _________________|"<<endl;
		cout<<"\t|                                                   -__-__-__-__-__                      ________________ ----| "<<endl;
		cout<<"\t|                                                          -__-__-__-__                   ------------------- |"<<endl;
		cout<<"\t|                                                                 -__-__---__     __   _    __________________|\n\n\n"<<endl;
		cout<<"\t\t\t[                                         YOUR   FLIGHT   IS   S]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                      ___                                    |"<<endl;
		cout<<"\t|                                                            __--_--- /  |    ---   -   -  -----------       -|"<<endl;
		cout<<"\t|                                                    __-__-__-__-    /   |             _______________________|"<<endl;
		cout<<"\t|                                ___________________________________/____|_              _________________    |"<<endl;
		cout<<"\t|                             __/[]      [][][][][][][][][][]  J & J   -------|               ----------------|"<<endl;
		cout<<"\t|                            |u              ______________   Airline   _--**|         ---------------   _____|"<<endl;
		cout<<"\t|                              -------------*-__-__-__-__-__-__-------**                   ___________________|"<<endl;
		cout<<"\t|                                                 -__-__-__-__-__                      ________________ ------| "<<endl;
		cout<<"\t|                                                        -__-__-__-__                   -------------------   |"<<endl;
		cout<<"\t|                                                               -__-__---__     __   _    ____________________|\n\n\n"<<endl;
		cout<<"\t\t\t[                                       YOUR   FLIGHT   IS   SAF]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                    ___                                      |"<<endl;
		cout<<"\t|                                                          __--_--- /  |    ---   -   -  -----------       ---|"<<endl;
		cout<<"\t|                                                  __-__-__-__-    /   |             _______________________  |"<<endl;
		cout<<"\t|                              ___________________________________/____|_              _________________    --|"<<endl;
		cout<<"\t|                           __/[]      [][][][][][][][][][]  J & J   -------|               ------------------|"<<endl;
		cout<<"\t|                          |u              ______________   Airline   _--**|         ---------------   _______|"<<endl;
		cout<<"\t|                            -------------*-__-__-__-__-__-__-------**                   _____________________|"<<endl;
		cout<<"\t|                                               -__-__-__-__-__                      ________________ --------| "<<endl;
		cout<<"\t|                                                      -__-__-__-__                   -------------------     |"<<endl;
		cout<<"\t|                                                             -__-__---__     __   _    ______________________|\n\n\n"<<endl;
		cout<<"\t\t\t[                                     YOUR   FLIGHT   IS   SAFE ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                  ___                                        |"<<endl;
		cout<<"\t|                                                        __--_--- /  |    ---   -   -  -----------       -----|"<<endl;
		cout<<"\t|                                                __-__-__-__-    /   |             _______________________    |"<<endl;
		cout<<"\t|                            ___________________________________/____|_              _________________    ----|"<<endl;
		cout<<"\t|                         __/[]      [][][][][][][][][][]  J & J   -------|               --------------------|"<<endl;
		cout<<"\t|                        |u              ______________   Airline   _--**|         ---------------   _________|"<<endl;
		cout<<"\t|                          -------------*-__-__-__-__-__-__-------**                   _______________________|"<<endl;
		cout<<"\t|                                             -__-__-__-__-__                      ________________ ----------| "<<endl;
		cout<<"\t|                                                    -__-__-__-__                   -------------------      -|"<<endl;
		cout<<"\t|                                                           -__-__---__     __   _    ________________________|\n\n\n"<<endl;
		cout<<"\t\t\t[                                   YOUR   FLIGHT   IS   SAFE   ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                ___                                          |"<<endl;
		cout<<"\t|                                                      __--_--- /  |    ---   -   -  -----------       -------|"<<endl;
		cout<<"\t|                                              __-__-__-__-    /   |             _______________________      |"<<endl;
		cout<<"\t|                          ___________________________________/____|_              _________________    ------|"<<endl;
		cout<<"\t|                       __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  |"<<endl;
		cout<<"\t|                      |u              ______________   Airline   _--**|         ---------------   __________ |"<<endl;
		cout<<"\t|                        -------------*-__-__-__-__-__-__-------**                   _________________________|"<<endl;
		cout<<"\t|                                           -__-__-__-__-__                      ________________ ------------| "<<endl;
		cout<<"\t|                                                  -__-__-__-__                   -------------------      ---|"<<endl;
		cout<<"\t|                                                         -__-__---__     __   _    __________________________|\n\n\n"<<endl;
		cout<<"\t\t\t[                                 YOUR   FLIGHT   IS   SAFE   WI]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                              ___                                            |"<<endl;
		cout<<"\t|                                                    __--_--- /  |    ---   -   -  -----------       ---------|"<<endl;
		cout<<"\t|                                            __-__-__-__-    /   |             _______________________       _|"<<endl;
		cout<<"\t|                        ___________________________________/____|_              _________________    --------|"<<endl;
		cout<<"\t|                     __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  __|"<<endl;
		cout<<"\t|                    |u              ______________   Airline   _--**|         ---------------   __________ --|"<<endl;
		cout<<"\t|                      -------------*-__-__-__-__-__-__-------**                   ___________________________|"<<endl;
		cout<<"\t|                                         -__-__-__-__-__                      ________________ --------------| "<<endl;
		cout<<"\t|                                                -__-__-__-__                   -------------------      -----|"<<endl;
		cout<<"\t|                                                       -__-__---__     __   _    ____________________________|\n\n\n"<<endl;
		cout<<"\t\t\t[                               YOUR   FLIGHT   IS   SAFE   WITH]\n\n\n\n\t";
		
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                            ___                                              |"<<endl;
		cout<<"\t|                                                  __--_--- /  |    ---   -   -  -----------       ---------  |"<<endl;
		cout<<"\t|                                          __-__-__-__-    /   |             _______________________       ___|"<<endl;
		cout<<"\t|                      ___________________________________/____|_              _________________    ----------|"<<endl;
		cout<<"\t|                   __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  ____|"<<endl;
		cout<<"\t|                  |u              ______________   Airline   _--**|         ---------------   __________ ----|"<<endl;
		cout<<"\t|                    -------------*-__-__-__-__-__-__-------**                   _____________________________|"<<endl;
		cout<<"\t|                                       -__-__-__-__-__                      ________________ --------------- | "<<endl;
		cout<<"\t|                                              -__-__-__-__                   -------------------      -------|"<<endl;
		cout<<"\t|                                                     -__-__---__     __   _    ______________________________|\n\n\n"<<endl;
		cout<<"\t\t\t[                             YOUR   FLIGHT   IS   SAFE   WITH  ]\n\n\n\n\t";
	
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                          ___                                                |"<<endl;
		cout<<"\t|                                                __--_--- /  |    ---   -   -  -----------       ---------    |"<<endl;
		cout<<"\t|                                        __-__-__-__-    /   |             _______________________       _____|"<<endl;
		cout<<"\t|                    ___________________________________/____|_              _________________    ------------|"<<endl;
		cout<<"\t|                 __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  ______|"<<endl;
		cout<<"\t|                |u              ______________   Airline   _--**|         ---------------   __________ ------|"<<endl;
		cout<<"\t|                  -------------*-__-__-__-__-__-__-------**                   _______________________________|"<<endl;
		cout<<"\t|                                     -__-__-__-__-__                      ________________ ---------------   | "<<endl;
		cout<<"\t|                                            -__-__-__-__                   -------------------      ---------|"<<endl;
		cout<<"\t|                                                   -__-__---__     __   _    ________________________________|\n\n\n"<<endl;
		cout<<"\t\t\t[                           YOUR   FLIGHT   IS   SAFE   WITH   U]\n\n\n\n\t";
	
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                        ___                                                  |"<<endl;
		cout<<"\t|                                              __--_--- /  |    ---   -   -  -----------       ---------    --|"<<endl;
		cout<<"\t|                                      __-__-__-__-    /   |             _______________________       _______|"<<endl;
		cout<<"\t|                  ___________________________________/____|_              _________________    --------------|"<<endl;
		cout<<"\t|               __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  _______ |"<<endl;
		cout<<"\t|              |u              ______________   Airline   _--**|         ---------------   __________ --------|"<<endl;
		cout<<"\t|                -------------*-__-__-__-__-__-__-------**                   ________________________________ |"<<endl;
		cout<<"\t|                                   -__-__-__-__-__                      ________________ ---------------   __| "<<endl;
		cout<<"\t|                                          -__-__-__-__                   -------------------      -----------|"<<endl;
		cout<<"\t|                                                 -__-__---__     __   _    _________________________________ |\n\n\n"<<endl;
		cout<<"\t\t\t[                         YOUR   FLIGHT   IS   SAFE   WITH   US ]\n\n\n\n\t";
	
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                      ___                                                    |"<<endl;
		cout<<"\t|                                            __--_--- /  |    ---   -   -  -----------       ---------    ----|"<<endl;
		cout<<"\t|                                    __-__-__-__-    /   |             _______________________       _________|"<<endl;
		cout<<"\t|                ___________________________________/____|_              _________________    ----------------|"<<endl;
		cout<<"\t|             __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  _______  -|"<<endl;
		cout<<"\t|            |u              ______________   Airline   _--**|         ---------------   __________ ----------|"<<endl;
		cout<<"\t|              -------------*-__-__-__-__-__-__-------**                   ________________________________   |"<<endl;
		cout<<"\t|                                 -__-__-__-__-__                      ________________ ---------------   ____| "<<endl;
		cout<<"\t|                                        -__-__-__-__                   -------------------      ------------ |"<<endl;
		cout<<"\t|                                               -__-__---__     __   _    _________________________________ --|\n\n\n"<<endl;
		cout<<"\t\t\t[                       YOUR   FLIGHT   IS   SAFE   WITH   US   ]\n\n\n\n\t";
		
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                    ___                                                      |"<<endl;
		cout<<"\t|                                          __--_--- /  |    ---   -   -  -----------       ---------    ------|"<<endl;
		cout<<"\t|                                  __-__-__-__-    /   |             _______________________       _________  |"<<endl;
		cout<<"\t|              ___________________________________/____|_              _________________    ------------------|"<<endl;
		cout<<"\t|           __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  _______  ---|"<<endl;
		cout<<"\t|          |u              ______________   Airline   _--**|         ---------------   __________ ------------|"<<endl;
		cout<<"\t|            -------------*-__-__-__-__-__-__-------**                   ________________________________   --|"<<endl;
		cout<<"\t|                               -__-__-__-__-__                      ________________ ---------------   ______| "<<endl;
		cout<<"\t|                                      -__-__-__-__                   -------------------      ------------   |"<<endl;
		cout<<"\t|                                             -__-__---__     __   _    _________________________________ ----|\n\n\n"<<endl;
		cout<<"\t\t\t[                     YOUR   FLIGHT   IS   SAFE   WITH   US     ]\n\n\n\n\t";
		
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                  ___                                                      | "<<endl;
		cout<<"\t|                                        __--_--- /  |    ---   -   -  -----------       ---------    ------|"<<endl;
		cout<<"\t|                                __-__-__-__-    /   |             _______________________       _________  |"<<endl;
		cout<<"\t|            ___________________________________/____|_              _________________    ------------------|"<<endl;
		cout<<"\t|         __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  _______  ---|"<<endl;
		cout<<"\t|        |u              ______________   Airline   _--**|         ---------------   __________ ------------|"<<endl;
		cout<<"\t|          -------------*-__-__-__-__-__-__-------**                   ________________________________   --|"<<endl;
		cout<<"\t|                             -__-__-__-__-__                      ________________ ---------------   ______| "<<endl;
		cout<<"\t|                                    -__-__-__-__                   -------------------      ------------   |"<<endl;
		cout<<"\t|                                           -__-__---__     __   _    _________________________________ ----|\n\n\n"<<endl;
		cout<<"\t\t\t[                   YOUR   FLIGHT   IS   SAFE   WITH   US       ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                ___                                                        |"<<endl;
		cout<<"\t|                                      __--_--- /  |    ---   -   -  -----------       ---------    --------|"<<endl;
		cout<<"\t|                              __-__-__-__-    /   |             _______________________       _________    |"<<endl;
		cout<<"\t|          ___________________________________/____|_              _________________    ------------------  |"<<endl;
		cout<<"\t|       __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  _______  -----|"<<endl;
		cout<<"\t|      |u              ______________   Airline   _--**|         ---------------   __________ --------------|"<<endl;
		cout<<"\t|        -------------*-__-__-__-__-__-__-------**                   ________________________________   ----|"<<endl;
		cout<<"\t|                           -__-__-__-__-__                      ________________ ---------------   ________| "<<endl;
		cout<<"\t|                                  -__-__-__-__                   -------------------      ------------     |"<<endl;
		cout<<"\t|                                         -__-__---__     __   _    _________________________________ ------|\n\n\n"<<endl;
		cout<<"\t\t\t[                 YOUR   FLIGHT   IS   SAFE   WITH   US         ]\n\n\n\n\t";
	
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                              ___                                                          |"<<endl;
		cout<<"\t|                                    __--_--- /  |    ---   -   -  -----------       ---------    ----------|"<<endl;
		cout<<"\t|                            __-__-__-__-    /   |             _______________________       _________    __|"<<endl;
		cout<<"\t|        ___________________________________/____|_              _________________    ------------------   _|"<<endl;
		cout<<"\t|     __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  _______  ------ |"<<endl;
		cout<<"\t|    |u              ______________   Airline   _--**|         ---------------   __________ -------------- _|"<<endl;
		cout<<"\t|      -------------*-__-__-__-__-__-__-------**                   ________________________________   ------|"<<endl;
		cout<<"\t|                         -__-__-__-__-__                      ________________ ---------------   _________-| "<<endl;
		cout<<"\t|                                -__-__-__-__                   -------------------      ------------     --|"<<endl;
		cout<<"\t|                                       -__-__---__     __   _    _________________________________ ------- |\n\n\n"<<endl;
		cout<<"\t\t\t[               YOUR   FLIGHT   IS   SAFE   WITH   US           ]\n\n\n\n\t";
		
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                            ___                                                            |"<<endl;
		cout<<"\t|                                  __--_--- /  |    ---   -   -  -----------       ---------    ---------- -|"<<endl;
		cout<<"\t|                          __-__-__-__-    /   |             _______________________       _________    ____|"<<endl;
		cout<<"\t|      ___________________________________/____|_              _________________    ------------------   ___|"<<endl;
		cout<<"\t|   __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  _______  ------  -|"<<endl;
		cout<<"\t|  |u              ______________   Airline   _--**|         ---------------   __________ -------------- ___|"<<endl;
		cout<<"\t|    -------------*-__-__-__-__-__-__-------**                   ________________________________   --------|"<<endl;
		cout<<"\t|                       -__-__-__-__-__                      ________________ ---------------   _________---| "<<endl;
		cout<<"\t|                              -__-__-__-__                   -------------------      ------------     ----|"<<endl;
		cout<<"\t|                                     -__-__---__     __   _    _________________________________ ------- __|\n\n\n"<<endl;
		cout<<"\t\t\t[             YOUR   FLIGHT   IS   SAFE   WITH   US             ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                          ___                                                              |"<<endl;
		cout<<"\t|                                __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---|"<<endl;
		cout<<"\t|                        __-__-__-__-    /   |             _______________________       _________    ______|"<<endl;
		cout<<"\t|    ___________________________________/____|_              _________________    ------------------   ___  |"<<endl;
		cout<<"\t| __/[]      [][][][][][][][][][]  J & J   -------|               --------------------  _______  ------  ---|"<<endl;
		cout<<"\t||u              ______________   Airline   _--**|         ---------------   __________ -------------- _____|"<<endl;
		cout<<"\t|  -------------*-__-__-__-__-__-__-------**                   ________________________________   --------  |"<<endl;
		cout<<"\t|                     -__-__-__-__-__                      ________________ ---------------   _________-----| "<<endl;
		cout<<"\t|                            -__-__-__-__                   -------------------      ------------     ------|"<<endl;
		cout<<"\t|                                   -__-__---__     __   _    _________________________________ ------- __ -|\n\n\n"<<endl;
		cout<<"\t\t\t[           YOUR   FLIGHT   IS   SAFE   WITH   US               ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                        ___                                                                |"<<endl;
		cout<<"\t|                              __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  |"<<endl;
		cout<<"\t|                      __-__-__-__-    /   |             _______________________       _________    ______ -|"<<endl;
		cout<<"\t|  ___________________________________/____|_              _________________    ------------------   ___  __|"<<endl;
		cout<<"\t|_/[]      [][][][][][][][][][]  J & J   -------|               --------------------  _______  ------  ---- |"<<endl;
		cout<<"\t|              ______________   Airline   _--**|         ---------------   __________ -------------- _____ -|"<<endl;
		cout<<"\t|-------------*-__-__-__-__-__-__-------**                   ________________________________   --------  __|"<<endl;
		cout<<"\t|                   -__-__-__-__-__                      ________________ ---------------   _________-------| "<<endl;
		cout<<"\t|                          -__-__-__-__                   -------------------      ------------     ------  |"<<endl;
		cout<<"\t|                                 -__-__---__     __   _    _________________________________ ------- __ -- |\n\n\n"<<endl;
		cout<<"\t\t\t[         YOUR   FLIGHT   IS   SAFE   WITH   US                 ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                      ___                                                                  |"<<endl;
		cout<<"\t|                            __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - |"<<endl;
		cout<<"\t|                    __-__-__-__-    /   |             _______________________       _________    ______ ---|"<<endl;
		cout<<"\t|___________________________________/____|_              _________________    ------------------   ___  __ -|"<<endl;
		cout<<"\t|[]      [][][][][][][][][][]  J & J   -------|               --------------------  _______  ------  ---- __|"<<endl;
		cout<<"\t|            ______________   Airline   _--**|         ---------------   __________ -------------- _____ ---|"<<endl;
		cout<<"\t|-----------*-__-__-__-__-__-__-------**                   ________________________________   --------  __  |"<<endl;
		cout<<"\t|                 -__-__-__-__-__                      ________________ ---------------   _________------- _| "<<endl;
		cout<<"\t|                        -__-__-__-__                   -------------------      ------------     ------  --|";
		cout<<"\t|                               -__-__---__     __   _    _________________________________ ------- __ -- __|\n\n\n"<<endl;
		cout<<"\t\t\t[       YOUR   FLIGHT   IS   SAFE   WITH   US                   ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                    ___                                                                    |"<<endl;
		cout<<"\t|                          __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - - |"<<endl;
		cout<<"\t|                  __-__-__-__-    /   |             _______________________       _________    ______ ---  |"<<endl;
		cout<<"\t|_________________________________/____|_              _________________    ------------------   ___  __ - -|"<<endl;
		cout<<"\t|     [][][][][][][][][][]  J & J   -------|               --------------------  _______  ------  ---- _____|"<<endl;
		cout<<"\t|          ______________   Airline   _--**|         ---------------   __________ -------------- _____ -----|"<<endl;
		cout<<"\t|---------*-__-__-__-__-__-__-------**                   ________________________________   --------  __  __|"<<endl;
		cout<<"\t|               -__-__-__-__-__                      ________________ ---------------   _________------- ___| "<<endl;
		cout<<"\t|                      -__-__-__-__                   -------------------      ------------     ------  ----|"<<endl;
		cout<<"\t|                             -__-__---__     __   _    _________________________________ ------- __ -- __  |\n\n\n"<<endl;
		cout<<"\t\t\t[     YOUR   FLIGHT   IS   SAFE   WITH   US                     ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                  ___                                                                      |"<<endl;
		cout<<"\t|                        __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -   |"<<endl;
		cout<<"\t|                __-__-__-__-    /   |             _______________________       _________    ______ ---  --|"<<endl;
		cout<<"\t|_______________________________/____|_              _________________    ------------------   ___  __ -  |"<<endl;
		cout<<"\t|   [][][][][][][][][][]  J & J   -------|               --------------------  _______  ------  ---- _____  |"<<endl;
		cout<<"\t|        ______________   Airline   _--**|         ---------------   __________ -------------- _____ ----- -|"<<endl;
		cout<<"\t|-------*-__-__-__-__-__-__-------**                   ________________________________   --------  __  __  |"<<endl;
		cout<<"\t|             -__-__-__-__-__                      ________________ ---------------   _________------- ___- | "<<endl;
		cout<<"\t|                    -__-__-__-__                   -------------------      ------------     ------  ---- -|"<<endl;
		cout<<"\t|                           -__-__---__     __   _    _________________________________ ------- __ -- __    |\n\n\n"<<endl;
		cout<<"\t\t\t[   YOUR   FLIGHT   IS   SAFE   WITH   US                       ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                ___                                                                        |"<<endl;
		cout<<"\t|                      __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -     |"<<endl;
		cout<<"\t|              __-__-__-__-    /   |             _______________________       _________    ______ ---  --  |"<<endl;
		cout<<"\t|_____________________________/____|_              _________________    ------------------   ___  __ -    - |"<<endl;
		cout<<"\t| [][][][][][][][][][]  J & J   -------|               --------------------  _______  ------  ---- _____ - -|"<<endl;
		cout<<"\t|      ______________   Airline   _--**|         ---------------   __________ -------------- _____ ----- -  |"<<endl;
		cout<<"\t|-----*-__-__-__-__-__-__-------**                   ________________________________   --------  __  __  - |"<<endl;
		cout<<"\t|           -__-__-__-__-__                      ________________ ---------------   _________------- ___-   |"<<endl;
		cout<<"\t|                  -__-__-__-__                   -------------------      ------------     ------  ---- -  |"<<endl;
		cout<<"\t|                         -__-__---__     __   _    _________________________________ ------- __ -- __      |\n\n\n"<<endl;
		cout<<"\t\t\t[ YOUR   FLIGHT   IS   SAFE   WITH   US                         ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                              ___                                                                          |"<<endl;
		cout<<"\t|                    __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -       |"<<endl;
		cout<<"\t|            __-__-__-__-    /   |             _______________________       _________    ______ ---  --    |"<<endl;
		cout<<"\t|___________________________/____|_              _________________    ------------------   ___  __ -    -   |"<<endl;
		cout<<"\t|][][][][][][][][][]  J & J   -------|               --------------------  _______  ------  ---- _____ - -  |"<<endl;
		cout<<"\t|    ______________   Airline   _--**|         ---------------   __________ -------------- _____ ----- -    |"<<endl;
		cout<<"\t|---*-__-__-__-__-__-__-------**                   ________________________________   --------  __  __  -   |"<<endl;
		cout<<"\t|         -__-__-__-__-__                      ________________ ---------------   _________------- ___-     |"<<endl;
		cout<<"\t|                -__-__-__-__                   -------------------      ------------     ------  ---- -    |"<<endl;
		cout<<"\t|                       -__-__---__     __   _    _________________________________ ------- __ -- __        |\n\n\n"<<endl;
		cout<<"\t\t\t[OUR   FLIGHT   IS   SAFE   WITH   US                         ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                            ___                                                                            |"<<endl;
		cout<<"\t|                  __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -         |"<<endl;
		cout<<"\t|          __-__-__-__-    /   |             _______________________       _________    ______ ---  --      |"<<endl;
		cout<<"\t|_________________________/____|_              _________________    ------------------   ___  __ -    -     |"<<endl;
		cout<<"\t|][][][][][][][][]  J & J   -------|               --------------------  _______  ------  ---- _____ - -    |"<<endl;
		cout<<"\t|  ______________   Airline   _--**|         ---------------   __________ -------------- _____ ----- -      |"<<endl;
		cout<<"\t|-*-__-__-__-__-__-__-------**                   ________________________________   --------  __  __  -     |"<<endl;
		cout<<"\t|       -__-__-__-__-__                      ________________ ---------------   _________------- ___-       |"<<endl;
		cout<<"\t|              -__-__-__-__                   -------------------      ------------     ------  ---- -      |"<<endl;
		cout<<"\t|                     -__-__---__     __   _    _________________________________ ------- __ -- __          |\n\n\n"<<endl;
		cout<<"\t\t\t[R   FLIGHT   IS   SAFE   WITH   US                           ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                          ___                                                                              |"<<endl;
		cout<<"\t|                __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -           |"<<endl;
		cout<<"\t|        __-__-__-__-    /   |             _______________________       _________    ______ ---  --        |"<<endl;
		cout<<"\t|_______________________/____|_              _________________    ------------------   ___  __ -    -       |"<<endl;
		cout<<"\t|][][][][][][][]  J & J   -------|               --------------------  _______  ------  ---- _____ - -      |"<<endl;
		cout<<"\t|______________   Airline   _--**|         ---------------   __________ -------------- _____ ----- -        |"<<endl;
		cout<<"\t|-__-__-__-__-__-__-------**                   ________________________________   --------  __  __  -       |"<<endl;
		cout<<"\t|     -__-__-__-__-__                      ________________ ---------------   _________------- ___-         |"<<endl;
		cout<<"\t|            -__-__-__-__                   -------------------      ------------     ------  ---- -        |"<<endl;
		cout<<"\t|                   -__-__---__     __   _    _________________________________ ------- __ -- __            |\n\n\n"<<endl;
		cout<<"\t\t\t[  FLIGHT   IS   SAFE   WITH   US                             ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                        ___                                                                                |"<<endl;
		cout<<"\t|              __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -             |"<<endl;
		cout<<"\t|      __-__-__-__-    /   |             _______________________       _________    ______ ---  --          |"<<endl;
		cout<<"\t|_____________________/____|_              _________________    ------------------   ___  __ -    -         |"<<endl;
		cout<<"\t|][][][][][][]  J & J   -------|               --------------------  _______  ------  ---- _____ - -        |"<<endl;
		cout<<"\t|____________   Airline   _--**|         ---------------   __________ -------------- _____ ----- -          |"<<endl;
		cout<<"\t|_-__-__-__-__-__-------**                   ________________________________   --------  __  __  -         |"<<endl;
		cout<<"\t|   -__-__-__-__-__                      ________________ ---------------   _________------- ___-           |"<<endl;
		cout<<"\t|          -__-__-__-__                   -------------------      ------------     ------  ---- -          |"<<endl;
		cout<<"\t|                 -__-__---__     __   _    _________________________________ ------- __ -- __              |\n\n\n"<<endl;
		cout<<"\t\t\t[FLIGHT   IS   SAFE   WITH   US                               ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                      ___                                                                                  |"<<endl;
		cout<<"\t|            __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -               |"<<endl;
		cout<<"\t|    __-__-__-__-    /   |             _______________________       _________    ______ ---  --            |"<<endl;
		cout<<"\t|___________________/____|_              _________________    ------------------   ___  __ -    -           |"<<endl;
		cout<<"\t|][][][][][]  J & J   -------|               --------------------  _______  ------  ---- _____ - -          |"<<endl;
		cout<<"\t|__________   Airline   _--**|         ---------------   __________ -------------- _____ ----- -            |"<<endl;
		cout<<"\t|__-__-__-__-__-------**                   ________________________________   --------  __  __  -           |"<<endl;
		cout<<"\t| -__-__-__-__-__                      ________________ ---------------   _________------- ___-             |"<<endl;
		cout<<"\t|        -__-__-__-__                   -------------------      ------------     ------  ---- -            |"<<endl;
		cout<<"\t|               -__-__---__     __   _    _________________________________ ------- __ -- __                |\n\n\n"<<endl;
		cout<<"\t\t\t[IGHT   IS   SAFE   WITH   US                                 ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                    ___                                                                                    |"<<endl;
		cout<<"\t|          __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -                 |"<<endl;
		cout<<"\t|  __-__-__-__-    /   |             _______________________       _________    ______ ---  --              |"<<endl;
		cout<<"\t|_________________/____|_              _________________    ------------------   ___  __ -    -             |"<<endl;
		cout<<"\t|][][][][]  J & J   -------|               --------------------  _______  ------  ---- _____ - -            |"<<endl;
		cout<<"\t|________   Airline   _--**|         ---------------   __________ -------------- _____ ----- -              |"<<endl;
		cout<<"\t|-__-__-__-__-------**                   ________________________________   --------  __  __  -             |"<<endl;
		cout<<"\t|__-__-__-__-__                      ________________ ---------------   _________------- ___-               |"<<endl;
		cout<<"\t|      -__-__-__-__                   -------------------      ------------     ------  ---- -              |"<<endl;
		cout<<"\t|             -__-__---__     __   _    _________________________________ ------- __ -- __                  |\n\n\n"<<endl;
		cout<<"\t\t\t[HT   IS   SAFE   WITH   US                                   ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                  ___                                                                                      |"<<endl;
		cout<<"\t|        __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -                   |"<<endl;
		cout<<"\t|__-__-__-__-    /   |             _______________________       _________    ______ ---  --                |"<<endl;
		cout<<"\t|_______________/____|_              _________________    ------------------   ___  __ -    -               |"<<endl;
		cout<<"\t|][][][]  J & J   -------|               --------------------  _______  ------  ---- _____ - -              |"<<endl;
		cout<<"\t|______   Airline   _--**|         ---------------   __________ -------------- _____ ----- -                |"<<endl;
		cout<<"\t|_-__-__-__-------**                   ________________________________   --------  __  __  -               |"<<endl;
		cout<<"\t|-__-__-__-__                      ________________ ---------------   _________------- ___-                 |"<<endl;
		cout<<"\t|    -__-__-__-__                   -------------------      ------------     ------  ---- -                |"<<endl;
		cout<<"\t|           -__-__---__     __   _    _________________________________ ------- __ -- __                    |\n\n\n"<<endl;
		cout<<"\t\t\t[   IS   SAFE   WITH   US                                     ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                ___                                                                                        |"<<endl;
		cout<<"\t|      __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -                     |"<<endl;
		cout<<"\t|-__-__-__-    /   |             _______________________       _________    ______ ---  --                  |"<<endl;
		cout<<"\t|_____________/____|_              _________________    ------------------   ___  __ -    -                 |"<<endl;
		cout<<"\t|][][]  J & J   -------|               --------------------  _______  ------  ---- _____ - -                |"<<endl;
		cout<<"\t|____   Airline   _--**|         ---------------   __________ -------------- _____ ----- -                  |"<<endl;
		cout<<"\t|__-__-__-------**                   ________________________________   --------  __  __  -                 |"<<endl;
		cout<<"\t|_-__-__-__                      ________________ ---------------   _________------- ___-                   |"<<endl;
		cout<<"\t|  -__-__-__-__                   -------------------      ------------     ------  ---- -                  |"<<endl;
		cout<<"\t|         -__-__---__     __   _    _________________________________ ------- __ -- __                      |\n\n\n"<<endl;
		cout<<"\t\t\t[ IS   SAFE   WITH   US                                       ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|              ___                                                                                          |"<<endl;
		cout<<"\t|    __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -                       |"<<endl;
		cout<<"\t|_-__-__-    /   |             _______________________       _________    ______ ---  --                    |"<<endl;
		cout<<"\t|___________/____|_              _________________    ------------------   ___  __ -    -                   |"<<endl;
		cout<<"\t|][]  J & J   -------|               --------------------  _______  ------  ---- _____ - -                  |"<<endl;
		cout<<"\t|__   Airline   _--**|         ---------------   __________ -------------- _____ ----- -                    |"<<endl;
		cout<<"\t|-__-__-------**                   ________________________________   --------  __  __  -                   |"<<endl;
		cout<<"\t|__-__-__                      ________________ ---------------   _________------- ___-                     |"<<endl;
		cout<<"\t|-__-__-__-__                   -------------------      ------------     ------  ---- -                    |"<<endl;
		cout<<"\t|       -__-__---__     __   _    _________________________________ ------- __ -- __                        |\n\n\n"<<endl;
		cout<<"\t\t\t[S   SAFE   WITH   US                                         ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|            ___                                                                                            |"<<endl;
		cout<<"\t|  __--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -                         |"<<endl;
		cout<<"\t|__-__-    /   |             _______________________       _________    ______ ---  --                      |"<<endl;
		cout<<"\t|_________/____|_              _________________    ------------------   ___  __ -    -                     |"<<endl;
		cout<<"\t|]  J & J   -------|               --------------------  _______  ------  ---- _____ - -                    |"<<endl;
		cout<<"\t|   Airline   _--**|         ---------------   __________ -------------- _____ ----- -                      |"<<endl;
		cout<<"\t|_-__-------**                   ________________________________   --------  __  __  -                     |"<<endl;
		cout<<"\t|-__-__                      ________________ ---------------   _________------- ___-                       |"<<endl;
		cout<<"\t|_-__-__-__                   -------------------      ------------     ------  ---- -                      |"<<endl;
		cout<<"\t|     -__-__---__     __   _    _________________________________ ------- __ -- __                          |\n\n\n"<<endl;
		cout<<"\t\t\t[  SAFE   WITH   US                                           ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|          ___                                                                                              |"<<endl;
		cout<<"\t|__--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -                           |"<<endl;
		cout<<"\t|-__-    /   |             _______________________       _________    ______ ---  --                        |"<<endl;
		cout<<"\t|_______/____|_              _________________    ------------------   ___  __ -    -                       |"<<endl;
		cout<<"\t| J & J   -------|               --------------------  _______  ------  ---- _____ - -                      |"<<endl;
		cout<<"\t| Airline   _--**|         ---------------   __________ -------------- _____ ----- -                        |"<<endl;
		cout<<"\t|__-------**                   ________________________________   --------  __  __  -                       |"<<endl;
		cout<<"\t|_-__                      ________________ ---------------   _________------- ___-                         |"<<endl;
		cout<<"\t|__-__-__                   -------------------      ------------     ------  ---- -                        |"<<endl;
		cout<<"\t|   -__-__---__     __   _    _________________________________ ------- __ -- __                            |\n\n\n"<<endl;
		cout<<"\t\t\t[SAFE   WITH   US                                             ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|        ___                                                                                                |"<<endl;
		cout<<"\t|--_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -                             |"<<endl;
		cout<<"\t|_-    /   |             _______________________       _________    ______ ---  --                          |"<<endl;
		cout<<"\t|_____/____|_              _________________    ------------------   ___  __ -    -                         |"<<endl;
		cout<<"\t| & J   -------|               --------------------  _______  ------  ---- _____ - -                        |"<<endl;
		cout<<"\t|irline   _--**|         ---------------   __________ -------------- _____ ----- -                          |"<<endl;
		cout<<"\t|-------**                   ________________________________   --------  __  __  -                         |"<<endl;
		cout<<"\t|__                      ________________ ---------------   _________------- ___-                           |"<<endl;
		cout<<"\t|-__-__                   -------------------      ------------     ------  ---- -                          |"<<endl;
		cout<<"\t| -__-__---__     __   _    _________________________________ ------- __ -- __                              |\n\n\n"<<endl;
		cout<<"\t\t\t[FE   WITH   US                                               ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|      ___                                                                                                  |"<<endl;
		cout<<"\t|_--- /  |    ---   -   -  -----------       ---------    ---------- ---  - -                               |"<<endl;
		cout<<"\t|    /   |             _______________________       _________    ______ ---  --                            |"<<endl;
		cout<<"\t|___/____|_              _________________    ------------------   ___  __ -    -                           |"<<endl;
		cout<<"\t| J   -------|               --------------------  _______  ------  ---- _____ - -                          |"<<endl;
		cout<<"\t|line   _--**|         ---------------   __________ -------------- _____ ----- -                            |"<<endl;
		cout<<"\t|-----**                   ________________________________   --------  __  __  -                           |"<<endl;
		cout<<"\t|                      ________________ ---------------   _________------- ___-                             |"<<endl;
		cout<<"\t|_-__                   -------------------      ------------     ------  ---- -                            |"<<endl;
		cout<<"\t|__-__---__     __   _    _________________________________ ------- __ -- __                                |\n\n\n"<<endl;
		cout<<"\t\t\t[   WITH   US                                                 ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|    ___                                                                                                    |"<<endl;
		cout<<"\t|-- /  |    ---   -   -  -----------       ---------    ---------- ---  - -                                 |"<<endl;
		cout<<"\t|  /   |             _______________________       _________    ______ ---  --                              |"<<endl;
		cout<<"\t|_/____|_              _________________    ------------------   ___  __ -    -                             |"<<endl;
		cout<<"\t|   -------|               --------------------  _______  ------  ---- _____ - -                            |"<<endl;
		cout<<"\t|ne   _--**|         ---------------   __________ -------------- _____ ----- -                              |"<<endl;
		cout<<"\t|---**                   ________________________________   --------  __  __  -                             |"<<endl;
		cout<<"\t|                    ________________ ---------------   _________------- ___-                               |"<<endl;
		cout<<"\t|__                   -------------------      ------------     ------  ---- -                              |"<<endl;
		cout<<"\t|-__---__     __   _    _________________________________ ------- __ -- __                                  |\n\n\n"<<endl;
		cout<<"\t\t\t[ WITH   US                                                   ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|  ___                                                                                                      |"<<endl;
		cout<<"\t| /  |    ---   -   -  -----------       ---------    ---------- ---  - -                                   |"<<endl;
		cout<<"\t|/   |             _______________________       _________    ______ ---  --                                |"<<endl;
		cout<<"\t|____|_              _________________    ------------------   ___  __ -    -                               |"<<endl;
		cout<<"\t| -------|               --------------------  _______  ------  ---- _____ - -                              |"<<endl;
		cout<<"\t|   _--**|         ---------------   __________ -------------- _____ ----- -                                |"<<endl;
		cout<<"\t|-**                   ________________________________   --------  __  __  -                               |"<<endl;
		cout<<"\t|                  ________________ ---------------   _________------- ___-                                 |"<<endl;
		cout<<"\t|                   -------------------      ------------     ------  ---- -                                |"<<endl;
		cout<<"\t|_---__     __   _    _________________________________ ------- __ -- __                                    |\n\n\n"<<endl;
		cout<<"\t\t\t[ITH   US                                                     ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|___                                                                                                        |"<<endl;
		cout<<"\t|  |    ---   -   -  -----------       ---------    ---------- ---  - -                                     |"<<endl;
		cout<<"\t|  |             _______________________       _________    ______ ---  --                                  |"<<endl;
		cout<<"\t|__|_              _________________    ------------------   ___  __ -    -                                 |"<<endl;
		cout<<"\t|------|               --------------------  _______  ------  ---- _____ - -                                |"<<endl;
		cout<<"\t| _--**|         ---------------   __________ -------------- _____ ----- -                                  |"<<endl;
		cout<<"\t|*                   ________________________________   --------  __  __  -                                 |"<<endl;
		cout<<"\t|                ________________ ---------------   _________------- ___-                                   |"<<endl;
		cout<<"\t|                 -------------------      ------------     ------  ---- -                                  |"<<endl;
		cout<<"\t|--__     __   _    _________________________________ ------- __ -- __                                      |\n\n\n"<<endl;
		cout<<"\t\t\t[H   US                                                       ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|_                                                                                                          |"<<endl;
		cout<<"\t||    ---   -   -  -----------       ---------    ---------- ---  - -                                       |"<<endl;
		cout<<"\t||             _______________________       _________    ______ ---  --                                    |"<<endl;
		cout<<"\t||_              _________________    ------------------   ___  __ -    -                                   |"<<endl;
		cout<<"\t|----|               --------------------  _______  ------  ---- _____ - -                                  |"<<endl;
		cout<<"\t|--**|         ---------------   __________ -------------- _____ ----- -                                    |"<<endl;
		cout<<"\t|                  ________________________________   --------  __  __  -                                   |"<<endl;
		cout<<"\t|              ________________ ---------------   _________------- ___-                                     |"<<endl;
		cout<<"\t|               -------------------      ------------     ------  ---- -                                    |"<<endl;
		cout<<"\t|__     __   _    _________________________________ ------- __ -- __                                        |\n\n\n"<<endl;
		cout<<"\t\t\t[  US                                                         ]\n\n\n\n\t";
		  
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                           |"<<endl;
		cout<<"\t|   ---   -   -  -----------       ---------    ---------- ---  - -                                         |"<<endl;
		cout<<"\t|            _______________________       _________    ______ ---  --                                      |"<<endl;
		cout<<"\t|              _________________    ------------------   ___  __ -    -                                     |"<<endl;
		cout<<"\t|--|               --------------------  _______  ------  ---- _____ - -                                    |"<<endl;
		cout<<"\t|**|         ---------------   __________ -------------- _____ ----- -                                      |"<<endl;
		cout<<"\t|                ________________________________   --------  __  __  -                                     |"<<endl;
		cout<<"\t|            ________________ ---------------   _________------- ___-                                       |"<<endl;
		cout<<"\t|             -------------------      ------------     ------  ---- -                                      |"<<endl;
		cout<<"\t|     __   _    _________________________________ ------- __ -- __                                          |\n\n\n"<<endl;
		cout<<"\t\t\t[US                                                           ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                           |"<<endl;
		cout<<"\t| ---   -   -  -----------       ---------    ---------- ---  - -                                           |"<<endl;
		cout<<"\t|          _______________________       _________    ______ ---  --                                        |"<<endl;
		cout<<"\t|            _________________    ------------------   ___  __ -    -                                       |"<<endl;
		cout<<"\t||               --------------------  _______  ------  ---- _____ - -                                      |"<<endl;
		cout<<"\t||         ---------------   __________ -------------- _____ ----- -                                        |"<<endl;
		cout<<"\t|              ________________________________   --------  __  __  -                                       |"<<endl;
		cout<<"\t|          ________________ ---------------   _________------- ___-                                         |"<<endl;
		cout<<"\t|           -------------------      ------------     ------  ---- -                                        |"<<endl;
		cout<<"\t|   __   _    _________________________________ ------- __ -- __                                            |\n\n\n"<<endl;
		cout<<"\t\t\t[                                                             ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                           |"<<endl;
		cout<<"\t|--   -   -  -----------       ---------    ---------- ---  - -                                             |"<<endl;
		cout<<"\t|        _______________________       _________    ______ ---  --                                          |"<<endl;
		cout<<"\t|          _________________    ------------------   ___  __ -    -                                         |"<<endl;
		cout<<"\t|              --------------------  _______  ------  ---- _____ - -                                        |"<<endl;
		cout<<"\t|        ---------------   __________ -------------- _____ ----- -                                          |"<<endl;
		cout<<"\t|            ________________________________   --------  __  __  -                                         |"<<endl;
		cout<<"\t|        ________________ ---------------   _________------- ___-                                           |"<<endl;
		cout<<"\t|         -------------------      ------------     ------  ---- -                                          |"<<endl;
		cout<<"\t| __   _    _________________________________ ------- __ -- __                                              |\n\n\n"<<endl;
		cout<<"\t\t\t[                                                             ]\n\n\n\n\t";
		
		system("cls");
		cout<<"\n\n\n\n";
		cout<<"\t\t\t[     THANK   YOU   FOR   SUPPORTING   THE   J & J   AIRLINE     ]\n\n"<<endl;
		cout<<"\t|                                                                                                           |"<<endl;
		cout<<"\t|--   -   -  -----------       ---------    ---------- ---  - -                                             |"<<endl;
		cout<<"\t|        _______________________       _________    ______ ---  --                                          |"<<endl;
		cout<<"\t|          _________________    ------------------   ___  __ -    -                                         |"<<endl;
		cout<<"\t|              --------------------  _______  ------  ---- _____ - -                                        |"<<endl;
		cout<<"\t|        ---------------   __________ -------------- _____ ----- -                                          |"<<endl;
		cout<<"\t|            ________________________________   --------  __  __  -                                         |"<<endl;
		cout<<"\t|        ________________ ---------------   _________------- ___-                                           |"<<endl;
		cout<<"\t|         -------------------      ------------     ------  ---- -                                          |"<<endl;
		cout<<"\t| __   _    _________________________________ ------- __ -- __                                              |\n\n\n"<<endl;
		cout<<"\t\t\t[             YOUR   FLIGHT   IS   SAFE   WITH   US             ]\n\n\n\n\t";
		
		
		system("pause");
		exit(1);
	
	}
	
	
	
	}while(mainchoice!=1 && mainchoice!=2 && mainchoice!=3);
	
	
	return 0;
}


	
