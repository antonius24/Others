#include<stdio.h>
#include<strings.h>
#include<malloc.h>

int val[2][2][2];

FILE *fpin, *fpout;

main(argc, argv)
int argc;
char **argv;

{
char line[100];
int c1, c2, c3;
//char *c1_file, *c2_file, *c3_file;

int ia,ib,ic;
int output;

//c1_file = (char *)malloc(sizeof(char));
//c2_file = (char *)malloc(sizeof(char));
//c3_file = (char *)malloc(sizeof(char));


if(open_files(argc, argv)==0){
   exit(-1);}

  while(freadline(fpin, line)!=EOF){
     int temp;
     sscanf(line, "%d%d%d%d", &c1, &c2, &c3, &temp);
     val[c1][c2][c3] = temp;
     printf("%d %d %d %d \n", c1, c2, c3, val[c1][c2][c3]);

   }

   fpout=fopen("HigherTruthTable.txt","w");

  for (ia=0;ia<=2;ia++)
 {
  c1=ia;
  for(ib=0;ib<=2;ib++)
  {
   c2=ib;
   for(ic=0;ic<=2;ic++)
   {
     c3=ic;
     printf("before: %d, %d, %d\n", c1, c2, c3);
     output=ComputeHigherValuedTable(c1, c2, c3);
     
     if (c1==2)
       fprintf(fpout, "x ");
     else
       fprintf(fpout, "%d ", c1);

     if (c2==2)
       fprintf(fpout, "x ");
     else
       fprintf(fpout, "%d ", c2);

     if (c3==2)
       fprintf(fpout, "x ");
     else
       fprintf(fpout, "%d ", c3);

     if (output==2)
       fprintf(fpout, "x \n");
     else
     {
       printf("output: %d\n", output);
       fprintf(fpout, "%d \n", output);
     }
   }
 }
}
}




int ComputeHigherValuedTable(int c1, int c2, int c3)
{
int outval;
int ia, ib,ic;
int last_val;

if((c1!=2)&(c2!=2)&(c3!=2))
{
  printf("c1, c2, c3: %d, %d, %d\n", c1, c2, c3);
  outval=val[c1][c2][c3];
  printf("outval: %d\n", outval);
}
else if ((c1==2)&(c2!=2)&(c3!=2))
{
if (val[1][c2][c3]==val[0][c2][c3])
outval=val[0][c2][c3];
else outval=2;
}

else if ((c2==2)&(c1!=2)&(c3!=2))
{
if (val[c1][0][c3]==val[c1][1][c3])
outval=val[c1][0][c3];
else outval=2;
}

else if ((c3==2)&(c1!=2)&(c2!=2))
{
if (val[c1][c2][0]==val[c1][c2][1])
outval=val[c1][c2][0];
else outval=2;
}

else if ((c1==2)&(c2==2)&(c3!=2))
{
	if((val[0][0][c3]==val[0][1][c3])&(val[0][1][c3]==val[1][0][c3])&(val[1][0][c3]==val[1][1][c3])&(val[0][0][c3]==val[1][1][c3]))
	outval=val[0][0][c3];
	else
	outval=2;
}

else if ((c1==2)&(c2!=2)&(c3==2))
{
	if((val[0][c2][0]==val[0][c2][1])&(val[0][c2][1]==val[1][c2][0])&(val[1][c2][0]==val[1][c2][1])&(val[0][c1][0]==val[0][c2][1]))
	outval=val[0][c2][0];
	else
	outval=2;
}

else if ((c1!=2)&(c2==2)&(c3==2))
{
	if((val[c1][0][0]==val[c1][0][1])&(val[c1][0][1]==val[c1][1][0])&(val[c1][1][0]==val[c1][1][1])&(val[c1][0][0]==val[c1][1][1]))
	outval=val[c1][0][0];
	else
	outval=2;
}

else
{
  //outval=2;

for (ia=0;ia<=1;ia++)
{
c1=ia;
for(ib=0;ib<=1;ib++)
{
c2=ib;
for(ic=0;ic<=1;ic++){
c3=ic;

 if(val[0][0][0]!=val[c1][c2][c3])
 return 2;
}
}
}
return val[0][0][0];

}
return outval;
}


int open_files(numstrngs, strngs)
int numstrngs;
char **strngs;
{
if(numstrngs!=2){
        fprintf(stdout, "Usage: %s input-file-name\n", strngs[0]);
        return(0);
}
if((fpin= fopen(strngs[1], "r"))== NULL){
  fprintf(stdout, "ERROR: can't open file %s for reading\n", strngs[1]);
  fprintf(stderr, "ERROR: can't open file %s for reading\n", strngs[1]);
  return(0);
}
return(1);

}





readline(char *str)
{
int i=0;
char ch;

while(scanf("%c", &ch)!=EOF){
   if(ch!='\n'){
	str[i]=ch;
	i++;
   }
   else{
	str[i]= '\0';
	return(1);
   }
}
return(EOF);
}

freadline(fp, str)
FILE *fp;
char *str;
{
  int i=0;
  char ch;

  while(fscanf(fp, "%c", &ch)!=EOF){
      if(ch!='\n'){
	   str[i]=ch;
	   i++;
   }
   else{
	   str[i]= '\0';
	   return(1);
   }
  }
  return(EOF);
}
