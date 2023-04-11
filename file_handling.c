#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

FILE *fp;
int buffer[200], t = 1, i;
char ch, fileName[20][150], text, manualFile[100], Mfile[200], del[100];
char alamat[100] = "E:\\School Property\\Tugas\\C Files 2\\File Handling\\"; // ganti alamat sesuai lokasi file ini disimpan

void addData(){
	int val = 0, j;
    system("cls");
    
    printf("Add File\n\nMasukkan Nama File Baru : ");	
	scanf(" %[^\n]", &fileName[t]);
	strcat(fileName[t], ".txt");
	
	for(i = 1; i < t; i++){
		if((strcmp(fileName[i], fileName[t]) == 1) && (strlen(fileName[t]) != strlen(fileName[i]))){
			val = 0;
		}
		if((strcmp(fileName[i], fileName[t]) == 0) && (strlen(fileName[t]) == strlen(fileName[i]))){
			val = i;
			i = t;
		}
	}
	
	if(val == 0){
		puts(fileName[t]);
		printf("\nFile Sudah Berhasil dibuat!");
		fp = fopen(fileName[t], "w");
		fclose(fp);
		t++;
	}else if(val > 0){
		printf("\nSudah ada File dengan Nama yang Sama");
	}
	
	getch();
}

void readData(){
	int a,r;
	
	system("cls");
    printf("Read Data\n");
    
    if(t==1){
    	printf("\nTidak ada File\n\n\t\t\t\tTekan '0' untuk memasukkan nama file secara manual\n");
	}else{
		system("cls");
		
		printf("Read Data");
		printf("\t\t\t\tTekan '0' untuk memasukkan nama file secara manual\n");
		
		for(r = 1; r < t; r++){
	    	printf("%i. %s\n", r, fileName[r]);
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
	
	if(a == '0'){
		manual();
		
	    fp = fopen(Mfile, "r");
	    
	    printf("\n\nIsi File :\n\n");
		while ((ch = fgetc(fp)) != EOF){
	        printf("%c", ch);
	    }
	    
	    fclose(fp);
	    getch();
	}else if(t != 1 && a < t){
	    fp = fopen(fileName[a], "r");
	    printf("\n\nIsi File :\n\n");
	    
	    while ((ch = fgetc(fp)) != EOF){
	        printf("%c", ch);
	    }
	    
	    fclose(fp);
	    getch();
	}else if(t != 1){
		printf("\n\n\t\tSalah Input");
		getch();
	}
}

void rewriteData(){
	int a, j, r;
    char ky, text[150];
    
	if(t == 1){
		system("cls");
		
		printf("Rewrite Data\n");
    	printf("\nTidak ada File\n\n\t\t\t\tTekan '0' untuk memasukkan nama file secara manual\n");
	}else{
		system("cls");
		
		printf("Rewrite Data\n");
		printf("\t\t\t\tTekan '0' untuk memasukkan nama file secara manual\n");
		
		for(r = 1; r < t; r++){
	    	printf("%i. %s\n", r, fileName[r]);
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
		manual();
		
    	system("cls");
    	
	    fp = fopen(Mfile, "w");
	    
	    printf("\nIsi : \n\n");
		scanf(" %[^\n]", text);
		
		strcat(text, "\n");
		
		fprintf(fp, "%s", text);
		
	    fclose(fp);
	    
	    printf("\n\nRewrite Data Sukses!!!");
	    getch();
	}else if(t != 1 && a < t){
		system("cls");
		
		fp = fopen(fileName[a], "w");
		
		printf("\nIsi : \n\n");
		scanf(" %[^\n]", text);
		
		strcat(text, "\n");
		
		fprintf(fp, "%s", text);
		
	    fclose(fp);
	    
	    printf("\n\nRewrite Data Sukses!!!");
	    getch();
	}else if(t != 1){
		printf("\n\n\t\tSalah Input");
		getch();
	}
}

void updateData(){
    int a, j, r;
    char ky, text[150];
    
	if(t == 1){
		system("cls");
		
		printf("Update Data\n");
    	printf("\nTidak ada File\n\n\t\t\t\tTekan '0' untuk memasukkan nama file secara manual\n");
	}else{
		system("cls");
		
		printf("Update Data\n");
		printf("\t\t\t\tTekan '0' untuk memasukkan nama file secara manual\n");
		
		for(r = 1; r < t; r++){
	    	printf("%i. %s\n", r, fileName[r]);
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
		manual();
		
    	system("cls");
    	
	    fp = fopen(Mfile, "a");
	    
	    printf("\nIsi : \n\n");
		scanf(" %[^\n]", text);
		
		strcat(text, "\n");
		
		fprintf(fp, "%s", text);
		
	    fclose(fp);
	    
	    printf("\n\nAdd Data Sukses!!!");
	    getch();
	}else if(t != 1 && a < t){
		system("cls");
		
		fp = fopen(fileName[a], "a");
		
		printf("\nIsi : \n\n");
		scanf(" %[^\n]", text);
		
		strcat(text, "\n");
		
		fprintf(fp, "%s", text);
		
	    fclose(fp);
	    
	    printf("\n\nAdd Data Sukses!!!");
	    getch();
	}else if(t != 1){
		printf("\n\n\t\tSalah Input");
		getch();
	}
}

void deleteData(){
    int ret, a, r;
    
    if(t==1){
    	system("cls");
    	
    	printf("Delete Data\n");
    	printf("\nTidak ada File\n\n\t\t\t\tTekan '0' untuk memasukkan nama file secara manual\n");
	}else{
		system("cls");
		
		printf("Delete Data");
		printf("\t\t\t\tTekan '0' untuk memasukkan nama file secara manual\n");
		
		for(r = 1; r < t; r++){
	    	printf("%i. %s\n", r, fileName[r]);
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
	
	if(a == '0'){
		manual();
		
    	ret = remove(Mfile);
    	
    	if(ret == 0) {
	        printf("\nFile deleted successfully");
	    }else{
	        printf("\nError: unable to delete the file");
	    }
	    getch();
	}else if(t != 1 && a < t){
		ret = remove(fileName[a]);
		printf("\n\nNama File yang ingin Dihapus : \"%s\"", fileName[a]);
		
		
		if(ret == 0) {
			for(r = 1; r <= t; r++){
				if(r >= a && r < t){
					for(i = 0; i <= strlen(fileName[r]); i++){
						fileName[r][i] = fileName[r+1][i];
					}
				}else if(r == t){
					memset(fileName[t], 0, sizeof(fileName[t]));
				}
			}
	        printf("\n\nFile deleted successfully");
			t--;
	    }else{
	        printf("\n\nError: unable to delete the file");
	    }
	    getch();
	}else if(t != 1){
		printf("\n\n\t\tSalah Input");
		getch();
	}
}

void manual(){
	memset(Mfile, 0, sizeof(Mfile));
	system("cls");
	printf("Masukkan Nama File : \n"); scanf(" %s", &manualFile);
	strcat(Mfile, alamat);
	strcat(Mfile, manualFile);
	strcat(Mfile, ".txt");
}

int main(){
    char key;
    while(key != 13){
        system("cls");
		printf("\tMenu\n\n1. Add Data\n2. Read Data\n3. Update Data\n4. Delete Data\n5. Exit\n\nPilihan : ");
        key = getch();
        printf("%c", key);
        if(key=='1'){
            addData();
            main();
        }else if(key=='2'){
            readData();
            main();
        }else if(key=='3'){
            system("cls");
            printf("1. Rewrite Data\n2. Update Data\n\nPilihan : ");
            key = getch();
            if(key == '1'){
				rewriteData();
	            main();
			}else if(key == '2'){
				updateData();
	            main();
			}
        }else if(key=='4'){
            deleteData();
            main();
        }else if(key=='5'){
            exit(0);
        }
    }
}
