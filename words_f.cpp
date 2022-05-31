#include "words_f.h"


bool check(string *odp,Word s,int n){
    cout << endl << odp[n-1];
    int good_counter=0;
    string tab_p[3] = {s.get_eng1(),s.get_eng2(),s.get_eng3()};

    for(int i=0;i<3;i++){

        int j=0;
        for(int k=0;k<n;k++){
            bool flaga = true;
            while(odp[k][j]!='\0'){

                if(tab_p[i][j] != odp[k][j]){
                    flaga = false;
                    break;
                }
                j++;
            }
            if(flaga == true)
                good_counter++;
            if(good_counter>=n)
                return 0;
        }

    }
    return 1;
}



vector<Word> get_data_from(string file_name){

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
        vector<Word> data;
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
        return data;
    }
    else
        cout << "Error: 404";
}


