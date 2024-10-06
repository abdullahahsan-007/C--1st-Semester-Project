#include<iostream>
#include<conio.h>    // I use this library to use getch.
#include<string.h>
using namespace std;
int n=178;
char ch= n;
int assci=254;        //I use ascii code to show menu section a littel bit good.
char r=assci;
int x=0;
int i=0;
int k=0;

void design();
void add_books(); 
void search_books();
void update_books();
void display_books();
void borrow_books();

struct library{
	string title;
	string pub_name;
	float price;
	int id;
}  book[100];

struct books{
 int id[5]={232449,232450,232451,232452,232453};
 string title[5]={"c++","java_script","Mr.chips","HTML","CSS"};
 string p_name[5]={"Oxford","Wiley","Springer","Penguin","Hamdard"};	
 string price[5]={"700","200","500","900","300"};
}bk[5];

//1
void design()
{
    for(int i=0;i<=27; i++)
      cout<<ch;
      cout<<"  FINAL PROJECT FOR 1ST SMESTER:";
      cout<<" LIBRARY MANAGEMENT SYSTEM	 ";
	  for(int i=0;i<=27; i++)
      cout<<ch;
      cout<<"\n\n\n";
      cout<<"      			     ";
for(int i=0;i<=25; i++)
      cout<<ch;
cout<<" MENU ";
for(int i=0;i<=25; i++)
      cout<<ch;
      cout<<"\n\n";
cout<<endl<<"       					     ";      
cout<<r<<" IF YOU ARE ADMIN THEN PRESS 1 ";
cout<<endl<<"      		    			     ";
cout<<r<<" IF YOU ARE USER THEN PRESS 2 ";

cout<<"\n\n";
}

//2	
void add_books(){
system("cls");                   // to clear screen
                                 // in this way output will be more describable.

	char c=196;
    cout<<"\n				";	for(int i=1;i<28;i++)	{cout<<c;}
	cout<<"\n		   		|ENTER NEW BOOK TO LIBRARY| \n";
    cout<<"				";	
     for(int i=1;i<28;i++) {cout<<c;}

	cout<<endl<<endl;

	cout<<"		   		Enter the title of new Book:  ";
	cin>>book[i].title;
cout<<"\n		   		Enter Publisher name:    ";
cin>>book[i].pub_name;
cout<<"\n		   		Enter ID of new Book:    ";
cin>>book[i].id;
cout<<"\n		   		Enter price of book:     ";
cin>>book[i].price;
cout<<"\n		   		NEW BOOK ADDED SUCSSESFULLY.";
cout<<"\n\n		   		PRESS ENTER TO EXIT.";
i++;
getch();
}  

//3
void search_books()
{
int id;
system("cls");
char c=196;
cout<<"			     		";	for(int i=1;i<22;i++)
	{cout<<c;}
	cout<<"\n		 	    	   	  |ENTER ID OF BOOK|\n";
cout<<"				       	";	for(int i=1;i<22;i++)
	{cout<<c;}
	cout<<endl<<endl; 
	cout<<"				  ENTER ID:   ";cin>>id;	
	for(int x=0;x<i;x++)
{
     if(book[x].id==id)
{
cout<<"\n				 TITLE OF BOOK IS:  "<<book[x].title<<endl;
cout<<"\n				 PUBLISHER NAMER IS: "<<book[x].pub_name<<endl;
cout<<"\n				 BOOK PRICE IS:    "<<book[x].price<<endl;
cout<<"\n      			         ID OF BOOK IS:   "<<book[x].id<<endl;
break;}
else
{ cout<<"              BOOK ID NOT FOUND\n";
}
}
cout<<"\n                       TO RETURN TO THE MAIN MENU PRESS ENTER\n";
getch();         // I use this to pause the screen on search function.
}

 //4
 void update_book(){
 	int id;
 	system ("cls");
 	char c=196;
cout<<"				";	for(int i=1;i<38;i++)
	{cout<<c;}
	cout<<"\n		   		|CHANGE BOOK INFORMATION BY USING ID| \n";
cout<<"				";	for(int i=1;i<38;i++)
	{cout<<c;}
	cout<<endl<<endl;
		cout<<"			ENTER ID:  ";
		cin>>id;
	for(int x=0;x<i;x++){
	if (book[x].id==id)
	{
	cout<<"\n 	 	 	Enter the title of Book:  ";
	cin>>book[x].title;
	cout<<"\n		 	Enter Name of Publisher of Book : ";
	cin>>book[x].pub_name;
	cout<<"\n		 	Enter ID of Book :  ";
	cin>>book[x].id;
	cout<<"\n		 	Enter price of Book : ";
	cin>>book[x].price;
	}	
	else{cout<<"\n\n				 BOOK not found ";}
	}

 getch();            
 }

