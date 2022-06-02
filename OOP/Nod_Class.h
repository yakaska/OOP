#ifndef NOD_CLASS_H
#define NOD_CLASS_H
using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include "Base_Class.h"
class Nod_Class : public Base_Class
{
public:
	Nod_Class(string dObject_Name, Base_Class* dRoot_Ptr);
};
#endif