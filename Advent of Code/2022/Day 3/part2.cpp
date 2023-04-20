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
    string first;
    string second;
    int pass = 0;
    while(getline(file, line)){
        if((pass % 3) == 0){
            first = "";
            second = "";
            for(int i = 0; i < line.length(); i++){
                first = first + line[i];
            }
        }else if((pass % 3) == 1){
            for(int i = 0; i < line.length(); i++){
                second = second + line[i];
            }
        }else{
            for(int i = 0; i < line.length(); i++){
                int isIn1 = first.find(line[i]);
                int isIn2 = second.find(line[i]);
                std::cout << line[i] << " " << isIn1 << " " << isIn2 << "\n";
                if(isIn1 != -1 && isIn2 != -1){
                    priority = priority + letters.find(line[i]) + 1;
                    break;
                }
            }
        }
        std::cout << pass % 3 << "\n";
        pass++;
    }
    std::cout << priority << "\n";
}
