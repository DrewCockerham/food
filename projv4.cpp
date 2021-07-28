#include <iostream>
#include <fstream>
using namespace std;
struct food{
    string name;
    double protein;
    double carbs;
    double fiber;
    double sugar;
};
int count(string *files,int fileNo){
    int counts[fileNo];
    for(int i=0;i<fileNo;i++){
        string line;
        ifstream counting;
        counting.open(files[i]);
        counts[i]=0;
        do{
            getline(counting,line);
            if(line!=""){
                counts[i]++;
            }
        } while(!counting.eof());
        counting.close();
    }
    for(int i=fileNo-1;i>0;i--){
        if(counts[i]-counts[i-1]!=0){
            return -1;
        }
    }
    return counts[0];
}
/*void nameCrt(food *p,int size){
    string line;
    ifstream read;
    read.open("names.txt");
    for(int i=0;i<size;i++){
        getline(read,line);
        if(line!=""){
            p[i].name=line;
        }
    }
    read.close();
}
void protCrt(food *p,int size){
    string line;
    ifstream read;
    read.open("protein.txt");
    for(int i=0;i<size;i++){
        getline(read,line);
        if(line!=""){
            double n=stod(line);
            p[i].protein=n;
        }
    }
    read.close();
}
void crbCrt(food *p,int size){
    string line;
    ifstream read;
    read.open("carbs.txt");
    for(int i=0;i<size;i++){
        getline(read,line);
        if(line!=""){
            double n=stod(line);
            p[i].carbs=n;
        }
    }
    read.close();
}
void fbrCrt(food *p,int size){
    string line;
    ifstream read;
    read.open("fiber.txt");
    for(int i=0;i<size;i++){
        getline(read,line);
        if(line!=""){
            double n=stod(line);
            p[i].fiber=n;
        }
    }
    read.close();
}
void sgrCrt(food *p,int size){
    string line;
    ifstream read;
    read.open("sugar.txt");
    for(int i=0;i<size;i++){
        getline(read,line);
        if(line!=""){
            double n=stod(line);
            p[i].sugar=n;
        }
    }
    read.close();
}*/
void arrayCrt(food *p,int size,string* files,int fileNo){
    for(int i=0;i<fileNo;i++){
        string line;
        ifstream read;
        read.open(files[i]);
        for(int n=0;n<size;n++){
            getline(read,line);
            if(line!=""){
                if(i==0){
                    p[n].name=line;
                }
                else{
                    double d=stod(line);
                    if(i==1){p[n].protein=d;}
                    if(i==2){p[n].carbs=d;}
                    if(i==3){p[n].fiber=d;}
                    if(i==4){p[n].sugar=d;}
                }
            }
        }
        read.close();
    }
}
/*void arrayCreate(food *p,int size){
    nameCrt(p,size);
    protCrt(p,size);
    crbCrt(p,size);
    fbrCrt(p,size);
    sgrCrt(p,size);
}*/
void attrList(food*foodArray,int size){
    for(int i=0;i<size;i++){
        cout<<foodArray[i].name<<":\n\tprotein: "<<foodArray[i].protein<<" g\n\tsugar: "<<foodArray[i].sugar
            <<" g\n\tfiber: "<<foodArray[i].fiber<<" g\n\tother carbs: "<<foodArray[i].carbs<<" g\n";
    }
}
/*string* itemInput(int fileNo){
    string array[fileNo];
    string input;
    cout<<"enter item name:\n";
    cin>>input;
    array[0]=input;
    cout<<"enter protein in grams:\n";
    cin>>input;
    array[1]=input;
    cout<<"enter carbs in grams:\n";
    cin>>input;
    array[2]=input;
    cout<<"enter fiber in grams:\n";
    cin>>input;
    array[3]=input;
    cout<<"enter sugar in grams:\n";
    cin>>input;
    array[4]=input;
    return array;
}*/
/*void itemCrt(string* array,){
//unfinished
}*/
int main(){
    string files[5]={"names.txt","protein.txt","carbs.txt","fiber.txt","sugar.txt"};
    int fileNo=sizeof(files)/sizeof(*files);
    int totalItems=count(files,fileNo);
    if(totalItems==-1){
        cerr<<"files must contain equal number of items"<<endl;
        exit(0);
    }
    if(totalItems==0){
        cout<<"The food database is empty. Would you like to add a new item? y/n"<<endl;
        string input;
        cin>>input;
        if(input=="y"){
            //newItem();
        }
    }
    food foodArray[totalItems];
    //arrayCreate(foodArray,totalItems);
    arrayCrt(foodArray,totalItems,files,fileNo);
    attrList(foodArray,totalItems);
    return 0;
}