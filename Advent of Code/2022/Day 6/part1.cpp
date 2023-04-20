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
        for(int i = 3; i < line.length(); i++){
            char first = line[i - 3];
            char second = line[i - 2];
            char third = line[i - 1];
            char fourth = line[i];
            if(first != second && first != third && first != fourth && second != third && second != fourth && third != fourth){
                std::cout << i + 1 << "\n";
                break;
            }
        }
    }
}
