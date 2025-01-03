#include<iostream>
using namespace std;


class DisJointSet{

    private:
        int* rank;
        int* parent;
        int n;
    public:
        DisJointSet(int n){

            this->n = n;
            rank = new int[n];
            parent = new int[n];
            this->initialSet();

        }
        void initialSet(){

            for(int i = 0; i < n; i ++){
                parent[i] = i;
                rank[i] = 1;
            }

        }
        int find(int target){

            if(parent[target] == target)
                return target;
            else{
                parent[target] = find(parent[target]);
                return parent[target];
            }

        };
        void unionS(int target1, int target2){

            int rank1 = rank[find(target1)];
            int rank2 = rank[find(target2)];
            if(rank1 > rank2){
                parent[target2] = parent[target1];
            }
            else if(rank1 == rank2){
                parent[target2] = parent[target1];
                rank[find(target1)] += 1;
            }
            else if(rank1 < rank2){
                parent[target1] = parent[target2];
            }

        };

};

int main(void){

    DisJointSet DJSet(5);
    DJSet.unionS(0, 2);
    DJSet.unionS(4, 2);
    DJSet.unionS(3, 1);

    //cout << DJSet.find(2) << "\n";

    if (DJSet.find(4) == DJSet.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n";
    
    if (DJSet.find(1) == DJSet.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    return 0;

}