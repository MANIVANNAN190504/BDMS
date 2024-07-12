#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>
void menu(void);
void password(void);
void namefun(void);
void searchfun(void);
void listfun(void);
void modifyfun(void);
void deletefun(void);
void exitfun(void);
void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main(){
	system("color 5");
	password();
	getch();	
}

void namefun(){
	system("cls");
	system("color A");
	gotoxy(30,1);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB GIVE  BLOOD   GIVE LIFE \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(31,4);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB NEW SECTION \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	FILE *fptr;
	char name[100];
	char address[200];
	char gmail[100];
	double phone;
	char gender[8];
	char bg[100];
	char dob[50];
	char age[100];
	fptr=fopen("Donor List.txt","ab+");
	if(fptr==NULL){
		printf("FAILED TO CREATE THE REQUIRED FILE....");
	}
	else{
		gotoxy(31,6);
		printf("NAME:\t");
		gotoxy(55,6);
		gets(name);
		gotoxy(31,7);
		printf("ADDRESS:\t");
		gotoxy(55,7);
		gets(address);
		gotoxy(31,8);
		printf("GENDER:\t");
		gotoxy(55,8);
		gets(gender);
		gotoxy(31,9);
		printf("MAIL ID:\t");
		gotoxy(55,9);
		gets(gmail);
		gotoxy(31,10);
		printf("PHONE NUMBER:");
		gotoxy(55,10);
		scanf("%lf",&phone);
		gotoxy(31,11);
		printf("LAST BLOOD DONATED DATE:\t");
		gotoxy(55,11);
		printf("(DD/MM/YEAR):");
		scanf("%s",&dob);
		gotoxy(31,12);
		printf("DATE OF BIRTH:");
		gotoxy(55,12);
		printf("(DD/MM/YEAR):");
		scanf("%s",&age);
		gotoxy(31,13);
		printf("BLOOD GROUP:\t");
		gotoxy(55,13);
		printf("(A-VE,B+VE,B-VE,O+VE,O-VE,AB+VE,AB-VE,A1+VE):");
		gotoxy(55,14);
		scanf("%s",&bg);
		gotoxy(31,14);
		fprintf(fptr,"%s %s %s %s %s %s %.0lf %s\n",name,address,gender,dob,age,gmail,phone,bg);
	}
	fclose(fptr);
	system("cls");
	char ch;
	gotoxy(31,4);
   	printf("PRESS 'Y' FOR MENU.");
	Sleep(100);
	fflush(stdin);
		while((ch=getch())=='Y')
		{
			menu();
			}
}
void searchfun(){
	system("cls");
	system("color B");
	gotoxy(30,1);
     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB DONATE BLOOD SAVE LIFE \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	FILE *fptr;
	int flag=0;
	int res;
	int f;
	char name[100];
	char address[100];
	char gmail[100];
	double phone;
	char gender[8];
	char bg[100],dob[50];
	char bg1[100];
	int age[100],age1[100];
	char name1[100];
	fflush(stdin);
	gotoxy(31,4);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB ENTER THE BLOOD GROUP YOU WANT TO SEE THE DETAILS:: ");
	gets(bg1);
	fptr=fopen("Donor List.txt","r");
	fflush(stdin);
	while(fscanf(fptr,"%s %s %s %s %s %s %lf %s",name,address,gender,dob,age,gmail,&phone,bg)!=EOF){
			res = strcmp(bg,bg1);
			if(res==0){
		printf("\n");
	    printf("----------------------------------------------");
		printf("\n");
		printf("Name:%s\n",name);
		printf("ADDRESS:%s\n",address);
		printf("GENDER:%s\n",gender);
		printf("DATE OF BIRTH:%s\n",age);
		printf("MAIL ID:%s\n",gmail);
		printf("PHONE NUMBER:%.0lf\n",phone);
	    printf("BLOOD GROUP:%s\n",bg);
		printf("LAST BLOOD DONATED DATE:%s\n",dob);
		printf("\n");
		printf("----------------------------------------------");
        printf("\n");
			}
	}
	if(res>0){
	printf("\n----------------------------------------------\n");
	printf("\n NO RECORD.....\n");
	printf("\n----------------------------------------------\n");
		
	printf("\n");
	printf("PRESS 'Y' FOR MAIN MENU.");
	printf("\n");

	Sleep(1000);
		
		while(getch()=='Y'){
			menu();
		}	
		}
}
void listfun(){
	system("cls");
	system("color 1");
	gotoxy(30,1);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB PROUD TO BE BLOOD DONOR \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");		
	FILE *fptr;
	char name[100],address[100],gmail[100];
	char bg[100],gender[8],dob[50];
	double phone;
	int f;
	char age[100];
	fptr=fopen("Donor List.txt","r");
	gotoxy(31,4);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB LIST SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	printf("\n");
	while(fscanf(fptr,"%s %s %s %s %s %s %lf %s",name,address,gender,dob,age,gmail,&phone,bg)!=EOF){
		
			printf("-----------------------------------------------");
			printf("\n");
		printf("NAME:%s\n",name);
		printf("ADDRESS:%s\n",address);
		printf("GENDER:%s\n",gender);
		printf("DATE OF BIRTH:%s\n",age);
		printf("MAIL ID:%s\n",gmail);
		printf("PHONE NUMBER:%.0lf\n",phone);
		printf("BLOOD GROUP:%s\n",bg);
		printf("LAST BLOOD DONATED DATE:%s\n",dob);
			f=1;
			printf("----------------------------------------------");
		     printf("\n\n");
		}
		printf("PRESS 'Y' FOR MAIN MENU.");
		while(getch()=='Y'){
			menu();
		}
		Sleep(10);
			fclose(fptr);
			}

