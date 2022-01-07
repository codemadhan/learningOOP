#include<iostream>
#include<string>
using namespace std;

class students{
public:
    int roll;
    string name;
    int age;
    void printInfo();
    students(int num, string Name, int Age){
        roll=num;
        name=Name;
        age=Age;
    }

};
 void students::printInfo(){
        cout << roll << " " << name << " " << age << endl;
 }
int main()
{
    
    students student1 = students(1,"Madhan",18);
    student1.name="Vignesh";
    student1.printInfo(); 

    students student2 = students(2,"Anshul",18);
    student2.printInfo();
    student1.printInfo();
}