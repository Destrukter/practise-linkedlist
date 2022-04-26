#include"functions.h"

void puffer(){
    string puffer;
    cout<<"Beliebige Tase drücken zum fortfahren.";
    cin>>puffer;
}

void searchmenu(bool status, vector<List*> listencopy){
    int kurs;
    string input;
    int inputzahl;
    Student* gesucht;
    kurs = Kursauswahl(listencopy);
    if(kurs==0){
        return;
    }
    while(true){
        cout<<"Matrikelnummer?";
        cin>>input;
        inputzahl = stringtoint(input);
        if(inputzahl>999999 || inputzahl<100000){       //Intercept invalid entries
            system("clear");
            cout<<"Ungültige Eingabe\n";
            continue;
        }
        if(status){//if deleted wanted
            gesucht = listencopy[kurs-1]->search(inputzahl);//search if exists
            if(gesucht==nullptr){
                cout<<"Student nicht gefunden"<<endl;
                break;
            }
            else{
                cout<<"Student gelöscht: "<<gesucht -> getfirstname()<<" "<<gesucht -> getlastname()<<endl;
            }
            if(kurs-1==0){//if deleted out of studend list delete out of every other list aswell
                for(unsigned int c = 0; c<listencopy.size(); c++)
                    listencopy[c]->searchdelete(inputzahl);
            }
            else{
                listencopy[kurs-1]->searchdelete(inputzahl);
            }
        }
        if(!status){//if searched wanted give result
            gesucht = listencopy[kurs-1]->search(inputzahl);
            if(gesucht == nullptr){
                cout<<"Nicht gefunden!\n";
            }
            else{
                cout<<"Student gefunden:"<<gesucht -> getmatrikelnumber()<<" "<<gesucht -> getfirstname()<<" "<<gesucht -> getlastname()<<endl;
            }
        }
        break;
    }
    puffer();
    return;
}

void addStudentmenu(vector<List*> listencopy){
    int kurs;
    kurs = Kursauswahl(listencopy);
    if(kurs==0){
        return;
    }
    string eingabe;
    if(kurs!=1){
        cout<<"Neuer Student(Ja | Nein)?"<<endl; //if old
        cin>>eingabe;
        if(eingabe=="Nein" || eingabe =="nein"){
            Student* gesucht;
            string input;
            int inputzahl;
            cout<<"Matrikelnummer?";
            cin>>input;
            inputzahl = stringtoint(input);
            if(inputzahl>999999 || inputzahl<100000){       //Intercept invalid entries
                system("clear");
                cout<<"Ungültige Eingabe\n";
                return;
            }
            gesucht = listencopy[0]->search(inputzahl); //search if student exists in studentlist
            if(gesucht!=nullptr && nullptr == listencopy[kurs-1]->search(inputzahl)){//if student exists and isnt already in current list
                listencopy[kurs-1]->addexistingStudent(gesucht);
                return;
            }
        }
    }
    if(kurs == 1 || eingabe == "ja" || eingabe =="Ja"){ //if new
        cout<<"Firstname: ";
        string firstname;
        cin>>firstname;
        cout<<"Lastname: ";
        string lastname;
        cin>>lastname;
        Student* neuerStudent = listencopy[0]->addStudent(lastname, firstname);//add into studentlist
        if(kurs!=1){
            listencopy[kurs-1]->addexistingStudent(neuerStudent);//if studentlist not selected also add into previously selected list
        }
    }
    return;
}

int stringtoint(string stringtemp){
    unsigned int counter = 0;
    int number = 0;
    while(counter < stringtemp.size() && isdigit(stringtemp.at(counter))){
        number = 10*number+stringtemp.at(counter)-'0';
        counter++;
    }
    return number;
}

int Kursauswahl(vector<List*> listencopy){
    unsigned long counter = 1;
    string kurs;
    unsigned long kursnummer;
    do{
        system("clear");
        counter = 1;
        while(counter <= listencopy.size()){ //list of lists
            cout<<"("<<counter<<")"<<listencopy[counter-1]->listname<<endl;
            counter++;
        }
        cout<<"Bitte wählen Sie einen Kurs.";
        cin>>kurs;
        kursnummer = stringtoint(kurs);
    }while(kursnummer>listencopy.size());       //intercept invalid entries(0 valid -> go back to main menu)
    return kursnummer;
}

List* addList(string listnametemp){
    List* thisList = new List(listnametemp);
    return thisList;
}
