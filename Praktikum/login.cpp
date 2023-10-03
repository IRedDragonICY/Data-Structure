/*
    Name     : Mohammad Farid Hendianto
    NIM      : 2200018401
    Class    : A
    Lecturer : Ardiansyah, S.T., M.Cs.
*/

#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <unistd.h>

using namespace std;

// Structure of Identity User
struct {
    string Name;
    string Address;
    string Email;
    string PhoneNumber;
    struct {
        int Day;
        int Month;
        int Year;
    } DateOfBirth;
    int Age;
} ID;

void calculateAge(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;

    if (ID.DateOfBirth.Month > currentMonth)
        ID.Age = currentYear - ID.DateOfBirth.Year - 1;
    else if (ID.DateOfBirth.Month == currentMonth)
    {
        if (ID.DateOfBirth.Day > currentDay)
            ID.Age = currentYear - ID.DateOfBirth.Year - 1;
        else
            ID.Age = currentYear - ID.DateOfBirth.Year;
    }
    else
        ID.Age = currentYear - ID.DateOfBirth.Year;
}

void listMenuIdentity(bool isMenuSelected[]){
    // List menu
    // 0 = Name
    // 1 = Address
    // 2 = Email
    // 3 = Phone Number
    // 4 = Date of Birth
    // 5 = Save
    // 6 = Reset
    // 7 = Cancel

    cout<<"Input Your Data\n\n";
    if (isMenuSelected[0])
        cout<<"> ";
    else
        cout<<"  ";
    cout<<"Name          : "<<ID.Name<<endl;
    if (isMenuSelected[1])
        cout<<"> ";
    else
        cout<<"  ";
    cout<<"Address       : "<<ID.Address<<endl;
    if (isMenuSelected[2])
        cout<<"> ";
    else
        cout<<"  ";
    cout<<"Email         : "<<ID.Email<<endl;
    if (isMenuSelected[3])
        cout<<"> ";
    else
        cout<<"  ";
    cout<<"Phone Number  : "<<ID.PhoneNumber<<endl;
    if (isMenuSelected[4])
        cout<<"> ";
    else
        cout<<"  ";
    cout<<"Date of Birth : "<<ID.DateOfBirth.Day<<"/"<<ID.DateOfBirth.Month<<"/"<<ID.DateOfBirth.Year<<endl<<endl;
    if (isMenuSelected[5])
        cout<<"> ";
    else
        cout<<"  ";
    cout<<"Save"<<endl;
    if (isMenuSelected[6])
        cout<<"> ";
    else
        cout<<"  ";
    cout<<"Reset"<<endl;
    if (isMenuSelected[7])
        cout<<"> ";
    else
        cout<<"  ";
    cout<<"Cancel"<<endl;
}

