#ifndef CHILD_4
#define CHILD_4
#include "Base_Class.h"
class Child4 : public Base_Class
{
public:
	Child4(string dObject_Name, Base_Class* dRoot_Ptr);
	void Signal(string&);
	void Handler(const string);
};
#endif // !CHILD_1

