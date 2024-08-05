#include "iostream"
#include "student.h"
using namespace std;

int main(){

    student_test X;
    X.set_number(60, 1.7);
    cout << X.bmi() << "\n";

}