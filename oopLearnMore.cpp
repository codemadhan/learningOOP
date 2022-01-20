#include<iostream>
using namespace std;

#define print cout

class Employee{
private:
    string workplace;
    int salary;
    int* experience;    
protected:
     int age;
    string name;
public:
    Employee(){}          // default constructor!! 
    Employee(string Name, int Age, string Workplace, int Salary, int exp): name(Name),workplace(Workplace),salary(Salary),experience(new int(exp)){
        if(Age>=18){
            age=Age;   // this is also possible!!!!  if age given less than 18, it will store garbage value
        }
    }
     
     // the above syntax is also valid

    ~Employee(){
        delete experience;
        experience=nullptr;
    }
        
    void setName(string Name){
        name=Name;
    }
    string getName() const {
        return name;
    }
    void setAge(int Age){
        if(Age >= 18)
            age=Age;
    }
    int getAge() const {          // usint const here because we don't want to change the value accidentally!
        return age;
    }
    void setWorkplace(string Workplace){
        workplace=Workplace;
    }
    string getWorkplace() const {
        return workplace;
    }
    void SetSalary(int s){
        salary=s;
    }
    int GetSalary() const {
        return salary;
    }
    void SetExperience(int exp){
        experience = new int(exp);
    }
    int GetExperience() const {
        return *experience;
    }

    void DoYouGetPaid(){
        cout << "No, " << name <<  " does'nt get paid";
    }

    int operator+(const Employee emp)const{
        return this->GetSalary() + emp.GetSalary();    //  Operator overloading used here!!
    }

    void willYouLoseJob();
    void SalaryComparison(Employee e);
    
    virtual void AreUHappy(){
        print << "Yes I'm happy." << endl;
    }
};

// pure virtual functions could also have been used here if we didn't know what to write in the base 
// class , in case we don't know what to write 
// virtual void AreUHappy() const = 0; could have been used there!!
// But if we create a pure virtual function inside a class it becomes abstract class
// and we won't be able to create objects of that class 
// For that we may have to use pointer of that class and point it to the derived class or simply make 
// another derived class for that function and inherit it wherever we may need it.!! 
// Pure virtual function used in the TrickyOOP do refer that 

void Employee::willYouLoseJob(){
    cout << "Not sure";
}


void Employee::SalaryComparison(Employee e){               //You can't do like this for an inherited class 
    if(this->salary > e.salary ){                     // like Teacher or Developer!!!
        print << "Your salary is higher." << endl;
    }
    else if(this->salary < e.salary){
        print << "Your salary is lesser." << endl;
    }
    else{
        print << "Your salaries are equal." << endl;
    }
}

class Teacher: Employee{
private:
    string subject;
public:
    Teacher(string Name, int Age , string Workplace , string Subject, int Salary, int exp) : Employee(Name, Age, Workplace, Salary, exp){
        subject=Subject;
    }
    void SetSubject(string sub){
        subject=sub;
    }
    string GetSubject() const {
        return subject;
    }
    void DoYouGetPaid(){
        cout << "The teacher gets paid. ";
    }
    void willYouLoseJob(){
        cout << "No you won't lose your job. " << endl;
    }
    void AreUHappy(){
        print << "I'm not really happy." << endl;
    }
};


class Developer:public Employee{
private:
    string favLang;
public:
    Developer(string n, int a, string w, string f, int s, int e) : Employee(n,a,w,s,e),favLang(f){}
        
      // this is also a way to define a constructer!!!!

    void setFavlang(string f){
        favLang=f;
    }

    string getFavLang() const {
        return favLang;
    }
    
    void AreUHappy(){
        print << "I'm very happy ." << endl;
    }
    
};

int main(){
    Developer d = Developer("Madhan",15,"College","C++",100000,5);
    Teacher t ("Vignesh",18,"School","SOS",50000,5);      // this is also possible!!!!
    Employee e("Idk",45,"Lawyer",90000,10);
    Employee c("Raj",32,"Hotel",54000,7);

    cout << t.GetSubject() << endl;
    
    cout << d.getAge() << endl << e.getAge();
    
    d.setAge(12);
    
    cout << endl << d.getAge() << endl;
    
    cout << d.getWorkplace(); cout << endl;
    
    d.DoYouGetPaid(); cout << endl;
    
    t.DoYouGetPaid();
    cout << endl;
    
    d.willYouLoseJob();
    cout << endl;
    
    t.willYouLoseJob();

    d.SalaryComparison(e);            //can't put t because the function has Employee parameter!!!

    d.AreUHappy();

    e.AreUHappy();

    // adding salaries!!
    print << e + c << endl;          // operator overloading used here 
    
    Employee* f;     // default constructor used here 
    f=&d;    // polymorphism

    f->AreUHappy();   // for pointers -> is used in place of .  
    // because of virtual function, AreUHappy of developer was called!!

}

