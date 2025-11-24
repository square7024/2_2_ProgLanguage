//-----------------------------------------------------------------------------------------------------------
// 2025 2학기 C++ 월56수78					11. 24 월요일                                             (12주 1일)
// 12/15 - (15주 1일) 기말시험 - 다형성(코드는 수업에 사용한 그대로)
//-----------------------------------------------------------------------------------------------------------
// class FILE I/O
// class간의 관계 - 상속(Inheritance)
//----------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;			// 관찰하고 싶으면 true로 바꾸자

// [문제] 다운받은 파일 "개들.txt" 에는 1000개의 Dog 객체가 있다.
// class Dog의 멤버는 다음과 같다.
//
// class Dog {
// private:
//		int				id;
//		std::string		name;
// };
//
// 파일에 있는 Dog 객체를 메모리에 저장하라.
// id 기준 오름차순으로 정렬하라.
// 화면에 id와 name을 출력하라.

class Dog {
private:
	int id;
	string name;
};

//--------
int main()
//--------
{
	ifstream in{ "개들.txt" };
	if (not in)
		return 20251124;

	Dog dog;

	int cnt{};
	while (in >> dog) {
		cout << dog;
		++cnt;
	}
	cout << "모두" << cnt << "개의 Dog를 읽었다" << endl;

	//(*save)("main.cpp");
}
