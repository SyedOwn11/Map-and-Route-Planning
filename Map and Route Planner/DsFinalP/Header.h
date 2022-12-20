#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h>

std::string makestring(System::String^ abc) {
	using namespace System::Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(abc)).ToPointer();
	std:: string os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));

	return os;
}
/*int makeInt(System::Decimal^ abc) {
	return msclr::interop::marshal_as<int>(abc);
}*/
