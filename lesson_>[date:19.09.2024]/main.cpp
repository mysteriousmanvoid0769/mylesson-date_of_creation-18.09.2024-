// Урок 19.09.2024


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout, std::cin;

inline void part1(void);
inline void part2(void);
inline void part3(void);
inline void part4(void);
inline void part5(void);
inline void part6(void);
inline void part6and7(void);
inline void part8(void);
inline void part9(void);
inline void part10(void);
inline void part11(void);
void swap(int& a, int& b);
inline void part12(void);
std::string Concatenate(const std::vector<std::string>& parts);
inline void part13(void);
struct Date;
inline void part14(void);
bool operator<(const Date& lhs, const Date& rhs);

int main(void){
    
    
    /*
	void* ptr = reinterpret_cast<void*>(0x7F671);
	
	cout<<ptr<<"\n";
	cout<<ptr+1<<"\n";
	*/
	

	
	
}


inline void part1(void){
	
	
	const int c1 = 42;
	
	
	int x;
	cin>>x;
	
	const int c2 = 2 * x;
	
	
	
}


inline void part2(void) {
	
	const std::vector<int> v = {1, 3, 5};
	
	cout<<v.size()<<"\n";
	
	// v.clear(); ошибка компиляции
	// v[0] = 0; ошибка компиляции
	
}

inline void part3(void){
	
	int x = 42;
	
	int& refx = x;
	
	const int& crefx = x;
	
	++x;
	++refx;
	// ++crefx
	
}

inline void part4(void){
	
	int x = 42;
	
	int* ptr = &x;
	
	const int* cptr = &x;
	
	++(*ptr);
	
	//++*ptr; ошибка
	
	int y = 20;
	
	cptr = &y;
	
}

inline void part5(void){
	
	const int cx = 42;
	
	// int& ref = cx; ошибка
	
	const int& crefx  = cx;
	
	// int* ptr = &cx; ошибка
	
	const int* cptr = &cx;
	
}

inline void part6(void){
	
	
	
}

inline void part6and7(void){
	int x = 42;
	
	const int cx = 13;
	
	int* ptr = &x;
	// ptr = &cx; //ошибка
	
	const int* cptr = &x;
	
	cptr = &cx;
	
	int* const ptrc = &x;
	
	// ptrc = nullptr; ошибка
	
	++*ptrc;

	const int* const cptrc = &x;
	
}

inline void part8(void){
	
	const size_t m = 1000000;
	
	const size_t n = 10000;
	
	std::vector<std::string> v(m);
	
	for(size_t i = 0; i != m; ++i){
		v[i].resize(n, '@');
	}
	
	size_t sum = 0;
	
	/*
	for( auto row: v){
		sum += row.size();
	}
	*/
	
	for(const auto& row: v){
		sum += row.size();
	}
		
	cout<<sum<<"\n";
}

inline void part9(void){
	
	int* ptr = nullptr;
	
	{
		int x = 42;
		
		ptr = &x;
	}
	
	cout<<*ptr<<"\n";
	//Скомпилируется, но так делать не надо
}	

inline void part10(void){
	
	std::vector<std::string> words = {"one", "two", "three"};
	
	std::string& ref = words[0];
	
	words.clear();
	
	cout<<ref<<"\n";
	//undefined
	
}

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

inline void part12(void){
	
	std::string line;
	std::getline(cin, line);
	
}

std::string Concatenate(const std::vector<std::string>& parts){
	
		
		std::string result;
		
		for(const auto& part: parts){
			result += part;
		}
		
		return result;
}

inline void part13(void){
	
	std::vector<std::string> parts = { "ab", "ra", "ca", "da", "bra"};
	
	cout<<Concatenate(parts)<<"\n"; // -так называемая временная переменная. move constructor(конструктор перемещения)
	
	/* -пример:
	 * 	int x{5} - конструктор 
	 * 	int y{x} - конструктор копирования
	 * 
	 * 
	 *  std::string str{Concatenate(parts)};
	 */
	 
}

struct Date{
	int year = 1970;
	int month = 1;
	int day = 1;
};

inline void part14(void){
	
	std::vector<Date> dates = { {2020, 3, 15}, {2019, 1, 21}, {2021, 1, 30} };
	
	
	for(const auto&[year, month, day]: dates){
		
		cout<<year<<"."<<month<<"."<<day<<"\n";
		
	}
	
	
}


	
	bool operator<(const Date& lhs, const Date& rhs){
			
			if(lhs.year != rhs.year){
				return lhs.year < rhs.year;	
			}
			
			if(lhs.month != rhs.month){
				return lhs.month<rhs.month;
			}
			return lhs.day < rhs.day;
			
			
	}
	


bool compare(const Date& lhs, const Date& rhs){
		
	return std::tie(lhs.year, lhs.month, lhs.day) < std::tie(rhs.year, rhs.month, rhs.day) ;
}

inline void _function_forLambdaFunctioon(void){
	
	std::sort(dates.begin(), dates.end(), [](const Date& lhs, const Date& rhs){
			
			return std::tie(lhs.year, lhs.month, lhs.day) < std::tie(rhs.year, rhs.month, rhs.day);
	}
	
	
}
