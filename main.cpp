#include "main.hpp"

int main()
{
	vector<Person> person;
	int number;

	makePerson(person);
	cout << "The number of record is " << person.size() << endl;
	printPerson(person);
	writeFile(person);
	number = 50;
	getRecord(number);
}
