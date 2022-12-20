#pragma once
#include<iostream>
#include<sstream>
#include<vector>

std::vector<std::string> explode(std::string i, char delimeter);

using System::Runtime::InteropServices::Marshal;

static std::string toStandardString(System::String^ string)
{
	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);
	return returnString;
}
