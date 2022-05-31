#include <iostream>
#include <ctime>
#include <deque>

#include "word.h"
#include "words_f.h"


/*CHECKING*/
#include <time.h>
clock_t b_stopwatch;
clock_t e_stopwatch;
void start_stopwatch(){
    b_stopwatch = clock();
}
void stop_stopwatch(){
    e_stopwatch = clock();
    cout << ((double) (e_stopwatch - b_stopwatch)) / CLOCKS_PER_SEC << " s\n";
}
/*CHECKING END*/

using namespace std;

int main()
{
    srand(time(NULL));
    //vector<Word> words;
    deque<Word> words;
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
        start_stopwatch();/**/
        words = get_data_from("Irregular Verbs");
        stop_stopwatch();/**/
        //words = get_data_from("test");
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
    int lim=3;
    while(remain!=0){
        cout << "\n_________\n";
        bool is_back;
        Word word;

        if(rand()%10>lim){
            is_back = true;
        }
        else{
            is_back = false;
        }
        if(is_back){
            word = words.back();
            words.pop_back();
        }
        else{
            word = words.front();
            words.pop_front();
        }
        unsigned short int status = word.get_status();
        cout << " Pozostalo: " << remain << endl << endl;

        cout << " " <<  word.get_pol() << ":\n";

        string res[correct_req]; /// response
        for(int i=0;i<correct_req;i++){
            cin >> res[i];
        }
        start_stopwatch(); /**/
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
        stop_stopwatch();/**/
        cin.clear();
        fflush(stdin);
        //system("cls");
    }

    cout << " Ilosc bledow: " << mistakes_counter << endl << endl;

}

