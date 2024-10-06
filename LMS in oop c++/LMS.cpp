#include<iostream>
#include<fstream>
#include<conio.h>
#include<unistd.h>
using namespace std;

 void registeration();
 void borrow();
 void adminMenu();
 void usermenu();
 void security();

class Person {                      
protected:
    string name;
    string department;
    string contactno;
public:
    Person(string n, string d, string c) : name(n), department(d), contactno(c) {}

    virtual void display() = 0;     
};

class user : public Person {        
protected:
    string teaid, stid;
    int semester;

public:
    user(string n, string d, string c, string i, string ii, int s) : Person(n, d, c), teaid(i), stid(ii), semester(s) {}

void display() override {           
        int ch;
        cout << "\n \t    Registered Data  ";
        cout << "\n Press 1 to Display Professor data ";
        cout << "\n Press 2 to Display Student data ";
        cin >> ch;
        if (ch == 1) {

        ifstream teacher("Registered Teachers.txt");
		if(!teacher){
			cout<<"\n\nBOOK NOT FOUND!";
		}
		else{
			while(teacher>>name>>department>>contactno>>teaid){
            cout << "\n \t Name : " << name;
            cout << "\n \t Department : " << department;
            cout << "\n \t Contact no : " << contactno;
            cout << "\n \t Professor ID : " << teaid;	
			cout<<endl;		
			}
		}
            teacher.close();    
        } 
		else if (ch == 2) {
		ifstream student("Registered Students.txt");
		if(!student){
			cout<<"\n\nBOOK NOT FOUND!";
		}
		else{
			while(student>>name>>department>>semester>>contactno>>stid){
            cout << "\n \t Name : " << name;
            cout << "\n \t Department : " << department;
         	cout << "\n \t Contact no : " << contactno;
			cout << "\n \t Semester : " << semester;
            cout << "\n \t Roll Num : " << stid;
			cout<<endl;
			}
		}
            student.close();
		}
    }
    
void borrowbook(string name, string contact, string designation, string isbn, double days) { 
    string t, a, i;                                       
    int p;
    ifstream old("Library.txt");                  
    ofstream iss("Issued.txt", ios::app);

    if (!old || !iss) {
        cout << "UNABLE TO OPEN FILE....";
        return;
    }

    bool found = false;
    while (old >> t >> a >> i >> p) {
        if (i == isbn) {
            found = true;
            iss << " " << t << " " << a << " " << i << " " << p <<endl;
			iss<<"PERSON INFORMATION ->"<<" Name: "<< name <<" Contact Number"<<contact<<endl;
          	cout << "\n----------------------------------------";
			cout << "\n| DESIGNATION: " << designation << "   NAME OF PERSON: " << name<<"     |";
            cout << "\n| CONTACT NO: " << contact<<"                         |";
            cout << "\n| Return BOOK After " << days << " Days"<<"             |";
            cout << "\n|                                      |";
			cout << "\n| Price Charged 100 Per Day "<<"           |";
            cout << "\n| Price: You Have To Pay " << days * 100 << " After " << days << " Days"<<"|";
			cout << "\n----------------------------------------";
			cout << "    \nBOOK ISSUED SUCCESSFULLY...";
            break;
        }
    }

    if (!found) {
        cout << "\nBOOK NOT FOUND!";
    }

    old.close();
    iss.close();
}

void displayIssuedBooks()  {        
        string data;
		ifstream file("Issued.txt");
        if(!file){
        	cout<<"NO BOOK FOUND";
        	return;
		}
        	cout<<"\n TITLE AUTHOR ISBN PAGES"<<endl;
        	while(getline(file,data)){
				cout<<endl<<data<<endl;
				}
    }
	
    

};

class Admin : public Person {       
protected:
    string password;
public:
    Admin(string n, string p) : Person(n, "", ""), password(p) {}

    void display() override {       
        cout << "\n  Admin Name: " << name;
        cout << "\n\n  Successfully logged In";
        cout << endl;
    }
};

