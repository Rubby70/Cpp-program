#include "iostream"
#include "student.h"
using namespace std;

float student_test::bmi(){

    return weight/(height*height);

}
void student_test::set_number(float w, float h){

    weight = w;
    height = h;

}