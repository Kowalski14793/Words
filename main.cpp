#include <iostream>
#include <ctime>

#include "word.h"
#include "words_f.h"

using namespace std;


int main()
{

    srand(time(NULL));

    //vector<Word> words;
    vector<Word> words;
    //words = get_data_from("Irregular Verbs.txt");
    //words = get_data_from("test.txt");
    int choice;
    cout << "\n Wybierz co chesz zdawac:\n\n";
    cout << " 1. Czasowniki nieregularne\n";
    cout << " 2. Zestawy slowek\n";
    cout << " *. Exit\n";
    cin >> choice;
    int correct_req;
    switch(choice){
    case 1:
        words = get_data_from("Irregular Verbs");
        correct_req = 3;
        break;
    case 2:
        words = get_data_from("Words");
        correct_req=1;
        break;
    default:
        return 3;
        break;
    }



    cout << "Zasady: \n";
    cout << " 1. Aby zaliczyc nalezy dobrze podac " << correct_req << " formy nieregularne.\n";
    cout << " 2. Bledna odpowiedz bedzie skutkowac koniecznoscia odpowiedzenia poprawnie 2 razy pod rzad dla danego slowa.\n\n";

    int n = words.size(); /// words_size
    int remain=n;
    unsigned int mistakes_counter = 0;

    while(remain!=0){

        int i = rand()%n;
        unsigned short int status = words[i].get_status();
        if(status>0){
            if(remain!=n)
                cout << " Pozostalo: " << remain << endl << endl;

            cout << " " <<  words[i].get_pol() << ":\n";

            string res[correct_req]; /// response
            for(int i=0;i<correct_req;i++){
                cin >> res[i];
            }

            if(check(res,words[i],correct_req)==0){
                status--;
                words[i].set_status(status);

                if(status==0)
                    remain--;
            }
            else{
                words[i].set_status(2);
                cout << "\nZle\n\n";
                cout << "Poprawna odpowiedz to:\n";
                cout << words[i] << endl;
                cout << "------------------------------" << endl;

                mistakes_counter++;
                system("pause");
            }

        }
        cin.clear();
        fflush(stdin);
        system("cls");
    }

    cout << " Ilosc bledow: " << mistakes_counter << endl << endl;

}