class Library {                     
protected:
    string title;
    string author;
    string isbn;
    int pages;

public:
	 Library() : title(""), author(""), isbn(""), pages(0) {};
    Library(string ti , string au , string isb , int p ) : title(ti), author(au), isbn(isb), pages(p) {}

    void addbooks() {               
      
       ofstream file("Library.txt",ios::app);
       file<<" "<<title<<" "<<author<<" "<<isbn<<" "<<pages<<endl;
       cout<<"\n BOOK ADDED SUCESSFULLY...";
       file.close();
	}

     void displaybooks() {          
        string data;
		ifstream file("Library.txt");
        if(!file){
        	cout<<"NO BOOK FOUND";
        	return;
		}
        	cout<<"\n TITLE AUTHOR ISBN PAGES"<<endl;
        	while(getline(file,data)){
				cout<<endl<<data<<endl;
				}
    }

  void updateBook(string nisbn) {   
    string t, a, i;
    int p;       
    ifstream old("Library.txt");
    ofstream temp("temp.txt");

    if (!old || !temp) {
        cout << "UNABLE TO OPEN FILE....";
        return;
    }

    bool found = false;
    while (old >> t >> a >> i >> p) {
        if (i == nisbn) {
            found = true;
            cout << "ENTER NEW TITLE: ";
            cin.ignore(); 
            getline(cin, title);
            cout << "ENTER NEW AUTHOR: ";
            getline(cin, author);
            cout << "ENTER NEW ISBN: ";
            getline(cin, isbn);
            cout << "ENTER PAGES: ";
            cin >> pages;
            temp << " " << title << " " << author << " " << isbn << " " << pages << endl;
            cout << "\nBOOK UPDATED SUCCESSFULLY... ";
        } else {
            temp << " " << t << " " << a << " " << i << " " << p << endl;
        }
    }

    old.close();
    temp.close();

    if (!found) {
        cout << "BOOK NOT FOUND!" << endl;
        remove("temp.txt");
    } else {
        remove("Library.txt");
        rename("temp.txt", "Library.txt");
    }
}



 void deleteBook(string deisbn) {    
    string t, a, i;
    int p;
    ifstream old("Library.txt");
    ofstream temp("temp.txt");

    if (!old || !temp) {
        cout << "UNABLE TO OPEN FILE....";
        return;
    }

    bool found = false;
    while (old >> t >> a >> i >> p) {
        if (i != deisbn) {
            temp << " " << t << " " << a << " " << i << " " << p << endl;
        } else {
            found = true;
        }
    }

    old.close();
    temp.close();

    if (!found) {
        cout << "BOOK NOT FOUND!" << endl;
        remove("temp.txt");
    } else {
        remove("Library.txt");
        rename("temp.txt", "Library.txt");
        cout << "\nBOOK DELETED SUCCESSFULLY... ";
    }
}

 
};
                                  
