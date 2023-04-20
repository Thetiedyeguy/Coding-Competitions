#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <cassert>
#include <memory>
#include <queue>
using namespace std;

typedef std::pair<string, int> file;

class Directory{
public:
    Directory(string directoryName, std::weak_ptr<Directory> parent){
        name = directoryName;
        parentDirectory = parent;
    }

    Directory(string directoryName){
        name = directoryName;
        parentDirectory = std::weak_ptr<Directory>();
    }

    int getSize(){
        int size = 0;
        for(auto itr = directories.begin(); itr != directories.end(); ++itr){
            size = size + (*itr)->getSize();
        }
        for(auto itr = files.begin(); itr != files.end(); ++itr){
            size = size + itr->second;
        }
        return size;
    }

    void addDirectory(std::shared_ptr<Directory> addition){
        directories.push_back(addition);
    }

    void addFile(file addition){
        files.push_back(addition);
    }

    void printDirectory(int indents){
        for(int i = 0; i < indents; i++){
            std::cout << " ";
        }
        std::cout << name << "\n";
        for(auto itr = directories.begin(); itr != directories.end(); ++itr){
            (*itr)->printDirectory(indents + 1);
        }
        for(auto itr = files.begin(); itr != files.end(); ++itr){
            for(int i = 0; i < indents + 1; i++){
                std::cout << " ";
            }
            std::cout << (*itr).first << " " << (*itr).second << "\n";
        }
    }
    std::vector<std::shared_ptr<Directory>> directories;
    string name;
    std::weak_ptr<Directory> parentDirectory;

private:
    std::vector<file> files;
};


int main(int argc, char** argv){
    std::ifstream file;
    file.open(argv[1]);
    string line;
    std::vector<string> v;
    std::vector<std::shared_ptr<Directory>> allDirectories;
    bool ls = false;
    std::shared_ptr<Directory> root;
    std::shared_ptr<Directory> currentDirectory;
    root = make_shared<Directory>("/");
    currentDirectory = root;
    allDirectories.push_back(currentDirectory);
    while(getline(file, line)){
        if(line[0] == '$'){
            ls = false;
        }
        if(ls){
            if(line[0] == 'd'){
                std::shared_ptr<Directory> newDirectory = make_shared<Directory>(line.substr(4, line.length() - 5), currentDirectory);
                currentDirectory->addDirectory(newDirectory);
            }else{
                int fSize = stoi(line.substr(0, line.find(" ")));
                string fName = line.substr(line.find(" ") + 1, line.length() - line.find(" ") - 2);
                std::pair<string, int> currentFile;
                currentFile.first = fName;
                currentFile.second = fSize;
                currentDirectory->addFile(currentFile);
            }
        }else{
            string command = line.substr(2, 2);
            if(command == "cd"){
                string location = line.substr(5, line.length() - 6);
                if(location == ".."){
                    v.pop_back();
                    currentDirectory = currentDirectory->parentDirectory.lock();
                }else if(location == "/"){
                    for(int i = 0; i < v.size(); i++){
                        v.pop_back();
                    }
                }else{
                    v.push_back(location);
                    for(auto itr = currentDirectory->directories.begin(); itr != currentDirectory->directories.end(); ++itr){
                        if((*itr)->name == location){
                            currentDirectory = *itr;
                            allDirectories.push_back(currentDirectory);
                            break;
                        }
                    }
                }
            }else if(command == "ls"){
                ls = true;
            }
        }
    }
    int totalSize = 0;
    for(auto itr = allDirectories.begin(); itr != allDirectories.end(); ++itr){
        int currentSize = (*itr)->getSize();
        if(currentSize < 100000){
            totalSize = totalSize + currentSize;
        }
    }
    std::cout << totalSize << "\n";
}
