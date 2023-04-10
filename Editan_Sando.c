#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Account, CheckUsername, CheckPassword;
char Username[15], Password[10], login_failed;

int main(){    
	Login();
}

void Login(){
	int i;
	char username[][10]={"Ariel", "Sando", "Eren"}, password[][10]={"Ganteng", "Ganteng", "Cantik"};
	
	Login:
    gotoxy(20,1);
    printf("Please Log In");
	
	if(login_failed==1){
		gotoxy(1,8);
		printf("Incorrect Username or Password");
	}
	gotoxy(5,4);
    printf("Username: "); scanf("%s",&Username);
    gotoxy(5,5);
	printf("Password: "); scanf("%s",&Password);

	for(i=0; i<3; i++){
		CheckUsername=strcmp(Username,username[i]);
        CheckPassword=strcmp(Password,password[i]);
        if(CheckUsername==0 && CheckPassword==0){
        	goto Approved;
		}
	}
    
    Approved:
	if(CheckUsername==0 && CheckPassword==0) {
        system("cls");
        login_failed=0;
        Main_menu();
    } else {
        system("cls");
        login_failed=1;
        goto Login;
    }
}

void Main_menu(){
	int Menu;
	
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
	gotoxy(1,11);
	printf("Choose: "); scanf("%d", &Menu);
}
