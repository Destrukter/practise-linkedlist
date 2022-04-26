#ifndef STUDENT_H
#define STUDENT_H
#include<vector>
#include<iostream>
using namespace std;

struct Student
{
private:
    string lastname;
    string firstname;
    int matrikelnumber;
    Student* next;
    Student* before;
    static int serie;
public:
    static int getserie();
    static void setserie(int newserie);
    string getlastname();
    string getfirstname();
    int getmatrikelnumber();
    Student* getnext();
    Student* getbefore();
    void setlastname(string newlastname);
    void setfirstname(string newfirstname);
    void setmatrikelnumber(int newmatrikelnumber);
    void setnext(Student* newnext);
    void setbefore(Student* newbefore);
};

#endif // STUDENT_H
