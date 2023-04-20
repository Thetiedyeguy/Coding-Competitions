#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <cassert>
#include <memory>
#include <queue>
using namespace std;

int main(int argc, char** argv){
    std::ifstream file;
    file.open(argv[1]);
    string line;
    std::vector<std::vector<int>> v;
    while(getline(file, line)){
        std::vector<int> u;
        for(int i = 0; i < line.length() - 1; i++){
            u.push_back(int(line[i] - '0'));
        }
        v.push_back(u);
    }
    int count = 0;
    std::vector<std::vector<bool>> vb;
    for(int i = 0; i < v.size(); i++){
        std::vector<bool> ub;
        for(int a = 0; a < v[i].size(); a++){
            ub.push_back(false);
        }
        vb.push_back(ub);
    }
    int columnLength = v[0].size();
    for(int i = 0; i < v.size(); i++){
        int tallest1 = -1;
        int tallest2 = -1;
        for(int a = 0; a < columnLength; a++){
            if(tallest1 == 9 && tallest2 == 9){
                break;
            }
            if(tallest1 < 9){
                if(v[i][a] > tallest1){
                    tallest1 = v[i][a];
                    vb[i][a] = true;
                }
            }
            if(tallest2 < 9){
                if(v[i][columnLength - a - 1] > tallest2){
                    tallest2 = v[i][columnLength - a - 1];
                    vb[i][columnLength - a - 1] = true;
                }
            }
        }
    }
    int rowLength = v.size();
    for(int i = 0; i < columnLength; i++){
        int tallest3 = -1;
        int tallest4 = -1;
        for(int a = 0; a < rowLength; a++){
            if(tallest3 == 9 && tallest4 == 9){
                break;
            }
            if(tallest3 < 9){
                if(v[a][i] > tallest3){
                    tallest3 = v[a][i];
                    vb[a][i] = true;
                }
            }
            if(tallest4 < 9){
                if(v[rowLength - a - 1][i] > tallest4){
                    tallest4 = v[rowLength - a - 1][i];
                    vb[rowLength - a - 1][i] = true;
                }
            }
        }
    }
    int totalCount = 0;
    for(int i = 0; i < vb.size(); i++){
        for(int a = 0; a < vb[i].size(); a++){
            if(vb[i][a]){
                count++;
                std::cout << "1";
            }else{
                std::cout << "0";
            }
            totalCount++;
        }
        std::cout << "\n";
    }
    std::cout << totalCount << " " << count << "\n";
}
