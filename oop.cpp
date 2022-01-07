#include<iostream>
#include<string>
using namespace std;

class students{
public:
    int rollnumber;
    string name;
    int age;
    void printstudents(){
        cout << name << endl;
        cout << rollnumber << endl;
        cout << age << endl;
    }
    void enterInput(int num, string Name, int Age){
        rollnumber=num;
        name=Name;
        age=Age;
    }
    
};

int main(){
    students student1;
    student1.rollnumber=1;
    student1.name="Madhan";
    student1.age=18;
    student1.printstudents();
    cout << endl;

    students student2;
    student2.rollnumber=2;
    student2.name="Anshul";
    student2.age=18;
    student2.printstudents(); 
    cout << endl;
    
    students student3;
    student3.enterInput(3,"Harpreet",19);
    student3.printstudents();

    return 0;
}