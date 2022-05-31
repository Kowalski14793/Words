#include "word.h"


Word::Word(string n_ang1,string n_ang2,string n_ang3,string n_pol):ang1(n_ang1),ang2(n_ang2),ang3(n_ang3),pol(n_pol){status=1;};
Word::~Word(){};

void Word::set_status(unsigned short int status){
    this->status=status;
}

string Word::get_ang1(){
    return ang1;
}
string Word::get_ang2(){
    return ang2;
}
string Word::get_ang3(){
    return ang3;
}
string Word::get_pol(){
    return pol;
}
unsigned short int Word::get_status(){
    return status;
}

ostream& operator << (ostream &s,Word w){
    cout << "PL:\t" << w.pol << endl;
    cout << "I.\t"  << w.ang1 << endl;
    cout << "II.\t" << w.ang2 << endl;
    cout << "III.\t" << w.ang3 << endl;
}



Irregular_verbs::Irregular_verbs(string n_ang1,string n_ang2,string n_ang3,string n_pol):Word(n_ang1,n_ang2,n_ang3,n_pol){};
Irregular_verbs::~Irregular_verbs(){};
