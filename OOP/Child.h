#ifndef CHILD_H
#define CHILD_H
using namespace std;
#include <string>
#include "Base_Class.h"
class Child1 : public Base_Class
{
public:
	Child1(string dObject_Name, Base_Class* dRoot_Ptr) : Base_Class(dObject_Name, dRoot_Ptr) {}
	static void Signal(string command);
	static void Handle(Base_Class*, string);
};
class Child2 : public Base_Class
{
public:
	Child2(string dObject_Name, Base_Class* dRoot_Ptr) : Base_Class(dObject_Name, dRoot_Ptr) {}
	static void Signal(string& command);
	static void Handle(Base_Class*, string&);
};
class Child3 : public Base_Class
{
public:
	Child3(string dObject_Name, Base_Class* dRoot_Ptr) : Base_Class(dObject_Name, dRoot_Ptr) {}
	static void Signal(string command);
	static void Handle(Base_Class*, string);
};
class Child4 : public Base_Class
{
public:
	Child4(string dObject_Name, Base_Class* dRoot_Ptr) : Base_Class(dObject_Name, dRoot_Ptr) {}
	static void Signal(string command);
	static void Handle(Base_Class*, string);
};
class Child5 : public Base_Class
{
public:
	Child5(string dObject_Name, Base_Class* dRoot_Ptr) : Base_Class(dObject_Name, dRoot_Ptr) {}
	static void Signal(string command);
	static void Handle(Base_Class*, string);
};
class Child6 : public Base_Class
{
public:
	Child6(string dObject_Name, Base_Class* dRoot_Ptr) : Base_Class(dObject_Name, dRoot_Ptr) {}
	static void Signal(string command);
	static void Handle(Base_Class*, string);
};
#endif