#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <dirent.h>

#include "QueueByStack.h"

using namespace std;

//===========================================//
//  You can't modify anything in this file.  //
//===========================================//

int main(){
    // Check input folder path
    string inputFolderName = "testcase/myQueue";
    string outputFolderName = "output/myQueue";
    struct dirent *entry;
    DIR *dp = opendir(inputFolderName.c_str());
    if (dp == NULL) {
        cout << "Please check your the path of testcase folder!!!!!" << endl;
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

        QueueByStack* myQueue = new QueueByStack();

        cout << "Running " << inputFileName << "..." << endl;
        string line;
        while(getline(fin, line)){
            istringstream iss(line);
            string token;
            int data;
            iss >> token;

            if(token == "push"){
                iss >> data;
                myQueue->push(data);
                continue;
            }

            if(token == "pop"){
                if(!myQueue->pop()) fout << "You can't pop the front element beacause the queue is empty!!!!!" << endl;
                continue;
            }

            if(token == "front"){
                if(myQueue->front() == INT_MIN) fout << "You can't get the front element beacause the queue is empty!!!!!" << endl;
                else fout << myQueue->front() << endl;
                continue;
            }

            if(token == "empty"){
                if(myQueue->empty()) fout << "The queue is empty!!!!!" << endl;
                else fout << "The queue is not empty!!!!!" << endl;
                continue;
            }
        }

        fin.close();
        fout.close();
        delete myQueue;
    }
}