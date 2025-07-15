#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <dirent.h>
#include "Stack.h"

using namespace std;

//===========================================//
//  You can't modify anything in this file.  //
//===========================================//

int main(){
    // Check input folder path
    string inputFolderName = "testcase/myStack";
    string outputFolderName = "output/myStack";
    struct dirent *entry;
    DIR *dp = opendir(inputFolderName.c_str());
    if (dp == NULL) {
        cout << "Please check your the path of testcase folder!" << endl;
        exit(1);
    }

    // Store all .in files as input
    vector<string> fileNames;
    while ((entry = readdir(dp))){
        string fileName = string(entry->d_name);
        if(fileName.find(".in") == string::npos) continue;
        fileNames.push_back(fileName);
    }
    closedir(dp);

    // Start execution
    ifstream fin;
    ofstream fout;
    for(string fileName : fileNames){
        string inputFileName = inputFolderName + "/" + fileName;
        fin.open(inputFileName);
        if(!fin.is_open()){
            cout << "Open " << inputFileName << " failed!!!!!" << endl;
            exit(1);
        }

        size_t pos = fileName.find(".in");
        fileName.replace(pos, 3, ".out");
        string outputFileName = outputFolderName + "/" + fileName;
        fout.open(outputFileName);
        if(!fout.is_open()){
            cout << "Open " << outputFileName << " failed!!!!!" << endl;
            exit(1);
        }

        Stack* myStack = new Stack();

        cout << "Running " << inputFileName << "..." << endl;
        string line;
        while(getline(fin, line)){
            istringstream iss(line);
            string token;
            int data;
            iss >> token;

            if(token == "push"){
                iss >> data;
                myStack->push(data);
                continue;
            }

            if(token == "pop"){
                if(!myStack->pop()) fout << "You can't pop the top element beacause the stack is empty!!!!!" << endl;
                continue;
            }

            if(token == "top"){
                if(myStack->top() == INT_MIN) fout << "You can't get the top element beacause the stack is empty!!!!!" << endl;
                else fout << myStack->top() << endl;
                continue;
            }

            if(token == "empty"){
                if(myStack->empty()) fout << "The stack is empty!!!!!" << endl;
                else fout << "The stack is not empty!!!!!" << endl;
                continue;
            }
        }

        fin.close();
        fout.close();
        delete myStack;
    }
    return 0;
}