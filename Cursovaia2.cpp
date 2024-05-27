#include "iostream"
#include "string"
#include "cstring"
using namespace std;

struct ExtraInf{
    int Phone=0;
    int BornData=0;
    string Post;
};
class Student{
public:
    string Surname;
    string Name;
    string Patronymic;
    int Estimation[5];
    int Salary;
    struct ExtraInf;
};
int main(int args, char* argv[]){
    bool mode=true;
    for(int i=0; i<args; i++)
        if(_stricmp(argv[i], "false")==0)mode= false;

}