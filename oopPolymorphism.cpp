#include<iostream>
using namespace std;

class Employee{
private:
    string workplace;
protected:
     int age;
    string name;
public:
    Employee(string Name, int Age, string Workplace){
        name=Name;
        age=Age;
        workplace=Workplace;
    }
    void setName(string Name){
        name=Name;
    }
    string getName(){
        return name;
    }
    void setAge(int Age){
        if(Age >= 18)
            age=Age;
    }
    int getAge(){
        return age;
    }
    void setWorkplace(string Workplace){
        workplace=Workplace;
    }
    string getWorkplace(){
        return workplace;
    }
    void DoYouGetPaid(){
        cout << "No, " << name <<  " does'nt get paid";
    }
    


};

class Teacher: Employee{
private:
    string subject;
public:
    Teacher(string Name, int Age , string Workplace , string Subject) : Employee(Name, Age, Workplace){
        subject=Subject;
    }
    void SetSubject(string sub){
        subject=sub;
    }
    string GetSubject(){
        return subject;
    }
    void DoYouGetPaid(){
        cout << "The teacher gets paid. ";
    }
};

class Developer:public Employee{
private:
    string favLang;
public:
    Developer(string n, int a, string w, string f) : Employee(n,a,w){
        favLang=f;
    }
    void setFavlang(string f){
        favLang=f;
    }
    string getFavLang(){
        return favLang;
    }
    
};

int main(){
    Developer d = Developer("Madhan",15,"College","C++");
    Teacher t = Teacher("Vignesh",18,"School","SOS");
    cout << t.GetSubject() << endl;
    cout << d.getAge();
    d.setAge(12);
    cout << endl << d.getAge() << endl;
    cout << d.getWorkplace(); cout << endl;
    d.DoYouGetPaid(); cout << endl;
    t.DoYouGetPaid();

}