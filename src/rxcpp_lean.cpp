// Copyright (c) Microsoft Open Technologies, Inc. All rights reserved. See License.txt in the project root for license information.

// testbench.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <memory>

#include "cpprx\rx.hpp"

#include "example.h"
#include "lambda_learn.h"

using namespace std;

int main(int argc, char* argv[]) {
	shared_ptr<IExample> example;

	// Lambda Example
	example = make_shared<lambda_learn>();
	example->Run();

	system("pause");
}