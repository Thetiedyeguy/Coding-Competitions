#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    std::ifstream file;
    file.open(argv[1]);
    string line;
    int count = 0;
    while(getline(file, line)){
        string first = line.substr(0, line.find(","));
        string second = line.substr(line.find(",") + 1, line.length() - line.find(","));
        int firstFirst = stoi(first.substr(0, first.find("-")));
        int firstSecond = stoi(first.substr(first.find("-") + 1, first.length() - first.find("-")));
        int secondFirst = stoi(second.substr(0, second.find("-")));
        int secondSecond = stoi(second.substr(second.find("-") + 1, second.length() - second.find("-")));
        int firstMax;
        int firstMin;
        int secondMax;
        int secondMin;
        if(firstFirst > firstSecond){
            firstMax = firstFirst;
            firstMin = firstSecond;
        }else{
            firstMax = firstSecond;
            firstMin = firstFirst;
        }
        if(secondFirst > secondSecond){
            secondMax = secondFirst;
            secondMin = secondSecond;
        }else{
            secondMax = secondSecond;
            secondMin = secondFirst;
        }
        std::cout << firstMin << " " << firstMax << " " << secondMin << " " << secondMax << "\n";
        if((firstMin <= secondMin && firstMax >= secondMax) || (secondMin <= firstMin && secondMax >= firstMax)){
            count++;
            std::cout << "\n\n";
        }
    }
    std::cout << count << "\n";
}
