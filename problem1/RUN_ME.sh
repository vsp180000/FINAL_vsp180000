
#!/bin/bash


gcc -I$HOME/local/gsl-2.5/include question1.c -o test -lgsl -lm -lgslcblas -L$HOME/local/gsl-2.5/lib
