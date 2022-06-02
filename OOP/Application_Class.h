#ifndef APP_CLASS_H
#define APP_CLASS_H
using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include "Base_Class.h"
#include "Nod_Class.h"
#include "Child2.h"
#include "Child3.h"
#include "Child4.h"
#include "Child5.h"
#include "Child6.h"
class Application_Class : public Base_Class
{
public:
	Application_Class(Base_Class*);
	void Build_Tree();
	int Exec_App();
	void Signal(string&);
	void Handler(const string);
};
#endif