#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <dirent.h>

#include "LinkedList.h"

int main(){
    // Check input folder path
    string inputFolderName = "testcase";
    string outputFolderName = "output";
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

        LinkedList* myLinkedList = new LinkedList();
        LinkedList::Iterator it;

        cout << "Running " << inputFileName << "..." << endl;
        string line;
        while(getline(fin, line)){
            istringstream iss(line);
            string token;
            int data;
            uint pos;
            iss >> token;

            if(token == "push_back"){
                iss >> data;
                myLinkedList->push_back(data);
                continue;
            }

            if(token == "pop_back"){
                if(!myLinkedList->pop_back()) fout << "You can't pop the back element beacause the linked list is empty!!!!!" << endl;
                continue;
            }

            if(token == "insert"){
                iss >> pos >> data;
                it = myLinkedList->begin();
                for(uint i = 0; i < pos; i++)
                    ++it;
                myLinkedList->insert(it, data);
                continue;
            }

            if(token == "erase"){
                iss >> pos;
                it = myLinkedList->begin();
                for(uint i = 0; i < pos; i++)
                    ++it;
                if(!myLinkedList->erase(it)) fout << "You can't erase the element on the position because there is no element!!!!!" << endl;
                continue;
            }

            if(token == "front"){
                if(myLinkedList->front() == INT_MIN) fout << "You can't get the front element beacause the linked list is empty!!!!!" << endl;
                else fout << myLinkedList->front() << endl;
                continue;
            }

            if(token == "back"){
                if(myLinkedList->back() == INT_MIN) fout << "You can't get the back element beacause the linked list is empty!!!!!" << endl;
                else fout << myLinkedList->back() << endl;
                continue;
            }

            if(token == "print"){
                if(myLinkedList->empty()) fout << "You can't print any element beacause the linked list is empty!!!!!" << endl;
                else{ 
                    for(it = myLinkedList->begin(); it != myLinkedList->end(); ++it)
                        fout << *it << " "; 
                    fout << endl;
                }
                continue;
            }

            if(token == "print_r"){
                if(myLinkedList->empty()) fout << "You can't print any element beacause the linked list is empty!!!!!" << endl;
                else{ 
                    for(it = myLinkedList->rbegin(); it != myLinkedList->rend(); --it)
                        fout << *it << " "; 
                    fout << endl;
                }
                continue;
            }

            if(token == "empty"){
                if(myLinkedList->empty()) fout << "The linked list is empty!!!!!" << endl;
                else fout << "The linked list is not empty!!!!!" << endl;
                continue;
            }

            if(token == "sort"){
                myLinkedList->sort();
                continue;
            }
        }

        fin.close();
        fout.close();
        delete myLinkedList;
    }
    return 0;
}