#ifndef CHILD_5
#define CHILD_5
#include "Base_Class.h"
class Child5 : public Base_Class
{
public:
	Child5(string dObject_Name, Base_Class* dRoot_Ptr);
	void Signal(string&);
	void Handler(const string);
};
#endif // !CHILD_1

