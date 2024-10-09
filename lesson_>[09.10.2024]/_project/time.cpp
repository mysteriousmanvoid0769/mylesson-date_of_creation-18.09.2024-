#include "time.h"


inline void chron::Time::normalize(void){
    this->minutes += this->seconds / 60;
	
	this->seconds %= 60;
	
	if(this->seconds < 0){
		
		this->minutes -= 1;
		this->seconds += 60;
	}
	
	this->hours += this->minutes/60;
	this->minutes %= 60;
	
	if(this->minutes < 0){
		this->hours -= 1;
		this->minutes += 60;
	}
	
	this->hours %= 24;
	
	if(this->hours < 0){
		this->hours += 24;
	}

}
/*
chron::Time::Time(int h, int m, int s){
	
    this->hours = h;
	this->minutes = m;
	this->seconds = s;

	normalize();
	
}
*/


chron::Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s){
    normalize();
}



int chron::Time::GetHours(void) const{
	return this->hours;
}

int chron::Time::GetMinutes(void) const{
	return this->minutes;
}

int chron::Time::GetSeconds(void) const{
	return this->seconds;
}

void chron::Time::AddSeconds(int s){
    
    chron::Time::normalize();

    this->seconds += s;
}

int chron::Time::totalSeconds(void) const{
    
    return 3600*(this->hours) + 60*(this->minutes) + (this->seconds);
}

chron::Time& chron::Time::operator+=(int s){
    seconds += s;
    normalize();
    return *this;
}

chron::Time chron::Time::operator+(int s) const{
    return chron::Time(this->hours, this->minutes, this->seconds + s);
}

/*
chron::Time chron::Time::operator+(const Time& t, int s){
    
    return Time(t.GetHours(), t.GetMinutes(), t.GetSeconds() + s);
}
*/


std::ostream& operator<<(std::ostream& out, const chron::Time& t){
    
        out << t.GetHours() << ":" << t.GetMinutes() << ":" << t.GetSeconds();

        return out;

}



