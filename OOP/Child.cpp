#include "Child.h"
void Child1::Signal(string dPath)
{
	cout << "Signal from " << dPath << endl;
}

void Child2::Signal(string dPath)
{
	cout << "Signal from " << dPath << endl;
}

void Child3::Signal(string dPath)
{
	cout << "Signal from " << dPath << endl;
}

void Child4::Signal(string dPath)
{
	cout << "Signal from " << dPath << endl;
}

void Child5::Signal(string dPath)
{
	cout << "Signal from " << dPath << endl;
}

void Child6::Signal(string dPath)
{
	cout << "Signal from " << dPath << endl;
}

void Child1::Handle(Base_Class* dObject_Ptr, string Command)
{
	cout << "Signal to " << "PATH HERE " << "Text:  " << Command << endl;
}

void Child2::Handle(Base_Class* dObject_Ptr, string Command)
{
	cout << "Signal to " << "PATH HERE " << "Text:  " << Command << endl;
}

void Child3::Handle(Base_Class* dObject_Ptr, string Command)
{
	cout << "Signal to " << "PATH HERE " << "Text:  " << Command << endl;
}

void Child4::Handle(Base_Class* dObject_Ptr, string Command)
{
	cout << "Signal to " << "PATH HERE " << "Text:  " << Command << endl;
}

void Child5::Handle(Base_Class* dObject_Ptr, string Command)
{
	cout << "Signal to " << "PATH HERE " << "Text:  " << Command << endl;
}

void Child6::Handle(Base_Class* dObject_Ptr, string Command)
{
	cout << "Signal to " << "PATH HERE " << "Text:  " << Command << endl;
}