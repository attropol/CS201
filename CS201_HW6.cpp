#include "strutils.h"

#include <string>

#include <sstream>


#include <fstream>


#include <iostream>

#include "date.h"

using namespace std;

bool CheckFileExistence(string nameOfDataFile);

void PrepareDate(int & mth1, int &

  yr1, int & mth2, int & yr2);

string PrepareOutpuFileNm(int mth1, int yr1, int mth2, int yr2);

void PutDataToFile(ofstream & outputFl1, ofstream

  &
  outputFl2, Date dateF, Date dateS, string gender, string name, Date birthDay);

void ReadFile(string nameOfDataFile, int mth1, int

  yr1, int mth2, int yr2);

void PutDataToFile(ofstream & outputFl1, ofstream &

  outputFl2, Date dateF, Date dateS, string gender, string name, Date birthDay) {
  if (dateF <= dateS && birthDay

    >=
    dateF && birthDay <=
    dateS) {
    if (gender == "F" ||

      gender == "f")
      outputFl2 << birthDay <<
      " "

      <<
      birthDay.DayName() << " " <<
      name << endl;
    else

      outputFl1 << birthDay << " " <<
      birthDay

      .DayName() << " " << name <<
      endl;

  } else if (birthDay >= dateS &&
    birthDay <= dateF)

  {
    if (gender ==
      "F" || gender == "f")

      outputFl2 <<
      birthDay << " "

      <<
      birthDay.DayName() << " " << name << endl;
    else
      outputFl1 <<
      birthDay << " "

      <<
      birthDay.DayName() <<
      " " << name

      <<
      endl;

  }

}

void ReadFile(string nameOfDataFile,

  int mth1, int yr1, int

  mth2, int yr2) {
  Date birthDay;

  ifstream
  dataFl;

  ofstream
  outputFl1, outputFl2;

  Date dateF(mth1, 1, yr1);

  Date dateS(mth2, 1, yr2);

  string inputLine,
  wordTmp, gender, name, outputCommonName;

  int day, month;

  int year,
  lcation;

  outputCommonName =

    PrepareOutpuFileNm(mth1, yr1, mth2, yr2);

  dataFl.open

  (nameOfDataFile);

  outputFl1.open("OutputMale_"

    +
    outputCommonName);

  outputFl2.open("OutputFemale_" + outputCommonName);

  while (getline(dataFl, inputLine)) {
    name = "";

    istringstream streamIss
      (inputLine);
    streamIss >>

      wordTmp;

    lcation = wordTmp.find(
      "/");

    day = atoi(wordTmp.substr(0, lcation));

    wordTmp = wordTmp.substr(lcation + 1);

    lcation =
      wordTmp.find("/");

    month
      = atoi

    (wordTmp.substr(0, lcation));
    wordTmp =
      wordTmp.substr(lcation + 1);

    year = atoi(
      wordTmp);

    birthDay = Date(month

      , day, year);

    streamIss >>
      gender;

    while (streamIss >> wordTmp)

    {
      ToLower
        (wordTmp);

      wordTmp.at(0) =
        wordTmp.at(0) +

        ('A' - 'a');

      name += wordTmp +
        " ";
    }

    PutDataToFile(
      outputFl1, outputFl2, dateF

      , dateS, gender, name, birthDay);
  }

  cout << endl <<
    "Outputs have been printed to"

    <<
    endl << "OutputMale_" + outputCommonName

    <<
    endl <<
    "OutputFemale_" + outputCommonName

    <<
    endl << endl;

  outputFl1.
  close();

  outputFl2.close();

  dataFl.close();

}

