#include "main.hpp"

int main()
{
	vector<Person> person;
	int length;

	length = makePerson(person);
	cout << "The number of record is " << length << endl;
	printPerson(person);
	sortPerson(person);
	printPerson(person);
}
