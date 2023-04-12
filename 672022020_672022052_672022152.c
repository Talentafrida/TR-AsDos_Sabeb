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
int Account, CheckUsername, CheckPassword[2], totalbuku = 1;
char Username[20], login_failed = 0, namabuku[][50], Manual[100], ManualBook[100];
char alamat[100] = "E:\\School Property\\Tugas\\C Files 3\\TAS_ASDOS_ASD\\"; // ganti alamat sesuai lokasi file ini disimpan

struct Book{
	char Judul[30],Penerbit[20],Tanggal_Terbit[20],Tempat_Terbit[20],Pengarang[45];
}Book[10];

void main(){
	Login();
}

void Login_Animation(){
	int end, count, i, j, x=10, y=5;
	
	while (count!=176){
		gotoxy(x, y);
		printf("%c", 475);
		
		count++;
		
		if(count<50){
			x++;
		}else if(count>=50 && count < 65){
			y++;
		}else if(count>= 65 && count < 114){
			x--;
		}else if(count>= 114 && count < 128){
			y--;
		}else if(count>= 128 && count < 176){
			x++;
		}
		
		if(count == 128){
			x=11;
			y=11;
		}
		
		if(login_failed==0){
			for (i=1;i<=4000;i++)
				for (j=1;j<=4000;j++);
		}
	}
}

void Login(){
	int i = 0, j = 0;
	char Input, Password[10];
	
	Login_Animation();
	
	if(login_failed==1){
		gotoxy(25,19);
		printf("Incorrect Password");
	}else if(login_failed==2){
		gotoxy(17,19);
		printf("Username did not match to any Account");
	}
	
    gotoxy(28,8);
    printf("Please Log In");
	
	gotoxy(25,15);
    printf("Username: "); scanf(" %s", &Username);
    gotoxy(25,16);
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
	
	if((strcmp(Username, "admin") == 0) && (strcmp(Password, "cantik") == 0)){
		login_failed = 0;
		system("cls");
		Main_menu();
	}else if((strcmp(Username, "admin") == 0) && (strcmp(Password, "ganteng") == 0)){
		login_failed = 0;
		system("cls");
		Main_menu();
	}else if (strcmp(Username, "admin") != 0){
		login_failed = 2;
		system("cls");
		Login();
	}else if(strcmp(Password, "cantik") != 0){
		login_failed = 1;
		system("cls");
		Login();
	}else if(strcmp(Password, "ganteng") != 0){
		login_failed = 1;
		system("cls");
		Login();
	}
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
		gotoxy(1,2);
		puts(namabuku[totalbuku]);
		gotoxy(1,4);
		printf("Book successfully created.");
		fp = fopen(namabuku[totalbuku], "w");
		fclose(fp);
		totalbuku++;
	}else if(val > 0){
		gotoxy(1,4);
		printf("Book already exists.");
	}
	
	getch();
}

