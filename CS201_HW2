#include <iostream>
#include <string>

using namespace std;

int main()

{
	double not1, not2, not3, not4, not5, fstev, secev;
	string name1, name2;

	cout << " This program is So good" << endl;
	cout << " Please enter your name: ";
	cin >> name1;

		cout <<" Gourmet " << name1 << ", please enter the name of restaurant: "<< endl;
	cin >> name2;

	cout <<" Gourmet " << name1 << ", please enter the scores of " << name2 << " for first-level evaluation:"<< endl;
	cin >> not1 >> not2;

	 if (not1<0 || not2<0)
	 {
		cout << "You can't give a score lower than 0"<< endl;

		system("pause");
	return 0;
	 }
	if (not1>10 || not2>10)
	 {
		cout << "You can't give a score higher than 10"<<endl;

		system("pause");
	return 0;
	}
	 else if (not2 <= 2 || not1 <= 2)
	{	
		cout << name2 << " couldn't pass the first-level evaluation... You couldn't possibly accept some food tastes that bad, right?"<< endl;
		
		system("pause");
	return 0;
	}
	
	cout <<" Gourmet " << name1 << ", please enter the scores of " << name2 << " for second-level evaluation:"<< endl;
	cin >> not3 >> not4 >> not5;

	if (not3<0 || not4<0 || not5<0)
	
	{
	cout <<"You can't give a score lower than 0"<<endl;

	}
	if (not3>10 || not4>10 || not5>10)
	
	{
	cout <<"You can't give a score higher than 10"<<endl;

	}

	fstev= 0.6*not1+0.4*not2;
	secev= 0.4*not1 +0.25*not2 +0.15*not3 +0.1*not4 +0.1*not5;

	if(fstev<5)
	{
		cout << name2 <<" couldn't pass the first-level evaluation..."<< endl;
	}
	else if(secev<6)

	{
		cout << name2 <<" passed the first-level evaluation, but that's as far as it can go." << endl;
	}
	if(6<=secev<7)

	{
		cout <<name1 << " according to your scores " << name2 << " deserves 1 star."<<endl;
	}

	else if(7<=secev<8)

	{
		cout <<name1 << " according to your scores " << name2 << " deserves 2 stars."<<endl;
	}
	else if(8<=secev<9)

	{
		cout <<name1 << " according to your scores " << name2 << " deserves 3 stars."<<endl;
	}
	else if(9<=secev<10)

	{
		cout <<name1 << " according to your scores " << name2 << " deserves 4 stars."<<endl;
	}
	else if(9<=secev<10)

	{
		cout <<name1 << " according to your scores " << name2 << " deserves 5 stars."<<endl;
	}
	

	system("pause");
	return 0;
}



