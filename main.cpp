#include "stack.h"
#include <fstream>
using namespace Work;

int main(){

	std::ifstream read;
	read.open("cities15000.txt");
	//std::ofstream write;
	//write.open("result.txt");

	madeStack<std::string> temp;
	std::string str;


	if (read.is_open()){
		while (getline(read, str)){
			temp.push(str);
		}
		read.close();
	}

	//temp.print(std::cout);
	std::cout << temp.top()<< std::endl;

	for (int i = 0; i != 8000; ++i){
		temp.pop();
	}

	return 0;
}