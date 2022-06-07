#ifndef WORD_H
#define WORD_H

#include <iostream>

using namespace std;

class Eng_word{
protected:
    string eng1,eng2,eng3;
public:
    Eng_word(string,string,string);
    Eng_word();
    ~Eng_word();
    string get_eng1();
    string get_eng2();
    string get_eng3();
};

class Desc_word{
protected:
    string desc;
public:
    Desc_word(string);
    Desc_word();
    ~Desc_word();
    string get_desc();
};

class Word:public Eng_word, public Desc_word{
private:
    unsigned short int status;
public:
    Word(string,string,string,string);
    Word();
    ~Word();

    friend ostream& operator << (ostream &s,Word w);

    void set_status(unsigned short int);

    unsigned short int get_status();
};

#endif // WORD_H
