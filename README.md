# Interpolation_Polynomial

newtonMethodGivenFile.cpp is used to compute Newton's interpolation. It should take as input a file in th command line that contains the data points in the following format:

x0  x1  x2  ...  xn

y0  y1  y2  ...  yn

that is, the first rows contains the first element of each data point, and the next row the second one. After processing the input, the program will provide a prompt asking of a value to be used to evaluate the polynomial and print the result of such evaluation, going back to the prompt. Entering 'q' instead of a real number will exit the program. Use your program to with the example in the exercises above to check your solution.


The other program takes a positive integer 'n' as input the produces a random data set file with 'n' points, in the format of the previous exercise. Use this program to create data sets with 10, 100, and 1000 points and run your program with these data sets. Evaluate at random points. The time it takes to compute interpolation and evaluate in each instance is reported.

Compilation:


For newtonMethodGivenFile.cpp

g++ newtonMethodGivenFile.cpp -o a.out

./a.out [filename]


For the other one,

g++ newtonMethodRandom.cpp -o a.out

./a.out
