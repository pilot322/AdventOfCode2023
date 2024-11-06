#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <unordered_map>

using namespace std;

int main(){
    ifstream input("input.txt");
    
    int sum_of_ids = 0;
    int max_reds = 12, max_greens = 13, max_blues = 14;
    string line;
    
    // vhma 1. diavase grammh
    getline(input, line);

    line = regex_replace(line, regex(","), "");
    line = regex_replace(line, regex(":"), "");
    line = regex_replace(line, regex(";"), " 0 ;");

    cout << line << endl;

    stringstream s(line);
    string str_buf;

    s >> str_buf; // "Game"

    int id;
    s >> id;
    
    int amount;
    string color;
    string diax;
    while(true){
        s >> amount;
        s >> color;
        s >> diax
    
    }
    
    

    input.close();
     
    return 0;
}
