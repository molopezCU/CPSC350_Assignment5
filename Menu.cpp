/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 5
*/

#include "Menu.h"

using namespace std;

Menu::Menu()
{
	struct stat buffer;
	if (stat (STUDENT_TABLE.c_str(), &buffer) == 0)
	{
		studentBST.loadFromFile(STUDENT_TABLE);
	}
	if (stat (FACULTY_TABLE.c_str(), &buffer) == 0)
	{
		facultyBST.loadFromFile(FACULTY_TABLE);
	}
}

Menu::~Menu()
{

}

bool Menu::isMalformedInt(string input)
{
	for (int i=0; i<input.size(); ++i)
	{
		if (!isdigit(input[i]))
		{
			return true;
		}
	}
	return false;
}

void Menu::printMenu()
{
	cout << "---Menu---" << endl;
	cout << 1 << ".  Print all student info (by ascending id)" << endl;
	cout << 2 << ".  Print all faculty info (by ascending id)" << endl;
	cout << 3 << ".  Print student info by student id" << endl;
	cout << 4 << ".  Print faculty info by faculty id" << endl;
	cout << 5 << ".  Print info of a student's faculty advisor" << endl;
	cout << 6 << ".  Print all advisees of a faculty member" << endl;
	cout << 7 << ".  Add a new student" << endl;
	cout << 8 << ".  Delete a student" << endl;
	cout << 9 << ".  Add a new faculty member" << endl;
	cout << 10 << ". Delete a faculty member" << endl;
	cout << 11 << ". Change a student's advisor" << endl;
	cout << 12 << ". Remove an advisee from a faculty member" << endl;
	cout << 13 << ". Rollback" << endl;
	cout << 14 << ". Exit" << endl;
	cout << "------" << endl;
	cout << "Enter an option: ";
}

void Menu::promptOption()
{
	string inputStr;
	int inputNum;
	printMenu();
	while (true)
	{
		cin >> inputStr;
		if (isMalformedInt(inputStr))
		{
			cout << "Malformed int. Try again: ";
			continue;
		}

		inputNum = atoi(inputStr.c_str());
		cout << "---Option " << inputNum << "---" << endl;
		switch (inputNum)
		{
			case 1:
				printAllStudents();
				break;
			case 2:
				printAllFaculty();
				break;
			case 3:
				printStudent();
				break;
			case 4:
				printFacultyMember();
				break;
			case 5:
				printAdvisor();
				break;
			case 6:
				printAdvisees();
				break;
			case 7:
				addStudent();
				break;
			case 8:
				deleteStudent();
				break;
			case 9:
				addFacultyMember();
				break;
			case 10:
				deleteFacultyMember();
				break;
			case 11:
				changeAdvisor();
				break;
			case 12:
				removeAdvisee();
				break;
			case 13:
				rollback();
				break;
			case 14:
				exit();
				return;
			default:
				cout << "Invalid option. Try again: ";
				continue;
		}
		printMenu();
	}
}

void Menu::printAllStudents()
{
	if (!studentBST.isEmpty())
		studentBST.printTree();
	else
		cout << "ERROR. Student table is empty." << endl;
}

void Menu::printAllFaculty()
{
	if (!facultyBST.isEmpty())
		facultyBST.printTree();
	else
		cout << "ERROR. Faculty table is empty." << endl;
}

int Menu::promptInt(string promptMsg)
{
	string input;
	cout << promptMsg;
	while (true)
	{
		getline(cin, input); //gets number input
		if (!input.empty())
		{
			if (isMalformedInt(input))
				cout << "Malformed int. Try again: ";
			else
				break;
		}

		else
			cout << "ERROR. Input field empty. Try again: ";
	}
	return atoi(input.c_str());
}

void Menu::printStudent()
{
	if (!studentBST.isEmpty())
	{
		int inputNum = promptInt("Enter student ID: ");
		printStudentInfo(inputNum);
	}
	else
		cout << "ERROR. Student table empty. Add a student before printing its info." << endl;
}

void Menu::printStudentInfo(int studentID)
{
	Student sr(studentID);
	if (studentBST.contains(sr))
		studentBST.printNode(sr);
	else
		cout << "ERROR. Student ID#" << studentID << " not found." << endl;
}

void Menu::printFacultyMember()
{
	if (!facultyBST.isEmpty())
	{
		int inputNum = promptInt("Enter faculty ID: ");
		printFacultyInfo(inputNum);
	}
	else
		cout << "ERROR. Faculty table empty. Add a faculty member before printing its info." << endl;
}

