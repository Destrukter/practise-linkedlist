#ifndef LIST_H
#define LIST_H
#include"student.h"

struct List
{
    string listname;
    Student* top;
    Student* bottom;
    long numberofelements;
    List(string listnametemp);
    Student* search(int mnumber);
    void searchdelete(int mnumber);
    void listeloeschen();
    Student* addStudent(string lasttemp, string firsttemp);
    void sort();
    void addexistingStudent(Student* neuerStudent);
};

#endif // LIST_H
