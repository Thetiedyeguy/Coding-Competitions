#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    std::ifstream file;
    file.open(argv[1]);
    int current = 0;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    string line;
    while(getline(file, line)){
        if(line.length() == 1){
            if(current > max1){
                max3 = max2;
                max2 = max1;
                max1 = current;
            }else if(current > max2){
                max3 = max2;
                max2 = current;
            }else if(current > max3){
                max3 = current;
            }
            current = 0;
        }else{
            current = current + stoi(line);
        }
    }
    std::cout << max1 << " + " << max2 << " + " << max3 << " = " << max1 + max2 + max3 << "\n";
}
