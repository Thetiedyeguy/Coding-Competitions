#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
std::vector<string> s;


void PrintStack(stack<char> s){
    if (s.empty())
    return;


    char x = s.top();

    // Pop the top element of the stack
    s.pop();

    // Recursively call the function PrintStack
    PrintStack(s);

    // Print the stack element starting
    // from the bottom
    cout << x << " ";

    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

int main(int argc, char** argv){
    std::ifstream file;
    file.open(argv[1]);
    string line;
    int numStacks = 0;
    bool beginning = true;
    std::vector<std::stack<char>> v;
    while(getline(file, line)){
        if(line.length() == 1){
            beginning = false;
            for(int i = 0; i < numStacks; i++){
                v[i].pop();
            }
            for(int i = 0; i < numStacks; i++){
                stack<char> temp;
                while(v[i].empty() == false){
                    temp.push(v[i].top());
                    v[i].pop();
                }
                v[i] = temp;
            }
        }else{
            if(beginning){
                if(numStacks == 0){
                    numStacks = (line.length() + 1) / 4;
                    for(int i = 0; i < numStacks; i++){
                        std::stack<char> u;
                        v.push_back(u);
                    }
                }
                for(int i = 0; i < numStacks; i++){
                    char currentChar = line[1 + (4 * i)];
                    if(currentChar != ' '){
                        v[i].push(currentChar);
                    }
                }
            }else{
                for(int i = 0; i < numStacks; i++){
                    std::cout << (i + 1) << " ";
                    PrintStack(v[i]);
                    std::cout << "\n";
                }
                std::cout << "\n\n";
                string delimiter = " ";
                int start = 0;
                int end = line.find(delimiter);
                while(end != -1){
                    s.push_back(line.substr(start, end - start));
                    start = end + delimiter.size();
                    end = line.find(delimiter, start);
                }
                s.push_back(line.substr(start, end - start));
                size_t moveAmount = stoi(s[1]);
                size_t from = stoi(s[3]) - 1;
                size_t to = stoi(s[5]) - 1;
                std::cout << moveAmount << " " << from << " " << to << "\n\n";
                s.clear();
                stack<char> temp;
                for(int a = 0; a < moveAmount; a++){
                    temp.push(v[from].top());
                    v[from].pop();
                }
                for(int a = 0; a < moveAmount; a++){
                    v[to].push(temp.top());
                    temp.pop();
                }
            }
        }
    }
    for(int i = 0; i < numStacks; i++){
        std::cout << (i + 1) << " ";
        PrintStack(v[i]);
        std::cout << "\n";
    }
}
