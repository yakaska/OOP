#include "Child4.h"
Child4::Child4(string dObjectName, Base_Class* dRoot_Ptr) : Base_Class(dObjectName, dRoot_Ptr)
{
	this->Class_Number = 4;
}

void Child4::Signal(string& Message)
{
	if (this->Status)
	{
		cout << endl << "Signal from " << Get_Absolute_Path();
		Message += " (class: 4)";
	}
}
void Child4::Handler(const string Message)
{
	if (this->Status)
	{
		cout << endl << "Signal to " << this->Get_Absolute_Path() << " Text: " << Message;
	}
}
