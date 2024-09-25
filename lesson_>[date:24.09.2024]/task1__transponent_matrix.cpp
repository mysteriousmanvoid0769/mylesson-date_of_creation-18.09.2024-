#include <iostream>
#include <vector>


using std::cout;

std::vector<std::vector<int>> transponent(const std::vector<std::vector<int>>&);

inline void cout_matrix(const std::vector<std::vector<int>>&);

int main(void)
{
	std::vector<std::vector<int>> matrix{{1, 2}, {3, 4}, {5, 6}};
	
	cout_matrix(matrix);
	
	cout_matrix(transponent(matrix));
	
	
	return 0;
}


std::vector<std::vector<int>> transponent(const std::vector< std::vector<int>>& matrix){
	
	std::vector<std::vector<int>> tmatrix(matrix[0].size(), std::vector<int>(matrix.size()));
    
    
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            tmatrix[j][i] = matrix[i][j];
        }
    }
	
	
	return tmatrix;
	
}

inline void cout_matrix(const std::vector<std::vector<int>>& matrix){
	
	for(unsigned int i = 0; i < matrix.size(); i++){
		for(unsigned int j = 0; j < matrix[0].size(); j++){
			
			cout<<matrix[i][j]<<" ";
			
		}
		cout<<"\n";
	}
	cout<<"------------------------------------"<<"\n";
	
}
