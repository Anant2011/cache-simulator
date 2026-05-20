#include "cachelab.h"
#include  <stdlib.h>
#include  <unistd.h>
#include  <getopt.h>
#include  <stdio.h>

  int hit=0;
  int miss=0;
  int eviction=0;
  int time=0;
   
typedef struct
 {
 int valid;
 unsigned long tag;
 int lru;
 }line_t;
int s,E,b;
int verbose=0; 
line_t **cache;


void accessData(unsigned long address)
{
    unsigned long tag = address >> (s+b);
   
   int set_index = (address >> b) & ((1 << s) -1);
  
   int p;
   for(p=0;p<E;p++) //checking hit
   {
   if(cache[set_index][p].valid && cache[set_index][p].tag == tag)
     {
       hit++;
       if(verbose)
       {
       printf("hit ");
       }
       cache[set_index][p].lru = time++;
       return;
     }
     
   }
   if(p==E)
   {
    miss++;
    if(verbose)
    printf("miss ");
    int i;
    for( i=0;i<E;i++)
     {
       if(cache[set_index][i].valid == 0)
       {
          cache[set_index][i].valid = 1;
          cache[set_index][i].tag=tag;
          cache[set_index][i].lru =time++;
          return;
        } 
      }
    if(i==E)
    {
      eviction++;
      if(verbose)
      printf("eviction ");
      int min = cache[set_index][0].lru;
      int minidx = 0;
      for(int k=1;k<E;k++)
      {
        if(cache[set_index][k].lru < min)
        {
          min = cache[set_index][k].lru;
          minidx = k;
        }
        
      }
      cache[set_index][minidx].valid=1;
      cache[set_index][minidx].tag=tag;
      cache[set_index][minidx].lru=time++;
    
    
    }
   }
    
    
  
}







int main(int argc , char *argv[])
{
  
  char *tracefile;   
  int opt;
while((opt = getopt(argc,argv,"vs:E:b:t:")) !=-1)
{
    switch (opt)
    {
      case 's':
      s = atoi(optarg);
      break;
      case 'E':
      E = atoi(optarg);
      break;
      case 'b':
      b = atoi(optarg);
      break;
      case 't':
      tracefile = optarg;
      break;
      case 'v':
      verbose =1;
      break;
    }
 }    
 
 
 int S= 1<<s ;
 
 
 cache = malloc(S*sizeof(line_t *)); //like array of pointers
 for(int i=0;i<S;i++)
{
  cache[i] = malloc(E*sizeof(line_t));
}
 
 
 for(int i =0 ;i<S;i++)
 {
    for(int j=0;j<E;j++)
    {  
      cache[i][j].valid=0;
      cache[i][j].tag=0;
      cache[i][j].lru=0;
    
    }
 }
 
 FILE *fp = fopen(tracefile,"r");
 
 if(fp==NULL)
{
  return 1;
}

char operation;
unsigned long address;
int size;

while(fscanf(fp," %c %lx,%d",&operation,&address,&size)==3)
{
  if(operation == 'I')
  continue;
  
  if(verbose)
  {
    printf("%c %lx,%d ",operation,address,size);
  }
  accessData(address);
  
  if(operation == 'M')
  accessData(address);
  
  if(verbose)
  {
    printf("\n");
  }
}

fclose(fp);

for(int i=0;i<S;i++)
{
  free(cache[i]);
}
free(cache);

 
 
 
    printSummary(hit, miss, eviction);
    return 0;
}
