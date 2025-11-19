//-----------------------------------------------------------------------------------------------------------
// 2025 2학기 C++ 월56수78					11. 17 수요일                                             (11주 2일)
// 12/15 - (15주 1일) 기말시험 - 다형성(코드는 수업에 사용한 그대로)
//-----------------------------------------------------------------------------------------------------------
// Modern C++(C++11) - move sematics
//----------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <algorithm>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;			// 관찰하고 싶으면 true로 바꾸자

int 오름(const void* a, const void* b)
{
	return ((STRING*)a)->length() - ((STRING*)b)->length();
}

//--------
int main()
//--------
{
	STRING s[] { "333", "1", "55555", "4444", "22" };
	관찰 = true;
	
	std::sort(begin(s), end(s), []( STRING& a, STRING& b) {
		return a.length() - b.length();
		});

	관찰 = false;

	for (const STRING& str : s)
		cout << str << endl;

	//save("main.cpp");
}
