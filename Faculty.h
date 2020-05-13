/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 5
*/

#include "DoublyLinkedList.h"
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Faculty
{
	private:
		void deserialize(string serializedFr);

	public:
		int id;
		string name;
		string level;
		string department;
		DoublyLinkedList<int> *adviseeIds;

		Faculty();
		~Faculty();
		Faculty(int newID);
		Faculty(int newID, string newName, string newLevel, string newDepartment);
		Faculty(string serializedFr);
		string serialize();
		void addAdviseeID(int id);
		int removeAdviseeID(int id);
		bool containsAdviseeID(int id);
		bool hasNoAdvisees();

		bool operator == (const Faculty &f)
		{
			return (this->id == f.id);
		}

		bool operator != (const Faculty &f)
		{
			return (this->id != f.id);
		}

		bool operator <= (const Faculty &f)
		{
			return (this->id <= f.id);
		}

		bool operator < (const Faculty &f)
		{
			return (this->id < f.id);
		}

		bool operator >= (const Faculty &f)
		{
			return (this->id >= f.id);
		}

		bool operator > (const Faculty &f)
		{
			return (this->id > f.id);
		}

		friend ostream& operator << (ostream& output, const Faculty &f)
		{
			output << "Faculty Member Name: " << f.name << endl;
			output << "Faculty ID: " << f.id << endl;
			output << "Level: " << f.level << endl;
			output << "Department: " << f.department << endl;
			output << "Advisee IDs: ";
			ListNode<int> *node = f.adviseeIds->head;
			if (node != NULL)
			{
				while (true)
				{
					output<<node->data;
					if (node->next == NULL)
						break;
					else
					{
						output << ", ";
						node = node->next;
					}
				}
			}
			else
				output << "None" << endl;
			return output;
		}
};
