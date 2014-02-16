/*
 *     	Pointers.c
 *
 *  	Created on: July 22, 2013
 *      Author: SayedZainulAbideen
 


		  GNU LESSER GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it willc be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.



*............................................PREPROCESSOR HEADERS
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//#include<curses.h>	......................install ncurses in your  system
#include<conio.h>

/*
 *............................................PROTOTYPES DECLARATION
 * */
int SumOfDigit(int *,int);
int SortItOut(int *,int);
int Search(int *,int);
/*
*.............................................GLOBAL VARIABLES DECLARATION
 * */
int *ptr,i,n,s,z,turn=3;
char *username="zainul";
char *passwd="pass4free";
int sortflag=0;
/*
 *............................................MAIN STARTS HERE
 * */
int main(){
	char c ='n';
	Authentication();
	printf("\nEnter The Number Of Elements::");
	scanf("%d",&n);
	ptr =(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		printf("\nEnter the  %d element::",i+1);
		scanf("%d",ptr+i);
	}
	printf("\nElements entered by u  are\n");
	for(i=0;i<n;i++)
		printf("\t %d",*(ptr+i));
	//printf("%d",*(ptr+4));
	while(1){
		clrscr();
		printf("\nEnter the choice of operation to be performed::");
		printf("\n1.Sum of Elements \t2.Largest Element \n3.Smallest         \t4.Search a element");
		scanf("%d",&s);
		switch(s){
			case 1:
				SumOfDigit(ptr,n);
				break;
			case 2:
				if(sortflag==0)
					SortItOut(ptr,n);
				z=n;
				z-=1;
				printf("\n The larhest element is::%d",*(ptr+z));
				break;
			case 3:
				if(sortflag==0)
					SortItOut(ptr,n);
				z=0;
				printf("\nThe Smallest element is::%d",*(ptr+z));
				break;
			case 4:
				if(sortflag==0)
					SortItOut(ptr,n);
				Search(ptr,n);
				break;
			default :
				printf("\nEnter the Correct choice!!!!!!!!!!!!!");
				break;
		}
		printf("\nIf you want to continue press y else n\n");
		scanf("%s",&c);
		if(c=='n'||c=='N')
			break;
	}
	printf("\n\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!BYE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
}

/*
 *..........................................Declaration of Engines/Methods starts here
 *
 *...........................................AUTHENTICATION MODULE
 * */
Authentication(){
	char *u,*p,*q,t;
	printf("\n\n testing  size of  u before malloc %d ",sizeof(u));
	p =(char *)malloc(sizeof(char)*15);
	u =(char *)malloc(sizeof(char)*15);
        printf("\n\n testing  size of  u after malloc %d ",sizeof(u));

	int i;
	do{
		i=0;
		t=0;
		printf("\nEnter your credentials\nusername\n");
		while(i<15){
			t=(int)getch();	
			if(t==10)
				break;	
			u[i]=(char *)t;
			printf("%c",u[i]);
			i++;
			}
		printf("\n%s\n",u);
		getch();
		i=0;
		t=0;
		printf("\npassword (max length should be 15 characters)\n");
		getch();
		while(i<15){
			t=(int)getch();
			if(t==10)
				break;
			p[i]=(char *)t;
			printf("*");
			i++;
			}
		/*printf("\n%s\n",p);
		//printf("\n %s \n%s",(char *)u,(char *)p);*/
		if((*u!=*username) || (*p!=*passwd)){
			turn-=1;
			printf("Number of turns remaining is %d",turn);
			if(turn==0){
				printf("\n\nSystem is going down(Dectected malicious actions) your actions will be reported to the admin");
				getch();
				system("exit");
				break;
				}
			}
		else {
			printf("\nAuthenticated user\n%s welcome to codeDuniya ",username);
			break;
		}
	
	   }while(1);
}

/*
..........................................SUM OF DIGITS
*/
int SumOfDigit(int *ptr,int n){
	int sum=0,i;
	for( i=0;i<n;i++)
		sum+=*(ptr+i);
printf("\nSum of all elements are %d ::",sum);
	return 0;

}
/*
 *.......................................SORTING FUNTION
 *
 * */

int SortItOut(int *ptr,int n){
	int tmp,i,j;
	for( i=0;i<n-1;i++)
		for( j=0;j<n-1-i;j++){
			if(*(ptr+j)>*(ptr+(j+1))){
				tmp=*(ptr+j);
				*(ptr+j)=*(ptr+(j+1));
				*(ptr+(j+1))=tmp;
			}

		}
	sortflag=1;

	return 0;
}
/*
 *.....................................BINARY SEARCH ENGINE
 * */
int Search(int *ptr,int n){
	int first,last,middle,a,s;
	first=0;
	last=n;
	middle=(first+last)/2;
	printf("Enter a element to be searched   ");
	scanf("%d",&s);
	while(first<=last){

		if(ptr[middle]<s)
			first=middle+1;
		 else if (ptr[middle]==s){
			printf("\nElement %d found at location %d ",s,middle);
			break;
		}
		else
		last= middle-1;
		
		middle=(first+last)/2;
	}
	return 0;
}

