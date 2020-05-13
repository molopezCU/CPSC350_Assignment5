/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 5
*/

#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Student
{
	public:
		Student();
		~Student();
		Student(int newID);
		Student(int newID, string newName, string newLevel, string newMajor, double newGPA, int newAdvisorID);
		Student(string serializedSr);
		string serialize();

		bool operator == (const Student &s)
		{
			return (this->id == s.id);
		}

		bool operator != (const Student &s)
		{
			return (this->id != s.id);
		}

		bool operator <= (const Student &s)
		{
			return (this->id <= s.id);
		}

		bool operator < (const Student &s)
		{
			return (this->id < s.id);
		}

		bool operator >= (const Student &s)
		{
			return (this->id >= s.id);
		}

		bool operator > (const Student &s)
		{
			return (this->id > s.id);
		}

		friend ostream& operator << (ostream& output, const Student &s)
		{
			output << "Student Name: " << s.name << endl;
			output << "Student ID: " << s.id << endl;
			output << "Level: " << s.level << endl;
			output << "Major: " << s.major << endl;
			output << "GPA: " << s.gpa << endl;
			if (s.advisorId >= 0)
				output << "Advisor ID: " << s.advisorId << endl;
			else
				output << "Advisor ID: None" << endl;
			return output;
		}

		int id;
		string name;
		string level;
		string major;
		double gpa;
		int advisorId;

	private:
		void deserialize(string serializedSr);
};
