#include "Child5.h"
Child5::Child5(string dObjectName, Base_Class* dRoot_Ptr) : Base_Class(dObjectName, dRoot_Ptr)
{
	this->Class_Number = 5;
}

void Child5::Signal(string& Message)
{
	if (this->Status)
	{
		cout << endl << "Signal from " << Get_Absolute_Path();
		Message += " (class: 5)";
	}
}
void Child5::Handler(const string Message)
{
	if (this->Status)
	{
		cout << endl << "Signal to " << this->Get_Absolute_Path() << " Text: " << Message;
	}
}
