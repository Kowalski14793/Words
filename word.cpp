#include "word.h"

/// Eng_word CLASS
Eng_word::Eng_word(string n_eng1,string n_eng2,string n_eng3):eng1(n_eng1),eng2(n_eng2),eng3(n_eng3){};
Eng_word::Eng_word(){};
Eng_word::~Eng_word(){};

string Eng_word::get_eng1(){
    return eng1;
}
string Eng_word::get_eng2(){
    return eng2;
}
string Eng_word::get_eng3(){
    return eng3;
}
/// Desc_word CLASS
Desc_word::Desc_word(string n_desc):desc(n_desc){};
Desc_word::Desc_word(){};
Desc_word::~Desc_word(){};

string Desc_word::get_desc(){
    return desc;
}
/// Word CLASS
Word::Word(string eng1,string eng2,string eng3,string desc):Eng_word(eng1,eng2,eng3),Desc_word(desc){status=1;};
Word::Word(){};
Word::~Word(){};

void Word::set_status(unsigned short int status){
    this->status=status;
}

unsigned short int Word::get_status(){
    return status;
}

ostream& operator << (ostream &s,Word w){
    cout << " \t" << w.desc << endl;
    cout << "I.\t"  << w.eng1 << endl;
    cout << "II.\t" << w.eng2 << endl;
    cout << "III.\t" << w.eng3 << endl;
}
