#include <iostream>
#include <string>
#include "food_item.h"
#include "itemList.cpp"
using namespace std;
string lookup(string input);
int main(){
    cout<<"Welcome.\nWhat would you like to do?";
    string input;
    string null="null";
    cin>>input;
    int position=lookup(input);
    
}
int lookup(string input){
    string line;
    ifstream names;
    names.open("nameList.txt");
        if(names.is_open()){
            int n=0;
            while(getline(names,line)){
                if(line==input){
                    names.close();
                    return n;
                }
                n++;
            }
            names.close();
            cout<<"no item found\n";
            return -1;
        }
    cout<<"error";
    return -1;
}

