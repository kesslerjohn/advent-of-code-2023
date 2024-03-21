#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    for (string line; getline(cin, line);){
        cout << line << endl;
    }
    return 0;
}