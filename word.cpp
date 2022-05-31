#include "word.h"


Word::Word(string n_eng1,string n_eng2,string n_eng3,string n_pol):eng1(n_eng1),eng2(n_eng2),eng3(n_eng3),pol(n_pol){status=1;};
Word::Word(){};
Word::~Word(){};

void Word::set_status(unsigned short int status){
    this->status=status;
}

string Word::get_eng1(){
    return eng1;
}
string Word::get_eng2(){
    return eng2;
}
string Word::get_eng3(){
    return eng3;
}
string Word::get_pol(){
    return pol;
}
unsigned short int Word::get_status(){
    return status;
}

ostream& operator << (ostream &s,Word w){
    cout << "PL:\t" << w.pol << endl;
    cout << "I.\t"  << w.eng1 << endl;
    cout << "II.\t" << w.eng2 << endl;
    cout << "III.\t" << w.eng3 << endl;
}



Irregular_verbs::Irregular_verbs(string n_eng1,string n_eng2,string n_eng3,string n_pol):Word(n_eng1,n_eng2,n_eng3,n_pol){};
Irregular_verbs::~Irregular_verbs(){};
