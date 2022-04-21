#include<iostream>
#include<vector>
using namespace std;

int n = 5;
// method declaration
void Coeff(vector<double>,vector<double>,vector<double>);
double EvalNewton(vector<double>,vector<double>,float);

// driver method
int main(){
    // Create an empty coefficient vector
    vector<double> cs;
    vector<double> xs;
    vector<double> ys;
    float z;
    
    xs.push_back(3);
    xs.push_back(1);
    xs.push_back(0);
    xs.push_back(4);
    xs.push_back(7);

    ys.push_back(1);
    ys.push_back(0.12);
    ys.push_back(-0.3);
    ys.push_back(2);
    ys.push_back(2.5);

    Coeff(xs,ys,cs);
    EvalNewton(xs,cs,z);
}

void Coeff(vector<double> xs,vector<double> ys, vector<double> cs){
    for(int i = 0; i <n;i++){
        cs[i] = ys[i];
    }

    for(int j = 1; j < n; j++){
        for(int i = n; i >= j; i--){
            cs[i] = (cs[i]-cs[i-1])/(xs[i]-xs[i-j]);
        }
    }
}

double EvalNewton(vector<double> xs, vector<double> cs, float z){
    double result = cs[n];

    for(int i = n-1; i >= 0; i--){
        result = result *(z-xs[i])+cs[i];
    }

    return result;
}
