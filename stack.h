#include<iostream>
#include<string>
#include<sstream>
#include<exception>
namespace Work{
	template <typename T>
	class madeStack{
	private:
		typedef size_t size;
		T* stack;
		size capacity;
		size item_num;
		T* at;
		
		void checkCondition(){
			if (item_num > 0.75 * capacity){
				//new capacity
				size newCapacity = 1.5 * capacity;
				//new array
				T* newArray = new T[capacity];
				//transfer items;
				for (int i = 0; i != capacity; ++i){
					newArray[i] = stack[i];
				}
				delete stack;
				this->capacity = newCapacity;

				stack = new T[capacity];
				std::cout << "Add slots apply" << std::endl;
			}
			if (item_num < 0.25 * capacity){
				//new capacity
				size newCapacity = 0.5 * capacity;
				//new array
				T* newArray = new T[capacity];
				//transfer items;
				for (int i = 0; i != newCapacity; ++i){
					newArray[i] = stack[i];
				}
				delete stack;
				this->capacity = newCapacity;

				stack = new T[capacity];

				std::cout << "reduce slots apply" << std::endl;

			}
		}
	public:

		madeStack(){
			this->capacity = 10;
			this->item_num = 0;
			//initialize array;
			stack = new T[capacity];
			//want a pointer that points to the first item;
			at = &(stack[0]);
		}

		madeStack(int capacity){
			this->capacity = capacity;
			this->item_num = 0;
			//initialize array;
			stack = new T[capacity];
			//want a pointer that points to the first item;
			at = &(stack[0]);
		}

		~madeStack(){}
		//classic stack menber function

		bool push(const T& element){
			checkCondition();
			if (item_num == 0){
				stack[0] = element;
				item_num++;
				return true;
			}
			else{
				for (int i = item_num; i != 0; i--){
					stack[i] = element;
					item_num++;
					return true;

				}
			}
		}

		bool pop(){
			
				checkCondition();
				if (item_num == 0){
					std::cout << "Empty stack" << std::endl;
				}
				else{
					
					for (int i = 0; i != item_num; ++i){
							stack[item_num] = stack[item_num + 1];
						
					}
					item_num--;
					return true;
				}	
		}

		T top(){
			return *at;
		}
		
		bool empty(){
			if (item_num == 0){
				return true;
			}
			else {
				return false;
			}
		}
		
		std::ostream& print(std::ostream& out) const {
			out << "Capacity: " << capacity << std::endl;
			out << "item_num: " << item_num << std::endl;
			for (int i = 0; i != item_num; ++i){
				out << " <";
				out << stack[i];
				out << ">";
			}
		}

		std::string osToString(std::ostream out){
			std::stringstream ss;
			ss << out.rdbuf();
			return ss.str();
		
		}

		//operator overload;
		T operator[](int i){
			return stack[i];
		}
	};
}