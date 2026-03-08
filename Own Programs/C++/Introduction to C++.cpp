/*Class in C++ holds data members and member function.
It may be private and public.
It is similar to C Structures syntactically.
User defined data type.
Class is a new data type.
Object creates an instance of class. So class have data members and member functions.
Object is just class but with values of data members.*/

/*Data abstraction is basically hiding data and showing what is needed to the user.*/
 
/*Data encapsulation - 
Private, Public and Protected (used only in inheritance)
Public is needed to access to it in main.
Private will allow the access only within public.*/

#include <iostream>
namespace first{
	std :: string a = "Anish";
}
int main(){
	std :: string a;
	std :: getline(std :: cin,a);
	std :: cout << a << std :: endl;
	std :: cout << first :: a << std::endl;
	return 0;
}
