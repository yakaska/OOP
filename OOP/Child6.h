#ifndef CHILD_6
#define CHILD_6
#include "Base_Class.h"
class Child6 : public Base_Class
{
public:
	Child6(string dObject_Name, Base_Class* dRoot_Ptr);
	void Signal(string&);
	void Handler(const string);
};
#endif // !CHILD_1

