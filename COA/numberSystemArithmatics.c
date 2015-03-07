/*
 *========================================================================================================
 *
 *       Filename:  numberSystemArithmatics.c
 *
 *    Description:  This program can be used to perform basic arithmatic in binary number system and converisons.
 *
 *        Version:  1.0
 *        Created:  01/25/2014 03:31:06 PM
 *       Revision:  000
 *       Compiler:  gcc
 *
 *         Author:  Zainul Sayed (zs), zainul.sayed28@gmail.com
 *        Company:  Student@Technology
 *        License:  GNU LESSER GENERAL PUBLIC LICENSE, Version 3, 29 June 2007 (<http://www.gnu.org/licenses/>).

 
 *
 * ======================================================================================================
 */


#include	<stdio.h>
#include	<unistd.h>
#include  	<stdlib.h>
#include      <conio.h>

#define		EXIT_SUCCESS  0		/* This section is for header files and constants in *nix system use Libconio as a substitute .*/
#define          MAX 50

//====================================================================================================
int count=0;
int sub=0;                            /* This section is for global variable declarations   */
int *a,*b,*c,A,Q,q;               
int minus =0;
int two =0;

//====================================================================================================

struct Stack{                           /*Stack start here*/
	int data[MAX];
	int top;
};

void Push(struct Stack *s, int d){
	s->top=s->top+1;				//incrementing the top
	s->data[s->top]=d;			//pushing the data into the stack
}

int Pop(struct Stack *s){
	int d;
	if(s->top == -1){				//Underflow Condition
		printf("\n\t Stack is Underflow");	//if stack is empty
	}
	else{
		d=s->data[s->top];			//popping the data from the stack
		s->top--;				//decrementing the top
		return d;
	}
}


void Display(struct Stack *s){
	int i;
	if(s->top == -1){
		//printf("\n\t Stack is Empty");	
	}
	else{
		for(i=s->top;i>=0;i--){
			printf("%d",s->data[i]);
		}
	}
}
void Initialize(struct Stack *s){
	s->top = -1;
}                                                  /*Stack ends here */


//====================================================================================================
void flush(struct Stack *s){
	s->top=-1;                            /* Since its a menu program the global variable used should not effect other oprations */
	count=0;                              /* therefore all global varibles are cleared for reuse*/
	sub=0;
	two = 0;
	minus=0;
	int i=0;
	for(i=0;i<20;i++);
		a[i]= b[i]=c[i]=0;
}
//====================================================================================================


int main ( int argc, char *argv[] ){
	
	int x,sum,carry;
	struct Stack s;
	Initialize(&s);
	a=(int *)malloc(sizeof(int)*20);
	b=(int *)malloc(sizeof(int)*20);                   /*Dynamic memory allocation is used for n Bits as input  */
	c=(int *)malloc(sizeof(int)*4);                   
	Disclamer();
	while(1)
		menu(&s);
	printf("\n");
	return EXIT_SUCCESS;

}                                                          /*Main ends here */


//==================================================================================================== 

Disclamer(){                 /*This section has been added as a flash screen to inform about shortcommings of this program */
	int j=10;
	system("clear");
	while(j--)
		printf("\n");
printf("=========================================================================~DISCLAMER~=================================================================================== ");
	printf("\n\n\n\t======>>This piece of software is not responsible to SUBRACT two binary numbers of different sizes ,so append ZERO'S to make the length same. \n\t        Eg:54-7 (111010 - 000111).");
	printf("\n\n\n\t======>>To multiply two/one negative numbers first find the TOWS COMPLIMENT using the provided OPTION(i;e option  4).  ");
	printf("\n\n\n\t======>>Add extra 4 bit multiplication to get results correct.");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYOU CAN MODIFY THE CODE TO OVERCOME THE SHORTCOMES...");
	getch();
	system("clear");
}


