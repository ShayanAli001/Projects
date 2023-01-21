#include<iostream>
#include<string.h>
using namespace std;

struct patient
{
    long long ID;
	string fullname;	
	int age;
	string blood;
	string gender;
    patient*next;
};

class linkedlist
{
	patient *head;
	patient *tail;
	public:
	linkedlist()
	{
		head = NULL;
		tail = NULL;
	}
    
patient input()
{
	system("cls");
   patient *p = new patient();
   cout << "\n\tPlease Enter The Data Of Patient\n";
   cout << "\tFull Name      : ";
   cin.get();
   getline(cin,p->fullname);
   blod:
   cout << "\tBlood Group    : ";
   cin >> p->blood;
   if(p->blood == "A+" || p->blood == "a+" || p->blood == "A-" || p->blood == "a-" ||
      p->blood == "B+" || p->blood == "b+" || p->blood == "b-" || p->blood == "B-" ||
	  p->blood == "O+" || p->blood == "o+" || p->blood == "O-" || p->blood == "o-" ||
	  p->blood == "AB+" || p->blood == "ab+" || p->blood == "AB-" || p->blood == "ab-")
	  {
	  	cout << "";
	  }
	  else 
	  {
	  	cout << "\tPlease Enter Correct";
	  	goto blod;
	  }
   gendr:
   cout << "\tGender         : ";
   cin >> p->gender;
   if(p->gender == "male" || p->gender == "female" || p->gender == "Male" || p->gender == "Female" || p->gender == "f" || p->gender == "m" || p->gender == "M" || p->gender == "F")
   {
   	cout << "";	
   }
   else 
   {
   	cout << "\tWrong Gender Please Enter Correct";
   	goto gendr;
   }
   cout << "\tAge            : ";
   cin >> p->age;
   cout << "\tMobile number  : ";
   cin >> p->ID;
   
   return *p;
}
void output(patient *p)
{
	cout << endl;
	cout << "** Patient data ***";
	cout << "\nFirst Name         : " << p->fullname;
	cout << "\nGender             : " << p->gender;
	cout << "\nAge                : " << p->age;
	cout << "\nBlood Group        : " << p->blood;
	cout << "\nMobile Number      : " << p->ID<<endl;
	cout << "*********";
}

void insrtStart()
{
     patient*p = new patient();
     *p = input();
     if(p->ID == 0)
     return;

     if(head == NULL)

     {
         head = p;
         tail = p;
         p->next = NULL;
     }
     else
     {
        p->next = head;
        head = p;
     }
     system("cls");
     cout << "\n Critical Patient Admitted In Head:" <<endl;
     output(p);
     system("cls");
}

void insrtEnd()
{
     patient *p = new patient();
     *p = input();
     if(p->ID == 0)
	 {
     	delete p;
     	return;
	 }
    

     if(tail == NULL)
     {
     	p->next = NULL;
     	head = tail = p;
     }
     else
     {
	    tail->next = p;
        p->next = NULL;
        tail = p;
     }
     system("cls");
     cout << "\n Normal Patient Admitted In Tail:" << endl;
     output(p);
     system("cls");
     
}

void patientsout()
{
	 system("cls");
     if(head == NULL)
     {
     	cout << "\n\tNo Patient ";
     }
     else
     {
     	patient *p = new patient();
     	p = head;
     	head = head->next;
 	    cout << "\n\tPatient to operate:";
        output(p);
        delete(p);
        
 	 }
}

void patientslist()
{
     if(head == NULL)
     {
     	cout << "\n\tNo patient";
 	 }
 	 else
 	 {
     patient *p = new patient;
	 p = head;
     while( p != NULL)
	 {	
        cout << "\n** Admitted Patients **";
		cout << "\nFirst Name       : " << p->fullname;
		cout << "\nGender           : " << p->gender;
        cout << "\nAge              : " << p->age;
        cout << "\nBlood Group      : " << p->blood;
		cout << "\nMobile Number    : " << p->ID<<endl;
		cout << "*********" << endl;
        p = p->next;
     }
     cout << "\n";
 	 }
}

void subdepart(linkedlist  q)
{
    int choice;
    patient p;
    while (choice != 5)
	{
    system("cls");
	cout << "\n\n\tWelcome To Department : " ;
	cout << "\n\t\t[1] Add normal patient\n";
	cout << "\t\t[2] Add critically ill patient\n";
	cout << "\t\t[3] Take patient to Doctor\n";
	cout << "\t\t[4] Display list\n";
	cout << "\t\t[5] Change department or exit\n";
	cout << "\n\tPlease enter your choice : ";
	cin  >> choice;

    switch (choice)
	{
	  case 1:	q.insrtEnd();
	    		departments1(q);
	    		system("cls");
	 			break;

      case 2:	q.insrtStart();
	    		departments1(q);
	    		system("cls");
				break;

      case 3:	q.patientsout();
     			departments1(q);
     			system("cls");
	      		break;

      case 4:	system("cls");
	 			q.patientslist();
	 			departments1(q);
	 			system("cls");
				break;
	 }
	 
	 	if(choice == 5)
	 	{
	 		cout << "\n\t\tThank you! \n" << endl;
	 		system("cls");
	 		departments1(q);
		}
    }
    departments1(q);
}

void departments1(linkedlist q)
{
	int choice;
		while(choice != 5)
		{
		cout << "\n\tHOSPITAL MANAGEMENT SYSTEM\t"<<endl;
		cout << "\t1 General Clinic\n";
		cout << "\t2 Heart Clinic\n";
		cout << "\t3 Lung Clinic\n";
		cout << "\t4 Plastic Surgery\n";
		cout << "\t5 Exit";
		cout << "\n\n\tPlease enter your choice : ";
		cin >> choice;
		if(choice >= 1 && choice <= 4)
		{
			subdepart(q);
		}
		}
	if(choice == 5)
	{
	cout << "\n\t\tThank you! \n";
	}
}

};



int main ()
{
	system("cls");
	system("COLOR 8E");
   	linkedlist q;
	q.departments1(q);
	exit(0);
}