#ifndef BASE_CLASS_H
#define BASE_CLASS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Base_Class;
typedef void (Base_Class::*Object_Signal)(string&);
typedef void (Base_Class::*Object_Handler)(const string);
#define SIGNAL(_Signal) ((Object_Signal)(&_Signal))
#define HANDLER(_Handler) ((Object_Handler)(&_Handler))

struct Connection // Структура задания одной связи
{
	Object_Signal Signal; // Указатель на метод сигнала
	Base_Class* Connected_Object; // Указатель на второй объект
	Object_Handler Handler; // Указатель на метод обработчика
};

class Base_Class
{
	protected:
		static Base_Class* Current_Object;
		vector<Base_Class*> Slave_Vec;
		vector<Connection> Connections_Vec; //added
		Base_Class* Root_Ptr;
		string Object_Name;
		int Status;
		int Class_Number;
	public:

		Base_Class(string dObject_Name, Base_Class* dRoot_Ptr = nullptr);

		void Set_Object_Name(string dObject_Name);
		string Get_Object_Name();

		void Print_Tree(string s);
		void Print_Tree_Ready(string s);

		void Set_Root_Ptr(Base_Class* dRoot_Ptr);
		Base_Class* Get_Root_Ptr();
		Base_Class* Get_Root();
		Base_Class* Get_Object(string name);
		void Set_Status(int Status);
		int Get_Status();

		Base_Class* Find_Object_By_Name(string dObject_Name);
		Base_Class* Find_Object_By_Path(string dPath);

		void Set_Current(Base_Class* dCurrent);
		Base_Class* Get_Current();

		int Get_Class_Number();
		void Set_Connection(Object_Signal, Base_Class*, Object_Handler);
		void Delete_Connection(Object_Signal, Base_Class*, Object_Handler);
		void Emit_Signal(Object_Signal, string&);
		void Set_Ready_All();
		string Get_Absolute_Path(); //added

};
#endif