//====================================================================================================
menu(struct Stack *s){                    /*This is the menu section */
	int ch,e,carry,x;
	sub=0;
	printf("\n################################################# NumberSystemArithmatics ###################################################");
	printf("\n1.Binary Addition \t 2.Binary Subraction \t 3.Decimal-binary \t 4. 2's Compliment \t 5.Binary Multiplication \n 6.Clear \t7.Exit     ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			getBinaryInputs();
			carry= 0;
			for(x=count-1;x>=0;x--){
				carry=full_adder(s,a[x],b[x],carry);                  /* This does the job of addition */ 
			}
			printf("\n");
			printf("%d",carry);                                  /*Printing of carry and sum can be improved */
			Display(s);
			flush(s);
			break;
		case 2:
			sub=1;
			getBinaryInputs();
			twoscompliment(s);
			carry= 0;
			for(x=count-1;x>=0;x--){
				carry=full_adder(s,a[x],b[x],carry);
			}
			if(sub==1 && carry==0){
		
				for(x=0;x<count;x++){
					b[x]=Pop(s);
				}	
				twoscompliment(s);
			}	
			Display(s);
			flush(s);
			break;
		case 3:
			deci_2_bin();
			break;
		case 4:
			two=1;
			minus=1;
			printf("Enter positive binary numbers to get corresponding compliments...");
			getBinaryInputs();
			twoscompliment(s);
			flush(s);
			break;	
		case 5:
			binary_multiplication(s);
			if(c[0]==1){                         /* This line checks if result is negative and then takes the  2's compliment*/
				sub = 1;
				count = Q+1;
				for(x=0;x<=Q;x++)
					b[x]=c[x];
				twoscompliment(s);
				for(x=0;x<=Q;x++){
					c[x]=b[x];
					//printf("%2d",c[x]); 
				}	

			}
			char sign;
			printf("\n\n The result of multiplication by Booths algorithm : (%c)",(sub==1?'-':'+') );  /*Logic to print the sign.*/
			for(x=0;x<=Q;x++)
				printf("%3d ",c[x]);
			getch();
			flush(s);
			break;
		case 6:
			system("clear");
			break;
		case 7:
			exit(0);

		default:
			fprintf(stderr,"\nEnter a valid option...");
			break;
	}
		
}                                           /*Menu ends here*/



//====================================================================================================
//                                                  Booths Algorithm is implemented here 
 
binary_multiplication(struct Stack *s){
	int carry,x,i=0,j;
	getBinaryInputs();
	playWithMarkers();        
	for(j=count;(j>0);){
		if((c[Q]^c[q])==0){
			shiftRight();                            /*As the code is very clear it doesn't require much doc. */
			j--;
			continue;
		}	
		if(c[Q]==0 && c[q]==1){
			carry =0;
			for(x=count-1;x>=0;x--)
				carry=full_adder(s,a[x],c[x],carry);
			printf("\nContent of the Accumulator(A = A+M):");              /*it just have three different states of algorithm*/
			Display(s);
			for(x=0;x<count;x++)
				c[x]=Pop(s);
			shiftRight();
			j--;
			continue;                                             /*For better understanding first refer to Algorithm */
		}	
		if(c[Q]==1 && c[q]==0){
			carry =0;
			for(x=0;x<count;x++)
				b[x]=a[x];
			twoscompliment(s);
			//printf("\nContent of the stack(complimented)");
			//Display(s);
			for(x=count-1;x>=0;x--)
				carry = full_adder(s,b[x],c[x],carry);
			printf("\nContent of the Accumulator(2's comp + add with acc i;e A = A-M):");
			Display(s);

			for(x=0;x<count;x++)
				c[x]=Pop(s);
			shiftRight();
			j--;
			continue;
		}
		
	}	
}

//====================================================================================================

