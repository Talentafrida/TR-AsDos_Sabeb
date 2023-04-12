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
int Account, CheckUsername[2], CheckPassword[2], totalbuku = 1;
char Username[20], login_failed, namabuku[][50], Manual[100], ManualBook;
char alamat[100] = "E:\\School Property\\Tugas\\C Files 3\\TAS_ASDOS_ASD\\"; // ganti alamat sesuai lokasi file ini disimpan

struct Book{
	char Judul[30],Penerbit[20],Tanggal_Terbit[20],Tempat_Terbit[20],Pengarang[45];
}Book[10];

void main(){
	Login();
}

void Login(){
	int i = 0, j = 0;
	char Input, Password[7], username[][10]={"Ariel", "Sando", "Ellen"}, password[][10]={"Ganteng", "Ganteng", "Cantik"};
	
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
		}else if(Input != 8 && Input != 13){
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
		    }else if(CheckUsername[i]==0 && strlen(Password) == 0){
		    	system("cls");
				login_failed=2;
		        Login();
			}else if(CheckUsername[i]==1 && CheckPassword[i]==1){
		        login_failed=1;
			}
		}
	}
	login_failed=1;
	system("cls");
	Login();
}

void Main_menu(){
	char Menu;
	
	gotoxy(20,1);
    printf("Welcome to Sabeb's Library, %s!", Username);
	gotoxy(1,3);
	printf("1. Add Book");
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
		Add_Book();
		system("cls");
		Main_menu();
	}else if(Menu == '2'){
		Read_Book();
		system("cls");
		Main_menu();
	}else if(Menu == '3'){
		Update_Book();
		system("cls");
		Main_menu();
	}else if(Menu == '4'){
		Delete_Book();
		system("cls");
		Main_menu();
	}else if(Menu == '5'){
		Search_Book();
		system("cls");
		Main_menu();
	}else if(Menu == '6'){
		Sort_Book();
		system("cls");
		Main_menu();
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

void Add_Book(){
	int i, j, val = 0;
	struct Book Data;
	
    system("cls");
    gotoxy(1,1);
    printf("New Book Title : ");
	scanf(" %[^\n]s", &namabuku[totalbuku]);
	strcat(namabuku[totalbuku], ".txt");
	
	for(i = 1; i < totalbuku; i++){
		if((strcmp(namabuku[i], namabuku[totalbuku]) == 1) && (strlen(namabuku[totalbuku]) != strlen(namabuku[i]))){
			val = 0;
		}
		if((strcmp(namabuku[i], namabuku[totalbuku]) == 0) && (strlen(namabuku[totalbuku]) == strlen(namabuku[i]))){
			val = i;
			i = totalbuku;
		}
	}
	
	if(val == 0){
		puts(namabuku[totalbuku]);
		gotoxy(1,3);
		printf("Book successfully created.");
		fp = fopen(namabuku[totalbuku], "w");
		fclose(fp);
		totalbuku++;
	}else if(val > 0){
		gotoxy(1,3);
		printf("Book already exists.");
	}
	
	getch();
}

void Read_Book(){
	int nomor, i, y=3;
	
	system("cls");
	
	if(totalbuku == 1){
		Isi_judul_sendiri();
		
		fp = fopen(Manual, "r");
		
		if(fp!=NULL){
			char read;
			
			while((read=fgetc(fp))!=EOF){
				printf("%s",read);
			}
		}else{
			gotoxy(1,y);
			printf("Book not found.");
		}
	}else{
		gotoxy(1,1);
		printf("Daftar Buku :");
		
		for(i=1; i<totalbuku; i++){
			gotoxy(1,y);
	    	printf("%i. %s", i, namabuku[i]);
	    	y++;
		}
		
		y++;
		gotoxy(1,y);
		printf("Select the book you want to read: ");
		scanf(" %i", &nomor);
		
		y++;
		
		fp = fopen(namabuku[nomor], "r");
		
		if(fp!=NULL){
			char read;
			
			while((read=fgetc(fp))!=EOF){
				printf("%s",read);
			}
		}else{
			gotoxy(1,y);
			printf("Book not found.");
		}
	}
	
	y+=2;
	gotoxy(1,y);
	printf("\nPress Enter to go back to the main menu.");
	
	fclose(fp);
	getch();
}

void Update_Book(){
	int a, j, r, y=3;
    char text[150];
    
	if(totalbuku == 1){
		system("cls");
		
		printf("Tekan '0' untuk memasukan judul buku");
		gotoxy(0,10);
	}else{
		system("cls");
		
		gotoxy(1,1);
		printf("Update Isi Buku");
		
		for(r = 1; r < totalbuku; r++){
			gotoxy(1,y);
	    	printf("%i. %s", r, namabuku[r]);
	    	y++;
		}
		
		printf("\nPilihan : ");
	}
	
	a = getch();
	printf("%c ", a);
	
	if(a == 49) a = 1;
	else if(a == 50) a = 2;
	else if(a == 51) a = 3;
	else if(a == 52) a = 4;
	else if(a == 53) a = 5;
	else if(a == 54) a = 6;
	else if(a == 55) a = 7;
	else if(a == 56) a = 8;
	else if(a == 57) a = 9;
	
	if(a == '0'){
		Isi_judul_sendiri();
		
    	system("cls");
    	
	    fp = fopen(Manual, "a");
	    
	    printf("\nIsi : \n\n");
		scanf(" %[^\n]", text);
		
		strcat(text, "\n");
		
		fprintf(fp, "%s", text);
		
	    fclose(fp);
	    
	    printf("\n\nAdd Data Sukses!!!");
	    getch();
	}else if(totalbuku != 1 && a < totalbuku){
		system("cls");
		
		fp = fopen(namabuku[a], "a");
				
		printf("Author: "); scanf(" %[^\n]s",&Book->Pengarang);
		printf("Publisher: "); scanf(" %[^\n]s",&Book->Penerbit);
		printf("Publication Date: "); scanf(" %[^\n]s",&Book->Tanggal_Terbit);
		printf("PLace of Publication: "); scanf(" %[^\n]s",&Book->Tempat_Terbit);
		fprintf(fp,"Title: %s\nAuthor: %s\nPublisher: %s\nPublication Date: %s\nPLace of Publication: %s\n", namabuku[a],Book->Pengarang,Book->Penerbit,Book->Tanggal_Terbit,Book->Tempat_Terbit);
		
	    fclose(fp);
	    
	    printf("\n\nAdd Data Sukses!!!");
	    getch();
	}else if(totalbuku != 1){
		gotoxy(10,10);
		printf("Salah Input");
		getch();
	}
}

void Delete_Book(){
	
}

void Search_Book(){
	
}

void Sort_Book(){
	int Sort,i,j;
	char So[50];
	
	system("cls");
	
	Sort:
	printf("Sort Book\n1. Ascending\n2. Descending\nChoose: "); scanf("%d",&Sort);
	
	if(Sort<1 || Sort>2) {
		system("cls");
		goto Sort;
	}else if(Sort==1){
		for(i = 1; i <= totalbuku; i++) {
			for(j = i + 1; j <= totalbuku; j++) {
				if(strcmp(namabuku[i],namabuku[j])>0) {
					strcpy(So,namabuku[i]);
					strcpy(namabuku[i],namabuku[j]);
					strcpy(namabuku[j],So);
				}
			}
		}
		printf("Sorted Books (Ascending):\n");
		for(i=1; i <= totalbuku; i++) {
			puts(namabuku[i]);
		}
	}
}

void Isi_judul_sendiri(){
	memset(Manual, 0, sizeof(Manual));
	system("cls");
	printf("Masukkan Nama Buku : \n"); scanf(" %s", &ManualBook);
	strcat(Manual, alamat);
	strcat(Manual, ManualBook);
	strcat(Manual, ".txt");
}
