#include <iostream>

using namespace std;

float _my_cube(float x){
	return x*x*x;
}


main(){
	float x;
	cin >> x;
	cout << _my_cube(x);

}
