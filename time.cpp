#include "time.h"

chron::Time::Time(int h, int m, int s){
	
	m += s / 60;
	
	s %= 60;
	
	if(s < 0){
		
		m -= 1;
		s += 60;
	}
	
	h += m/60;
	m %= 60;
	
	if(m < 0){
		h -= 1;
		m += 60;
	}
	
	h %= 24;
	
	if(h < 0){
		h += 24;
	}
	
	hours = h;
	minutes = m;
	seconds = s;
}

int chron::Time::GetHours() const{
	return this->hours;
}

int chron::Time::GetMinutes() const{
	return this->minutes;
}

int chron::Time::GetSeconds() const{
	return this->seconds;
}






