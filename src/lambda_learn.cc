#include "lambda_learn.h"


lambda_learn::lambda_learn() {
}


lambda_learn::~lambda_learn() {
}

void lambda_learn::Run() {
	hello h;
	callhello("hello:", h);
	callhello("hello lambda:", -3.14);

	int temp = 6;
	callhello("hello lambda2:", [&](double x) -> void{
		cout << x << endl;
		cout << temp++ << endl;
	});
	cout << temp << endl;

	function<void(double x)> f = returnLambda("lambda string");
	f(3.3);

	string lambdastring2 = "lambda string2";
	f = returnLambda2(lambdastring2);
	f(6.6);
}

void lambda_learn::callhello(string s, hello func) {
	cout << s;
	func(3.14);
}

void lambda_learn::callhello(string s, const function <void(double x)> &func) {
	cout << s;
	func(3.14);
}

void lambda_learn::callhello(string s, double d) {
	[=](double x) {
		cout << s << x << endl;
	}(d);
}

function<void(double x)> lambda_learn::returnLambda(string s) {
	cout << s << endl;
	function<void(double x)> f = ([=/*值传递 字符串s函数返回后会被销毁 */](double x){
		cout << s << x << endl;
	});
	s = "changed"; //这里对返回的lambda表达式无效
	return f;
}

function<void(double x)> lambda_learn::returnLambda2(string &s) {
	cout << s << endl;
	function<void(double x)> f = ([&/*引用传递*/](double x){
		cout << s << x << endl;
	});
	s = "changed"; //这里对返回的lambda表达式有效
	return f;
}
