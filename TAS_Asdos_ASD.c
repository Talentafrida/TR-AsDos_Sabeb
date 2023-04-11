#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

FILE *fp;
int Account, CheckUsername[2], CheckPassword[2];
char Username[15], login_failed;

void main(){    
	Login();
}

void Login(){
	int i = 0, j = 0;
	char Input, Password[7], username[][10]={"Ariel", "Sando", "Talenta"}, password[][10]={"Ganteng", "Ganteng", "Cantik"};
	
    gotoxy(20,1);
    printf("Please Log In");
	
	if(login_failed==1){
		gotoxy(1,8);
		printf("Username did not match to any Account");
	}else if(login_failed==2){
		gotoxy(1,8);
		printf("Incorrect Password");
	}
	
	gotoxy(5,4);
    printf("Username: "); scanf(" %s", &Username);
    gotoxy(5,5);
	printf("Password: ");
	
	while((Input = getch()) != 13){
		if(Input == 8 && i > 0){
			printf("\b \b");
			Password[i] = "\b";
			i-=1;
		}else if(Input != 8){
			if(i<0){
				i=0;
			}
			printf("*");
			Password[i] = Input;
			i++;
		}
	}
	Password[i] = '\0';

	for(i=0; i<3; i++){
		CheckUsername[i]=strcmp(Username,username[i]);
        CheckPassword[i]=strcmp(Password,password[i]);
        if(CheckUsername[i] == 0 && CheckPassword[i] == 0){
	        system("cls");
	        login_failed=0;
	        Main_menu();
		}else{
			if(CheckUsername[i]==0 && CheckPassword[i]==1){
		    	system("cls");
				login_failed=2;
		        Login();
		    }else if(CheckUsername[i]==1 && CheckPassword[i]==1){
		        login_failed=1;
			}
		}
	}
	login_failed=2;
	system("cls");
	Login();
}

void Main_menu(){
	char Menu;
	
	gotoxy(20,1);
    printf("Welcome to Sabeb's Library, %s!", Username);
	gotoxy(1,3);
	printf("1. Create Book");
	gotoxy(1,4);
	printf("2. Read Book");
	gotoxy(1,5);
	printf("3. Update Book");
	gotoxy(1,6);
	printf("4. Delete Book");
	gotoxy(1,7);
	printf("5. Search Book");
	gotoxy(1,8);
	printf("6. Sort Book");
	gotoxy(1,9);
	printf("7. Log Out");
	gotoxy(1,10);
	printf("8. Exit");
	gotoxy(1,12);
	printf("Choose: "); scanf(" %c", &Menu);
	
	if(Menu == '1'){
		Create_Book();
	}else if(Menu == '2'){
		Read_Book();
	}else if(Menu == '3'){
		Update_Book();
	}else if(Menu == '4'){
		Delete_Book();
	}else if(Menu == '5'){
		Search_Book();
	}else if(Menu == '6'){
		Sort_Book();
	}else if(Menu == '7'){
		system("cls");
		main();
	}else if(Menu == '8'){
		exit(0);
	}else{
		system("cls");
		Main_menu();
	}
}

void Create_Book(){
	
}

void Read_Book(){
	
}

void Update_Book(){
	
}

void Delete_Book(){
	
}

void Search_Book(){
	
}

void Sort_Book(){
	
}