void Menu::printFacultyInfo(int facultyID)
{
	Faculty fr(facultyID);
	if (facultyBST.contains(fr))
		facultyBST.printNode(fr);
	else
		cout << "ERROR. Faculty ID#" << facultyID << " not found." << endl;
}

void Menu::printAdvisor()
{
	if (!studentBST.isEmpty())
	{
		int studentID = promptInt("Enter student ID: ");
		Student sr(studentID);
		Student val = studentBST.find(sr);
		if (val.id >= 0)
		{
			if (val.advisorId < 0)
				cout << val.name << " has no faculty advisor." << endl;
			else
				printFacultyInfo(val.advisorId);
		}
		else
			cout << "ERROR. Student ID#" << studentID << " not found." << endl;
	}
	else
		cout << "ERROR. Student table empty. Add a student before printing its info." << endl;
}

void Menu::printAdvisees()
{
	if (!facultyBST.isEmpty())
	{
		int facultyID = promptInt("Enter faculty ID: ");
		Faculty fr(facultyID);
		Faculty val = facultyBST.find(fr);
		if (val.id >= 0)
		{
			ListNode<int> *node = val.adviseeIds->head;
			if (node != NULL)
			{
				while (true)
				{
					Student sr;
					sr.id = node->data;
					Student stud = studentBST.find(sr);
					cout << stud.name << endl;
					if (node->next == NULL)
						break;
					else
						node = node->next;
				}
			}
			else
				cout << "ERROR. " << val.name << " has no advisees.";
		}
		else
			cout << "ERROR. Faculty ID#" << facultyID << " not found." << endl;
	}
	else
		cout << "ERROR. Faculty table empty. Add a faculty member before printing its info." << endl;
}

void Menu::promptString(string promptMsg, string &input, bool nonEmpty)
{
	cout << promptMsg;
	while (true)
	{
		getline(cin, input);
		if (nonEmpty && input.empty()) // nonEmpty = true if input must be nonEmpty
			cout << "ERROR. Input field empty. Try again: ";
		else
			break;
	}
}

bool Menu::isMalformedDouble(string input)
{
	bool hasPoint = false;
	if (input.size() == 1 && !isdigit(input[0]))
		return true;
	if (input[input.size()-1] == '.')
		return true;
	for (int i=0; i<input.size()-1; ++i)
	{
		if (input[i] == '.')
		{
			if (hasPoint)
				return true;
			else
				hasPoint = true;
		}
		else if(!isdigit(input[i]))
			return true;
	}
	return false;
}

void Menu::addStudent()
{
	string hack;
	getline(cin, hack);
	// Enter student id
	int id = promptInt("Enter student id: ");
	// Enter student name
	string promptMsg = "Enter student name: ";
	string name;
	promptString(promptMsg, name, true);
	// Enter student level
	promptMsg = "Enter student level: ";
	string level;
	promptString(promptMsg, level, true);
	// Enter major
	promptMsg = "Enter student major: ";
	string major;
	promptString(promptMsg, major, true);
	// Enter gpa
	promptMsg = "Enter student GPA: ";
	double gpa;
	cout << promptMsg;
	while (true)
	{
		string sgpa;
		getline(cin, sgpa);
		if (sgpa.empty())
		{
			cout << "ERROR. Input field empty. Try again: ";
			continue;
		}
		if (isMalformedDouble(sgpa))
		{
			cout << "ERROR. Malformed double. Try again: ";
			continue;
		}
		else
		{
			gpa = atof(sgpa.c_str());
			break;
		}
	}
	//enter advisorId
	cout << "Press [Enter] to skip adding an advisor ID." << endl;
	promptMsg = "Enter advisor ID: ";
	string advisorId;
	int advisorIdNum;
	promptString(promptMsg, advisorId, false);
	if (advisorId.empty())
		advisorIdNum = -1;
	else
		advisorIdNum = atoi(advisorId.c_str());
	//checks if student id matches
	Student sr(id, name, level, major, gpa, advisorIdNum);
	if (studentBST.contains(sr))
	{
		cout << "ERROR. Student ID " << id << " already exists." << endl;
		return;
	}
	//checks if advisorId exists.
	Faculty fr(advisorIdNum);
	if (advisorIdNum == -1 || facultyBST.contains(fr))
		studentBST.insert(sr);
	else
		cout << "Advisor ID " << advisorId << " does not exist." << endl;
}

