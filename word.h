#ifndef WORD_H
#define WORD_H

#include <iostream>

using namespace std;

class Word{
protected:
    string eng1,eng2,eng3,pol;
    unsigned short int status;
public:
    Word(string ,string ,string ,string );
    ~Word();
    friend ostream& operator << (ostream &s,Word w);

    void set_status(unsigned short int);
    string get_eng1();
    string get_eng2();
    string get_eng3();
    string get_pol();
    unsigned short int get_status();
};

class Irregular_verbs:public Word{
    Irregular_verbs(string ,string ,string ,string);
    ~Irregular_verbs();
};


#endif // WORD_H
