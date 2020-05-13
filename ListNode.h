/*
Name: Nick Lai
Student ID#: 2282417
Chapman email: lai137@mail.chapman.edu
Course Number and Section: 350-02
Assignment: 5
*/

#include <iostream>

using namespace std;

template <class T>
class ListNode
{
	public:
		ListNode();
		~ListNode();
		ListNode(T d);

		T data;
		ListNode *prev;
		ListNode *next;
};

template <class T>
ListNode<T>::ListNode()
{
	prev = NULL;
	next = NULL;
}

template <class T>
ListNode<T>::~ListNode()
{

}

template <class T>
ListNode<T>::ListNode(T d)
{
	data = d;
	prev = NULL;
	next = NULL;
}