void Borrow() {                      
	    system("cls");
	string name,contact,designation,isbn;
	double days;

    Library l2;

    cout<<"\n Enter Your Name: ";
    cin>>name;
    cout<<"\n Enter Your Contact No: ";
    cin>>contact;
    cout<<"\n Enter Your Designation: ";
    cin>>designation;
	cout<<"\n For How many Days You Want To Borrow Book: ";
    cout<<"\n Enter Days: ";
    cin>>days;
    l2.displaybooks();
    cout<<"\n\n Which Book You Want To Borrow \n";
	cout<<" Enter ISBN Of Book: ";
    cin>>isbn;                           
   user u(" ", " ", " ", " ", " ",0);  
    
	   u.borrowbook(name,contact,designation,isbn,days); 
}
 
 void registeration(){                 
system("cls");
 	string name, dep, cno;
    int semes , choice;
    string sid, tid;

    cout<<"\n FIRST REGISTERED TO LIBRARY";
    cout << "\n\n  -----------Registration Page----------- " << endl;
    cout << "\n  Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "  Enter your contact number: ";
    cin.ignore();
    getline(cin, cno);
    cout << "  Choose your Designation ";
    cout << "\n  Press 1 for Teacher ";
    cout << "\n  Press 2 for Student ";
    cin >> choice;
    if (choice == 1) {
        cout << "  Enter your ID (only numbers): ";
        cin.ignore();
        getline(cin, tid);
        cout << "  Enter your DEPARTMENT: ";
        cin >> dep;
  ofstream file("Registered Teachers.txt", ios::app);
            file<<name<<" "<<dep<<" "<<cno<<" "<<tid<<endl;
            file.close();
    } else if (choice == 2) {
        cout << "  Enter your Roll Num (only numbers): ";
        cin.ignore();
        getline(cin, sid);
        cout << "  Enter your DEPARTMENT: ";
        cin >> dep;
        cout << "  Enter your semester num:  ";
        cin >> semes;
        cout << endl;
        ofstream file("Registered Students.txt", ios::app);
			file<<name<<" "<<dep<<" "<<semes<<" "<<cno<<" "<<sid<<endl;
            file.close();
    }
    cout << "\n  REGISTRATION SUCCESSFUL...\n\n";
   	user u(name, dep, cno, tid, sid, semes);
 sleep(1);
 usermenu();
 }

void adminMenu() {                                   
    string title, author, isbn, newisbn, disbn;
    int pages;

    int choice;
    do {
        cout << "\n\n------- Admin Menu -------";
        cout << "\n1. Add Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Delete Book";
        cout << "\n4. Update Book";
        cout << "\n5. Display Issued Books";
        cout << "\n6. Display Registered Data";
        cout << "\n7. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        cout << endl << endl;
        switch (choice) {
        case 1: {
            cout << "ENTER TITLE OF BOOK: ";
            cin.ignore(); 
            getline(cin, title);
            cout << "ENTER AUTHOR OF BOOK: ";
            getline(cin, author);
            cout << "ENTER ISBN OF BOOK: ";
            getline(cin, isbn);
            cout << "ENTER PAGES OF BOOK: ";
            cin >> pages;
            Library l1(title, author, isbn, pages);
            l1.addbooks();
            break;
        }
        case 2: {
            Library l1;
            l1.displaybooks();
            break;
        }
        case 3: {
            Library l1;
            l1.displaybooks();
            cout << "\n\nWHICH BOOK YOU WANT TO DELETE.\n";
            cout << "ENTER ISBN OF BOOK YOU WANT TO DELETE: ";
            cin >> disbn;
            l1.deleteBook(disbn);
            break;
        }
        case 4: {
            Library l1;
            l1.displaybooks();
            cout << "\n\nWHICH BOOK YOU WANT TO UPDATE.\n";
            cout << "ENTER ISBN OF BOOK YOU WANT TO UPDATE: ";
            cin >> newisbn;
            l1.updateBook(newisbn);
            break;
        }
        case 5: {
            user u(" ", " ", " ", " ", " ", 0);
            u.displayIssuedBooks();
            break;
        }
        case 6: {
            user u(" ", " ", " ", " ", " ", 0);
            u.display();
            break;
        }
        case 7:
            return;
        default:
            cout << "\nInvalid choice! Please try again.";
        }
    } while (choice != 7);
}

void usermenu() {                              
    int choice;
    do {
        cout << "\n\n------- User Menu -------";
        cout << "\n1. Borrow Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Display Issued Books";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << endl << endl;

        switch (choice) {
        case 1:
            Borrow();
            break;
        case 2: {
            Library l1;
            l1.displaybooks();
            break;
        }
        case 3: {
            user u(" ", " ", " ", " ", " ", 0);
            u.displayIssuedBooks();
            break;
        }
        case 4:
            return;
        default:
            cout << "\nInvalid choice! Please try again.";
        }
    } while (choice != 4);
}


