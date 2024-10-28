#include <iostream>
#include<stdexcept>
using namespace std;

int main() {
	// try block
	try {
		int numerator = 10;
		int denominator = 0;
		int res;

		// check if denominator is 0 then throw runtime error. Here runtime_error is a specialised class under the stdexcept header file
		if (denominator == 0) {
			throw runtime_error("Division by zero not allowed!"); // Here we have used the runtime_error class to determine this exception! kyunki technically this is the correct type of exception for dividing by zero! jiss type ka error hai uss type ka class hi handle krega!
            // jaise iss case me dividing by zero ek runtime error ki category me aata hai toh hum isme yhi class use krenge! koi aur class use krenge toh compile error dikhayega! kyunki it's not just about ki hum kya print kr rhe hai! kyunki "stdexcept" me jo code likha hua hai runtime_error ya kisi bhi aur class ka vo iss hisaab se hi likha hai ki ek particular tarah ke errors ko hi handle krne ke liye banaa hua hai! isliye using some other kind of exception class will cause compile error!
		}

		// calculate result if no exception occurs
		res = numerator / denominator;
		// printing result after division
		cout << "Result after division: " << res << endl;
	}
	// catch block to catch the thrown exception
	catch (const runtime_error& e) {
		// print the exception
		cout << "Exception " << e.what() << endl; // Here you should be using what() as becoz now as you are using the class runtime_error! so to catch exception messages you need to use .what() keyword!
	}
	return 0;
}