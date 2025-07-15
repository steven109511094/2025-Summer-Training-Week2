#include <bits/stdc++.h>

using namespace std;

#define PAT_NUM     10000
#define MIN_DATA    -50000
#define MAX_DATA    50000
#define OVER_RANGE  110
#define DEBUG_FLAG  false   // After each push_back, pop_back, insert, erase and sort operation is executed,
                            // print and print_r will be executed for checking the connection of all elements.

enum class Op_Type{
    Push_Back = 30,
    Pop_Back = 60,
    Insert = 70,
    Erase = 80,
    Front = 85,
    Back = 90,
    Print = 93,
    Print_R = 96,
    Empty = 98,
    Sort = 100
};

int main(){
    ofstream fout("testcase/5.in");

    uint op_type;
    int data;
    uint pos;
    uint size = 0;

    for(uint pat_i = 0; pat_i < PAT_NUM; pat_i++){
        op_type = rand() % 100;

        if(op_type < (uint)Op_Type::Push_Back){
            data = rand() % (MAX_DATA - MIN_DATA + 1) + MIN_DATA;
            fout << "push_back " << data << endl;
            if(DEBUG_FLAG) fout << "print" << endl;
            if(DEBUG_FLAG) fout << "print_r" << endl;
            size++;
            continue;
        }
        
        if(op_type < (uint)Op_Type::Pop_Back){
            fout << "pop_back " << endl;
            if(DEBUG_FLAG) fout << "print" << endl;
            if(DEBUG_FLAG) fout << "print_r" << endl;
            if(size > 0) size--;
            continue;
        }

        if(op_type < (uint)Op_Type::Insert){
            data = rand() % (MAX_DATA - MIN_DATA + 1) + MIN_DATA;
            pos = (size == 0) ? 0 : rand() % (size * OVER_RANGE / 100);
            fout << "insert " << pos << " " << data << endl;
            if(DEBUG_FLAG) fout << "print" << endl;
            if(DEBUG_FLAG) fout << "print_r" << endl;
            size++;
            continue;
        }
        if(op_type < (uint)Op_Type::Erase){
            pos = (size == 0) ? 0 : rand() % (size * OVER_RANGE / 100);
            fout << "erase " << pos << endl;
            if(DEBUG_FLAG) fout << "print" << endl;
            if(DEBUG_FLAG) fout << "print_r" << endl;
            if(pos < size && size > 0) size--;
            continue;
        }

        if(op_type < (uint)Op_Type::Front){
            fout << "front" << endl;
            continue;
        }

        if(op_type < (uint)Op_Type::Back){
            fout << "back" << endl;
            continue;
        }

        if(op_type < (uint)Op_Type::Print){
            fout << "print" << endl;
            continue;
        }

        if(op_type < (uint)Op_Type::Print_R){
            fout << "print_r" << endl;
            continue;
        }

        if(op_type < (uint)Op_Type::Empty){
            fout << "empty" << endl;
            continue;
        }

        if(op_type < (uint)Op_Type::Sort){
            fout << "sort" << endl;
            if(DEBUG_FLAG) fout << "print" << endl;
            if(DEBUG_FLAG) fout << "print_r" << endl;
            continue;
        }
    }

    fout.close();
}