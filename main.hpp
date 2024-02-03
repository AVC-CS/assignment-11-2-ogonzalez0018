#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
struct Name
{
    string first;
    string last;
};
struct Bdate
{
    int year;
    int month;
    int day;
};
struct Person
{
    int no;
    string ID;
    Name name;
    string email;
    string gender;
    string phone;
    Bdate bdate;
    string jobtitle;
};

void makePerson(vector<Person> &);
void printPerson(vector<Person>);
void writeFile(vector<Person>);
Person *getRecord(int);

void makePerson(vector<Person> &person)
{
    /*******************************
     * Code your program here
     *******************************/
}
void printPerson(vector<Person> person)
{
    vector<Person>::iterator it;
    printf("NO\tID\t\tName\t\t\tEmail\t\tPhone\t\t\tBirthday\t\t\t\tJobtitle\n");
    for (it = person.begin(); it != person.end(); it++)
    {
        cout << it->no << "\t";
        cout << it->ID << "\t";
        cout << it->name.first << " " << it->name.last << "\t";
        cout << it->email << "\t";
        cout << it->phone << "\t";
        cout << it->bdate.year << "\t"
             << it->bdate.month << "\t"
             << it->bdate.day << "\t";
        cout << it->jobtitle << endl;
    }
    cout << "**************************************************\n";
}
void printOnePerson(Person person)
{
    printf("NO\tID\t\tName\t\t\tEmail\t\tPhone\t\t\tBirthday\t\t\t\tJobtitle\n");
    cout << person.no << "\t";
    cout << person.ID << "\t";
    cout << person.name.first << " " << person.name.last << "\t";
    cout << person.email << "\t";
    cout << person.phone << "\t";
    cout << person.bdate.year << "\t"
         << person.bdate.month << "\t"
         << person.bdate.day << "\t";
    cout << person.jobtitle << endl;
    cout << "**************************************************\n";
}
void writeFile(vector<Person> person)
{
    /*******************************
     * Code your program here
     *******************************/
}
Person *getRecord(int number)
{
    Person *p;
    /*******************************
     * Code your program here
     *******************************/

    return p;
}