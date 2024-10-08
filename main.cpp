#include <iostream>

#include "time.h"

inline void get_info(const chron::Time& time, const bool is_show_in_console){
	
	time.GetHours();
	time.GetMinutes();
	time.GetSeconds();
	
	if(is_show_in_console){
		std::cout << time.GetHours() << "\n";
		std::cout << time.GetMinutes() << "\n";
		std::cout << time.GetSeconds() << "\n";
	}
	
}



bool isAfternoonTime(const chron::Time& time){
	
	return time.GetHours() >= 12;
}

int main(void){
	
	chron::Time t(13, 30, 0);
	
	std::cout << t.GetHours() << "\n";
	

	get_info(t, true);
	
	

	
	return 0;
}
