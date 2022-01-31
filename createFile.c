/* 
Student Name: Connor Sparkman
Student NetID: cps260 
Compiler Used: Linux CMD
Program Description: Program takes in input from a user. Uses this input or default to generate random numbers, perform calculations, and turn into byte, writing bytes to file and reading back.
! SOME CODE WAS WRITTEN BY ME IN PREVIOUS OPERATING SYSTEMS COURSE. PLESE EMAIL ME QUESTIONS ABOUT HOW I CAME UP WITH CODE AND I'LL GLADLY RESPOND! 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

union {
    unsigned int number;
    unsigned char byte[4];
} bytes;

// function to turn val into 4 bytes and write into file 2 of 4 bytes
void buffer(int value, char *argv[]){

// open file to write
int fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);

// check for error
if (fd < 0) {
perror("open");
exit(1);
}

// create char array
char arr[12];

// asign arr 0-3 values
arr[0] = (value >> 24) & 0xFF;
arr[1] = (value >> 16) & 0xFF;
arr[2] = (value >> 8) & 0xFF;
arr[3] = value & 0xFF;

bytes.number = value;
arr[8] = bytes.byte[3];
arr[9] = bytes.byte[2];
arr[10] = bytes.byte[1];
arr[11] = bytes.byte[0];

// write to file
int rc = write(fd, bytes.byte, sizeof(bytes));
// close file
(void) close(fd);


// open file to read
    int fdr = open(argv[1], O_RDONLY);

// check for error
    if (fdr < 0) {
	perror("open");
	exit(1);
    }

// read file until EOF
    while (1) {	
	int rc;
	rc = read(fdr, bytes.byte, sizeof(bytes));
	if (rc == 0) // 0 indicates EOF
	    break;
	if (rc < 0) {
	    perror("read");
	    exit(1);
	}
	
	// print out first 2 bytes, ignore other 2
	printf("%u %u\n", bytes.byte[1],bytes.byte[0]);
    }
    
// close file
(void) close(fd);
}

// random number generator 1-100
int rng(){
        int b = rand() % (100 + 1 - 0) +0;
        return b;
	}

// offset and other calculations
int offset(int val){
        double offset = ((double)rand()/RAND_MAX*1.0) -0.5; 
        double add = val + offset; 
        int addhund = add * 100;
	return addhund;
        }


int main(int argc, char *argv[])
{  

// make sure correct number of args
    if(argc == 0 || argc == 2 || argc == 4 || argc == 5 || argc > 6){
    printf("Too few arguments.\n");
    exit(0);
    } 
    
    // seed time for rand
    srand ( time(NULL) );

    // 1 argument given
    if(argc == 1)
    {       
    	
    	// default filename
    	argv[1] = "flowData.dat";
    	
    	// default number of runs
    	int conv = 60;
    	for(int count; count < conv; count++){
    
        // random number 1-100
        int b = rng();
        	
    	// high
    	if(b >= 85)
    	{
    	   // default high number
    	   int val1 = 15;
    	   
    	   // do calculations
    	   int val = offset(val1);
    	   
    	   // turn into 4 bytes and then output 2 bytes
           buffer(val, argv);
    	}
    	
    	// low
    	if(b <= 15)
    	{
    	   // default low number
    	   int val1 = 5;
    	   
    	   // do calculations
    	   int val = offset(val1);
    	   
    	    // turn into 4 bytes and then output 2 bytes
           buffer(val, argv);
    	}
    	// middle
	if( b > 15 && b < 85 )
	{
	      // default middle number
              int val1 = 10;
              
              // do calculations
              int val = offset(val1);
              
              // turn into 4 bytes and then output 2 bytes
              buffer(val, argv);
    	}
    }
}
    
    // 3 arguments given
    if(argc == 3)
    {       
    
       // get number of runs
    	long conv = strtol(argv[2], NULL, 10);
    	
    	
    	for(int count; count < conv; count++){
    	
    	// get random number 1-100
    	int b = rng();  
          	
    	// high
    	if(b >= 85)
    	{
    	
          // default high value
    	   int val1 = 15; 
    	   
    	   // do calculations
    	   int val = offset(val1);
    	   
    	   // turn into 4 bytes and then output 2 bytes
           buffer(val, argv);
    	}
    	
    	// low
    	if(b <= 15)
    	{
    	
    	   // default low value
    	   int val1 = 5;
    	   
    	   // do calculations
    	   int val = offset(val1);
    	   
    	   // turn into 4 bytes and then output 2 bytes
           buffer(val, argv);
    	}
    	// middle
	if( b > 15 && b < 85 )
	{
	
	   // default middle value
           int val1 = 10;
           
           // do calculations
    	   int val = offset(val1);
    	   
    	   // turn into 4 bytes and then output 2 bytes
           buffer(val, argv);
    	}
    }
}

	// 6 arguments given
	if (argc == 6){
	
	// get number of runs
    	long conv = strtol(argv[2], NULL, 10);
    	
    	for(int count; count < conv; count++){
    	
    	// get random number 1-100
    	int b = rng();  
          	
    	// high
    	if(b >= 85)
    	{  
    	   
    	   // get high value
    	   long val1  = strtol(argv[5], NULL, 10);
    	   
    	   // get calculations
    	   int val = offset(val1);
    	   
    	   // turn into 4 bytes and then output 2 bytes
           buffer(val, argv);
    	}
    	
    	// low
    	if(b <= 15)
    	{
    	
    	   // get low value
     	   long val1  = strtol(argv[3], NULL, 10);
     	   
     	   // do calculations
    	   int val = offset(val1);
    	   
    	   // turn into 4 bytes and then output 2 bytes
           buffer(val, argv);  
    	}
    	// midle
	if( b > 15 && b < 85 )
	{
	
	    // get middle value
    	    long val1  = strtol(argv[4], NULL, 10);
    	    
    	    // do calculations
    	    int val = offset(val1);
    	    
    	    // turn into 4 bytes and then output 2 bytes
           buffer(val, argv);
    	}
    }
}

    return 0;
}