void security(){                           
	  string username, password, pass, uname, pet;
    
	p:
    int choice;
    system("cls");
    cout << "\n    Admin Page";
    cout << "\n  Enter Username: ";
    cin.ignore();
    getline(cin, username);

    cout << "\n  Enter Password: ";
    cin >> password;

    fstream f1("password.txt");
    getline(f1, uname);
	getline(f1, pass);
    f1.close();
    if (password == pass && username==uname) {
        Admin a(username, password);
        a.display();
        sleep(1);
	    adminMenu();
    } else {
        cout << "\n  Wrong Credentials.... \n\n";
        cout << "\n Press 1 for Try Again ";
        cout << "\n Press 2 for Forgot password \n";
        cin >> choice;
        switch (choice) {
        case 1:                    
            goto p;
            break;
        case 2:
            system("cls");           
            cout << " Enter your favourite pet ";
            cin >> pet;
            if (pet == "tiger") {
            	cout << "\n Write Username ";
                cin>>username;
				cout << "\n Write New Password ";
                cin >> pass;
                ofstream f2("password.txt");
                f2 << username<<endl;
                f2 << pass<<endl;
				f2.close();
                cout << "\n Password changed Successfully ";
                sleep(1);
                goto p;
            }
            if (pet != "tiger") {
                cout << "Wrong information...";
                sleep(1);
                goto p;
            }
            break;
        }
    }
	}
void design()
{
	int n=178;
char ch= n;
int assci=254;
char r=assci;
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
cout<<r<<" IF YOU ARE USER THEN PRESS 1 ";
cout<<endl<<"      		    			     ";
cout<<r<<" IF YOU ARE ADMIN THEN PRESS 2 ";
cout<<endl<<"      		    			     ";
cout<<r<<" IF YOU WANT TO EXIT THEN PRESS 3 ";
cout<<"\n\n";
}


void registeredpersons() {
    string name;
    string line, n, d, c, r;
    int s,choice;
    do{
    cout << "  Choose your Designation To LogIn ";
    cout << "\n  Press 1 for Student ";
    cout << "\n  Press 2 for Teacher ";
    cout << "\n  Press 3 for Logout ";
    cin >> choice;
    switch(choice){
  case 1:{
    cout << "Enter your Name: ";
    cin >> name;
    ifstream file("Registered Students.txt");
    if (!file) {
        cout << "File Not Found!" << endl;
        return; }
    bool found = false;
    while ((file >> n >> d >> s >> c >> r)) {
      if (n == name) {
            found = true;
            break;    }
    }
    file.close();
    if (found) {
        cout << "Successfully Logged In..." << endl;
        usermenu();
    } else {
        registeration();  }
		break;
	}
   case 2:{
    	cout << "Enter your Name: ";
    cin >> name;
    ifstream file("Registered Teachers.txt");
    if (!file) {
        cout << "File Not Found!" << endl;
        return;
    }
    
    bool found = false;
    while ((file >> n >> d >> s >> c >> r)) {

        if (n == name) {
            found = true;
            break;
        }
    }
    file.close();
    
    if (found) {
        cout << "\n\nSuccessfully Logged In...\n" << endl;
        usermenu();
    } else {
        registeration();
    }
		break;}
   case 3:
	            return;
			default:			
		{   cout << "\nInvalid choice! Please try again.";
			break;
			}
	}
	} while(choice!=3);
}
	
int main() {

 	string uName,userDesignation;
    string username, password, pass, pet;
    int choose;
    do{
				system("cls");
    	design();
        cout<<"      		    			     ";
		cin >> choose;
	switch(choose){
	case 1:
		registeredpersons();

  		break;
	case 2:
        security();
        break;
	case 3:
		break;	
	default:
			cout<<"\nInvalid Choice....\n\n";
			sleep(1);
}
      }while(choose!=3);
	
    return 0;
}

