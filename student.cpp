#include"student.h"

int Student::serie = 100000;

Student* Student::getbefore(){
    return before;
}
void Student::setbefore(Student *newbefore){
    before = newbefore;
}
int Student::getserie(){
return serie;
}
void Student::setserie(int newserie){
serie = newserie;
}
string Student::getlastname(){
return lastname;
}
string Student::getfirstname(){
return firstname;
}
int Student::getmatrikelnumber(){
return matrikelnumber;
}
Student* Student::getnext(){
return next;
}
void Student::setlastname(string newlastname){
lastname = newlastname;
}
void Student::setfirstname(string newfirstname){
firstname = newfirstname;
}
void Student::setmatrikelnumber(int newmatrikelnumber){
matrikelnumber = newmatrikelnumber;
}
void Student::setnext(Student* newnext){
next = newnext;
}
