#include <iostream>
#include <string>
#include <fstream> // file library
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
#include <iomanip>
using namespace std;

// global variables
int MIN = -100;
int MAX = 100;
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

    // Create an empty coefficient vector and initialize arrays and variables
    double cs[n],xs[n],ys[n];
    float z;

    // write random points to file
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<double> distr(MIN, MAX);

    ofstream myfile;
    
    myfile.open("Random.pnt");
    
    for(int i = 0; i < n; i++){
        myfile << distr(eng) << " ";
    }

    myfile << "\n";

    for(int i = 0; i < n; i++){
        myfile << distr(eng) << " ";
    }

    myfile.close();

    // read numbers to file
    ifstream file; // call read file function
    file.open("Random.pnt");
    double y = -1;
    int counter = 0;
   
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

    string q;
    bool valid = false;

    while(!valid){
        cout << "Please enter the point to be evaluated at: x = [enter q if you wanted to quit]";
        cin >> q;

        if(q == "q"){
            exit(0);
        }

        else{
            try
            {
                z = stod(q);
                valid = true;
            }
            catch(...)
            {
                cout << "Invalid evluation point entered!" << endl;
            }
                
        }
    }

    clock_t start = clock (); // time starts
        
    Coeff(xs,ys,cs);

    cout << endl;
    // time ends and time taken are calculated
    cout << "Time Taken for Coeff(xs,ys,cs): " << 
            (((float)( clock() - start )) / CLOCKS_PER_SEC)*1000000000 << " nano seconds." << endl;
        

    start = clock ();

    cout << endl;
    cout << "f(" << z << ") = " << EvalNewton(xs,cs,z) << endl;
    cout << endl;

    // time ends and time taken are calculated
    cout << "Time Taken for EvalNewton(xs,cs,z): " << 
            (((float)( clock() - start )) / CLOCKS_PER_SEC)*1000000000 << " nano seconds." << endl;
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
