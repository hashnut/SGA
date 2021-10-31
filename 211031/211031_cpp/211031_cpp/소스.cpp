#include <iostream>
#include <functional>
// functional : 전역함수, 멤버 함수, 람다를 보관할 수 있는 객체인 functional object를 만들어 준다.


using namespace std;

class A
{
private:
	int Hp;

public:

};



int main()
{

	// []() -> void {cout << "Hell World" << endl; }();
	// 
	// [] : 변수 캡쳐
	//
	// - [] : 아무 변수도 사용하지 않음
	// - [&] : 람다문 외부의 모든 변수를 참조 형식으로
	// - [=] : 람다문 외부의 모든 변수를 값 복사 형식으로 람다문에서 사용. 이때 캡쳐된 모든 변수는 람다문 내부에서 상수처럼 사용된다.
	// - [x, y] : 람다문 외부의 변수중 x, y만 값 복사 형태로 사용
	// - [&x, &y] : 람다문 외부의 변수중 x, y만 참조 형태로 사용
	// - [&, x, y] : 람다문 외부의 모든 변수를 참조 형식으로 사용하지만, x와 y는 값 복사 형식으로 사용
	// - [=, &x, &y] : 람다문 외부의 모든 변수를 값 복사 형식으로 사용하지만, x와 y는 참조 형태로 사용
	// - [this] : 모든 멤버들을 람다문 내부에서 사용하도록 한다.
	//
	//
	// () : 매개 변수 선언 부분
	// {} : 함수 동작 부분
	// () : 함수 호출 시 인자

	// - function의 선언 방법 : function<ReturnType(ParamType)> 식별자;
	function<void(int, int)> plus = 
		[](int a, int b) -> void {cout << "덧셈 결과 : " << (a + b) << endl; };
	plus(10, 20);



	return 0;
}