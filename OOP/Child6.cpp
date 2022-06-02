#include "Child6.h"
Child6::Child6(string dObjectName, Base_Class* dRoot_Ptr) : Base_Class(dObjectName, dRoot_Ptr)
{
	this->Class_Number = 6;
}

void Child6::Signal(string& Message)
{
	if (this->Status)
	{
		cout << endl << "Signal from " << Get_Absolute_Path();
		Message += " (class: 6)";
	}
}
void Child6::Handler(const string Message)
{
	if (this->Status)
	{
		cout << endl << "Signal to " << this->Get_Absolute_Path() << " Text: " << Message;
	}
}
