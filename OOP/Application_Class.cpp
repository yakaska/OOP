#include "Application_Class.h"

Application_Class::Application_Class(Base_Class* dRoot_Ptr) : Base_Class("root", dRoot_Ptr)
{
	this->Class_Number = 1;
}

void Application_Class::Signal(string& Message)
{
	if (this->Status)
	{
		cout << endl << "Signal from " << Get_Absolute_Path();
		Message += " (class: 1)";
	}
}

void Application_Class::Handler(const string Message)
{
	if (this->Status)
	{
		cout << endl << "Signal to " << this->Get_Absolute_Path() << " Text: " << Message;
	}
}

void Application_Class::Build_Tree()
{
	string Parent_Name, Child_Name;
	int Class_Number;
	cin >> Child_Name;
	Set_Current(this);
	this->Set_Object_Name(Child_Name);
	Base_Class* Parent = this;
	Base_Class* Child;
	cin >> Parent_Name;
	while (Parent_Name != "endtree")
	{
		cin >> Child_Name >> Class_Number;
		Parent = this->Find_Object_By_Path(Parent_Name);
		if (!Parent)
		{
			cout << "Object tree" << endl;
			this->Print_Tree("");
			cout << endl << "The head object " << Parent_Name << " is not found";
			exit(0);
		}
		switch (Class_Number)
		{
		case 2:
			Child = new Child2(Child_Name, Parent);
			break;
		case 3:
			Child = new Child3(Child_Name, Parent);
			break;
		case 4:
			Child = new Child4(Child_Name, Parent);
			break;
		case 5:
			Child = new Child5(Child_Name, Parent);
			break;
		case 6:
			Child = new Child6(Child_Name, Parent);
			break;
		default:
			break;
		}
		cin >> Parent_Name;
	}
	Object_Signal Signal_List[6] = { 
		SIGNAL(Application_Class::Signal), 
		SIGNAL(Child2::Signal),
		SIGNAL(Child3::Signal),
		SIGNAL(Child4::Signal),
		SIGNAL(Child5::Signal),
		SIGNAL(Child6::Signal)
	};
	
	Object_Handler Handler_List[6] = {
		HANDLER(Application_Class::Handler),
		HANDLER(Child2::Handler),
		HANDLER(Child3::Handler),
		HANDLER(Child4::Handler),
		HANDLER(Child5::Handler),
		HANDLER(Child6::Handler)
	};
	cin >> Parent_Name;
	while (Parent_Name != "end_of_connections")
	{
		cin >> Child_Name;
		Parent = this->Find_Object_By_Path(Parent_Name);
		Child = this->Find_Object_By_Path(Child_Name);
		Parent->Set_Connection(Signal_List[Parent->Get_Class_Number() - 1], Child, Handler_List[Child->Get_Class_Number() - 1]);
		cin >> Parent_Name;
	}
}

int Application_Class::Exec_App()
{
	Object_Signal Signal_List[6] = {
		SIGNAL(Application_Class::Signal),
		SIGNAL(Child2::Signal),
		SIGNAL(Child3::Signal),
		SIGNAL(Child4::Signal),
		SIGNAL(Child5::Signal),
		SIGNAL(Child6::Signal)
	};
	Object_Handler Handler_List[6] = {
		HANDLER(Application_Class::Handler),
		HANDLER(Child2::Handler),
		HANDLER(Child3::Handler),
		HANDLER(Child4::Handler),
		HANDLER(Child5::Handler),
		HANDLER(Child6::Handler)
	};
	cout << "Object tree" << endl;
	this->Print_Tree("");
	this->Set_Ready_All();
	string Command, Path, Message;
	int Status;
	Base_Class* Current = nullptr;
	Base_Class* Target = nullptr;
	cin >> Command;
	while (Command != "END")
	{
		cin >> Path;
		Current = Find_Object_By_Path(Path);
		if (!Current)
		{
			cout << endl << "Object " << Path << " not found";
			getline(cin, Message);
		}
		else
		{
			if (Command == "EMIT")
			{
				getline(cin, Message);
				Current->Emit_Signal(Signal_List[Current->Get_Class_Number() - 1], Message);
			}
			else if (Command == "SET_CONNECT")
			{
				cin >> Message;
				Target = Find_Object_By_Path(Message);
				if (Target)
					Current->Set_Connection(Signal_List[Current->Get_Class_Number() - 1], Target, Handler_List[Current->Get_Class_Number() - 1]);
				else
					cout << endl << "Handler object " << Message << " not found";
			}
			else if (Command == "DELETE_CONNECT")
			{
				cin >> Message;
				Target = Find_Object_By_Path(Message);
				if(Target)
					Current->Delete_Connection(Signal_List[Current->Get_Class_Number() - 1], Target, Handler_List[Target->Get_Class_Number() - 1]);
				else
					cout << endl << "Handler object " << Message << " not found";
			}
			else if (Command == "SET_CONDITION")
			{
				cin >> Status;
				Current->Set_Status(Status);
			}
		}
		cin >> Command;
	}
	return 0;
}
