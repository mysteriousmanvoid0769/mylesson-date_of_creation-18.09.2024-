#include <iostream>
#include <array>
#include <deque>
#include <list>
#include <iterator>
#include <forward_list>
#include <vector>
#include <map>
#include <string>

using std::cout;

int main(void){
    
    
    {
		std::array<int, 3> point{1, 2, 3};
	}
	
	
	{
		std::deque<int> d {1, 2, 3, 4};
    
		d.push_back(5);
		d.push_back(6);
		d.pop_back();
		d.push_front(0);
		d.push_front(-1);
		d.pop_front();
		
		for(size_t i = 0; i != d.size(); ++i){
			cout<<d[i]<<"\n";
		}
		
		for(int x: d){
			cout<<x<<"\n";
		}
		/*
			for(int& x: d){
				cout<<x<<"\n";
			}
			Здесь мы не используем вариант передачи по ссылке потому что для встроенных типов данных этьо более ресурсо затратно
		 */
		cout<<"----------------------------------\n";
	}
	
	
	{
		std::list<int> l{10, 15, 20};
		
		l.push_back(5);
		l.push_front(0);
		l.push_back(25);
		l.push_back(30);
		l.pop_back();
		l.pop_front();
		
		
		for(int x: l){
			cout<<x<<"\n";
		}
		
		cout<<"----------------------------------\n";
	}
	
	
	{
		std::list<int> l{10, 15, 20};
		
		auto iter = l.begin(); // здесь auto это std::_List_iterator<int> :>[BY_MYSELF]
		
		cout<<*iter<<"\n";
		
		++iter;
		
		cout<<*iter<<"\n";
		
		--iter;
		
		cout<<*iter<<"\n";
		
		cout<<"----------------------------------\n";
		
		/* BY_MYSELF
		 *  decltype(iter) x = 4;
		  decltype(iter) y = reinterpret_cast<int*>(4);
		  это для проверки(compilation error) что бы добавить комментарий к строке 63
		  */
	}
	
	
	{
		std::list<int> l{10, 20, 30};
		
		for(auto iter = l.begin(); iter != l.end(); ++iter){
			cout<<*iter<<"\n";
		}
		
		for(auto iter = l.rbegin(); iter != l.rend(); ++iter)
			cout<<*iter<<"\n";
		
		
		cout<<"----------------------------------\n";
	}
	
	
	{
		std::list<int> l{0, 10, 15, 20};
		
		{
			auto iter = l.begin();
		
			++iter;
		
			l.insert(iter, 5); // l = {0, 5, 10, 15, 20}
		}
		
		for(auto iter = l.begin(); iter != l.end(); ++iter)
			if(*iter % 2 == 0)
				iter = l.erase(iter);
			/*else
				++iter;*/
		
		for(auto iter = l.begin(); iter != l.end(); ++iter){
			cout<<*iter<<"\n";
		}
		
		cout<<"----------------------------------\n";
	}
	

	{
		// next и advance из заголовочного файла iterator
		std::list<int> l{0, 10, 15, 20};
		
		auto iter = std::next(l.begin());
		
		std::advance(iter, 2); //здесь сам iter меняется из-за этого написали строку 135 а не  auto iter2 = std::advance(iter, 2); 
		
		auto iter2 = iter;
		
	}

	
	
	{
		std::forward_list<int> fl {3, 42, 5};
		
		fl.push_front(2);
		
		//fl.push_back(3); ошибка
		
		auto iter = std::next(fl.begin());
		
		iter = fl.erase_after(iter);
		
		fl.insert_after(iter, 4);
		
		for(int x: fl){
			cout<<x<<"\n";
		}		
		
		cout<<"----------------------------------\n";
	}
	
	
	{
		std::vector<int> v{1, 2, 3, 4};
		
		auto iter = v.begin();
		
		int* ptr = &v.front();
		
		int& ref = v.front();
		
		
		cout<<*iter<<" "<<*ptr<<" "<<ref<<"\n";
		
		v.push_back(5);
		
		cout<<*iter<<" "<<*ptr<<" "<<ref<<"\n";
		
		cout<<"----------------------------------\n";
		
		/*  Инвалидация
		 *  
		 *  vector:
		 * 		- iter
		 *      - ptr
		 *  	- ref
		 * 
		 * 	deque:
		 * 		- iter
		 *  	+ ptr
		 * 		+ ref
		 *  
		 *  list, forward_list:
		 * 		+ iter
		 * 		+ ptr
		 * 		+ ref
		 */
		
	}
	
	
	{
		std::map<std::string, int> years {
							{"Moscow", 1147},
							{"Rome", -753},
							{"London", 47}
			
						};
		
		
		for(const auto&[city, year]: years){
			
			cout<<city<<":"<<year<<"\n";
			
		}
			
		cout<<"----------------------------------\n";
			
		/*
		 * Поиск, вставка и удалении в КЧД O(log(n))
		 * 
		 * 
		 */
	}
	
	/*
	{
		std::map<std::string, int> data;
		std::string key;
		int value;
		
		
		while(std::cin >> key >> value){
			data[key] = value;
		}
		
		data.erase("hello");
		
		if(auto iter = data.find("test"); iter != data.end()){
			cout<<"Found the key "<<iter->first<<" with the value "<<iter->second<<"\n";
		}
		else{
			cout<<"not found\n";
		}
		
		
		
		
		cout<<"----------------------------------\n";
	}
	*/
	
	{
		std::map<std::string, int>  freqs;
		
		std::string word;
		
		while(std::cin >> word){
			++freqs[word];
		}
		
		for(const auto& [word, freq]: freqs){
			
			cout<<word<<"\t"<<freq<<"\n";
		}
		
		
		cout<<"----------------------------------\n";
	}
	
    return 0;

}
