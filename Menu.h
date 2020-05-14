/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 5
*/

#include "BST.h"
#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

const string STUDENT_TABLE = "studentTable";
const string FACULTY_TABLE = "facultyTable";

class Menu
{
	private:
		StudentTable studentBST;
		FacultyTable facultyBST;
		bool isMalformedInt(string input);
		void printMenu();
		int promptInt(string promptMsg);
		void printStudentInfo(int studentId);
		void printFacultyInfo(int facultyId);
		bool isMalformedDouble(string input);
		void promptString(string promptMsg, string &input, bool nonEmpty);

	public:
		Menu(); //load BSTs
		~Menu();
		void promptOption();
		void printAllStudents(); //sorted by ascending
		void printAllFaculty(); //sorted by ascending
		void printStudent();
		void printFacultyMember();
		void printAdvisor();
		void printAdvisees();
		void addStudent(); //prompt for student info part by part here
		void deleteStudent();
		void addFacultyMember();
		void deleteFacultyMember();
		void changeAdvisor();
		void removeAdvisee();
		void rollback();
		void exit();
};
