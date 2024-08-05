#include <iostream>
using namespace std;

class student{

    private:
        float weight;
        float height;
    public:
        float bmi(){
            return weight/(height*height);
        }
        void set(float w, float h){
            weight = w;
            height = h;
        }

};

int main(){

    student X[5];
    X[0].set(70, 1.8);
    X[1].set(80, 1.8);
    cout << X[0].bmi() << "\n";
    cout << X[1].bmi() << "\n";

}