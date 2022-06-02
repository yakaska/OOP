#include "Base_Class.h"

Base_Class* Base_Class::Current_Object;

vector<string> Tokenize(string s)
{
	string delim = "/";
	vector<string> result;
	auto start = 0U;
	auto end = s.find(delim);
	while (end != string::npos)
	{
		if(s.substr(start, end - start) != "")
			result.push_back(s.substr(start, end - start));
		start = end + delim.length();
		end = s.find(delim, start);
	}
	if(s.substr(start, end) != "")
		result.push_back(s.substr(start, end));
	return result;
}

Base_Class::Base_Class(string dObject_Name, Base_Class* dRoot_Ptr)
{
	this->Object_Name = dObject_Name;
	this->Root_Ptr = dRoot_Ptr;
	if (Root_Ptr)
	{
		Root_Ptr->Slave_Vec.push_back(this);
	}
}

void Base_Class::Set_Object_Name(string dObject_Name)
{
	Object_Name = dObject_Name;
}

string Base_Class::Get_Object_Name()
{
	return Object_Name;
}

void Base_Class::Print_Tree(string s)
{
	cout << endl << s << Get_Object_Name();
	for (int i = 0; i < Slave_Vec.size(); i++)
	{
		Slave_Vec[i]->Print_Tree(s + "    ");
	}
}

void Base_Class::Print_Tree_Ready(string s)
{
	cout << endl << s << Get_Object_Name();
	if (Get_Status() == 0)
	{
		cout << " is not ready";
	}
	else
	{
		cout << " is ready";
	}

	for (int i = 0; i < Slave_Vec.size(); i++)
	{
		Slave_Vec[i]->Print_Tree_Ready(s + "    ");
	}
}

void Base_Class::Set_Root_Ptr(Base_Class* dRoot_Ptr)
{
	if (dRoot_Ptr != nullptr)
	{
		for (int i = 0; Slave_Vec.size(); i++)
		{
			if (dRoot_Ptr->Slave_Vec[i]->Get_Object_Name() == Object_Name)
			{
				dRoot_Ptr->Slave_Vec.erase(Slave_Vec.begin() + i);
				break;
			}
		}
	}
	this->Root_Ptr = dRoot_Ptr;
	Root_Ptr->Slave_Vec.push_back(this); //fixme
}

Base_Class* Base_Class::Get_Root_Ptr()
{
	return Root_Ptr;
}

Base_Class* Base_Class::Get_Root()
{
	if (Root_Ptr != nullptr)
	{
		Root_Ptr->Get_Root();
	}
	return this;
}

Base_Class* Base_Class::Find_Object_By_Name(string dObject_Name)
{
	if (this->Object_Name == dObject_Name)
	{
		return this;
	}
	for (int i = 0; i < Slave_Vec.size(); i++)
	{
		Base_Class* Temp_Object = Slave_Vec[i]->Get_Object(dObject_Name);
		if (Temp_Object != nullptr)
		{
			return Temp_Object;
		}
	}
	return nullptr;
}

Base_Class* Base_Class::Find_Object_By_Path(string dPath)
{
	if (dPath == "")
		return nullptr;
	if (dPath == "/")
		return Get_Root();
	else if (dPath == ".")
	{
		return Get_Current();
	}
	else if (dPath.rfind("//", 0) == 0)
	{
		string Object_Name = dPath.substr(2);
		return Get_Object(Object_Name);
	}
	else if (dPath[0] == '/')
	{
		Base_Class* Find_From_Object = Get_Root();
		vector<string> Path_Names = Tokenize(dPath);
		for (int i = 0; i < Path_Names.size(); i++)
		{
			Find_From_Object = Find_From_Object->Find_Object_By_Name(Path_Names[i]);
			if (Find_From_Object == nullptr)
				break;
		}
		return Find_From_Object;
	}
	else
	{
		Base_Class* Find_From_Object = Get_Current();
		vector<string> Path_Names = Tokenize(dPath);
		for (int i = 0; i < Path_Names.size(); i++)
		{
			Find_From_Object = Find_From_Object->Find_Object_By_Name(Path_Names[i]);
			if (Find_From_Object == nullptr)
				break;
		}
		return Find_From_Object;
	}
}

Base_Class* Base_Class::Get_Object(string name)
{
	return Get_Root()->Find_Object_By_Name(name);
}

void Base_Class::Set_Status(int a)
{
	if (!a)
	{
		status = 0;
		for (int i = 0; i < Slave_Vec.size(); i++)
		{
			Slave_Vec[i]->Set_Status(0);
		}
	}
	else if (Root_Ptr == nullptr || Root_Ptr->Get_Status())
	{
		status = a;
	}
}

int Base_Class::Get_Status()
{
	return status;
}

void Base_Class::Set_Current(Base_Class* dCurrent)
{
	Current_Object = dCurrent;
}

Base_Class* Base_Class::Get_Current()
{
	return Current_Object;
}

void Base_Class::Set_Connection(Signal P_Signal, Base_Class* P_Object, Handler P_Object_Handler)
{
	for (Connection c : Connections_Vec)
	{
		if (c.P_Signal == P_Signal && c.P_Handler == P_Object_Handler && c.P_Base_Class == P_Object)
			return;
	}
	Connection c = { P_Signal, P_Object, P_Object_Handler };
	Connections_Vec.push_back(c);
}

void Base_Class::Delete_Connection(Signal P_Signal, Base_Class* P_Object, Handler P_Object_Handler)
{
	for (auto i = Connections_Vec.begin(); i != Connections_Vec.end(); i++)
	{
		if (i->P_Signal == P_Signal && i->P_Handler == P_Object_Handler && i->P_Base_Class == P_Object)
		{
			Connections_Vec.erase(i);
			return;
		}
	}
}

void Base_Class::Emit_Signal(Signal P_Signal, string& Command)
{
	for (auto connect : Connections_Vec)
	{
		if (Connections_Vec.empty())
			return;
		if (connect.P_Signal == P_Signal)
		{
			connect.P_Handler(connect.P_Base_Class, this->Object_Name);
			P_Signal(Command);
		}
	}
}