void modifyfun(){
	system("cls");
	system("color 9");
	gotoxy(30,1);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB SHARE LIFE GIVE BLOOD \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    FILE *fptr,*fptr1;
	char name[100],address[100],gmail[100],gmail1[100],address1[100],name1[100],age[100],age1[100],gender[8],gender1[8],dob[50],dob1[50],bg[100],bg1[100],name3[100];
	int res,f=0,n,r1,r2;
	double phone,phone1;
	fptr=fopen("Donor List.txt","r");
	fptr1=fopen("temp.txt","a");
	gotoxy(31,4);
	printf("ENTER THE DONOR'S NAME:");
	gets(name3);
	gotoxy(31,5);
	printf("ENTER THE DONOR'S MAIL ID: ");
	gets(gmail1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %s %s %lf %s\n",name,address,gender,dob,age,gmail,&phone,bg)!=EOF){
		r1=strcmp(name,name3);
		r2=strcmp(gmail,gmail1);
		res=r1+r2;
	if(res==0)
		{
			f=1;
			gotoxy(31,4);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB MODIFY SECTION OPENED \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    gotoxy(31,6);
	printf("1.NAME");
	gotoxy(31,7);
    printf("2.ADDRESS");
    gotoxy(31,8);
    printf("3.GENDER"); 
    gotoxy(31,9);
    printf("4.DATE OF BIRTH"); 
    gotoxy(31,10);
    printf("5.MAIL ID");
    gotoxy(31,11);
    printf("6.PHONE NUMBER");
	gotoxy(31,12);
	printf("7.BLOOD GROUP");
	gotoxy(31,13);
	printf("8.LAST BLOOD DONATED DATE:");
	gotoxy(31,14);
	printf("ENTER THE NUMBER:");
	scanf("%d",&n);
	system("cls");
		switch(n)
	{
		case 1:
		    gotoxy(31,13);
			printf("ENTER THE NEW NAME:");
			scanf("%s",&name1);
			fprintf(fptr1,"%s %s %s %s %s %s %.0lf %s\n",name1,address,gender,dob,age,gmail,phone,bg);
			printf("NEW DETAILS UPDATED.");
			break;
		case 2:	
			gotoxy(31,13);
			printf("ENTER THE NEW ADDRESS:");
			scanf("%s",&address1);
			fprintf(fptr1,"%s %s %s %s %s %s %.0lf %s\n",name,address1,gender,dob,age,gmail,phone,bg);
			printf("NEW DETAILS UPDATED.");
			break;
		case 3:	
			gotoxy(31,13);
			printf("ENTER THE NEW GENDER:");
			scanf("%s",&gender1);
			fprintf(fptr1,"%s %s %s %s %s %s %.0lf %s\n",name,address,gender1,dob,age,gmail,phone,bg);
			printf("NEW DETAILS UPDATED.");
			break;
		case 4:	
		    gotoxy(31,13);
			printf("ENTER THE NEW DATE OF BIRTH:");
			scanf("%d",&age1);
			fprintf(fptr1,"%s %s %s %s %s %s %.0lf %s\n",name,address,gender,dob,age1,gmail,phone,bg);
			break;
		case 5:	
		    gotoxy(31,13);
			printf("ENTER THE NEW MAIL ID:");
			scanf("%s",&gmail1);
			fprintf(fptr1,"%s %s %s %s %s %s %.0lf %s\n",name,address,gender,dob,age,gmail1,phone,bg);
			printf("NEW DETAILS UPDATED.");
			break;
		case 6:
		     gotoxy(31,13);
			printf("ENTER THE NEW PHONE NUMBER:");
			scanf("%s",&phone1);
            fprintf(fptr1,"%s %s %s %s %s %s %.0lf %s\n",name,address,gender,dob,age,gmail,phone1,bg);
	         printf("NEW DETAILS UPDATED.");	
			break;	
		case 7:	
		     gotoxy(31,13);
			printf("ENTER THE NEW BLOOD GROUP:");
			scanf("%s",bg1);
            fprintf(fptr1,"%s %s %s %s %s %s %.0lf %s\n",name,address,gender,dob,age,gmail,phone,bg1);
			printf("NEW DETAILS UPDATED.");
			break;
		case 8:	
		gotoxy(31,13);
			printf("ENTER THE NEW LAST BLOOD DONATED DATE:");
			scanf("%s",&dob1);
			fprintf(fptr1,"%s %s %s %s %s %s %.0lf %s\n",name,address,gender,dob1,age,gmail,phone,bg);
			printf("NEW DETAILS UPDATED.");
			break;
		default:	
		    gotoxy(31,13);
		    printf("INVALID ENTRY");
             exit(0);
	}	
		}
	else  {
			fprintf(fptr1,"%s %s %s %s %s %s %.0lf %s\n",name,address,gender,dob,age,gmail,phone,bg);
		}
	}
	if(f==0){
		gotoxy(31,13);
		printf("RECORD NOT FOUNDED.");
	}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("Donor List.txt","w");
	fclose(fptr);
	fptr=fopen("Donor List.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %s %s %lf%s\n",name,address,gender,dob,age,gmail,&phone,bg)!=EOF){
		fprintf(fptr,"%s %s %s %s %s %s %.0lf %s\n",name,address,gender,dob,age,gmail,phone,bg);
		
	}
	
	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	gotoxy(31,14);
	printf("PRESS 'Y' FOR MAIN MENU.");
	fflush(stdin);
	if(getch()=='Y'){
		menu();
	}
}

