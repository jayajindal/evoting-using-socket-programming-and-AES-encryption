#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int a=1, b=2;
	char c,ch,m,ch1,ch2;
	FILE *fd, *fp, *fp2, *fp3, *fp1, *fp4;
	int loop, i, l1=6,pos;
        char str[512],str2[512],str3[512];
	fp=fopen("master.txt","w");
	fp1=fopen("banja.txt","r");
	fd=fopen("program.txt","r");
	fp4=fopen("aut.txt","w");
	c=getc(fd);
	switch(c)
	{
		case '1' :
			fseek(fd, 0L, SEEK_END);
			pos=ftell(fd);
			fseek(fd, 0L, SEEK_SET);
			while(pos--)
			{
				ch=fgetc(fd);
				fputc(ch,fp);
			}
			
			break;
		default :
			ch1=fgetc(fp1);
			ch2=fgetc(fd);
			while((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2))
			{
				ch1=getc(fp1);
				ch2=getc(fd);	
			}
			if(ch1 != ch2)
			{	fprintf(fp4,"%d\n",a);	printf("error"); }	
			if(ch1 == ch2)
			{	fprintf(fp4,"%d\n",b); printf("identical");}
			break;	
	}
fclose(fd);
fclose(fp);
fclose(fp1);
fclose(fp4);
/*fp2=fopen("banja.txt","w");
fp3=fopen("master.txt","r");
if (fp3 == NULL) {
        printf("Failed to open file\n");
        return -1;
    }
while(!feof(fp3))
{
        for(i= 0;i<l1;i++)
	{
           	fgets(str, sizeof(str), fp3);  
        }
	fputs(str,fp2);
}
fclose(fp3);		
fclose(fp2);*/
return 0;
}
