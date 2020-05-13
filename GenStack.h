/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 5


#include <iostream>

using namespace std;

template <class T>
class GenStack
{
	public:
		GenStack();
		~GenStack();
		void push(T d);
		T pop();
		T peek();
		bool isEmpty();

	private:
		T *stack;
};

template <class T>
GenStack<T>::GenStack()
{
	stack = new DoublyLinkedList<T>();
}

template <class T>
GenStack<T>::~GenStack()
{
	delete stack;
}

template <class T>
void GenStack<T>::push(T d)
{
	stack->insertFront(d);
}

template <class T>
T GenStack<T>::pop()
{
	return stack->removeFront();
}

template <class T>
T GenStack<T>::peek()
{
	if (!isEmpty())
		return stack->peekHead();
	else
		cout << "ERROR. Stack is empty.";
}
template <class T>
bool GenStack<T>::isEmpty()
{
	return stack->isEmpty();
}
*/

/*
Moises Lopez
2282417
molopez@chapman.edu
350-02
Assignment 3

=== Template classes necessary for working with stacks. Push, pop and peek methods are set up as well as
checks on the stack to make sure whether or not they are empty (isEmpty)/(isFull)full. ===
*/

#include <iostream>
#include <string>

using namespace std;

template <class T>
class GenStack
{
  public:
    GenStack(int maxSize); //constructor
    ~GenStack(); //destructor
    int topStack, max;//member variables
    T *userArray;
    T *tempArray;

    bool isFull(); //checks if stack is full
    bool isEmpty(); //checks if stack is empty

    void push(T data); //adds to top of the stack
    T pop(); //removes data from the top of the stack
    T peek(); //shows the top element of the stack

    void expand(); //++size of stack if the stack T is full
};

//constructor
template <class T>
GenStack<T>::GenStack(int maxSize)
{
  userArray = new T[maxSize];
  max = maxSize;
  topStack = -1;
  tempArray = new T[max];
}

//destructor
template <class T>
GenStack<T>::~GenStack()
{
  delete []userArray;
  delete []tempArray;
  cout << "Arrays have been cleared." << endl;
}

template <class T>
bool GenStack<T>::isEmpty()
{
  return (topStack == -1);
}

template <class T>
bool GenStack<T>::isFull()
{
  return (topStack == max - 1);
}

template <class T>
void GenStack<T>::push(T data)
{
  //checks if stack full before adding onto it
  if (isFull() == true)
  {
    expand();
    push(data);
  }
  else
    userArray[++topStack] = data;
}

template <class T>
T GenStack<T>::peek()
{
  if (topStack == -1)
    return 0;
  else
    return userArray[topStack];
}

template <class T>
T GenStack<T>::pop()
{
  //checks if the stack is empty before removing from it
  if (isEmpty() == true)
  {
    cout << "Stack array is empty." << endl;
    return 0;
  }
  else
    return userArray[topStack--];
}

template <class T>
void GenStack<T>::expand()
{
  tempArray = new T[max];
  for (int i = topStack; i > -1; --i)
  {
    tempArray[i] = userArray[i];
  }
  max += 1;
  userArray = new T[max];
  for (int i = topStack; i > -1; --i)
  {
    userArray[i] = tempArray[i];
  }
}
