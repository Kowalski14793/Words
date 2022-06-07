#include <iostream>
#include <ctime>
#include <deque>

#include "word.h"
#include "words_f.h"

using namespace std;

int main()
{
    srand(time(NULL));
    deque<Word> words;

    int choice;
    cout << " 1. Czasowniki nieregularne\n";
    cout << " *. Exit\n";
    cin >> choice;
    int correct_req;
    switch(choice){
    case 1:
        words = get_data_from("Irregular Verbs");
        correct_req = 3;
        break;
    default:
        return 3;
        break;
    }

    cout << "Zasady: \n";
    cout << " 1. Odpowiedz wymaga podania dobrze " << correct_req << " form.\n";
    cout << " 2. Bledna odpowiedz bedzie skutkowac koniecznoscia odpowiedzenia poprawnie 2 razy pod rzad dla danego czasownika nieregularnego.\n\n";

    int n = words.size();
    int remain=n;
    unsigned int mistakes_counter = 0;
    int lim=3;
    while(remain!=0){
        cout << "\n_________\n";
        bool is_back;
        Word word;

        if(rand()%10>lim){
            is_back = true;
            word = words.back();
            words.pop_back();
        }
        else{
            is_back = false;
            word = words.front();
            words.pop_front();
        }

        unsigned short int status = word.get_status();
        cout << " Pozostalo: " << remain << endl << endl;

        cout << " " <<  word.get_desc() << ":\n";

        string res[correct_req]; /// response

        for(int i=0;i<correct_req;i++){
            cin >> res[i];
        }

        if(check(res,word,correct_req)==0){
            status--;
        }
        else{
            status = 2;
            cout << "\nZle\n\n";
            cout << "Poprawna odpowiedz to:\n";
            cout << word << endl;
            cout << "------------------------------" << endl;

            mistakes_counter++;
            system("pause");
        }

        if(status!=0){
            if(rand()%10>lim){
                words.push_back(word);
                words.back().set_status(status);
            }
            else{
                words.push_front(word);
                words.front().set_status(status);
            }
        }
        else
            remain--;

        cin.clear();
        fflush(stdin);
        system("cls");
    }

    cout << "\n Ilosc bledow: \n" << mistakes_counter << endl << endl;
}
