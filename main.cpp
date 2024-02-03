#include "main.hpp"

int main()
{
	vector<Person> person;
	int number;
	Person *p;

	makePerson(person);
	cout << "The number of record is " << person.size() << endl;
	printPerson(person);
	writeFile(person);
	number = 50;
	p = getRecord(number);
	printOnePerson(*p);
	number = 26;
	p = getRecord(number);
	printOnePerson(*p);
}