//5
void display_books(){
	system("cls");
	int v=5;
	cout<<"	AVAILABLE BOOKS IN LIBRARY\n";	
		
	cout<<endl<<endl;		
	for(int j=0;j<5;j++)
	{   cout<<"BOOK "<<j+1<<endl;
		cout<<"TITLE OF BOOK IS: "	<<bk[j].title[j]<<endl;
		cout<<"PUBLISHER NAME  : "	<<bk[j].p_name[j]<<endl;
		cout<<"ID OF BOOK      : "	<<bk[j].id[j]<<endl;
		cout<<"PRICE OF BOOK   : "	<<bk[j].price[j]<<endl;
		cout<<" "<<endl;
	}
	if(i!=0)
	{
	
	for(int m=0;m<i;m++)
	{   cout<<"BOOK "<<++v<<endl;
		cout<<"TITLE OF BOOK IS: "	<<book[m].title<<endl;
		cout<<"PUBLISHER NAME  : "	<<book[m].pub_name<<endl;
		cout<<"ID OF BOOK      : "	<<book[m].id<<endl;
		cout<<"PRICE OF BOOK   : "	<<book[m].price<<endl;
		cout<<" "<<endl;
	}
    }      
		getch();
 }

//6
 void borrow_books()
 {
 	system("cls");
 	string firstname,lastname;
 	double num,days;
 	int ID;
 	char c=196;
cout<<"				";	for(int i=1;i<28;i++)
	{cout<<c;}
	cout<<"\n		   		|BORROW A BOOK FROM LIBRARY| \n";
cout<<"				";	for(int i=1;i<28;i++)
	{cout<<c;}
	cout<<endl<<endl;
 	
 cout<<"                      ENTER ID OF BOOK WHICH YOU WANT TO BORROW:  ";
 cin>>ID;
 		for(int j=0;j<i;j++){
 	if(book[j].id==ID){
 		
 	cout<<"\n\n 			             TITLE OF BOOK IS: "<<book[j].title<<endl;
 	cout<<"\n\n	 	IF YOU WANT TO BORROW A BOOK THEN ENTER FOLLOWING INFORMATION ";
 	cout<<"\n\n 				ENTER YOUR FIRST NAME:   ";
 	cin>>firstname;
	cout<<"  \n	                 	ENTER YOUR LAST NAME:  ";
 	cin>>lastname;
 	cout<<"  \n	               		ENTER YOUR STUDENT CARD NUM:   ";
 	cin>>num;
 	cout<<endl<<endl;
	cout<<"           EXTRA CHARGES WILL BE APPLIED IF BOOK IS RETURNED AFTER 10 DAYS "<<endl;
	cout<<"\n                                 ENTER DAYS:  ";
    cin>>days;
 	if(days<10){
 		char c=220;
	 cout<<"\n\n\n";
cout<<"			  ";	
for(int i=1;i<49;i++)
	{cout<<c;}
	
	 cout<<"\n				                 RECIEPT";
	 cout<<"\n\n	          		"<<"NAME: "<<firstname<<" "<<lastname<<".    ";
	 cout<<"ROLL NUM: "<<num<<"."<<endl;
	 cout<<"\n	    		    AFTER "<<days<<" DAYS YOU WILL RETURN BOOK TO LIBRARY."; 
	 cout<<"\n		   		  RECIPT WILL ALSO RETURN WITH BOOK.";
	 cout<<"\n			  ";	for(int i=1;i<49;i++)
	 {cout<<c;}
	 }
	 else{
char c=220;
	 cout<<"\n\n\n";
cout<<"			  ";	
for(int i=1;i<49;i++)
	{cout<<c;}
	
	 cout<<"\n				                 RECIEPT";
	 cout<<"\n\n	          		"<<"NAME: "<<firstname<<" "<<lastname<<".    ";
	 cout<<"ROLL NUM: "<<num<<"."<<endl;
	 cout<<"\n	    		    AFTER "<<days<<" DAYS YOU WILL RETURN BOOK TO LIBRARY."; 
	 cout<<"\n                		        500 RUPEES WILL BE CHARGED. "<<endl;
	 cout<<"\n		   		  RECIPT WILL ALSO RETURN WITH BOOK.";
	 cout<<"\n			  ";	for(int i=1;i<49;i++)
	 {cout<<c;}

	 }	
}
 else{cout<<"				 BOOK NOT FOUND IN LIBRARY.";}	
}
  		
 getch();
 }

