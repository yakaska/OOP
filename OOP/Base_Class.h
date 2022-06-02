#ifndef BASE_CLASS_H
#define BASE_CLASS_H

class Base_Class;
typedef void(*Signal)(string&);
typedef void(*Handler)(Base_Class*, string& Str);
#define SIGNAL(S_Signal) ((Signal) (&S_Signal))
#define HANDLER(S_Handler) ((Hanlder) (&S_Handler))

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Base_Class
{
	protected:
		struct Connection // Структура задания одной связи
		{
			Signal P_Signal; // Указатель на метод сигнала
			Base_Class* P_Base_Class; // Указатель на второй объект
			Handler P_Handler; // Указатель на метод обработчика
		};

		static Base_Class* Current_Object;
		string Object_Name;
		Base_Class* Root_Ptr;
		int status;
		vector<Base_Class*> Slave_Vec;
		vector<Connection> Connections_Vec; //added
		
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
		void Set_Status(int status);
		int Get_Status();

		Base_Class* Find_Object_By_Name(string dObject_Name);
		Base_Class* Find_Object_By_Path(string dPath);

		void Set_Current(Base_Class* dCurrent);
		Base_Class* Get_Current();

		void Set_Connection(Signal P_Signal , Base_Class* P_Object, Handler P_Object_Handler);
		void Delete_Connection(Signal P_Signal, Base_Class* P_Object, Handler P_Object_Handler);
		void Emit_Signal(Signal P_Signal, string& Command);

};
#endif
