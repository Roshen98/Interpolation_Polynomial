#include <iostream>
#include <string>
#include <fstream> // file library
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
#include <iomanip>
using namespace std;

// global variables
int MIN = 0;
int MAX = 1000;
int n;

// method declaration
void Coeff(double[],double[],double[]);
double EvalNewton(double[],double[],float);

// driver method
int main(){
    
    

    /* initialize random seed: */
    srand (time(NULL));

    cout << "Please enter the size of the random data: ";
    cin >> n;

    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> distr(MIN, MAX);

    ofstream file;
    file.open("Random.pnt");
    for(int i = 0; i < n; i++){
        file << distr(eng) << " ";
    }

    file << "\n";

    for(int i = 0; i < n; i++){
        file << distr(eng) << " ";
    }
    file.close();

    
}

void Coeff(double xs[n+1] , double ys[n+1], double cs[n+1]){
    for(int i = 0; i <=n;i++){
        cs[i] = ys[i];
    }

    for(int j = 1; j <= n; j++){
        for(int i = n; i >= j; i--){
            cs[i] = (cs[i]-cs[i-1])/(xs[i]-xs[i-j]);
        }
    }
}

double EvalNewton(double xs[n+1], double cs[n+1] , float z){
    double result = cs[n-1];

    for(int i = n-2; i >= 0; i--){
        result = result *(z-xs[i])+cs[i];
    }

    return result;
}
