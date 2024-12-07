#include<iostream>
#include<cstdlib>
#include<chrono>
#include<vector>
#include<ctime>
using namespace std;

int randInt(int i, int j) {
    return i + rand() % (j - i + 1);
}

void algorithm1(vector<int> a, int n ){
    srand(time(nullptr));
    
    do
    {
        /* code */
        int j = randInt(0, n-1);
        for (int k = a.size() ; k > 0 ; k-- ){
            if (a[k] == j){
                break;
            }else{
                a.push_back(j);
            }
        }
    } while (a.size()<n);
    
        
}
void algorithm2(vector<int> a,int n){
     srand(time(nullptr));
    vector<int> used ;
    int j = randInt(0,n-1);
}


int main (){

return 0; 
}