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
            if(line!=""){counts[i]++;}
        }while(!counting.eof());
        counting.close();
    }
    for(int i=fileNo-1;i>0;i--){
        if(counts[i]-counts[i-1]!=0){return -1;}
    }
    return counts[0];
}
void arrayCrt(food *p, int size, string* files,int fileNo){
    for(int i=0;i<fileNo;i++){
        string line;
        ifstream read;
        read.open(files[i]);
        for(int n=0;n<size;n++){
            getline(read,line);
            if(line!=""){
                if(i==0){p[n].name=line;}
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
void addItem(string* files,int fileNo, string* newFood, int* no, food* foodArray){
    (*no)++;
    delete[] foodArray;
    foodArray=new food[(*no)];
    for(int i=0;i<fileNo;i++){
        ofstream write;
        write.open(files[i], std::fstream::in | std::fstream::out | std::fstream::app);
        write << newFood[i] << endl;
        write.close();
    }
}
void arrayRd(food* foodArray, int size){
    cout << "top of read" << endl;
    cout << foodArray << " size = " << size << endl;
    for(int i=0;i<size;i++){
        cout<<foodArray[i].name<<" "<<foodArray[i].protein<<" "<<foodArray[i].carbs<<" "<<foodArray[i].fiber<<" "<<foodArray[i].sugar<<endl;
    }
    cout << "after loop" << endl;
    cout<<endl;
}

void erase(string* files, int fileNo, int* no, food* foodArray){
    std::cout << "here" << std::endl;
    *no = 0;
    cout << "there" << std::endl;
    cout<<foodArray<<endl;
    if(foodArray==NULL){
        cout<<"good"<<endl;
    }
    delete[] foodArray;
    foodArray=new food[1];
    foodArray[1].name="null";
    foodArray[1].protein=0;
    foodArray[1].carbs=0;
    foodArray[1].fiber=0;
    foodArray[1].sugar=0;
    for(int i=0;i<fileNo;i++){
        ofstream erase;
        erase.open(files[i], std::ofstream::out | std::ofstream::trunc);
        erase.close();
    }
}


int main(){
    string files[5]={"names.txt","protein.txt","carbs.txt","fiber.txt","sugar.txt"};
    int fileNo=sizeof(files)/sizeof(*files);
    int totalItems=count(files,fileNo);
    cout << "one" << endl;
    food* foodArray=new food[totalItems];
    arrayCrt(foodArray,totalItems,files,fileNo);
    string newFood[5]= {"burger","15","15","15","10"};
    //arrayRd(foodArray,totalItems);
    cout << "two" << endl;
    addItem(files,fileNo,newFood,&totalItems,foodArray);
    cout << "three" << endl;
    arrayCrt(foodArray,totalItems,files,fileNo);
    cout << "four" << endl;

    //arrayRd(foodArray,totalItems);
    cout << "five" << endl;
    //cout << foodArray << endl;
    cout << "calling erase" << endl;
   erase(files,fileNo,&totalItems,foodArray);
   cout << "six" << endl;
    //arrayRd(foodArray,totalItems);

    return 0;
}