#include "words_f.h"

bool check(string *res,Word s,int n){
    int good_counter=0;
    string answer_tab[3] = {s.get_eng1(),s.get_eng2(),s.get_eng3()};

    for(int i=0;i<n;i++){
        if(answer_tab[i].length()!=res[i].length())
            return 1;
        for(int j=0;j<res[i].length();j++){
            if(res[i][j]!=answer_tab[i][j])
                return 1;
        }
    }
    return 0;
}

deque<Word> get_data_from(string file_name,int n){

    bool extension_flag = false;
    int i=0;
    while(file_name[i]!='\0'){
        if(file_name[i]=='.'){
            extension_flag = true;
            break;
        }
        i++;
    }
    if(extension_flag==false)
        file_name = file_name+".txt";

    ifstream file;
    file.open(file_name);
    if(file.is_open()){
        deque<Word> data,f_data;
        string col1,col2,col3,col4;

        while(!file.eof()){
            getline(file,col1,'|');
            getline(file,col2,'|');
            getline(file,col3,'|');
            getline(file,col4);
            Word w(col1,col2,col3,col4);
            data.push_back(w);
        }
        file.close();
        random_shuffle(data.begin(),data.end());

        if(n==0 || n>=data.size())
            return data;
        else{
            for(int i=0;i<n;i++){
                f_data.push_back(data[i]);
            }
            return f_data;
        }
    }
    else
        cout << "Error: 404";
}
