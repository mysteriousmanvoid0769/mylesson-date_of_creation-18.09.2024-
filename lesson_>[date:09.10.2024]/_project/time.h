#ifndef TIME_H
#define TIME_H

#include <ostream>

namespace chron{
	
	class Time{
		private:
			int hours = int{}; // int hours = 0;
			int minutes = int{}; // int minutes = 0;
			int seconds = int{}; // int seconds = 0;

            inline void normalize(void);
		
		public:
            Time() = default;
			Time(int h, int m, int s);
            
            /* 
            Time(int h, int m, int s) : hours(h), minutes(m), seconds(s){
            }
                [personal comment: + new advancement]_void*[0]
                even particulary refers to function definition of Time(int h, int m, int s) in time.cpp
            */

            Time(int s) : Time(0, 0, s){ //delegating constructor
            }
            
            
            

			int GetHours(void) const;
			int GetMinutes(void) const;
			int GetSeconds(void) const;
            			         

			void AddSeconds(int s);

            int totalSeconds(void) const;

            Time& operator+=(int s);
            
            Time operator+(int s) const;

            //Time operator+(const Time& t, int s);
		
	};
	
}


std::ostream& operator<<(std::ostream& out, const chron::Time& t);



#endif