void deletefun(){
	system("cls");
	system("color 4");
	gotoxy(30,1);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB GIVE THE GIFT OF LIFE TO OTHER'S \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	FILE *fptr,*fptr1;
	char name[100],address[200],age[100],gmail[100],gmail1[100],gmail2[100],address1[100],name1[100],gender[8],bg[50],dob[50];
	int res,r1,r2,f=0;
	double phone,phone1;
	fptr=fopen("Donor List.txt","r");
	fptr1=fopen("temp.txt","ab+");
	gotoxy(31,5);
	printf("ENTER THE DONOR NAME THAT YOU WANT TO DELETE: ");
	gets(name1);
	gotoxy(31,7);
	printf("ENTER THE DONOR EMAIL ID THAT YOU WANT TO DELETE: ");
    gets(gmail2);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %s %s %lf %s\n",name,address,gender,dob,age,gmail,&phone,bg)!=EOF){
		r1=strcmp(name,name1);
		r2=strcmp(gmail,gmail2);
		res=r1+r2;
		if(res==0)
		{
			f=1;
			gotoxy(31,14);
			printf("RECORD DELETED SUCCESSFULLY");
			
		}else{
			fprintf(fptr1,"%s %s %s %s %s %s %.0lf %s\n",name,address,gender,dob,age,gmail,phone,bg);
		}
	}
	if(f==0){
		gotoxy(31,14);
		printf("RECORD NOT FOUND.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("Donor List.txt","w");
	fclose(fptr);
	fptr=fopen("Donor List.txt","ab+");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %s %s %lf %s\n",name,address,gender,dob,age,gmail,&phone,bg)!=EOF){
		fprintf(fptr,"%s %s %s %s %s %s %.0lf %s\n",name,address,gender,dob,age,gmail,phone,bg);
		
	}
	
	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	gotoxy(31,15);
	printf("PRESS 'Y' FOR MAIN MENU.");
	fflush(stdin);
	if(getch()=='Y'){
		menu();
	}  
}
void exitfun(){
	system("cls");
	 system("color D");
	gotoxy(30,1);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB YOUR LITTLE EFFORT CAN GIVE OTHER'S SECOND CHANCE TO LIVE LIFE \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(31,12);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB TEAM MEMBERS \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(31,14);
	printf("\xDB\xDB KIRAN RAJ.A");
	gotoxy(31,16);
	printf("\xDB\xDB MANIVANNAN.M");
    gotoxy(30,25);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB THANK YOU FOR TAKING THE TIME AND PRIORITY TO DONATE BLOOD \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
}
void password(void)
{
	char passwords[20]={"KIRAN"};
	gotoxy(22,2);
	int j;
	int z;
	char name[40]="AUTHORIZED PERSON ONLY";
	z=strlen(name);
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	for(j=0;j<=z;j++){
		Sleep(60);
		printf(" %c",name[j]);
	}
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	gotoxy(30,4);
	printf("PASSWORD:");
	char ch,pass[20];
	char w='*';
	int i=0;
	while(ch!=13){
		ch=getch();
		if(ch!=13 && ch!=8){
			printf("%c",w);
			pass[i]=ch;
			i++;
		}
			}
	pass[i]='\0';
	if(strcmp(pass,passwords)==0){
		gotoxy(30,6);
		printf("CORRECT PASSWORD.");
		Sleep(10);
		menu();
	}
	else{
		gotoxy(30,6);
		printf("YOU ENTER THE WRONG PASSWORD.");
		Sleep(70);
		system("cls");
		password();
}
	
}
	

