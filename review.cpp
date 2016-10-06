#include <iostream>
#include <string>
#include <exception>
using namespace std;

	void func(){

	}
	int f( int* const a ){
	   return  ++(*a);
	}

	class E : public exception{
		const char* msg = nullptr;
		E() {};
	public:
		E(const char* s ) throw(): msg(s){}
		const char* what() const throw(){return msg;}
	};

	class A{
		int a;
	public:
		A (const int & a) : a (a){}
		const int & value() const{return a;}
	};

	int operator+(const A & lhs, const A & rhs){
		return lhs.value() + rhs.value();
	}

	namespace bwstring{
		const std::string prefix = "(bwstring)";

		class bwstring {
			std::string _s = "";
			bwstring();
		public:
			bwstring (const std::string & s){
				_s = s;
			}
			string & getString(){ return _s;}
			const string& operator() (){return _s;}
			const char * c_str(){return _s.c_str();}

		};

	};

	class Animal{
		string _type = "";
		string _name = "";
		string _sound ="";
		public:
			//Animal(){}
			Animal(string a="a", string b="b", string c="c"):_type(a),_name(b),_sound(c){}
			Animal(const Animal & a){
				_type = a._type;
				_name = a._name;
				_sound = a._sound;
			}
			Animal & operator= (const Animal & b){
				if(this != &b){
					_type = b._type;
					_name = b._name;
					_sound = b._sound;					
				}
				return *this;
			}
			string sound(){
				return _type+_name+_sound;
			}
	};

int main(int argc ,char** argv){

	// Initialize array
	int array[5] = {0,0,0,0,0};

	//C- String
	char s[] = {'s','t','r','i','n','g','0'};
	char s_1[] = {'s','t','i','n','g','0'};
	//C-String 
	char x[] = "string";

	int * a_p =array;
	//char * st_p = string;

	int i = 0;
	//can't change a_p
	// Int array does not have null terminate 
	// Can't play like this 
	for(;*a_p;++a_p){
		*a_p = ++i;
	}

  for(char* cp = x; *cp;++cp){
        //\n is 0
        printf("char is %c\n",*cp);
    }



	for (int x : array){
		printf("Array contains %d\n",x);
	}

	void (*fp)() = func;
	int a  = 1;
	cout << f(&a);

	Animal pig("A","Pig","Poww");
	cout << pig.sound();

	Animal pig2(pig);
	cout << pig.sound();

	Animal pig3 = pig2;
	cout << pig3.sound();

	cout << endl;

	char c_string_example[] = {'a','b','c'};
	bwstring::bwstring bwstring1("test1");
	printf("The c_string is %s\n",bwstring1.c_str());
	printf("The c_string is %s\n",c_string_example);
	const string& b = bwstring1();
	cout << b;
	return 0;
}