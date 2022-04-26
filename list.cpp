#include"list.h"

List::List(string nametemp){
    listname = nametemp;
    top = nullptr;
    bottom = nullptr;
    numberofelements = 0;
}

Student* List::addStudent(string lasttemp, string firsttemp){
    Student* thisStudent = new Student;
    thisStudent -> setbefore(nullptr); //set before
    thisStudent -> setlastname(lasttemp);
    thisStudent -> setfirstname(firsttemp);
    thisStudent -> setmatrikelnumber(Student::getserie());
    Student::setserie(Student::getserie()+1);
    numberofelements++;
    thisStudent -> setnext(top);    //set next
    if(top == nullptr){ //set bottom if first element
        bottom = thisStudent;
    }
    else{ //if not first element set before of previous top
        thisStudent -> getnext() -> setbefore(thisStudent);
    }
    top = thisStudent;              //new top of list
    return thisStudent;
}

void List::addexistingStudent(Student* neuerStudent){
    Student* thisStudent = new Student;
    thisStudent -> setlastname(neuerStudent->getlastname()); //copy elements
    thisStudent -> setfirstname(neuerStudent->getfirstname());
    thisStudent -> setmatrikelnumber(neuerStudent->getmatrikelnumber());
    numberofelements++; //same as other add function
    thisStudent -> setnext(top);
    thisStudent -> setbefore(nullptr);
    if(top == nullptr){
        bottom = thisStudent;
    }
    else{
        top -> setbefore(thisStudent);
    }
    top = thisStudent;
}

void List::sort(){//gnome sort
    Student* current = top; //start with top
    if(current == nullptr){ //no element in list break sort
        return;
    }

    while(current->getnext()!=nullptr){
        string cnextvalue = current->getnext()->getlastname();
        string cvalue = current->getlastname();
        if(cnextvalue[0]<91 && cnextvalue[0]>64){//convert upper to lowercase for comparison
            cnextvalue[0] += 32;
        }
        if(cvalue[0]<91 && cvalue[0]>64){
            cvalue[0] += 32;
        }
        if(cnextvalue[0]<cvalue[0]){
            if(current->getbefore()==nullptr){//if top element is swapped, update top
                top = current ->getnext();
            }
            Student* before = current -> getbefore(); //safe current pointers of both elements
            Student* next = current -> getnext();
            Student* before2 = current -> getnext() -> getbefore();
            Student* next2 = current -> getnext() -> getnext();

            if(next2!= nullptr){//swap pointer of element after 2nd element if 2nd element isnt bottom
                next2 -> setbefore(before2);
            }

            if(before != nullptr){//swap pointer of element before 1st element if 1st element isnt top
                before -> setnext(next);
            }

            next->setbefore(before); //swap pointers of both elements
            next->setnext(before2);
            before2->setnext(next2);
            before2->setbefore(next);

            if(current->getbefore()!=nullptr){//step left if not already at top
                current = current->getbefore();
            }
            else{
                current = current->getnext();
            }
        }
        else{
            current = current->getnext();//step right if already in right order
        }
    }
    bottom = current;//update bottom at the end
}

Student* List::search(int mnumber){
    Student* current = top; //start with top
    while(true){
        if(current == nullptr || current -> getmatrikelnumber() == mnumber){
            break;
        }
        current = current -> getnext();     //step
    }
    if(current == nullptr){
        return nullptr;         //nothing was found
    }
    if(current -> getmatrikelnumber() == mnumber){
        return current;         //return found element
    }
    else{
        cout<<"Fehler\n";
        return nullptr;         //error
    }
}

void List::searchdelete(int mnumber){
    Student* current = top; //start with top
    while(current!=nullptr){
        if(current -> getmatrikelnumber() == mnumber){
            if(current == bottom && current == top){//special case: only element in list
                bottom = nullptr;
                top = nullptr;
            }
            else if(current == top){//special case: top element in list
                top = current->getnext();
                current->getnext()->setbefore(nullptr);
            }
            else if(current == bottom){//special case: bottom element in list
                bottom = current->getbefore();
                current->getbefore()->setnext(nullptr);
            }
            else{//normal case update pointers
                current->getbefore()->setnext(current->getnext());
                current->getnext()->setbefore(current->getbefore());
            }
            delete current;
            numberofelements--;
            return;
        }
        current = current -> getnext(); //step
    }
}

void List::listeloeschen(){
    Student* del = top;
    while(del!=nullptr){
    Student* temp = del->getnext();
    delete del;
    del = temp;
    }
}
