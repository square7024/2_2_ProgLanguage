//-----------------------------------------------------------------------------------------------------------
// STRING - std::string을 흉내낸 클래스
//		  - 헤더에는 클래스의 선언만 코딩한다
// 
// 2025. 11. 5 시작
// - 클래스에는 6개의 special 함수가 있다
// 1. STRING()							 - default constructor
// 2. ~STRING()							 - destructor
//
// 3. STRING( const STRING& )			 - copy constructor
// 4. STRING& operator=( const STRING& ) - copy assignment operator
//
// 5. STRING( STRING&& )				 - move constructor
// 6. STRING& operator=( STRING&& )		 - move assignment operator
//-----------------------------------------------------------------------------------------------------------
#pragma once

class STRING {
public:
	// 2025. 11. 5
	STRING();							// 1. 스페셜 함수
	~STRING();							// 2. 스페셜 함수

	STRING(const char* str);			// 스페셜 함수가 아니다.

	// 2025. 11. 10
	STRING(const STRING& OTHER);		// 3. 복사생성자(스페셜 함수)
	STRING& operator=(const STRING&);	// 4. 복사할당연산자

	// 2025. 11. 19
	STRING(STRING&&);					// 5. 이동생성자
	STRING& operator=(STRING&&);		// 6. 이동할당연산자


	// 연산자 오버로딩 함수는 여기에
	// 2025. 11. 12
	STRING operator+(const STRING& rhs);
	// 2025. 11. 19
	char operator[](int) const;
	char& operator[](int);

	// 인터페이스 함수 - 클래스의 정보를 바깥 세상에 전달
	unsigned length();
	void show() const;				// 2025. 11. 10 const 일관성

private:
	unsigned len{};
	char* p{};

	// 2025. 11. 5
	unsigned id;					// 만들때 붙인 고유번호
	static unsigned gid;			// 고유번호

	// 2025. 11. 17
	// 전역연산자 오버로딩 함수 클래스에서 friend로 선언한다.
	friend STRING operator+(const char*, const STRING&);
	friend std::ostream& operator<<(std::ostream&, const STRING&);
};
