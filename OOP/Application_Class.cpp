#include "Application_Class.h"

void Application_Class::Build_Tree()
{
	//Set_Current(this);
	string Temp_Parent_Path, Temp_Object_Name;
	int Class_Type;
	cin >> Temp_Object_Name;
	//Set_Object_Name(Temp_Object_Name);
	Base_Class* Temp_Parent = new Child1(Temp_Object_Name, nullptr); //корневой объект
	Set_Current(Temp_Parent);
	Base_Class* Temp_Child;
	while (true)
	{
		cin >> Temp_Parent_Path;
		if (Temp_Parent_Path == "endtree")
			break;
		cin >> Temp_Object_Name >> Class_Type;
		Temp_Parent = Find_Object_By_Path(Temp_Parent_Path);
		if (Temp_Parent == nullptr)
		{
			cout << "Object tree";
			Print_Tree("");
			cout << endl << "The head object " << Temp_Parent_Path << " is not found";
			exit(0);
		}
		switch (Class_Type)
		{
		case 1: Temp_Child = new Child1(Temp_Object_Name, Temp_Parent);
			break;
		case 2: Temp_Child = new Child2(Temp_Object_Name, Temp_Parent);
			break;
		case 3: Temp_Child = new Child3(Temp_Object_Name, Temp_Parent);
			break;
		case 4: Temp_Child = new Child4(Temp_Object_Name, Temp_Parent);
			break;
		case 5: Temp_Child = new Child5(Temp_Object_Name, Temp_Parent);
			break;
		case 6: Temp_Child = new Child6(Temp_Object_Name, Temp_Parent);
			break;
		}
	}

}

int Application_Class::Exec_App()
{
	cout << "Object tree";
	Print_Tree("");
	string Command;
	while (true)
	{
		cin >> Command;
		if (Command == "END")
			break;
		if (Command == "EMIT")
		{
			string dPath, Message;
			cin >> dPath >> Message;
			Base_Class* dObject = Find_Object_By_Path(dPath);
			if (dObject == nullptr)
			{
				cout << "Object " << dPath << " not found" << endl;
			}
		}
		else if (Command == "SET_CONNECT") {

		}
		else if (Command == "DELETE_CONNECT")
		{

		}
		else if (Command == "SET_CONDITION") {

		}
		
	}
	return 0;
}