void Read_Book(){
	int i, y=3, isi=0;
	char read, nomor;
	
	system("cls");
	
	if(totalbuku == 1){
		Isi_judul_sendiri();
		fp = fopen(Manual, "r");
		
		if(fp!=NULL){
			printf("%s", Manual);
			
			while((read=fgetc(fp))!=EOF){
				printf("%c",read);
				isi++;
			}
			if(isi == 0){
				y+=2;
				gotoxy(1,y);
				printf("(Buku ini belum ada isinya)");
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
		
		nomor = getch();
		printf("%c ", nomor);
		
		if(nomor == 49) nomor = 1;
		else if(nomor == 50) nomor = 2;
		else if(nomor == 51) nomor = 3;
		else if(nomor == 52) nomor = 4;
		else if(nomor == 53) nomor = 5;
		else if(nomor == 54) nomor = 6;
		else if(nomor == 55) nomor = 7;
		else if(nomor == 56) nomor = 8;
		else if(nomor == 57) nomor = 9;
		else nomor = 0;
		
		y++;
		
		fp = fopen(namabuku[nomor], "r");
		
		if(fp!=NULL){
			
			while((read=fgetc(fp))!=EOF){
				printf("%c",read);
				isi++;
			}
			y+=2;
			if(isi == 0){
				gotoxy(1,y);
				printf("(Buku ini belum ada isinya)");
			}
		}else{
			gotoxy(1,y);
			printf("Book not found.");
		}
	}
	
	y+=2;
	gotoxy(1,y);
	printf("Press Enter to go back to the main menu.");
	
	fclose(fp);
	getch();
}

void Update_Book(){
	int a, j, r, y=3;
    char text[150];
    
	if(totalbuku == 1){
		Isi_judul_sendiri();
		
		fp = fopen(Manual, "r");
		
		if(fp!=NULL){
			fp = fopen(Manual, "w");
			printf("Author: "); scanf(" %[^\n]s",&Book->Pengarang);
			printf("Publisher: "); scanf(" %[^\n]s",&Book->Penerbit);
			printf("Publication Date: "); scanf(" %[^\n]s",&Book->Tanggal_Terbit);
			printf("PLace of Publication: "); scanf(" %[^\n]s",&Book->Tempat_Terbit);
			fprintf(fp,"Title: %s\nAuthor: %s\nPublisher: %s\nPublication Date: %s\nPLace of Publication: %s\n", namabuku[a],Book->Pengarang,Book->Penerbit,Book->Tanggal_Terbit,Book->Tempat_Terbit);
			
		    
		    printf("\n\nAdd Data Sukses!!!");
		}else{
			gotoxy(1,y);
			printf("Book not found.");
		}
		fclose(fp);
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
    	
	    fp = fopen(Manual, "w");
	    
	    printf("\nIsi : \n\n");
		scanf(" %[^\n]", text);
		
		strcat(text, "\n");
		
		fprintf(fp, "%s", text);
		
	    fclose(fp);
	    
	    printf("\n\nAdd Data Sukses!!!");
	    getch();
	}else if(totalbuku != 1 && a < totalbuku){
		system("cls");
		
		fp = fopen(namabuku[a], "w");
				
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
	int ret, a, r, y=3, i, j;
    
    if(totalbuku == 1){
		Isi_judul_sendiri();
		
		fp = fopen(Manual, "r");
		
		if(fp!=NULL){
			printf("%s", Manual);
			
			ret = remove(Manual);
	    	
	    	if(ret == 0) {
		        printf("\nFile deleted successfully");
		    }else{
		        printf("\nError: unable to delete the file");
		    }
		}
		else{
			gotoxy(1,4);
			printf("Book not found.");
		}
	}else{
		system("cls");
		
		gotoxy(1,1);
		printf("Hapus Buku");
		
		for(r = 1; r < totalbuku; r++){
			gotoxy(1,y);
	    	printf("%i. %s", r, namabuku[r]);
	    	y++;
		}
		
		printf("\nPilihan : ");
	}
	
	a = getch();
	printf("%c ", a);
	
	if(a==49) a=1;
	else if(a==50) a=2;
	else if(a==51) a=3;
	else if(a==52) a=4;
	else if(a==53) a=5;
	else if(a==54) a=6;
	else if(a==55) a=7;
	else if(a==56) a=8;
	else if(a==57) a=9;
	
	if(totalbuku != 1 && a < totalbuku){
		ret = remove(namabuku[a]);
		printf("\n\nNama File yang ingin Dihapus : \"%s\"", namabuku[a]);
		
		if(ret == 0) {
			for(r = 1; r <= totalbuku; r++){
				if(r >= a && r < totalbuku){
					for(i = 0; i <= strlen(namabuku[r]); i++){
						namabuku[r][i] = namabuku[r+1][i];
					}
				}else if(r == totalbuku){
					memset(namabuku[totalbuku], 0, sizeof(namabuku[totalbuku]));
				}
			}
	        printf("\n\nFile deleted successfully");
			totalbuku--;
	    }else{
	        printf("\n\nError: unable to delete the file");
	    }
	    getch();
	}else if(totalbuku != 1){
		printf("\n\n\t\tSalah Input");
		getch();
	}
}

void Search_Book(){
		y++;
	gotoxy(1,y);
	printf("Select the book you want to search: ");
	scanf(" %i", &nomor);
	nomor = getch();
	printf("%c ", nomor);
	if(nomor == 49) nomor = 1;
	else if(nomor == 50) nomor = 2;
	else if(nomor == 51) nomor = 3;
	else if(nomor == 52) nomor = 4;
	else if(nomor == 53) nomor = 5;
	else if(nomor == 54) nomor = 6;
	else if(nomor == 55) nomor = 7;
	else if(nomor == 56) nomor = 8;
	else if(nomor == 57) nomor = 9;
	else nomor = 0;

	y++;
	int idx=0,pos=-1;
	for (idx = 0 ; idx < sizeof(namabuku) ; idx++){
		if (strcmp(namabuku[idx],namabuku[nomor])==0){
			pos = idx;
			break;
		}
	}
	
	print("%s\n",namabuku[pos]);
	return;
}

void Sort_Book(){
	int i,j, Sort;
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
		printf("\nSorted Books (Ascending):\n");
		for(i=1; i <= totalbuku; i++) {
			puts(namabuku[i]);
		}
	}
	
	system("pause");
}

void Isi_judul_sendiri(){
	memset(Manual, 0, sizeof(Manual));
	system("cls");
	printf("Masukkan Nama Buku : \n"); scanf(" %s", &ManualBook);
	strcat(Manual, alamat);
	strcat(Manual, ManualBook);
	strcat(Manual, ".txt");
}
