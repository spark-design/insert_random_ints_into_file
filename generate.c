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
# define NUMRECS (24)

typedef struct __rec_t {
    unsigned int key;
    unsigned int record[NUMRECS];
} rec_t;

union test {
    int x, y;
};

void usage(char *prog) 
{
    fprintf(stderr, "usage: %s <-s random seed> <-n number of records> <-o output file>\n", prog);
    exit(1);
}

int rng(){
        int b = rand() % (100 + 1 - 0) +0;
        return b;
	}

int offset(int val){
	printf("value: %d\n", val);
	int val2 = val * 100;
	printf("value * 100: %d\n", val2);
        double offset = ((double)rand()/RAND_MAX*1.0) -0.5; 
        printf("offset: %f\n", offset);
        int offset2 = offset * 100;
        printf("offset * 100: %d\n", offset2);
        int multiplied = val2 + offset2;
	return multiplied;
        }

int main(int argc, char *argv[])
{  
   
    // program assumes a 4-byte key in a 100-byte record
    assert(sizeof(rec_t) == 100);

    // arguments
    // generate an integer and convert it
    int recordsLeft = 0;
    char *outFile   = "/no/such/file";

    if(argc == 0 || argc == 2 || argc == 4 || argc == 5 || argc > 6){
    printf("Too few arguments.\n");
    exit(0);
    } 
    
    rec_t r;
    srand ( time(NULL) );

    if(argc == 1)
    {       
    	printf("1 argument given. \n");
    	
    	int conv = 3;
    	for(int count; count < conv; count++){
    
        int b = rng();	
    	// high
    	if(b >= 85)
    	{
    	   printf("big, %d\n", b);
    	   int val = 15;
    	   int multiplied = offset(val);
           printf("truncated number: %d\n\n", multiplied);
    	}
    	
    	// low
    	if(b <= 15)
    	{
    	   printf("small, %d\n", b);
    	   int val = 5;
    	   int multiplied = offset(val);
           printf("truncated number: %d\n\n", multiplied);
    	}
    	// midle
	if( b > 15 && b < 85 )
	{
              printf("middle, %d\n", b);
              int val = 10;
              int multiplied = offset(val);
              printf("truncated number: %d\n\n", multiplied);
    	}
    }
}
    
    if(argc == 3)
    {       
    	printf("3 arguments given. \n");
    	
        int fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
        if (fd < 0) {
	perror("open");
	exit(1);
        }
	printf("file: %s\n", argv[1]);
	
	
    	long conv = strtol(argv[2], NULL, 10);
    	for(int count; count < conv; count++){

    	int b = rng();  
          	
    	// high
    	if(b >= 85)
    	{
    	   printf("big %d\n", b);
    	   int val = 15; 
    	   int multiplied = offset(val);
           printf("truncated number: %d\n\n", multiplied);
    	}
    	
    	// low
    	if(b <= 15)
    	{
    	   printf("small %d\n", b);
    	   int val = 5;
    	   int multiplied = offset(val);
           printf("truncated number: %d\n\n", multiplied);
    	}
    	// middle
	if( b > 15 && b < 85 )
	{
           printf("middle %d\n", b);
           int val = 10;
    	   int multiplied = offset(val);
           printf("truncated number: %d\n\n", multiplied);  
    	}
    }
}

	
	if(argc == 6){
	    	printf("6 arguments given. \n");
    	
        int fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
        if (fd < 0) {
	perror("open");
	exit(1);
        }
	printf("file: %s\n", argv[1]);
       int val;
	
	
    	long conv = strtol(argv[2], NULL, 10);
    	for(int count; count < conv; count++){
    	int b = rng();  
          	
    	// high
    	if(b >= 85)
    	{
    	   printf("big, %d\n", b);
    	   long val  = strtol(argv[5], NULL, 10);
    	   int multiplied = offset(val);
           printf("truncated number: %d\n\n", multiplied);  
    	}
    	
    	// low
    	if(b <= 15)
    	{
    	   printf("small, %d\n", b);
     	   long val  = strtol(argv[3], NULL, 10);
    	   int multiplied = offset(val);
           printf("truncated number: %d\n\n", multiplied);  
    	}
    	// midle
	if( b > 15 && b < 85 )
	{
            printf("middle, %d\n", b);
    	    long val  = strtol(argv[4], NULL, 10);
    	    int multiplied = offset(val);
           printf("truncated number: %d\n\n", multiplied);  
    	}
    }
}


    // A union variable t
    union test t;
  
    t.x = 2; // t.y also gets value 2
    printf("After making x = 2:\n x = %d, y = %d\n\n",
           t.x, t.y);
  
    t.y = 10; // t.x is also updated to 10
    printf("After making y = 10:\n x = %d, y = %d\n\n",
           t.x, t.y);
           
           
   if(strcmp(argv[2],"me")==0)
   {
   printf("me"); 
   }
   /*
    // input params
    int c;
    opterr = 0;
    while ((c = getopt(argc, argv, "n:s:o:")) != -1) {
	switch (c) {
	case 'n':
	    recordsLeft = atoi(optarg);
	    break;
	case 's':
	    randomSeed  = atoi(optarg);
	    break;
	case 'o':
	    outFile     = strdup(optarg);
	    break;
	default:
	    usage(argv[0]);
	}
    }

    printf("Invalid input. \n");
    printf("Acceptable inputs: \n");
    printf("createFile \n");
    printf("createFile <filename> <number> \n");
    printf("createFile <filename> <numbers> <low value> <middle value> <high value>\n"); 
    
    // seed random number generator

    // open and create output file

    int fd = open(outFile, O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
    if (fd < 0) {
	perror("open");
	exit(1);
    }

    int i;
    for (i = 0; i < recordsLeft; i++) {
	// fill in random key
	r.key = (rand() % (100 - 0 + 1)) + 0;
	// fill in random rest of records
	int j;
	for (j = 0; j < NUMRECS; j++) {
	    r.record[j] = (rand() % (10 - 0 + 1)) + 0;
	}

	int rc = write(fd, &r, sizeof(rec_t));
	if (rc != sizeof(rec_t)) {
	    perror("write");
	    exit(1);
	    // should probably remove file here but ...
	}
    }
    

    // ok to ignore error code here, because we're done anyhow...
    (void) close(fd);
    */

    return 0;
}