shiftRight(){
	int x,a;
	for(x=q;x>0;x--){                                    //this is shifting logic starting from the end of array 
		c[x] = c[x-1];                              //  the first element is not changed therefore  100101 ~ 110010
	}	
	
	printf("\n The content of A Q q after shifting (>>).");
	a = count;
	for(x=0;x<=q;x++){
		printf("%2d",c[x]);                            
		if(a==1){                                       
			printf("  ");                           /*this is logic whento print the spaces */
			a = count+1;
		}	
		a--;
	}

}
//====================================================================================================
playWithMarkers(){
	int x=0,i=0;
	A=count-1;
	Q=2*A+1;
	q=Q+1;
	for(x=0;x<=q;x++){                                    /*here we used something interesting */
		if(x<=A)            
			c[x]=0;                               /*instead of creating seprate array for ACC Q Q-1 we used only 1 array  */ 
		if(x<=Q && x>A){
			c[x]= b[i];
			i++;                                 /*Here A Q q are used to keep Tab on the locations*/
		}
		if(x==q)
			c[x]=0;
	}
	//printf("\n %d %d %d \n",A,Q,q);
	int a =count;
	printf("\n The content of A Q q :");
	for(x=0;x<=q;x++){
		printf("%d",c[x]);
		if(a==1){
			printf("  ");                  /*this is printing logic  to display illusion as seprately stored array*/
			a = count+1;                   /*When to  give the space is the logic*/
		}
		a--;
	}
}

//=====================================================================================================
getBinaryInputs(){                                                 
	int i,x;
	i=0;                                                    /*Here we take the inputs using getch() */
	int s[50]; 
	getch();                                                /*getch(); takes the input without echoing it on screen */    
	if(two==0){
		printf("\nEnter the first number ");
		while(i<20){
			x=(int)getch();                                  
			if(x==10)                              /*The ASCII value of enter key is 10 */
				break;                         /*If its 10 the it stops taking the input*/
			a[i]=(x==48)?0:1;                      /*Here we convert the ASCII to 0 or 1 */
			printf("%d",a[i]);                      /*48 is the ASCII for 0 so ,we used ternary oprator */
			i++;
		}
	}	
	i=0;
	x=0;
	printf("\nEnter the second number ");
	while(i<20){
		x=(int)getch();
		if(x==10)
			break;
		b[i]=(x==48)?0:1;                                  /*same as above*/
		count++;
		printf("%d",b[i]);
		i++;
	}	

}

//====================================================================================================


twoscompliment(struct Stack *s){
	int carry =1;                                                                    /*carry is intentionally made  1 to add 1 to 2's compliment*/
	int x=0;
	for(x=0;x<count;x++)
		b[x]=(b[x]==0)?1:0;                                                               /*Here we converts  0 to 1*/

	for(x=count-1;x>=0;x--){
		carry = full_adder(s,b[x],0,carry);                                   /*Here we add 1 to the result*/
	}
	printf("\n");
	for(x=0;x<count;x++){
		b[x]=Pop(s);
		if(minus%2!=0)
		printf("%d",b[x]);                                                /*This is a arbitary logic used to decide when to print the result*/
	}
	minus++;
}



//====================================================================================================
//
//                                            This is our main engine to to do all arithmatic.

int full_adder(struct Stack *s,int a,int b,int c){
	int sum,carry,a1,a2,a3;
	sum  = a^b^c;                                                    /*Ex-or operation*/
	a1=a&b;
	a2=a&c;
	a3=b&c;                                                            /*All the anding*/
	carry = a1|a2|a3;
	Push(s,sum);                                                     /*Pushes the result of each bit to stack*/
	return carry;                                                    /*carry is returned and again added to to result*/
}


//====================================================================================================
void deci_2_bin(){
	int i,y[100],z;
	int j = 0;
		printf("\nEnter the decimal number ");
		scanf("%d",&z);
		for(i=z;i>0;i=i/2){
			y[j]=i%2;                                   /*this is our simple decimal  to  binary conversion*/
			j++;                                        /*remainder is presereved at each iteration*/
		}
		j--;
		while(j>=0){
			printf("%d " ,y[j]);
			j--;                                        /*here the result is displayed in the reversed order */
		}printf("\n");
 
}
