#include <iostream>
#include <cmath>
#include <deque>
#include "stack.h"

int tests_run = 0;
int tests_correct = 0;

void checkBool( const std::string &s, const bool&  given, const bool& correct )
{
   tests_run++;	
   if( given != correct )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

void checkSizet( const std::string &s, const size_t&  given, const size_t& correct )
{
   tests_run++;	
   if( given != correct )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

void checkDouble( const std::string &s, const double&  given, const double& correct )
{
   tests_run++;	
   if( abs(given - correct) > 0.1 )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}

void checkString( const std::string s, const std::string&  given, const std::string& correct )
{
   tests_run++;	
   if( given != correct )
   {
      std::cout << "~INCORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
   } else {
      std::cout << "~CORRECT " << s << " : " << given <<
                   " SHOULD HAVE BEEN " << correct << "\n";
      tests_correct++;
   }
}


int main(){
	std::string message = "DEFAULT CONSTRUCTOR";
	stack defst;
	std::deque<int> defdq;
	checkSizet(message, defst.size(), defdq.size());
	checkBool(message, defst.empty(), 1);	

	message = "INIT_LIST CONSTRUCTOR";
	stack initst = {1,3,5,7,9,11,13};
	std::deque<int> initdq {1,3,5,7,9,11,13};	
	checkSizet(message, initst.size(), initdq.size());
	checkBool(message, initst.empty(), 0);
	checkSizet(message, initst.peek(), initdq.back());

	message = "COPY CONSTRUCTOR";	
	stack copyst {initst};
	std::deque<int> copydq {initdq};
	checkSizet(message, copyst.size(), copydq.size());
	checkBool(message, copyst.empty(), 0);	

	message = "PUSH and POP";

	for(size_t i = 1; i < 20000; i *= 2){
		defst.push(i);
		defdq.push_back(i);
	}	

	while(!defdq.empty()){
		checkSizet(message, defst.peek(), defdq.back());
		checkSizet(message, defst.size(), defdq.size());
		defst.pop();
		defdq.pop_back();
	}

	message = "ASSIGNMENT OPERATOR";

	defst = initst;
	defdq = initdq;


	for(int i = 1; i > -23; i -= 2){
        
		defst.push(i);
		defdq.push_back(i);
	}	

	copyst = copyst;
	copyst = defst;
	copydq = defdq;

	while(!defdq.empty()){
		checkSizet(message, defst.peek(), defdq.back());
		checkSizet(message, defst.size(), defdq.size());
		defst.pop();
		defdq.pop_back();
	}

	message = "SELF ASSIGNMENT";
	for(size_t i = 0; i < 3; i++){
		copyst.pop();
		copydq.pop_back();
	}	
	
	checkSizet(message, copyst.peek(), copydq.back());
	checkSizet(message, copyst.size(), copydq.size());
	
	message = "CLEAR";
	copyst.clear();
	copydq.clear();
	
	checkSizet(message, copyst.size(), copydq.size());

	copyst.push(42);
	copydq.push_back(42);

	message = "WHAT'S MEANING OF LIFE?";

	checkSizet(message, copyst.peek(), copydq.back());

	std::cout << "\nTESTS RUN: " << tests_run << std::endl;
	std::cout << "\nTESTS CORRECT: " << tests_correct << std::endl;		
	return 0;
}
