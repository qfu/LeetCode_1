#include <iostream>
using namespace std;
// -- interface --

const string unk = "unknown";
const string clone_prefix = "clone-";

class Animal {
    string _type = "";
    string _name = "";
    string _sound = "";
protected:
public:
	Animal();
    Animal(const string & type, const string & name, const string & sound);
    Animal(const Animal & a); // copy constructor
    Animal & operator=(const Animal &); // assignment operator overload
    ~Animal();  // destructor
    void print() const;
    string operator()() const { return _type; }
};


class B : public Animal{
public:
    B(){
      Animal* f = new Animal(); // Not allowed to access constructor like this!
    }
   

};
// -- implementation --
Animal::Animal() : _type(unk), _name(unk), _sound(unk) {
    puts("default constructor");
}

Animal::Animal(const string & type, const string & name, const string & sound)
: _type(type), _name(name), _sound(sound) {
    puts("constructor with arguments");
}

Animal::Animal(const Animal & a) {
    puts("copy constructor");
    _name = clone_prefix + a._name;
    _type = a._type;
    _sound = a._sound;
}

Animal::~Animal() {
    printf("destructor: %s the %s\n", _name.c_str(), _type.c_str());
}

void Animal::print () const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

Animal & Animal::operator=(const Animal & o) {
    puts("assignment operator");
    // cannot use *this != o 
    //because comparion between const vs non- const 
    if(this != &o) {
        _name = clone_prefix + o._name;
        _type = o._type;
        _sound = o._sound;
    }
    return *this;
}


const int & funct(const int & x){
    static int y = x;
    ++y;
    return y;
}

struct preferences {
    // number of bit to take in
    bool likesMusic:1;
    bool hasHair:1;
    bool hasInternet:1;
    bool hasDinosaur:1;
    unsigned int numberOfChildren:4;
};


enum colors_t {black, blue, green, cyan, red, purple, yellow, white};
enum card_rank { ACE = 1, DEUCE = 2, JACK = 11, QUEEN, KING };
union ipv4 {
    uint32_t i32;
    struct {
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
    } octets;
};

int main(int argc, char ** argv){
	B a = B();
	float f;
    double df;
    //more precision 
    long double ldf;
    
    //Precision error 
    f = 0.1 * 3;
    
    //10 precision 
    printf("float f is %1.10f\n",f);
    printf("size of float f is %ld\n", sizeof(f));
    printf("size of double float df is %ld\n", sizeof(df));
    printf("size of long double float ldf is %ld\n", sizeof(ldf));
    
    
    char cstring[] = "String" "String" "String";

    puts(cstring);

    for( unsigned int i = 0; cstring[i]; i++) {
        printf("%02d: %c\n", i, cstring[i]);
    }


    cout << funct(1);

    preferences homer;
    homer.likesMusic = true;
    homer.hasHair = false;
    homer.hasInternet = true;
    homer.hasDinosaur = false;
    homer.numberOfChildren = 15;
    
    printf("sizeof int: %ld bits\n", sizeof(int) * 8);
    printf("sizeof homer: %ld bits\n", sizeof(homer) * 8);
    
    if(homer.likesMusic) printf("homer likes music\n");
    if(homer.hasHair) printf("homer has hair\n");
    if(homer.hasInternet) printf("homer has net\n");
    if(homer.hasDinosaur) printf("homer has a dino\n");
    printf("homer has %d children\n", homer.numberOfChildren);

    colors_t obj1 = purple;
    colors_t obj2 = green;
    card_rank obj3 = QUEEN;
    cout << obj1;
    cout << obj2;
    cout << QUEEN;

    ipv4 addr;
    addr.octets = { 192, 163, 73, 42 };
    //access like a 32 int or a struct 
    //different representation of same data

    
    printf("addr is %d.%d.%d.%d is %08x\n",
           addr.octets.a, addr.octets.b, addr.octets.c, addr.octets.d, addr.i32 );
    

    cout << typeid(addr).name();
	return 0;
}