void menu(){
	system("color 5");
	system("cls");
	gotoxy(30,1);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB A FEW DROPS OF YOUR BLOOD CAN HELP A LIFE TO BLOOM \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(31,5);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB  BLOOD DONOR'S \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(31,9);
	printf("\xDB\xDB\xDB\xDB\xDB 1.REGISTER");
	gotoxy(31,11);
	printf("\xDB\xDB\xDB\xDB\xDB 2.SEARCH");
	gotoxy(31,13);
	printf("\xDB\xDB\xDB\xDB\xDB 3.LIST");
	gotoxy(31,15);
	printf("\xDB\xDB\xDB\xDB\xDB 4.EDIT");
	gotoxy(31,17);
	printf("\xDB\xDB\xDB\xDB\xDB 5.DELETE");
	gotoxy(31,19);
	printf("\xDB\xDB\xDB\xDB\xDB 6.EXIT");
	switch(getch()){
		case '1':
			namefun();
			break;
		case '2':
			searchfun();
			break;
		case '3':
			listfun();
			break;
		case '4':
			modifyfun();
			break;
		case '5':
			deletefun();
			break;
		case '6':
			exitfun();
			break;
		default:
			system("cls");
			gotoxy(31,13);
			printf("INVALID ENTRY");
			gotoxy(31,15);
			printf("PRESS 'Y' FOR MENU.");
	         fflush(stdin);
	         if(getch()=='Y'){
		      menu();
			 }
			getch();
	}
}