int main() {
  string nameOfDataFile;

  int mth1, yr1,
  mth2;

  string gender;

  string
  name;

  int yr2;

  cout <<
    "This program bla bla bla"

    <<
    endl

    <<
    endl;

  cout << "Please enter the name of the data file: ";

  cin >>
    nameOfDataFile;

  while (CheckFileExistence(nameOfDataFile) ==
    false) {

    cout << "You have entered wrong file name. Please enter the name of the data file: ";
    cin >>
      nameOfDataFile;
  }

  PrepareDate(mth1,
    yr1, mth2, yr2);

  ReadFile(
    nameOfDataFile, mth1, yr1, mth2, yr2);

  cout <<
    "Press any key to continue . . .";

  cin.get();

  cin.ignore(

  );

  return 0;

}

bool CheckFileExistence(string

  nameOfDataFile) {
  ifstream
  myFile;

  myFile.open(nameOfDataFile);

  if (myFile.fail()) {
    return
    0;
  } else {
    myFile.

    close();
    return 1;
  }
}

string PrepareOutpuFileNm(int mth1, int yr1, int

  mth2, int yr2) {
  Date dateF(mth1, 1, yr1);
  string name;

  Date dateS(mth2

    , 1, yr2);

  if (dateF <=
    dateS) {
    name = to_string(mth1)

      +
      "-" +
      to_string(
        yr1)

      +
      "_" + to_string(mth2) +
      "-" + to_string(yr2)

      +
      ".txt";
  } else {
    name = to_string(mth2) +
      "-"

      +
      to_string(

        yr2) +
      "_" +
      to_string(
        mth1)

      +
      "-" +
      to_string(yr1)

      +
      ".txt";
  }

  return
  name;
}

void PrepareDate(

  int & mth1, int & yr1, int & mth2, int & yr2) {
  int nmbr;

  mth1 = 0;

  while (mth1 < 1 ||
    mth1 > 12)

  {
    cout << "Please enter month value for first date: ";
    while ((cin >> nmbr) == 0) {
      string s;
      cin.clear(

      );
      cin >>
        s;
      cout << "You have to enter an integer value. "

        <<
        s <<
        " is not an integer."

        <<
        endl;
      cout << "Please enter month value for first date: ";

    }
    mth1 = nmbr;

    if (mth1 <
      1 ||
      mth1 > 12)

      cout <<
      "Integer value must be between 1 and 12" <<
      endl;

  }

  yr1 = 0;

  while (yr1 <
    1900 || yr1 >

    2100) {
    cout <<
      "Please enter year value for first date: ";
    while (

      (cin >>
        nmbr) == 0) {

      string
      s;
      cin.
      clear();
      cin >> s;

      cout <<
        "You have to enter an integer value. " <<
        s << " is not an integer." <<
        endl;

      cout << "Please enter year value for first date: ";
    }
    yr1 = nmbr;
    if (yr1 < 1900

      ||
      yr1 >
      2100)

      cout << "Integer value must be between 1900 and 2100" <<
      endl;
  }

  mth2 = 0;

  while (mth2 < 1

    ||
    mth2 >
    12) {
    cout << "Please enter month value for second date: ";
    while ((
        cin >>

        nmbr) == 0) {
      string

      s;
      cin
        .clear();
      cin >> s;

      cout <<
        "You have to enter an integer value. " <<
        s

        <<
        " is not an integer." <<
        endl;
      cout <<

        "Please enter month value for second date: ";
    }

    mth2 =

      nmbr;

    if (mth2 < 1 || mth2 > 12)
      cout

      <<
      "Integer value must be between 1 and 12" <<
      endl;

  }

  yr2 = 0;

  while (yr2 <

    1900 || yr2 >
    2100) {
    cout

      <<
      "Please enter year value for second date: ";
    while ((cin >>
        nmbr) == 0) {

      string s;
      cin
        .clear();
      cin >>

        s;
      cout << "You have to enter an integer value. " <<

        s << " is not an integer." << endl;

      cout << "Please enter year value for second date: ";
    }
    yr2 = nmbr;

    if (yr2 <
      1900 || yr2

      >
      2100)
      cout << "Integer value must be between 1900 and 2100"

      <<
      endl;
  }

}
