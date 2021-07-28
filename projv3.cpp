#include <iostream>
#include <fstream>
#include "names.cpp"
#include "structs.cpp"
#include "id.cpp"
using namespace std;
int countLines(){
    ifstream count ("names.cpp");
    string line;
    int i;
    while(getline(count,line)){
        i++;
    }
    count.close();
    cout<<i<<endl;
    return i;
}
void createFood(string name){
    int count=countLines();
    ifstream idlist;
    idlist.open("id.cpp");
    string line;
    for(int i=0;i<count;i++){
        getline(idlist,line)
    }
    ofstream namelist;
    namelist.open("names.cpp", ios::app);
    namelist<<count<<".name = \""<<name<<"\"";
    namelist.close();
}

void greeting(){
    string input;
    cout<<"Welcome. Enter '1' to view food database. Enter '2' to add new food."<<endl;
    cin>>input;
    if(input=="2"){
        cout<<"food name?";
        cin>>input;
        createFood(input);
    }
}
void accessfood(string number){
    cout<<"name is "<<number.name<<endl;
}
int main(){
    greeting();
    char number;
    cin>>number;
    accessfood(number);
    return 0;
}