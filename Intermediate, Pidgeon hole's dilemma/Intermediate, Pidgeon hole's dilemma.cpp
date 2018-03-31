// Intermediate, Pidgeon hole's dilemma.cpp : 
//outputs all possibilities to put + or - or nothing between the numbers 1,2,…,9
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

std::vector <std::string> PidgeonPerm(int);
//std::vector <std::string> MergePidgeon(std::string, std::string);


int main()
{
	std::vector <std::string> L = { "1","2","3","4","5" };
	auto Length = L.size() - 1;
	auto perm = PidgeonPerm(Length);
	
	for (int i = 0; i <= perm.size(); i++) {
		std::vector <std::string> Result;
		auto h = perm[i];
		for (int j = 0; j <= Length; j++) {
			Result.push_back(L[j]+ h[j]);
			std::cout << Result[j];
		}
		
	}
	
	/*for (auto str : perm)
	{
		std::cout << ">" << str << "<" << "\t";
	}*/

    return 0;
}

std::vector <std::string> PidgeonPerm(int Length) {

	if (Length == 0) {
		return { "" };
	}
	else if (Length > 0)
	{
		std::vector <std::string> Output;
		auto Input = PidgeonPerm(Length - 1);

		for (auto str : Input)
		{
			Output.push_back(str + "+");
			Output.push_back(str + "-");
			Output.push_back(str + " ");
		}

		return Output;
	}
}
//std::vector <std::string> MergePidgeon(std::string L, std::string K) {}