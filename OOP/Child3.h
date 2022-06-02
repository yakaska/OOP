#ifndef CHILD_3
#define CHILD_3
#include "Base_Class.h"
class Child3 : public Base_Class
{
public:
	Child3(string dObject_Name, Base_Class* dRoot_Ptr);
	void Signal(string&);
	void Handler(const string);
};
#endif // !CHILD_1

