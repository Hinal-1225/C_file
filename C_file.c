#include<stdio.h>
#include<stdlib.h>
int main()
{
    system("cls");
    char name[20],ch,c;
    int i,pos;
	FILE* fp1;
	FILE* fp2;
	//write in file
	fp1=fopen("1_file.txt","w");
	printf("\nEnter your name = ");
	scanf("%s",name);
	fprintf(fp1,"\n%s\n",name);
	fclose(fp1);
	//read file to display content in reverse order
	fp1=fopen("1_file.txt","r");
	if(fp1==NULL)
    {
        printf("\nFile does not exist");
    }
    fseek(fp1,0,SEEK_END);
    pos=ftell(fp1);
    i=0;
    printf("\nreverse order");
    while(i<pos)
    {
        i++;
        fseek(fp1,-i,SEEK_END);
        ch=fgetc(fp1);
        printf("%c",ch);
    }
    // open a file for writing
    fp2=fopen("2_copied_file.txt","w");
    //coping one file to another
	c=fgetc(fp1);
	while(c != EOF)
    {
        fputc(c,fp2);
        c=fgetc(fp1);
    }
    printf("\n File copied to another file");
    fclose(fp1);
    fclose(fp2);

    system("pause");
	return 10;
}
