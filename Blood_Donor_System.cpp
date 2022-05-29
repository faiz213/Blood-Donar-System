#include <iostream>
#include <fstream>
#include <string>
const int tRecord = 100;
using namespace std;

fstream file;

struct Data
{
    string name;
    string rollno;
    int donationNum;
    string Bgroup;
    string dateofDonation;
};

void menu()
{

    cout << "-----------------FCIT BLOOD DONOR SOCIETY-----------" << endl;
    cout << "\n\t |------------Main Menu----------------------              |";
    cout << "\n\t |1. Add Donor Data                                        |";
    cout << "\n\t |2. Search Donor by name                                  |";
    cout << "\n\t |3. Search all record of same blood group type            |";
    cout << "\n\t |4. Update Donor record                                   |";
    cout << "\n\t.|5. Delete Donor record                                   |";
    cout << "\n\t |----------------------------------------------           |";
}

    void addDonor(Data d1[], int &record)
{
    file.open("donors_data.txt", ios::out | ios::app | ios::binary);
    if (file.is_open())
    {
        cout << "-----------Add  a Record----------------" << endl;
        cin.ignore();
        cout << "Enter Donor name " << record + 1 << endl;
        getline(cin, d1[record].name);
        cout << "Enter donor Blood group  " << record + 1 << endl;
        getline(cin, d1[record].Bgroup);
        cout << "donation date : " << record + 1 << endl;
        getline(cin, d1[record].dateofDonation);
        cout << "Enter Donor number of donations  " << record + 1 << endl;
        cin >> d1[record].donationNum;
        file.write(reinterpret_cast<char *>(&d1[record]), sizeof(Data));
    }
    else
    {
        cout << endl;
        cout << "Eror file opening ";
    }
    file.close();
    record++;
}
// search donor data by name
    void searchData(Data d1[], int &record);
{

    string name;
    cout << "\n\tEnter donor  name you  want to search : ";
    cin >> name;
    Data student;
    file.open("donors_data.txt", ios::in | ios::binary);
    if (!read.eof())
    {

        cout << "---------Donor's Data----------" << endl;
        file.read(reinterpret_cast<char *>(&d1[i]), sizeof(Data));
        cin.ignore();
        getline(read, student.name);
        if (student.name == name)
        {
            cout << student;
            return name;
        }
    }
}
else
{
    cout << endl;
    cout << "File not opened" << endl;
}
    void searchbyBgroup(Data d1[], int &records);
{
    int searchbyBgroup;
    cout << "--Enter the Blood group of donor to see the list of same Blood group donors--" << endl;
    getline(cin, searchbyBgroup);
    cout << endl;
    cout << "---------Data of All Same Blood group type-----------" << endl;
    cout << searchbyBgroup;
    cout << endl;
    file.open("donors_data.txt", ios::in | ios::binary);
    if (file.is_open())
    {
        for (int i=0; i < records; i++)
        {
            file.read(reinterpret_cast<char *>(&d1[i]), sizeof(Data));
            if (d1[i].Bgroup == searchbyBgroup)
            {
                searchbyBgroup(d1, i);
            }
        }
    }
}
    void updateRecord(Data d1[],int &records);
{
    string updateRecord;
    cout<<"Enter the name of donor to update information"<<endl;
    getline(cin,updateRecord);
    file.open("donors_data.txt", ios::in | ios::binary | ios::out);
    if(file.is_open())
    {
        for(int i=0;int<records;i++)
        {
            file.read(reinterpret_cast<char *>(&d1[i]), sizeof(Data));
            if(d1[i].name == updateRecord)
            {
            cout<<"Blood donation of donor updated from "<<d1[i].donationNum <<"to"<<d1[i].donationNum +1<<endl;
            file.write(reinterpret_cast<char *>(&d1[i]), sizeof(Data));

            }
        }
    }
}
  
int main()
{
    bool program = 0;
    Data d1[tRecord];
    int index = 0;
    do
    {
        menu();
        char ch;
        cout << endl;
        cout << "Enter the key to funtion :" << endl;
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            addDonor(d1, index);
            break;
        }
        case '2':
        {
            searchData(d1, index);
            break;
        }
         case '3':
         {
            searchbyBgroup(d1,index);
            break;
         }
         case '4':
         {
           updateRecord(d1,index);
           break;
         }
    }
    }while(program==0);




    return 0;
}