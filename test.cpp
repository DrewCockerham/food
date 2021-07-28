#include <iostream>
using namespace std;
struct hello{
    int ball;
};
int main(){
    string array[3]={"ball","bat","humongous"};
    hello what;
    what.ball=3;
    cout<<what.array[0]<<endl;
    return 0;
}