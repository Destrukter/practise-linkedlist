//Practise_LinkedList
//Frederik Hinz
//05.01.2021

#include"functions.h"
using namespace std;

int main()
{
    vector<List*> listen;
    listen.push_back(addList("Studentenliste"));
    while(true){
        system("clear");
        cout<<"(1)Kurs anlegen\n(2)Kurs anzeigen\n(3)Kurs löschen\n(4)Student anlegen\n(5)Student anzeigen\n(6)Student löschen\n(7)Programm beenden\n";
        string eingabe;
        cout<<"Neue Eingabe:";
        cin>>eingabe;
        if(eingabe=="1"){//Kurs anlegen
            cout<<"Name eingeben:"<<endl;
            string name;
            cin>>name;
            listen.push_back(addList(name));
        }
        if(eingabe=="3"){//Kurs löschen
            int kurs;
            kurs = Kursauswahl(listen);
            if(kurs==0){
                continue;
            }
            kurs--;
            if(kurs==0){
                cout<<"Studentenliste darf nicht gelöscht werden!"<<endl;
                puffer();
            }
            else{
            listen[kurs]->listeloeschen();
            delete listen[kurs];
            listen.erase(listen.begin() + kurs);
            }
        }
        if(eingabe=="2"){//Kurs anzeigen
            int kurs;
            kurs = Kursauswahl(listen);
            if(kurs==0){ //no kurs created yet
                continue;
            }
            listen[kurs-1]->sort();
            cout<<listen[kurs-1] -> listname<<":\nLastname       |Firstname      |Mnumber"<<endl;
            Student* current = listen[kurs-1] -> top;
            while(true){
                if(current == nullptr){ //end of list reached
                    break;
                }
                cout.setf(ios::left);
                cout.width(15);
                cout<<current -> getlastname()<<" ";
                cout.width(15);
                cout<<current -> getfirstname()<<" ";
                cout.width(6);
                cout<<current -> getmatrikelnumber()<<endl;
                current = current -> getnext();
            }
            puffer();
        }
        if(eingabe=="4"){//Student anlegen
            addStudentmenu(listen);
        }
        if(eingabe=="5"){//Student anzeigen
            searchmenu(0, listen);
        }
        if(eingabe=="6"){//Student löschen
            searchmenu(1, listen);
        }
        if(eingabe=="7"){
            return 0;
        }
        else{
            continue;
        }
    }
}
