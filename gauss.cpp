#include "tenet_64.hpp"
#include <stdio.h>


using namespace std;


int main (void){

	int n (3);
	double_st A[n][n] = {{-1, 1.0 , 1}, {2, -1, 3}, {-1, 2, 5}};
	double_st B[n] = {1, 2, 4};
	double_st c, tmp;
	int p = 0;
	
	/*
		=========================================
						Affichage
		=========================================
	*/
	printf("Initial Matrix A is:\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j< n; j++){
			
			printf("%e\t", A[i][j].get_a());
			A[i][j].set_mode(1);
			A[i][j].change_state(1);
		}
		printf("\n");
	}
	
	printf("\nInitial Matrix B is:\n");
	for(int i = 0; i < n; i++){
		
		printf("%e\t", B[i].get_a());
	}
	printf("\n");
	/*
		=========================================
				Echelonnage et Réduction
		=========================================
	*/
	for(int i = 0; i < n; i++) {
		p = i;
		for(int k = (i + 1); k < n; k++){

			if (abs(A[k][i]) > abs (A[p][i])){
				p = k;
			}
		}
		if(p != i){
			permute(B[i], B[p]);
			for(int k = 0; k < n; k++){
				permute(A[i][k], A[p][k]);	
			}
		}
    	for(int j = 0; j < n; j++) {
        	if(i != j) {
            	c = A[j][i]/A[i][i];
				B[j] -= c * B[i];
            	for(int k = 0; k < n; k++) { 
               		A[j][k] -= c * A[i][k];
            	}
         	}
       	}
    }
	for(int i =  0; i < n; i++){
		B[i] /= A[i][i];
		A[i][i] /= A[i][i];
	}

	/*
		=========================================
						Affichage
		=========================================
	*/
	printf("\n\nFinal Matrix A is:\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j< n; j++){
			
			printf("%e\t", A[i][j].get_a());
			A[i][j].set_mode(0);
		}
		printf("\n");
	}
   	cout<<"\nThe solution is:\n";
   	for(int i = 0; i < n; i++) {
		B[i].set_mode(2);
      	cout<<"x("<<i << ") = "<<B[i].get_a()<<", ";
   	}

    printf("\n");

	
	return 0;
}