//7
void admin(){
	int choice;
	
cout<<"\n\n"<<r<<" 1: ADD NEW BOOK TO LIBRARY \n" <<endl;
cout<<r<<" 2: SEARCH FOR BOOK TO LIBRARY \n" <<endl;
cout<<r<<" 3: DISPLAY ALL BOOKS OF LIBRARY \n" <<endl; 
cout<<r<<" 4: UPDATE INFORMATION OF BOOK \n" <<endl;
cout<<r<<" 5: PRESS 0 TO EXIT\n\n";
char f=126;
for(int i=1;i<25;i++){
	cout<<f;
}
cout<<endl<<endl<<" select your choice ->>\n\n";
cin>>choice;
	switch(choice){
	case 1:
		add_books();
	break;
	case 2:
	   search_books();		
	break;	
	case 3:
       display_books();
	break;	
	case 4:
		update_book();
	break;
	
	case 0:
		exit (0);
default:	
cout<<endl<<r<<"SELECT CORRECT OPTION"<<r;					
	break;	
}
getch();
}
//8
void user(){
	int choice;
	
cout<<"\n\n";
cout<<"									"<<r<<" 1: SEARCH FOR BOOK TO LIBRARY \n" <<endl;
cout<<"									"<<r<<" 2: DISPLAY ALL BOOKS OF LIBRARY \n" <<endl; 
cout<<"									"<<r<<" 3: BORROW A BOOK FROM LIBRARY \n" <<endl;
cout<<"									"<<r<<" 4: PRESS 0 TO EXIT\n\n";
char f=126;
cout<<"									";
for(int i=1;i<25;i++){
	cout<<f;
}
	cout<<endl<<endl<<"									"<<" select your choice ->>\n\n";
cin>>choice;
	switch(choice)
{
	case 1:
	   search_books();		
	break;	
	case 2:
      cout<<" press 3 to see available books in library";
       display_books();
	case 3:
		borrow_books();
	break;	
	case 0:
		exit (0);	
default:	
cout<<endl<<r<<"SELECT CORRECT OPTION"<<r;					
	break;	
}
getch();
}

int main(){
	p:
		system("cls");
	int choice;

design ();
cout<<"					     ";
cout<<" select your choice ->> ";
cin>>choice;
switch(choice)
{
	case 1:
		admin();
		break;
		
	case 2:
		
       user();
		break;
	case 0:
		exit(0);
default:	
cout<<endl<<r<<"SELECT CORRECT OPTION"<<r;					
	break;	
}
goto p;
 getch();
  }


