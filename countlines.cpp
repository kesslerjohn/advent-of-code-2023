#include <iostream>
#include <string>

using namespace std;

int main(){
    int count = 0;
    for (string line; getline(cin, line);){
        count++;
    }
    cout << to_string(count) << endl;
    return 0;
}