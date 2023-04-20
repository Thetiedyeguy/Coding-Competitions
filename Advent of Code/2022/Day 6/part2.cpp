#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, char** argv){
    std::ifstream file;
    file.open(argv[1]);
    string line;
    while(getline(file, line)){
        for(int i = 13; i < line.length(); i++){
            string currentString = line.substr(i - 13, 14);
            bool unique = true;
            for(int a = 0; a < currentString.length(); a++){
                for(int b = 0; b < currentString.length(); b++){
                    if(a != b && currentString[a] == currentString[b]){
                        unique = false;
                    }
                }
            }
            if(unique){
                std::cout << i + 1 << "\n";
                break;
            }
        }
    }
}
