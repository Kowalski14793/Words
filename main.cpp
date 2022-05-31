#include <iostream>
#include <ctime>

#include "word.h"
#include "words_f.h"

using namespace std;


int main()
{

    srand(time(NULL));

    //vector<Word> slowka;
    vector<Word> slowka;
    //slowka = get_data_from("Irregular Verbs.txt");
    //slowka = get_data_from("test.txt");
    int a;
    cout << "\n Wybierz co chesz zdawac:\n\n";
    cout << " 1. Czasowniki nieregularne\n";
    cout << " 2. Zestawy slowek\n";
    cout << " *. Exit\n";
    cin >> a;
    int no;
    switch(a){
    case 1:
        slowka = get_data_from("Irregular Verbs");
        no = 3;
        break;
    case 2:
        slowka = get_data_from("Words");
        no=1;
        break;
    default:
        return 3;
        break;
    }



    cout << "Zasady: \n";
    cout << " 1. Aby zaliczyc nalezy dobrze podac " << no << " formy nieregularne.\n";
    cout << " 2. Bledna odpowiedz bedzie skutkowac koniecznoscia odpowiedzenia poprawnie 2 razy pod rzad dla danego slowa.\n\n";

    int n = slowka.size();
    int pozostalo=n;
    unsigned int bledy = 0;

    while(pozostalo!=0){

        int i = rand()%n;
        unsigned short int status = slowka[i].get_status();
        if(status>0){
            if(pozostalo!=n)
                cout << " Pozostalo: " << pozostalo << endl << endl;

            cout << " " <<  slowka[i].get_pol() << ":\n";

            string odp[no];
            for(int i=0;i<no;i++){
                cin >> odp[i];
            }

            if(poprawnosc(odp,slowka[i],no)==0){
                status--;
                slowka[i].set_status(status);

                if(status==0)
                    pozostalo--;
            }
            else{
                slowka[i].set_status(2);
                cout << "\nZle\n\n";
                cout << "Poprawna odpowiedz to:\n";
                cout << slowka[i] << endl;
                cout << "------------------------------" << endl;

                bledy++;
                system("pause");
            }

        }
        cin.clear();
        fflush(stdin);
        system("cls");
    }

    cout << " Ilosc bledow: " << bledy << endl << endl;

}

