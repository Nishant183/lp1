#include <stdlib.h>   
#include <stdio.h>    
#include <omp.h>      

#define ARRAY_SIZE 8     
#define NUM_THREADS 4   

int main (int argc, char *argv[]) 
{
	int * a;
	int * b; 
	int * c;
        
        int n = ARRAY_SIZE;                 
	int n_per_thread;                   
	int total_threads = NUM_THREADS;    
	int i;      
        
        a = (int *) malloc(sizeof(int)*n);
	b = (int *) malloc(sizeof(int)*n);
	c = (int *) malloc(sizeof(int)*n);

        for(i=0; i<n; i++) {
            a[i] = i;
        }
        for(i=0; i<n; i++) {
            b[i] = i;
        }   
        
	omp_set_num_threads(total_threads);
	
	n_per_thread = n/total_threads;
	
        #pragma omp parallel for shared(a, b, c) private(i) schedule(static, n_per_thread)
        for(i=0; i<n; i++) {
		c[i] = a[i]+b[i];
		printf("Thread-%d element-%d\n", omp_get_thread_num(), i);
        }
	
	//printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
        for(i=0; i<n; i++) {
		printf("%d\t+\t%d\t=\t%d\n", a[i], b[i], c[i]);
        }
	
        // clean up memory
        free(a);  free(b); free(c);
	
	return 0;
}


/*output

Thread-0 element-0
Thread-0 element-1
Thread-2 element-4
Thread-2 element-5
Thread-1 element-2
Thread-1 element-3
Thread-3 element-6
Thread-3 element-7

0	+	0	=	0
1	+	1	=	2
2	+	2	=	4
3	+	3	=	6
4	+	4	=	8
5	+	5	=	10
6	+	6	=	12
7	+	7	=	14

*/
