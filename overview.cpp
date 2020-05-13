BST database
Create Read Update Delete

One tree for student (st ud)
On for teacher (faculty id)

Template class for bst we made in class

Have s base class person
Has id name and level

Student-faculty inherit from person
Then apply variables that are specific to student and faculty
Simulation and main class as well

For the list of advisee, use LL of ints (a single liked list that is a template)

Once exit, write to file to store values

Same method 1 - 6 (get info)

Rollback - use stack to go back

If update advisor of student but dne, let them know they do not exits
 Facult dne so pull up faculty table and recommend one

Before update or del, ake sure the person eixsts
When del faculty, students get a new id for their new faculty

Rollback is used if user realises they made a mistake in their process

If insert and dleet, push action to stack

Rollback class
Instance of a stack
The stack stores another class type called transactions types
was it an insert? store delete and id
insert is the faculty obj you deleted
