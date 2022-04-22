#include <iostream>
#include <string>
#include <fstream> // file library
using namespace std;

int n;
// method declaration
void Coeff(double[],double[],double[]);
double EvalNewton(double[],double[],float);

// driver method
int main(int argc, char** argv){

    // command line arguments
    if(string(argv[1]).find(".pnt")!=string::npos){

        ifstream file; // call read file function
    
        file.open(argv[1]);
        double x;
        while(file>>x){
            n++;
        }
        file.close();

        n/=2;
    
        // Create an empty coefficient vector and initialize arrays and variables
        double cs[n],xs[n],ys[n];
        float z;
        
        int counter = 0;

        file.open(argv[1]);
        double y;
        for(int i = 0; i < n; i++){
            
            file >> y;
            xs[counter] = y;
            counter++;
        }
        
        counter = 0;
        for(int i = n; i < n*2; i++){
            
            file >> y;
            ys[counter] = y;
            counter++;
        }
        file.close();

        cout << "Please enter the point to be evaluated at: x = ";
        cin >> z;
        
        Coeff(xs,ys,cs);
        
        cout << "f(" << z << ") = " << EvalNewton(xs,cs,z);
    }
    
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
