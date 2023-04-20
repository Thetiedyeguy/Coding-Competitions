#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    std::ifstream file;
    file.open(argv[1]);
    int current = 0;
    int max = 0;
    string line;
    while(getline(file, line)){
        if(line.length() == 1){
            if(current > max){
                max = current;
            }
            current = 0;
        }else{
            current = current + stoi(line);
        }
    }
    std::cout << max << "\n";
}
