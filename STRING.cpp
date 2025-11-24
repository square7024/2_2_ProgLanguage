//-----------------------------------------------------------------------------------------------------------
// STRING - std::string을 흉내낸 클래스
//		  - 멤버함수는 cpp에 코딩한다
// 
// 2025. 11. 5
// 2025. 11. 10 복사생성자
// 2025. 11. 12 관찰하고 싶을때만 관찰메시지 출력
// 2025. 11. 17 출력연산자 오버로딩
//-----------------------------------------------------------------------------------------------------------
#include <iostream>
#include <print>
#include "STRING.h"
using namespace std;

// 2025. 11. 5
unsigned STRING::gid{ 0 };

// 2025. 11. 12
bool 관찰{ false };

// 2025. 11. 5
STRING::STRING()						// 스페셜 함수
	: id { ++gid }
{
	// 관찰메시지
	if ( 관찰 )
		println("[{:5}] 생성자()        - 내주소:{:014}, 글자수:{:3}, 글자주소:{:014}", id, (void*)this, len, (void*)p);
}

STRING::~STRING()						// 스페셜 함수
{
	// 내 자신이 사라지기 전에 정리할 내용이 있으면 깨끗하게 정리한다.
	delete[] p;
	// 이럴 필요가 있을까?
	// p = nullptr;
	// len = 0;

	// 관찰메시지
	if (관찰)
		println("[{:5}] 소멸자          - 내주소:{:014}, 글자수:{:3}, 글자주소:{:014}", id, (void*)this, len, (void*)p);
}

STRING::STRING(const char* str)
	: id { ++gid }
{
	len = (unsigned)strlen(str);
	p = new char[len];
	// 복사는 반드시 이렇게 - DMA(Direct Memory Access)
	memcpy(p, str, len);
	// 관찰메시지
	if (관찰)
		println("[{:5}] 생성자(char*)   - 내주소:{:014}, 글자수:{:3}, 글자주소:{:014}", id, (void*)this, len, (void*)p);
}

// 2025. 11. 10 - 3. 복사생성자
STRING::STRING( const STRING& other )
	: id { ++gid }
{
	len = other.len;
	// 깊은 복사를 해야
	p = new char[len];
	memcpy(p, other.p, len);
	// 관찰메시지
	if (관찰)
		println("[{:5}] 복사생성자      - 내주소:{:014}, 글자수:{:3}, 글자주소:{:014}", 
			id, (void*)this, len, (void*)p);
}

// 2025. 11. 10 - 4. 복사할당연산자
STRING& STRING::operator=(const STRING& other)
{
	// 자신을 자신에게 할당하는 경우엔 아무것도 하지말고 돌아간다
	if (this == &other) {
		return *this;
	}

	delete[] p;

	len = other.len;
	p = new char[len];
	memcpy(p, other.p, len);

	// 관찰메시지
	if (관찰)
		println("[{:5}] 복사할당연산자 - 내주소:{:014}, 글자수:{:3}, 글자주소:{:014}",
			id, (void*)this, len, (void*)p);

	return *this;
}

// 2025. 11. 19 - 5. 이동생성자
STRING::STRING(STRING&& other)
	: id{ ++gid }
{
	len = other.len;
	p = other.p;

	// 원본(other)을 이렇게 해야
	other.len = 0;
	other.p = nullptr;

	// 관찰메시지
	if (관찰)
		println("[{:5}] 이동생성자      - 내주소:{:014}, 글자수:{:3}, 글자주소:{:014}",
			id, (void*)this, len, (void*)p);
}

// 2025. 11. 19 - 6. 이동할당연산자
STRING& STRING::operator=(STRING&& other)
{
	if (&other == this)
		return *this;

	delete[] p;

	len = other.len;
	p = other.p;

	other.len = 0;
	other.p = nullptr;

	// 관찰메시지
	if (관찰)
		println("[{:5}] 이동할당연산자  - 내주소:{:014}, 글자수:{:3}, 글자주소:{:014}",
			id, (void*)this, len, (void*)p);
}

// 2025. 11. 12
STRING STRING::operator+(const STRING& rhs)
{
	STRING temp;							// STRING temp(s1) <--- 개선 ver.
	temp.len = len + rhs.len;				// 더한 스트링의 길이
	temp.p = new char[temp.len];			// 메모리 확보
	memcpy(temp.p, p, len);					// 메모리에 왼쪽 오퍼런드의 내용 복사
	memcpy(temp.p + len, rhs.p, rhs.len);	// 메모리에 오른쪽 오퍼런드의 내용 복사
	return temp;
}

// 2025. 11. 19
char STRING::operator[]( int i ) const
{
	return p[i];
}

// 2025. 11. 19
char& STRING::operator[](int i)
{
	return p[i];
}

// 2035. 11. 24 const 일관성있게 수정
unsigned STRING::length() const
{
	return len;
}

// 2025. 11. 10 const-qualifier 추가
void STRING::show() const
{
	for (int i = 0; i < len; ++i)
		cout << p[i];
	cout << endl;
}

// 2025. 11. 17
// 전역연산자 오버로딩 함수 클래스에서 friend로 선언한다.
STRING operator+(const char* s, const STRING& rhs)
{
	STRING temp;
	unsigned len = strlen(s);
	temp.len = len + rhs.len;				// temp의 길이 = s의 길이 + rhs의 길이
	temp.p = new char[temp.len];			// temp의 길이만큼 메모리 확보
	memcpy(temp.p, s, len);					// 확보한 메모리에 s를 복사
	memcpy(temp.p + len, rhs.p, rhs.len);	// s를 복사한 이후에 rhs를 복사
	return temp;
}

// 2025. 11. 17
// 전역연산자 오버로딩 함수 클래스에서 friend로 선언한다.
ostream& operator<<(ostream& os, const STRING& rhs)
{
	for (int i = 0; i < rhs.len; ++i)
		os << rhs.p[i];
	return os;
}
