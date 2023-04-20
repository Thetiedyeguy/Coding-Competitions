#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    std::ifstream file;
    file.open(argv[1]);
    string line;
    int score = 0;
    while(getline(file, line)){
        char theirMove = line[0];
        char myMove = line[2];
        std::cout << theirMove << " " << myMove << "  " << score << "\n";
        if(myMove == 'X'){
            score = score + 1;
            if(theirMove == 'A'){
                score = score + 3;
            }else if(theirMove == 'C'){
                score = score + 6;
            }
        }else if(myMove == 'Y'){
            score = score + 2;
            if(theirMove == 'B'){
                score = score + 3;
            }else if(theirMove == 'A'){
                score = score + 6;
            }
        }else if(myMove == 'Z'){
            score = score + 3;
            if(theirMove == 'C'){
                score = score + 3;
            }else if(theirMove == 'B'){
                score = score + 6;
            }
        }else{
            std::cout << "not working\n";
        }
        std::cout << score << "\n\n";
    }
    std::cout << score << "\n";
}
