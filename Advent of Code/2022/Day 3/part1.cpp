#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    std::ifstream file;
    file.open(argv[1]);
    string line;
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int priority = 0;
    while(getline(file, line)){
        string firstHalf;
        string secondHalf;
        std::cout << priority << "\n";
        for(int i = 0; i < line.length()/2; i++){
            std::cout << line[i];
            firstHalf = firstHalf + line[i];
        }
        std::cout << "\n";
        for(int i = line.length()/2; i < line.length(); i++){
            std::cout << line[i];
            int isIn1 = firstHalf.find(line[i]);
            int isIn2 = secondHalf.find(line[i]);
            if(isIn1 != -1 && isIn2 == -1){
                std::cout << "1";
                secondHalf = secondHalf + line[i];
                priority = priority + letters.find(line[i]) + 1;
            }
        }
        std::cout << "\n";
        std::cout << priority << "\n\n";
    }
    std::cout << priority << "\n";
}
