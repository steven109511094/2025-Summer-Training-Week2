#include <bits/stdc++.h>

using namespace std;

#define PAT_NUM 50000
#define MIN_DATA -50000
#define MAX_DATA 50000

enum class Op_Type{
    Push = 40,
    Pop = 80,
    Get = 95,
    Empty = 100
};

int main(){
    ofstream fout1("testcase/myStack/3.in");
    ofstream fout2("testcase/myQueue/3.in");

    uint op_type;
    int data;

    for(uint pat_i = 0; pat_i < PAT_NUM; pat_i++){
        op_type = rand() % 100;

        if(op_type < (uint)Op_Type::Push){
            data = rand() % (MAX_DATA - MIN_DATA + 1) + MIN_DATA;
            fout1 << "push " << data << endl;
            fout2 << "push " << data << endl;
            continue;
        }
        
        if(op_type < (uint)Op_Type::Pop){
            fout1 << "pop"<< endl;
            fout2 << "pop"<< endl;
            continue;
        }

        if(op_type < (uint)Op_Type::Get){
            fout1 << "top"<< endl;
            fout2 << "front"<< endl;
            continue;
        }

        if(op_type < (uint)Op_Type::Empty){
            fout1 << "empty"<< endl;
            fout2 << "empty"<< endl;
            continue;
        }
    }

    fout1.close();
    fout2.close();
}