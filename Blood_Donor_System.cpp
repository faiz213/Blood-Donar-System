#include<iostream>
#include <fstream>
#include <string>
using namespace std;
int ID;
struct Student
{
    int id;
    string name;
    string bloodGroup;
    int age;
    string degree;
    int semesterNo;
};

void addStudent()
{
    Student student;
    cin.ignore();
    cout << "\n\tEnter donor name : ";
    getline(cin, student.name);
    cout << "\n\tEnter donor blood group : ";
    getline(cin, student.bloodGroup);
    cout << "\n\tEnter donor age : ";
    cin >> student.age;
    cout << "\n\tEnter donor degree : ";
    cin >> student.degree;
    cout << "\n\tEnter donor semester number : ";
    cin >> student.semesterNo;
    ID++;

    ofstream write;
    write.open("student.txt", ios::app);
    write << "\n"
          << ID;
    write << "\n"
          << student.name;
    write << "\n"
          << student.bloodGroup;
    write << "\n"
          << student.age;
    write << "\n"
          << student.degree;
    write << "\n"
          << student.semesterNo;
    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "\n\tData save to file"<<endl;
}

void print(Student s)
{
    cout << "\n\t---donor's Data---";
    cout << "\n\tID is : " << s.id;
    cout << "\n\tdonor is : " << s.name;
    cout << "\n\tblood group is : " << s.bloodGroup;
    cout << "\n\tAge is : " << s.age;
    cout << "\n\tDegree is : " << s.degree;
    cout << "\n\tSmester Number is : " << s.semesterNo;
}

void readData()
{
    Student student;
    ifstream read;
    read.open("student.txt");
    while (!read.eof())
    {
        read >> student.id;
        read.ignore();
        getline(read, student.name);
        getline(read, student.bloodGroup);
        read >> student.age;
        read >> student.degree;
        read >> student.semesterNo;
        print(student);
    }
    read.close();
}
//Checkpoint
void searchData()
{
    cin.ignore();
    string name;
    cout << "\n\tEnter donor name want to search : ";
    getline(cin,name);
    Student student;
    ifstream read;
    read.open("student.txt");
    while (!read.eof())
    {
        read >> student.id;
        read.ignore();
        getline(read, student.name);
        getline(read, student.bloodGroup);
        read >> student.age;
        read >> student.degree;
        read >> student.semesterNo;
        if (student.name == name)
        {
            print(student);
        }
    }
}
void searchDatabyBloodGroup()
{
    cin.ignore();
    string blood;
    cout << "\n\tEnter donor name want to search : ";
    getline(cin, blood);
    Student student;
    ifstream read;
    read.open("student.txt");
    while (!read.eof())
    {
        read >> student.id;
        read.ignore();
        getline(read, student.name);
        getline(read, student.bloodGroup);
        read >> student.age;
        read >> student.degree;
        read >> student.semesterNo;
        if (student.bloodGroup == blood)
        {
            print(student);
        }
    }
}

void deleteData()
{
    cin.ignore();
    string name;
    cout << "\n\tEnter donor name want to search : ";
    getline(cin, name);
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Student student;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("student.txt");
        while (!read.eof())
        {
            read >> student.id;
            read.ignore();
            getline(read, student.name);
            getline(read, student.bloodGroup);
            read >> student.age;
            read >> student.degree;
            read >> student.semesterNo;
            if (student.name != name)
            {
                tempFile << "\n"
                         << student.id;
                tempFile << "\n"
                         << student.name;
                tempFile << "\n"
                         << student.bloodGroup;
                tempFile << "\n"
                         << student.age;
                tempFile << "\n"
                         << student.degree;
                tempFile << "\n"
                         << student.semesterNo;
            }
        }
        read.close();
        tempFile.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "\n\tData deleted successfuly";
    }
    else
    {
        cout << "\n\tRecord not deleted";
    }
}

void updateData()
{
    cin.ignore();
    string name;
    cout << "\n\tEnter donor name want to search : ";
    getline(cin, name);
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Student newData;
        cin.ignore();
        cout << "\n\tEnter donor name : ";
        getline(cin, newData.name);
        cout << "\n\tEnter donor blood group : ";
        getline(cin, newData.bloodGroup);
        cout << "\n\tEnter donor age : ";
        cin >> newData.age;
        cout << "\n\tEnter donor degree : ";
        cin >> newData.degree;
        cout << "\n\tEnter donor semester number : ";
        cin >> newData.semesterNo;
        Student student;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("student.txt");
        while (!read.eof())
        {
            read >> student.id;
            read.ignore();
            getline(read, student.name);
            getline(read, student.bloodGroup);
            read >> student.age;
            read >> student.degree;
            read >> student.semesterNo;
            if (student.name != name)
            {
                tempFile << "\n"
                         << student.id;
                tempFile << "\n"
                         << student.name;
                tempFile << "\n"
                         << student.bloodGroup;
                tempFile << "\n"
                         << student.age;
                tempFile << "\n"
                         << student.degree;
                tempFile << "\n"
                         << student.semesterNo;
            }
            else
            {
                tempFile << "\n"
                         << student.id;
                tempFile << "\n"
                         << newData.name;
                tempFile << "\n"
                         << newData.bloodGroup;
                tempFile << "\n"
                         << newData.age;
                tempFile << "\n"
                         << newData.degree;
                tempFile << "\n"
                         << newData.semesterNo;
            }
        }
        read.close();
        tempFile.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "\n\tData updated successfuly";
    }
    else
    {
        cout << "\n\tRecord not deleted";
    }
}

int main()
{
    ifstream read;
    read.open("id.txt");
    if (!read.fail())
    {
        read >> ID;
    }
    else
    {
        ID = 0;
    }
    read.close();

    while (true)
    {
       cout << "\t-----------------FCIT BLOOD DONOR SOCIETY-----------" << endl;
    cout << "\n\t |-------------------Main Menu----------------------|";
    cout << "\n\t |1. Add Donor Data                                 |";
    cout << "\n\t |2. Search all  Donors Data                        |";
    cout << "\n\t |3. Search all record of donors by name            |";
    cout << "\n\t |4. Delete Donor record                            |";
    cout << "\n\t |5. Update Donor record                            |";
    cout << "\n\t |6. search donors by blood group                   |";
    cout << "\n\t |--------------------------------------------------|";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        case 6:
            searchDatabyBloodGroup();
            break;  
        }
    }
}