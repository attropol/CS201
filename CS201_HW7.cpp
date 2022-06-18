#include "strutils.h"
#include <string>

#include <vector>
using namespace std;

#include <sstream>
#include <fstream>

#include <iostream>


struct MovDir
{
	string movieName;
	string director;
};

struct RatingSt
{
	string movieName;
	double point;
};

struct Result
{
	string movieName;
	string director;
	double point;
	int count;
};

int main()
{
	ifstream file;
	vector <MovDir> movDirs;
	vector <RatingSt> movRatings;
	ofstream fileOfResult;
	ifstream movFile,ratFile;
	string readLn,movieName,director;	
	vector <Result> results;
	string nameOfMovFile,nameOfRtFile,nameOfResFile, word;
	double point;
	int indx,j,k;
	bool validfile=false;
	bool movieEx;

	while (validfile == false)
	{
		if (nameOfMovFile!="")
		{
			cout << "Can not find the specified file." << endl;
		}
		cout << "Please enter a filename for Movie-Director file: ";
		cin  >> nameOfMovFile;
		file.open(nameOfMovFile);
		if(file.fail() == true)
		{
			validfile= false;
		}
		else
		{			
			validfile= true;
			file.close();
		}
	}

	validfile = false;
	while (validfile == false)
	{
		if (nameOfRtFile!="")
		{
			cout << "Can not find the specified file." << endl;
		}
		cout << "Please enter a filename for Rating file: ";
		cin  >> nameOfRtFile;

		file.open(nameOfRtFile);
		if(file.fail() == true)
		{
			validfile= false;
		}
		else
		{
			file.close();
			validfile= true;
		}
	}	
	cout << "Please enter a filename for output file: ";
	cin >> nameOfResFile;
				
	fileOfResult.open(nameOfResFile);
	movFile.open(nameOfMovFile);
	ratFile.open(nameOfRtFile);

	while (getline(movFile,readLn))
	{		
		
		movieName ="";
		director = "";
		indx= readLn.find(";");
		string line;
		line = readLn.substr(0,indx);
		istringstream iss(line);

		while(iss >> word)
		{
			director =  director + word + " ";		
		}

		director = director.substr(0,director.length()-1);
		readLn = readLn.substr(indx+1);
		istringstream iss2(readLn);

		while(iss2 >> word)
		{
			movieName += word + " ";		
		}
		movieName = movieName.substr(0,movieName.length()-1);
		ToUpper(movieName);
		MovDir movieDirector;
		movieDirector.movieName = movieName;
		movieDirector.director = director;	
		movDirs.push_back(movieDirector);
	}	
	while (getline(ratFile,readLn))
	{		
		
		istringstream iss(readLn);
		iss >> point;

		movieName = "";
		while(iss >> word)
		{
			movieName += word + " ";		
		}
		movieName = movieName.substr(0,movieName.length()-1);
		ToUpper(movieName);
		RatingSt newRating;
		newRating.movieName = movieName;
		newRating.point = point;	
		movRatings.push_back(newRating);
	}

	for (int i = 0; i< movRatings.size();i++)
	{
		movieName = movRatings[i].movieName;
		point = movRatings[i].point;
		for (int j = 0; j< movDirs.size();j++)
		{
			if (movDirs[j].movieName == movRatings[i].movieName)
				director = movDirs[j].director;		
		}
		movieEx = false;
		for (int i = 0; i< results.size(); i++)
		{
			if (results[i].movieName == movieName)
			{
				indx = i;
				movieEx = true;
			}
		}
	
		if (movieEx)
		{
			results[indx].point += point;
			results[indx].count++;
		}
		else
		{
			Result output;
			output.movieName = movieName;
			output.director = director;
			output.point = point;
			output.count = 1;
			results.push_back(output);
		}	
	}


	for(j=results.size()-1; j > 0; j--)
    {		
		for(k=0; k < j; k++)
    	{
			if(results[k+1].point/results[k+1].count 
				
				== results[k].point/results[k].count)
			{
				if(results[k+1].movieName < results[k].movieName)
				{
					Result temp = results.at(k+1);
					results.at(k+1) = results.at(k);
					results.at(k) = temp;				
				}
			}
			else if (results[k+1].point/results[k+1].count 
				
				> results[k].point/results[k].count)
            {
				Result temp = results.at(k+1);
				results.at(k+1) = results.at(k);
				results.at(k) = temp;
	   		}
			
		}
    }

	fileOfResult << "RANK,NAME,DIRECTOR,POINTS" << endl;
	for (int i = 0; i< results.size(); i++)
	{
		fileOfResult << i+1 << ", " 
			<< results[i].movieName << ", " << results[i].director 
			<< ", " << results[i].point / results[i].count << endl;
	}

	cout<< "Results are in the file: " << nameOfResFile;

	ratFile.close();
	movFile.close();
	fileOfResult.close();
	
	cin.get();

	cin.ignore();

	return 0;

}
