#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include"list.h"

List* addList(string listnametemp);
int stringtoint(string stringtemp);
int Kursauswahl(vector<List*> listencopy);
void puffer();
void searchmenu(bool status, vector<List*> listencopy);
void addStudentmenu(vector<List*> listencopy);

#endif // FUNCTIONS_H
