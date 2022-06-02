#include "Child2.h"
Child2::Child2(string dObjectName, Base_Class* dRoot_Ptr) : Base_Class(dObjectName, dRoot_Ptr)
{
	this->Class_Number = 2;
}

void Child2::Signal(string& Message)
{
	if (this->Status)
	{
		cout << endl << "Signal from " << Get_Absolute_Path();
		Message += " (class: 2)";
	}
}
void Child2::Handler(const string Message)
{
	if (this->Status)
	{
		cout << endl << "Signal to " << this->Get_Absolute_Path() << " Text: " << Message;
	}
}
