#include "Child3.h"
Child3::Child3(string dObjectName, Base_Class* dRoot_Ptr) : Base_Class(dObjectName, dRoot_Ptr)
{
	this->Class_Number = 3;
}

void Child3::Signal(string& Message)
{
	if (this->Status)
	{
		cout << endl << "Signal from " << Get_Absolute_Path();
		Message += " (class: 3)";
	}
}
void Child3::Handler(const string Message)
{
	if (this->Status)
	{
		cout << endl << "Signal to " << this->Get_Absolute_Path() << " Text: " << Message;
	}
}
