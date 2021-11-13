#include <stdio.h>

int main() {

	cout << "Lambda test 1 + 2 : " <<  []() -> int {return 1+2;}() << endl; 

}