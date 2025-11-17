//-----------------------------------------------------------------------------------------------------------
// 2025 2학기 C++ 월56수78					11. 17 월요일                                             (11주 1일)
// 12/15 - (15주 1일) 기말시험 - 다형성(코드는 수업에 사용한 그대로)
//-----------------------------------------------------------------------------------------------------------
// operator overloading - 연산자 오버로딩
//----------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "save.h"
#include "STRING.h"
using namespace std;

extern bool 관찰;			// 관찰하고 싶으면 true로 바꾸자

// [문제] main()이 문제없이 실행되도록 class INT 를 코딩하라.

class INT {
public:
	INT() = default;
	INT( int n ) : num{ n } {}

	INT(const INT&) = default;				// 자동으로 만들어진다
	INT& operator=(const INT&) = default;	// 자동으로 만들어진다

	// pre-increment
	INT& operator++() {
		++num;
		return *this;
	}

	// post-increment
	operator++() {
		// 다음시간에 계속...
		// 옛 값을 리턴한다
		// 그리고 나서 1 증가한다.
	}

private:
	int num;

	friend ostream& operator<<(ostream& os, const INT& rhs) {
		os << rhs.num;
		return os;
	}
};

//--------
int main()
//--------
{
	INT a = 1;
	INT b = a++;

	cout << b << endl;

	//save("main.cpp");
}
