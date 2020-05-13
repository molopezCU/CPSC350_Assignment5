/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 5
*/

#include "FacultyRecord.h"

using namespace std;

FacultyRecord::FacultyRecord()
{
	id = -1;
	name = "";
	level = "";
	department = "";
	adviseeIds = new DoublyLinkedList<int>();
}

FacultyRecord::~FacultyRecord()
{
	delete adviseeIds;
}

FacultyRecord::FacultyRecord(int newID)
{
	id = newID;
	name = "";
	level = "";
	department = "";
	adviseeIds = new DoublyLinkedList<int>();
}

FacultyRecord::FacultyRecord(int newID, string newName, string newLevel, string newDepartment)
{
	id = newID;
	name = newName;
	level = newLevel;
	department = newDepartment;
	adviseeIds = new DoublyLinkedList<int>();
}

FacultyRecord::FacultyRecord(string serializedFr)
{
	adviseeIds = new DoublyLinkedList<int>();
	deserialize(serializedFr);
}

string FacultyRecord::serialize()
{
	ostringstream oss;
	oss << id << ',' + name + ',' + level + ',' + department + ',';
	ListNode<int> *node = adviseeIds->head;
	if (node != NULL) {
		while (true) {
			oss << node->data;
			if (node->next == NULL)
				break;
			else
			{
				oss <<',';
				node = node->next;
			}
		}
	}
	else
		oss<<'-';
	return oss.str();
}

void FacultyRecord::deserialize(string serializedFr)
{
	stringstream ss(serializedFr);
	string item;
	int count = 0;
	while (getline(ss, item, ','))
	 {
		if (count == 0)
			id = atoi(item.c_str());
		else if
			(count == 1) name = item;
		else if
			(count == 2) level = item;
		else if
			(count == 3) department = item;
		else if
			(count >= 4) addAdviseeID(atoi(item.c_str()));
		count++;
	}
}

void FacultyRecord::addAdviseeID(int id)
{
	adviseeIds->insertBack(id);
}

int FacultyRecord::removeAdviseeID(int id)
{
	return adviseeIds->remove(id);
}

bool FacultyRecord::containsAdviseeID(int id)
{
	return (adviseeIds->contains(id));
}

bool FacultyRecord::hasNoAdvisees()
{
	return (adviseeIds->isEmpty());
}
