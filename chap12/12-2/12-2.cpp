#include "string2.h"
#include <iostream>

int main()
{
	String s1(" and I am a C++ student.");
	std::cout << s1;
	String s2 = "Please enter your name: ";
	String s3;
	std::cout << s2 << std::endl;// << "\n" << s1 << "\n";
	std::cin >> s3;
	s2 = "My name is " + s3;
	std::cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.StringUp();
	std::cout << R"(The string \)" << s2 << R"(\ contains )" << s2.CountChar('A') << R"('A' characters in it.)" << std::endl;
	s1 = "red";
	String rgb[3] = { String(s1), String("green"), String("blue") };
	std::cout << "Enter the name of a primer color for mixing light: ";
	String ans;
	bool success = false;
	while (std::cin >> ans)
	{
		ans.StringLow();
		for(int i=0;i<3;i++)
			if (ans == rgb[i])
			{
				std::cout << "That's right!\n";
				success = true;
				break;
			}
		if (success)break;
		else std::cout << "Try again!\n";
	}
	std::cout << "Bye!\n";
	return 0; 
}