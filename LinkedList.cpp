#include <iostream>
#include "LinkedList.h"
using namespace std;
LinkedList::~LinkedList()
{
	cout << "Destructing List" << endl;
	DestructorHelper(head);
	head = nullptr;
}


void LinkedList::DestructorHelper(Course* cursor)// recursive helper for ~LinkedList()
{
	// base case
	if (cursor == nullptr)
	{
		return;
	}
	else
	{
		Course* tmp = cursor->next;//
		delete cursor;
		DestructorHelper(tmp);
	}
}

void LinkedList::PrintList() const// prints the contents of the list of courses to cout
{
	cout << "List Contents: " << "(" << Size() << ")";
	PrintListHelper(head);
}

void LinkedList::PrintListHelper(Course const* cursor) const// recursive helper for PrintList()
{


	if (cursor == nullptr)
	{
		cout << endl;
		return;

	}
	else
	{
		cout << endl;
		cout << "cs" << cursor->courseNumber << " ";
		cout << cursor->courseName << " ";
		cout << " Grade:" << cursor->grade;
		cout << " Credit Hours: " << cursor->credits << "";
		PrintListHelper(cursor->next);
	}

}

// precondition: list is in sorted order
// postcondition: newCourse is inserted into the list so the list maintains
//                sorted order. using recursison.
void LinkedList::Insert(Course* newCourse)
{
	head = InsertHelper(head, newCourse);
}


Course* LinkedList::InsertHelper(Course* head, Course* newCourse)// recursive helper for insert()//??
{
	// base case
	if (head == nullptr)//insert at beginning 
	{
		Course* tmp = new Course(newCourse->courseNumber, newCourse->courseName, newCourse->credits, newCourse->grade);
		return tmp;
	}
	else if (head->courseNumber > newCourse->courseNumber)//insert in between compare the coursenumbers
	{
		Course* tmp = new Course(newCourse->courseNumber, newCourse->courseName, newCourse->credits, newCourse->grade);
		tmp->next = head;
		return tmp;
	}
	else
	{
		head->next = InsertHelper(head->next, newCourse);
		return head;
	}

}


int LinkedList::Size() const 	// postcondition: size is returned. Must be calculated using recursion.
{
	return SizeHelper(head);
}


int LinkedList::SizeHelper(Course const* cursor) const// recursive helper for size()
{
	if (cursor == nullptr)
	{
		return 0;
	}
	//!null
	else
	{
		return SizeHelper(cursor->next) + 1;//recursion thing calls itself until no more in linkedlist

	}
}

// calculates the Cumulative GPA of all courses in the list.
// Cumulative GPA is the sum of all "grade points" divided by the sum of all credits
// "grade points" is found by multiplying the grade of a course by the number of 
// credits for that course
// this must be calculated recursively.
double LinkedList::CalculateGPA() const
{
	return CalculateTotalGradePoints(head) / CalculateTotalCredits(head);
}

// for help understanding the next two, google how to calulate Cumulative GPA
double LinkedList::CalculateTotalGradePoints(Course const* cursor) const// total of all earned Grade Points in list of courses
{
	if (cursor == nullptr)
	{
		return 0;
	}
	return (cursor->grade * cursor->credits) + CalculateTotalGradePoints(cursor->next);
}

unsigned int LinkedList::CalculateTotalCredits(Course const* cursor) const// total of all credits in list of courses
{
	if (cursor == nullptr)
	{
		return 0;
	}
	return (cursor->credits) + CalculateTotalCredits(cursor->next);
}
