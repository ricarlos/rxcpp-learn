#pragma once

#include <iostream>
#include <string>
#include <functional>

#include "example.h"

using namespace std;

class lambda_learn : public IExample
{
public:
	lambda_learn();
	~lambda_learn();

	void Run();

private:
	typedef class hello {
	public:
		void operator()(double x) {
			cout << x << endl;
		}
	}hello;
	void callhello(string s, hello func);
	void callhello(string s, const function<void(double x)> &func);
	void callhello(string s, double d);
	function<void(double x)> returnLambda(string s);
	function<void(double x)> returnLambda2(string &s);
};

