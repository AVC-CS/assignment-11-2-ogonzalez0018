#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
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
    string line, buf;
    Person p;
    char delimiter = ',';
    ifstream ifs;
    stringstream ss;
    int fcnt, tmp;
    ifs.open("people-100.csv");
    if (!ifs)
    {
        cerr << "File Open Error\n";
        exit(0);
    }
    while (getline(ifs, line))
    {
        ss << line;
        fcnt = 0;
        while (getline(ss, buf, delimiter))
        {
            switch (fcnt)
            {
            case 0:
                p.no = stoi(buf);
                break;
            case 1:
                p.ID = buf;
                break;
            case 2:
                p.name.first = buf;
                break;
            case 3:
                p.name.last = buf;
                break;
            case 4:
                p.gender = buf;
                break;
            case 5:
                p.email = buf;
                break;
            case 6:
                p.phone = buf;
                break;
            case 7:
                p.bdate.year = stoi(buf.substr(0, 4));
                p.bdate.month = stoi(buf.substr(5, 2));
                p.bdate.day = stoi(buf.substr(8, 2));
                break;
            case 8:
                p.jobtitle = buf;
                ss.str("");
                break;
            default:
                cout << "Error happend while parsing\n";
            }
            fcnt++;
        }
        person.push_back(p);
        ss.clear();
    }
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
    ofstream ofs;
    ofs.open("Person.bin", ios::binary | ios::out);
    if (!ofs)
    {
        cerr << "File Open Error. Function WriteFile()\n";
        exit(0);
    }
    for (int i = 0; i < person.size(); i++){
        cout << person[i].email << endl;  
        ofs.write((char *)&(person[i]), sizeof(Person));
    }
    ofs.close();
}
Person *getRecord(int number)
{
    ifstream ifs;
    unsigned long offset;
    Person *p;

    ifs.open("Person.bin", ios::binary | ios::in);
    if (!ifs)
    {
        cerr << "File Open Error\n";
        exit(0);
    }
    offset = sizeof(Person) * (number - 1);

    ifs.seekg(offset, ios::beg);
    p = (Person *)malloc(sizeof(Person));
    ifs.read((char *)p, sizeof(Person));
    ifs.close();
    return p;
}
/*******************************
 * Code your program here
 *******************************/