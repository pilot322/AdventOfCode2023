#include <iostream>
#include <fstream>
using namespace std;

int first_digit(string &buf){
    for(int i = 0; i < buf.length(); i++){
        if(buf[i] >= '0' && buf[i] <= '9'){
            return buf[i] - '0';
        }
    }
    return 0;
}

int last_digit(string &buf){
    for(int i = buf.length()-1; i >= 0; i--){
        if(buf[i] >= '0' && buf[i] <= '9'){
            return buf[i] - '0';
        }
    } 
        
    return 0;
}

int main(){
    ifstream input("input.txt");
    string buf;
    
    int sum = 0;
        
    while(getline(input, buf)){
        // find first digit
        //
        int n = first_digit(buf) * 10 + last_digit(buf);
        cout << n << endl;
        sum += n;
    }
    
    input.close();

    cout << sum << endl;
}
