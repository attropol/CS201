#include <iostream>
#include <string>
using namespace std;


int main()
{
	int epis1, epis2;
	double episize1, episize2, hardgb, hardmb, totmb1, totmb2;
	string name;


	cout <<" Please enter your name: ";
	cin >> name;

	cout << name << ", please enter the number of episodes for the first season: ";
	cin >> epis1;

	cout << name << ", please enter the size of an episode for the first season as megabytes: ";
	cin >> episize1;

	cout << name << ", please enter the number of episodes for the second season: ";
	cin >> epis2;

	cout << name << ", please enter the size of an episode for the second season as megabytes: ";
	cin >> episize2;

	cout << name << ", please enter the total harddisk size as gigabytes: ";
	cin >> hardgb;

	hardmb= 1024*hardgb;
	totmb1= epis1*episize1+epis2*episize2;
	totmb2= hardmb-totmb1;

	cout << "The harddisk size is " << hardmb << " megabytes." << endl;
	cout << "The total size of the two seasons is " << totmb1 << " megabytes." << endl;
	cout << "The total size of empty space is " << totmb2 << " megabytes.";



	system("pause");
	return 0;

}
