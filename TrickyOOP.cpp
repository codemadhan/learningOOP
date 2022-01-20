#include<iostream>
#include<string>
using namespace std;

#define print cout 

// shallow copying is basically a object shows directly the existing object without actually making a new 
// object and copying its values


class Horn{
public:
     virtual void Sound() const=0;     /// pure virtual function ! 
};

class Cars{
private:
    string name;
    int* year;        // didn't use const pointer here because we won't be able to set it to nullptr!
public:
    Cars(){}          // default constructor!!
    Cars(string n, int y): name(n),year(new int(y)){}
    void SetName(string n){
        n=name;
    }
    ~Cars(){
        delete year;
        year=nullptr;
    }
    string GetName() const {
        return name;
    }
    void SetYear(int y){
        *year=y;
    }
    int GetYear() const {
        return *year;
    }
    char& operator[](int index){    //char& is used here to return the char variable not char value!!! 
        return name[index];                  // operator overloading here !!
    }
    friend void printName(Cars);
};

class Tata:public Cars,public Horn{
private:
    string engType;
public:
    Tata(){}  // default constructor
    Tata(string n, int y, string e):Cars(n,y),engType(e){}
    
    void SetEng(string e){
        engType=e;
    }
    
    string GetEng() const {
        return engType;
    }
    void Sound() const {
        cout << "Not very Loud" << endl;
    }
   
};

class Suzuki:public Cars, public Horn{
private:
    string engType;
public:
    Suzuki(){}     // default constructor!
    Suzuki(string n, int y, string e):Cars(n,y),engType(e){}

    void SetEng(string e){
        engType=e;
    }

    string GetEng(){
        return engType;
    }
    
   void Sound() const {
       cout << "Very loud" << endl;
   }
};

void printName(Cars x){
    print << x.name << endl;
}



int main(){

    Cars car("Ferrari",2021);
    car[3]='m';                         // operator [] was oveloaded here
    print << car.GetName();             
    printName(car);

    Cars** ptr = new Cars*[3];
    ptr[0]= new Tata("Punch",2021,"Off road");
    ptr[1]= new Suzuki("Wagonr", 2020 ,"Economy");    // used pointers here!!
    ptr[2]= new Tata("Altroz",2021,"All purpose");

    for(int i=0; i < 3; i++){
        cout << ptr[i]->GetName() << endl;   // I wanted to get that sound function here but since the return value
    }                                // of the pointer was Cars and it didn't have the sound function, I couldn't
                                    // call it!!!

    for(int i=0; i < 3; i++){
        delete ptr[i];
    }
    delete[] ptr;
    ptr=nullptr;

    Tata t("Sumo",2014,"Offroad");
    t.Sound();

}