// Intermediate, Pidgeon hole's dilemma.cpp : 
//outputs all possibilities to put + or - or nothing between the numbers 1,2,…,9
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

std::vector <std::string> PidgeonPerm(int);
std::vector <int> MergePidgeon(int, std::vector<std::string>);


int main()
{
	auto perm = PidgeonPerm(5);
	auto temp = MergePidgeon(5, perm);
	for (auto str : temp) {
		std::cout << str;
	}

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

std::vector <int> MergePidgeon(int c) {

	std::vector <int> a;
	std::vector <int> Output;
	auto b = PidgeonPerm(c);

	for (int i = 1; i = c; i++) {
		a.push_back(i);
	}

	if (c == 0) {
		return {};
	}

	if (c == 2) {
		for (int i = 0; i <= b.size()-1; i++) {

			if (b[i].end = "+") {
				Output = (a.end + a.begin);
				return Output;
			}
			else if (b[i].end = "-")
			{
				Output = a.begin - a.end;
				return Output;
			}
			else
			{
				Output = (a.begin * 10) + a.end;
				return Output;
			}
		}
	}
	else if (c > 2) {
		Output = MergePidgeon(c - 1, b);
		return Output;
	}
}