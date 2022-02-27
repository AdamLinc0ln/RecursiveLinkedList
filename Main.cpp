
#include <iostream>
#include <fstream>

#include "LinkedList.h"

using namespace std;


int main()
{

	char dataFileName[] = "data.txt";
	ifstream fileData;
	fileData.open(dataFileName, 0);
	if (fileData.good() == false)
	{
		cout << "ERROR: can't open data file: " << dataFileName << endl;

		cout << endl << "Press the [Enter] key to quit...";
		cin.get();
		return -1;
	}


	{
		LinkedList courses;

		while (fileData.eof() == false)
		{
			unsigned int courseNumber;
			string courseName;
			unsigned int grades;
			double grade;

			fileData >> courseNumber;
			if (fileData.good() == false)
				break;
			fileData.ignore(1024, ',');

			getline(fileData, courseName, ',');//coursname = fileDate until "," can't use >> because of spaces

			fileData >> grades;
			fileData.ignore(1024, ',');

			fileData >> grade;

			// add the course
			courses.Insert(new Course(courseNumber, courseName, grades, grade));
		}

		fileData.close();

		// display the ordered list of courses

		courses.PrintList();

		double gpa = courses.CalculateGPA();
		cout.precision(4);
		cout << endl;
		cout << endl;
		cout << "Cumulative GPA: " << gpa << endl;

		// wait for the user to press enter to quit
		cout << endl << "Press the [Enter] key to quit...";
		cin.get();
	}
	return 0;
}