void Menu::deleteStudent()
{
	if (studentBST.isEmpty())
	{
		cout << "ERROR. Student table empty. Add a student before printing its info." << endl;
		return;
	}
	//prompts for student id#
	int id = promptInt("Enter student id: ");
	//checks if student tree contains id#
	Student sr(id);
	if (studentBST.contains(sr))
	{
		Faculty fr;
		fr.addAdviseeID(id);
		bool successful = facultyBST.removeStudentId(id);
		//successful = false if the student is not an advisee of any advisor
		if (!successful)
			studentBST.deleteNode(sr);
		else
			cout << "ERROR. Student already has an advisor. Change or remove student's advisor before deleting the student." << endl;
	}
	else
		cout << "ERROR. Student ID#" << id << " does not exist." << endl;
}

void Menu::addFacultyMember()
{
	//enter faculty id
	int id = promptInt("Enter faculty id: ");
	//enter faculty name
	string promptMsg = "Enter faculty name: ";
	string name;
	promptString(promptMsg, name, true);
	//enter faculty level
	promptMsg = "Enter faculty level: ";
	string level;
	promptString(promptMsg, level, true);
	//enter faculty department
	promptMsg = "Enter faculty department: ";
	string department;
	promptString(promptMsg, department, true);

	Faculty fr(id, name, level, department);

	//enter advisee IDs
	cout << "Enter a single advisee ID and press [Enter] to add it." << endl;
	cout << "When you are finished adding IDs, type /done and press [Enter]" << endl;
	promptMsg = "Enter advisee ID: ";
	string input;
	cout << promptMsg;
	while (true)
	{
		getline(cin, input);
		getline(cin, input);

		if (input.empty()) // nonEmpty = true if input must be nonEmpty
			cout << "ERROR. Input field is empty. Try again: ";
		else if (input == "/done")
			break;
		else if (!isMalformedInt(input))
		{
			int idNum = atoi(input.c_str());
			fr.addAdviseeID(idNum);
			cout<<promptMsg;
		}
		else
			cout << "ERROR. Malformed int. Try again: ";
	}
	facultyBST.insert(fr);
}

void Menu::deleteFacultyMember()
{
	if (facultyBST.isEmpty())
	{
		cout << "ERROR. Faculty table empty. Add a faculty member before printing its info." << endl;
		return;
	}

	// Prompt for faculty id
	int id = promptInt("Enter faculty id: ");
	// Check if faculty tree contains id
	Faculty fr(id);
	Faculty found = facultyBST.find(fr);
	if (found.id != -1)
	{
		// Check if the advisee list is empty
		if (found.hasNoAdvisees())
			facultyBST.deleteNode(found);
		else
			cout << "ERROR. Faculty ID#" << id << " has advisees. Remove advisees before deleting faculty member." << endl;
	}
	else
		cout << "ERROR. Faculty ID#" << id << " does not exist." << endl;
}

void Menu::changeAdvisor()
{
	if (studentBST.isEmpty())
	{
		cout << "ERROR. Student table empty. Add a student before printing its info." << endl;
		return;
	}

	// Enter student id
	int studID = promptInt("Enter student id: ");
	Student sr(studID);
	Student found = studentBST.find(sr);
	Faculty old(found.advisorId);
	if (found.id != -1)
	{
		int facultyID = promptInt("Enter new advisor id: ");
		Faculty newr(facultyID);
		if (facultyBST.contains(newr))
		{
			sr.advisorId = facultyID;
			// replace advisor id in the student tree
			studentBST.replaceAdvisorId(sr);

			// replace student id in the faculty tree
			facultyBST.replaceStudentId(old, newr, studID);

		}
		else
			cout << "Faculty ID#" << facultyID << " does not exist." << endl;
	}
	else
		cout << "Student ID " << studID << " does not exist" << endl;
}

void Menu::removeAdvisee()
{
	if (facultyBST.isEmpty())
	{
		cout << "ERROR. Faculty table empty. Add a faculty member before printing its info." << endl;
		return;
	}

	// Enter faculty id
	int facultyID = promptInt("Enter faculty id: ");
	Faculty fr(facultyID);
	Faculty found = facultyBST.find(fr);
	if (found != -1)
	{
		// Enter student id
		int studID = promptInt("Enter student id: ");
		if (found.containsAdviseeID(studID))
			facultyBST.removeAdviseeID(found, studID);
	}
	else
		cout << "Faculty ID#" << facultyID << " does not exist." << endl;
}

void Menu::rollback()
{

}

void Menu::exit()
{
	cout << "Exiting..." << endl;
}
