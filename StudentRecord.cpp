/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 5
*/

#include "StudentRecord.h"

using namespace std;

StudentRecord::StudentRecord()
{
	id = -1;
	name = "";
	level = "";
	major = "";
	gpa = -1.0;
	advisorId = -1;
}

StudentRecord::~StudentRecord()
{

}

StudentRecord::StudentRecord(int newID)
{
	id = newID;
	name = "";
	level = "";
	major = "";
	gpa = -1.0;
	advisorId = -1;
}

StudentRecord::StudentRecord(int newID, string newName, string newLevel, string newMajor, double newGPA, int newAdvisorID)
{
	id = newID;
	name = newName;
	level = newLevel;
	major = newMajor;
	gpa = newGPA;
	advisorId = newAdvisorID;
}

StudentRecord::StudentRecord(string serializedSr)
{
	deserialize(serializedSr);
}

string StudentRecord::serialize()
{
	ostringstream oss;
	oss << id << ',' + name + ',' + level + ',' + major + ',' << gpa << ',' << advisorId;
	return oss.str();
}

void StudentRecord::deserialize(string serializedSr)
{
	stringstream ss(serializedSr);
	string item;
	int count = 0;
	while (getline(ss, item, ','))
	{
		if (count == 0) id = atoi(item.c_str());
		else if (count == 1) name = item;
		else if (count == 2) level = item;
		else if (count == 3) major = item;
		else if (count == 4) gpa = atof(item.c_str());
		else if (count == 5) advisorId = atoi(item.c_str());
		count++;
	}
}
