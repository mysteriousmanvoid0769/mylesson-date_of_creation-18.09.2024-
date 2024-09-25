#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin;


template<typename T>
T Max(const T& x, const T& y){
	if(x > y)
		return x;
	else
		return y;
}

template <typename T>
const std::vector<T>& Max(const std::vector<T>& v1, const std::vector<T>& v2){
	
	if(v1.size() > v2.size()){
		return v1;
	}
	else if(v1.size() < v2.size()){
		return v2;
	}
	else if(v1 > v2){
		return v1;
	}
	else{
		return v2;
	}
	
}


template<typename T1, typename T2, typename T3>
struct Triple{
	T1 first;
	T2 second;
	T3 third;
	
};



int main(void){
	
	{
		cout<<Max(1, 2)<<"\n";
		cout<<Max(3.1428, 2.718)<<"\n";
	
		std::string word1 {"hello"}; std::string word2 {"world"};
	
		cout<<Max(word1, word2)<<"\n";
	
		cout<<Max<double>(3.14, 2.72)<<"\n";
		cout<<Max<double>(3.14, 2)<<"\n";
	}
	cout<<"----------------------------------------------------------------------------------------------"<<"\n";
	{
	
		cout<<Max(1, 2)<<"\n";
	
		std::vector<int> v1 = {1, 2, 3};
		std::vector<int> v2 = {4, 5, 6};
	
		for(const int& x: Max(v1, v2)){
			cout<<x<<"  ";
		
		}
		cout<<"\n";
	}
	cout<<"----------------------------------------------------------------------------------------------"<<"\n";
	{
		Triple<int, int, int> point{-1, 3, 2};
		Triple<std::string, std::string, int> wordPairsfreq {"hello", "world", 42};
		
	}
	
	
	
	
	
	
	
	
	return 0;
}
