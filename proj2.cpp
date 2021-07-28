#include <iostream>
#include <fstream>
#include "foodItem.h"
#include  "functions.h"
using namespace std;
int main(){
    foodItem 1;
    1.name="hello";
    string input;
    int position;
    do{
        cout<<"enter food name:\n";
        cin>>input;
        if(input=="exit"){
            return 1;
        }
        position=count(input);
        if(position==-1){
            cout<<"no item found.\n";
        }
        if(position==-2){
            cerr<<"error";
            return 1;
        }
    } while (position==-1);
    cout<<input<<" found in position "<<position<<endl;
    cout<<"create new food item?\n";
    string input2;
    cin>>input2;
    if(input2=="yes"){
        addFood(position, input);
        cout<<"done\n";
    }
    else{
        cout<<"Goodbye.\n";
        return 0;
    }
}

int count (string input){
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
            return -1;
        }
    return -2;
}
void addFood(int n, string name){
    ofstream header;
    header.open("foodItem.h",ios::app);
        if(header.is_open()){
            header<<endl<<"foodItem "<<n<<";    "<<n<<".name="<<name<<";";
            header.close();
            return;
        }
        else{
            cerr<<"Error! could not open foodItem.h";
            return;
        }
}