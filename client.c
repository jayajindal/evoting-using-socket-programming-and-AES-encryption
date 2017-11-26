#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stream[1000],stream1[1000];
void new_user()
{
    
    int a=1;
    //File handling
      FILE *filepointer1 = fopen("program.txt", "w"); //temp file
      if (filepointer1 == NULL)
      {
          printf("Could not open file newuser.txt"); 
      }
      
      
        //interface  
            printf("\n Welcome to the new user registration portal. Please Enter the following Details. \n ");
            printf(" ");
               // fgets(stream,50,stdin);
                fprintf(filepointer1,"%d\n",a);
            printf("Full Name: ");
                fgets(stream,50,stdin);  //flush the stream before continuing frwrd
                fprintf(filepointer1,"%s",stream);
            printf("\nDate of Birth(dd/mm/yyyy): ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s",stream);
            printf("\ncontact(10 digit): ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s",stream);
            printf("\nAadhaar Card number(12 digits): ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s",stream);
            printf("Voter-ID number: (10 digts)");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s",stream);
      
            printf("\n Username: ");
		fgets(stream,16,stdin);
            fprintf(filepointer1,"%s",stream);
            printf("\tPassword: ");
		fgets(stream,16,stdin);
            fprintf(filepointer1,"%s",stream);
        fclose(filepointer1);

        //send this file to server
        
        
}

void existing_user()
{
	//int b=2;
        FILE *filepointer3 = fopen("program.txt", "w"); //temp file
        //login
        char username[50],password[50];
           // fprintf(filepointer3,"%d\n",b);
            printf("\n Welcome back to the E-Voting portal. Please login to continue. \n ");
            printf("\t Username: ");
            scanf("%s",username);
	    printf("\n\t Password: ");
            scanf("%s",password);
            fprintf(filepointer3,"%s\n",username);
            fprintf(filepointer3,"%s\n",password);
        
        fclose(filepointer3);

}
vote_ornot()
{
	char c; int m;
	char a[]="raj singh", b[]="prakash singh", d[]="non of these"; 
	FILE *fp,*fp1;
	fp=fopen("aut.txt","r");
	fp1=fopen("program.txt","w");
	c=getc(fp);
	switch(c)
	{
		case '1' :
			printf("not autenticate voter");
			break;
		case '2' :
			printf("vote for your contituency\n");
			printf(" 1. raj singh \n 2. prakash singh \n 3. none of these \n");
			scanf("%d",&m);
			if(m == 1)
					fprintf(fp1,"%s\n",a);
			else if(m == 2)
					fprintf(fp1,"%s\n",b);
		 	else if(m == 3)
					fprintf(fp1,"%s",d);
			else
				printf("wrong choice");
	}
}

int main()
{
    int choice; 
    printf("Welcome to the E-Voting System\n");
    
    printf("Please choose from the following options: \n \b 1. New User \t 2. Existing User\n :"); 
    scanf("%d",&choice);
    getchar();
    switch (choice){
	case 1:
		new_user();
		break;
	case 2:
		existing_user();
		vote_ornot();
		break;
	default:
		printf("enter valid choice");
		break;
}
return 0;
}

