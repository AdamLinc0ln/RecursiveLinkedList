#include "Course.h"

Course::Course(int courseNumber, std::string courseName, unsigned int credits, double grade)
{
	next = nullptr;

	this->courseNumber = courseNumber;
	this->courseName = courseName;
	this->credits = credits;
	this->grade = grade;
}
