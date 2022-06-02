#ifndef CHILD_2
#define CHILD_2
#include "Base_Class.h"
class Child2 : public Base_Class
{
public:
	Child2(string dObject_Name, Base_Class* dRoot_Ptr);
	void Signal(string&);
	void Handler(const string);
};
#endif // !CHILD_1