void inputIdentity(){
    bool isInputing = true;
    int totalMenu = 8;
    int totalMenuConfirm = 2;
    bool isMenuSelected[totalMenu]={1,0,0,0,0,0,0,0};
    bool isMenuConfirmSelected[totalMenuConfirm]={1,0};

    while (isInputing)
    {
        system("cls");
        listMenuIdentity(isMenuSelected);

        switch (getch())
        {
            case 72: // up
                for (int i = 0; i < totalMenu; i++)
                {
                    if (isMenuSelected[i]){
                        if (i == 0)
                            break;
                        else
                        {
                            isMenuSelected[i] = 0;
                            isMenuSelected[i-1] = 1;
                            break;
                        }
                    }
                }
                break;
            case 80: // down
                for (int i = 0; i < totalMenu; i++)
                {
                    if (isMenuSelected[i]){
                        if (i == 7)
                            break;
                        else
                        {
                            isMenuSelected[i] = 0;
                            isMenuSelected[i+1] = 1;
                            break;
                        }
                    }
                }
                break;
            case 13: // enter
                system("cls");
                for (int i = 0; i < totalMenu; i++)
                {
                    if (isMenuSelected[i]){
                        switch (i)
                        {
                            case 0:
                                cout<<"Input Your Name : ";
                                getline(cin,ID.Name);
                                break;
                            case 1:
                                cout<<"Input Your Address : ";
                                getline(cin,ID.Address);
                                break;
                            case 2:
                                cout<<"Input Your Email : ";
                                getline(cin,ID.Email);
                                break;
                            case 3:
                                cout<<"Input Your Phone Number : ";
                                getline(cin,ID.PhoneNumber);
                                break;
                            case 4:
                                cout<<"Input Your Date of Birth : "<<endl;
                                cout<<"Day   : ";
                                cin>>ID.DateOfBirth.Day;
                                // check if day is valid or not
                                while (ID.DateOfBirth.Day < 1 || ID.DateOfBirth.Day > 31)
                                {
                                    system("cls");
                                    cout<<"Input Your Date of Birth : "<<endl;
                                    cout<<"Invalid Day, please input again";
                                    cout<<"Day   :";
                                    cin>>ID.DateOfBirth.Day;
                                }
                                cout<<"Month : ";
                                cin>>ID.DateOfBirth.Month;
                                // check if month is valid or not
                                while (ID.DateOfBirth.Month < 1 || ID.DateOfBirth.Month > 12)
                                {
                                    system("cls");
                                    cout<<"Input Your Date of Birth : "<<endl;
                                    cout<<"Invalid Month, please input again";
                                    cout<<"Month : ";
                                    cin>>ID.DateOfBirth.Month;
                                }
                                cout<<"Year  : ";
                                // check if year is valid or not
                                while (ID.DateOfBirth.Year < 0)
                                {
                                    system("cls");
                                    cout<<"Input Your Date of Birth : "<<endl;
                                    cout<<"Invalid Year, please input again";
                                    cout<<"Year  : ";
                                    cin>>ID.DateOfBirth.Year;
                                }
                                cin>>ID.DateOfBirth.Year;
                                break;
                            case 5:
                                while (isInputing)
                                {
                                    system("cls");
                                    cout<<"Are you sure your data is correct?\n\n          ";
                                    if (isMenuConfirmSelected[0])
                                        cout<<"> ";
                                    else
                                        cout<<"  ";
                                    cout<<"Yes   ";
                                    if (isMenuConfirmSelected[1])
                                        cout<<"> ";
                                    else
                                        cout<<"  ";
                                    cout<<"No";
                                    switch (getch())
                                    {
                                        case 75:
                                            for (int i = 0; i < totalMenuConfirm; i++)
                                            {
                                                if (isMenuConfirmSelected[i]){
                                                    if (i == 0)
                                                        break;
                                                    else
                                                    {
                                                        isMenuConfirmSelected[i] = 0;
                                                        isMenuConfirmSelected[i-1] = 1;
                                                        break;
                                                    }
                                                }
                                            }
                                            break;
                                        case 77:
                                            for (int i = 0; i < totalMenuConfirm; i++)
                                            {
                                                if (isMenuConfirmSelected[i]){
                                                    if (i == 1)
                                                        break;
                                                    else
                                                    {
                                                        isMenuConfirmSelected[i] = 0;
                                                        isMenuConfirmSelected[i+1] = 1;
                                                        break;
                                                    }
                                                }
                                            }
                                            break;
                                        case 13:
                                            for (int i = 0; i < totalMenuConfirm; i++)
                                            {
                                                if (isMenuConfirmSelected[i]){
                                                    isInputing = false;
                                                    switch (i)
                                                    {
                                                        case 0:
                                                            calculateAge();
                                                            system("cls");
                                                            break;
                                                        case 1:
                                                            inputIdentity();
                                                            break;
                                                    }
                                                    break;
                                                }
                                            }
                                            break;
                                    }
                                }
                                break;
                            case 6:
                                // reset struct into default value
                                ID.Name = "";
                                ID.Address = "";
                                ID.Email = "";
                                ID.PhoneNumber = "";
                                ID.DateOfBirth.Day = 0;
                                ID.DateOfBirth.Month = 0;
                                ID.DateOfBirth.Year = 0;
                                ID.Age = 0;
                                break;
                            case 7:
                                isInputing = false;
                                cout<<"Thank You for using this program";
                                sleep(2);
                                break;
                        }
                        break;
                    }
                }
                break;
        }
    }
}
void outputIdentity(){
    // output data yang rapih
    cout<<"===================================================================================================="<<endl;
    cout<<"                                        Identity Data"<<endl;
    cout<<"Name          : "<<ID.Name<<endl;
    cout<<"Address       : "<<ID.Address<<endl;
    cout<<"Email         : "<<ID.Email<<endl;
    cout<<"Phone Number  : "<<ID.PhoneNumber<<endl;
    cout<<"Date of Birth : "<<ID.DateOfBirth.Day<<"/"<<ID.DateOfBirth.Month<<"/"<<ID.DateOfBirth.Year<<endl;
    cout<<"Age           : "<<ID.Age<<endl;
    cout<<"===================================================================================================="<<endl;
    
    // save to Identity.txt, if file doesn't exist, create new one. if file exist, append the data
    ofstream file;
    file.open("Identity.txt", ios::app);
    file<<"Name          : "<<ID.Name<<endl;
    file<<"Address       : "<<ID.Address<<endl;
    file<<"Email         : "<<ID.Email<<endl;
    file<<"Phone Number  : "<<ID.PhoneNumber<<endl;
    file<<"Date of Birth : "<<ID.DateOfBirth.Day<<"/"<<ID.DateOfBirth.Month<<"/"<<ID.DateOfBirth.Year<<endl;
    file<<"Age           : "<<ID.Age<<endl<<endl;
    file.close();

}

int main(){
    inputIdentity();
    outputIdentity();
    return 0;
}
