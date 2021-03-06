// Intermediate, Pidgeon hole's dilemma.cpp : 
//outputs all possibilities to put + or - or nothing between the numbers 1,2,…,9
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

std::vector <std::string> PidgeonPerm(int);
int MergePidgeon(std::string, int);
//std::vector <int> MergePidgeon(int);


int main()
{
	auto perms = PidgeonPerm(8);

	for (auto perm : perms)
	{

		//if (perm.size() != 8)
		if (MergePidgeon(perm, 1) == 100)
			std::cout << perm << "\n";
	}


	/*auto temp = MergePidgeon(5);

	for (auto str : temp) {
		std::cout << str<<"\t";
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

int MergePidgeon(std::string perm, int ordinal) {
	if (perm.size() == 0)
		return ordinal;

	auto val = MergePidgeon(perm.substr(1, perm.size() - 1), ordinal + 1);

	if (perm[0] == '+')
		return ordinal + val;
	else if (perm[0] == '-')
		return ordinal - val;
	else
		return (val > 0 ? 1 : -1)*((ordinal * std::pow(10, std::ceil(std::log10(std::abs(val))))) + val);
}


//std::vector<int> MergePidgeon(int c) {
//
//	std::vector <int> a;
//	std::vector <int> Output;
//	auto b = PidgeonPerm(c - 1);
//
//	for (int i = 1; i = c; i++) {
//		a.push_back(i);
//	}
//
//	if (c == 2) {
//
//		if (b.end == "+") {
//			Output = (a.end + a.begin);
//			return Output;
//		}
//		else if (b.end == "-")
//		{
//			Output = a.begin - a.end;
//			return Output;
//		}
//		else
//		{
//			Output = (a.begin * 10) + a.end;
//			return Output;
//		}
//	}
//
//	else if (c > 2) {
//		Output = MergePidgeon(c - 1);
//		return Output;
//	}
//}