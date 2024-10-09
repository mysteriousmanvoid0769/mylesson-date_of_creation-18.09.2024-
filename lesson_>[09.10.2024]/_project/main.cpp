#include <iostream>

#include "time.h"

int foo(int a, int b);
int foo(int a);


int main(void){
	
	chron::Time t1(13, 30, 0);

    chron::Time t2;

    chron::Time t3(5);
	

    
    std::cout<<t1<<"\n";
	
	std::cout<<t2<<"\n";

    std::cout<<t3<<"\n";

	
	return 0;
}
