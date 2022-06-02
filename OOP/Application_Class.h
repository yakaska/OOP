#ifndef APP_CLASS_H
#define APP_CLASS_H
using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include "Base_Class.h"
#include "Nod_Class.h"
#include "Child.h"
class Application_Class : public Base_Class
{
public:
	Application_Class(string name = "") :Base_Class(name) {};
	void Build_Tree();
	int Exec_App();
};
#endif