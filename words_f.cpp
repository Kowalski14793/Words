#include "words_f.h"


bool check(string *res,Word s,int n){
    int good_counter=0;
    string answer_tab[3] = {s.get_eng1(),s.get_eng2(),s.get_eng3()};

    for(int i=0;i<3;i++){

        int j=0;
        for(int k=0;k<n;k++){
            if(answer_tab[i].length()!=res[k].length())
                continue;
            bool flag = true;
            while(res[k][j]!='\0'){

                if(answer_tab[i][j] != res[k][j]){
                    flag = false;
                    break;
                }
                j++;
            }
            if(flag == true){
                if(n==3 && i==k){
                    good_counter++;
                }
                else if(n==1)
                    good_counter++;
            }
            if(good_counter>=n)
                return 0;
        }
    }
    return 1;
}



deque<Word> get_data_from(string file_name){

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
        deque<Word> data;
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
        return data;
    }
    else
        cout << "Error: 404";
}


