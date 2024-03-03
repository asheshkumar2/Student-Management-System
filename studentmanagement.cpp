
//*************************************
//	HEADER FILES USED IN PROJECT
//*************************************

#include <iostream>

#include <cstdlib>
#include <fstream>
using namespace std;

//**************************************
//		CLASS USED IN PROJECT
//**************************************

class student
{
private:
    string name;
    string id;
    string course;
    string address;
    string roll_no;
    string email_id;
    string contect_no;
public:
    void menu(void);         // function to get get data from 					  user
    void insert(void);       // function to get new record 						from user
    void display(void);      // function to display all student 					   record
    void modify(void);       // function which modify the 						  student record
    void search(void);       // function which search the 						  details of a particular student
    void deleteRecord(void); // function delete the 							   particular student record

}; // class ends here

//**************************************
//		MENU USED IN PROJECT
//**************************************

void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t\t**************************************************" << endl;
    cout << "\t\t\t\t*           STUDENT MANEGMENT SYSTEM             *" << endl;
    cout << "\t\t\t\t**************************************************" << endl;
    cout << "\t\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t\t 2. Display record" << endl;
    cout << "\t\t\t\t 3. Modify record" << endl;
    cout << "\t\t\t\t 4. Search record" << endl;
    cout << "\t\t\t\t 5. Delete rocord" << endl;
    cout << "\t\t\t\t 6. Exit" << endl;

    cout << "\t\t\t\t**************************" << endl;
    cout << "\t\t\t\tchoose option[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t\t**************************" << endl;
    cout << "\t\t\t\tEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t\tAdd Another Student Record(Y, N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleteRecord();
        break;
    case 6:
        printf("\t\t\t\tMr. Ashish Kumar\n");
        printf("\t\t\t\tSTUDENT MANAGEMENT SYSTEM\n");
        printf("\t\t\t\tAmity University Jharkhand\n");
        printf("\t\t\t\tWe are Exiting from Entire program\n\n");
        exit(0);
    default:
        cout << "\n\t\t\t\tInvalide choice...Pls Try Again..." << endl;
    }
   
    goto menustart;
}

//**************************************
//   INSERT NEW DATA USED IN PROJECT
//**************************************

void student::insert()
{
    system("cls");
    fstream file;
    cout << "\n---------------------------------------------------------------------------";
    cout << "\n------------------------------------ Add Student Details ------------------" << endl;
    cout << "\t\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\t\tEnter Roll no: ";
    cin >> roll_no;
    cout << "\t\t\t\tEnter address: ";
    cin >> address;
    cout << "\t\t\t\tEnter Course: ";
    cin >> course;
    cout << "\t\t\t\tEnter Email id: ";
    cin >> email_id;
    cout << "\t\t\t\tEnter Contect no: ";
    cin >> contect_no;

    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << address << " " << email_id << " " << contect_no << endl;
    file.close();
}

//**************************************
//  DISPLAY FUNCTIONUSED IN PROJECT
//**************************************

void student::display()
{
    system("cls");
    int total = 0;
    fstream file;
    cout << "\n---------------------------------------------------------------------------";
    cout << "\n------------------------------------ display Student Details ------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\tNo Data Is Present.....";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> address >> email_id >> contect_no;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t\t Student No: " << ++total << endl;
            cout << "\t\t\t\t Student Name: " << name << endl;
            cout << "\t\t\t\t Student Roll no: " << roll_no << endl;
            cout << "\t\t\t\t Student course: " << course << endl;
            cout << "\t\t\t\t Student Address: " << address << endl;
            cout << "\t\t\t\t Student Email Id: " << email_id << endl;
            cout << "\t\t\t\t Student Contect No: " << contect_no << endl;
            file >> name >> roll_no >> course >> address >> email_id >> contect_no;
        }
        if (total == 0)
        {
            cout << "\n\t\t\t\tNo Data Is Present.....";
        }
    }
    file.close();
}

//**************************************
//   MODIFYFUNCTION USED IN PROJECT
//**************************************

void student::modify()
{
    system("cls");
    int found = 0;
    fstream file, file1;
    string rollno;
    cout << "\n---------------------------------------------------------------------------";
    cout << "\n------------------------------------ Student Modify Details ------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\tNoData Is Present....";
        file.close();
    }
    else
    {
        cout << "Enter roll no. of student which you want to modify: ";
        cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> address >> email_id >> contect_no;
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << address << " " << email_id << " " << contect_no << endl;
            }
            else
            {
                cout << "\t\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\t\tEnter Roll no: ";
                cin >> roll_no;
                cout << "\t\t\t\tEnter address: ";
                cin >> address;
                cout << "\t\t\t\tEnter Course: ";
                cin >> course;
                cout << "\t\t\t\tEnter Email id: ";
                cin >> email_id;
                cout << "\t\t\t\tEnter Contect no: ";
                cin >> contect_no;
                file1 << " " << name << " " << roll_no << " " << course << " " << address << " " << email_id << " " << contect_no << endl;
                found++;
            }
            file >> name >> roll_no >> course >> address >> email_id >> contect_no;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\t Student roll no. Not Found...";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");
    }
}

//**************************************
//  SEARCH FUNCTION USED IN PROJECT
//**************************************

void student::search()
{
    system("cls");
    int found = 0;
    string rollno;
    fstream file;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n---------------------------------------------------------------------------";
        cout << "\n------------------------------------ Student seearch Details ------------------" << endl;
        cout << "\n\t\t\t\tNo Data Is Present...";
    }
    else
    {
        cout << "\n---------------------------------------------------------------------------";
        cout << "\n------------------------------------ Student seearch Details ------------------" << endl;
        cout << "\nEnter roll no. of student which you to search: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> address >> email_id >> contect_no;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\t\t\t\t Student Name: " << name << endl;
                cout << "\t\t\t\t Student Roll no: " << roll_no << endl;
                cout << "\t\t\t\t Student course: " << course << endl;
                cout << "\t\t\t\t Student Address: " << address << endl;
                cout << "\t\t\t\t Student Email Id: " << email_id << endl;
                cout << "\t\t\t\t Student Contect No: " << contect_no << endl;
                found++;
            }
            file >> name >> roll_no >> course >> address >> email_id >> contect_no;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\tStudent roll number is not found...";
        }
        file.close();
    }
}

//**************************************
//	DELETE USED IN PROJECT
//**************************************

void student::deleteRecord()
{
    system("cls");
    int found = 0;
    string rollno;
    fstream file, file1;
    cout << "\n---------------------------------------------------------------------------";
    cout << "\n------------------------------------ Delete Student Details ------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\tNo Data Is Present....";
    }
    else
    {
        cout << "\nEnter roll number of the student which you want to delete data: ";
        cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> address >> email_id >> contect_no;
        while (!file.eof())
        {
            if (roll_no != rollno)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << address << " " << email_id << " " << contect_no << endl;
            }
            else
            {
                found++;
            }
            file >> name >> roll_no >> course >> address >> email_id >> contect_no;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\tStudent roll number is not found.....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");
    }
}

//**************************************
//	MAIN FUNCTION USED IN PROJECT
//**************************************

int main()
{
    // ifstream file("studentRecord");
    // remove("studentRecord");
    student project;
    project.menu();
    return 0;
}

//**************************************
// END MAIN FUNCTION USED IN PROJECT
//**************************************