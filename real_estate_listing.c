#include<stdio.h>
#include<string.h>
#define total 3940

// global variabel untuk menyimpan line pertama file yang akan dipakai berulang kali
char location1[101]; char location[] = "Location"; char city1[101]; char city[] = "City"; char type[101]; char furnish1[101]; char furnish[] = "Furnish"; char price[101]; char room[101]; char bathroom[101]; char carpark[101];

// struct untuk menyimpan data
struct DATA {
	char location[101];
	char city[101];
	int price;
	int rooms;
	int bathroom;
	int carpark;
	char Type[101];
	char Furnish[101];
};

struct DATA DAT[total];

// function untuk mendisplay menu utama
void MENU(){
	printf("What do you want to do?\n");
	printf("1. Display data\n");
	printf("2. Search data\n");
	printf("3. Sort data\n");
	printf("4. Export data\n");
	printf("5. Exit\n");
	printf("Your choice: ");
}

// function untuk read file dan simpan isi file ke struct
void getFile(){
	FILE* fptr = fopen("file.csv", "r");
	if(fptr == NULL){
		printf("File is empty!\n");}
	
	int i = 0;
	fscanf(fptr, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", location1, city1, price, room, bathroom, carpark, type, furnish1);
	i++;
	while (!feof (fptr)){
		fscanf(fptr, " %[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]", DAT[i].location, DAT[i].city, &DAT[i].price, &DAT[i].rooms, &DAT[i].bathroom, &DAT[i].carpark, DAT[i].Type, DAT[i].Furnish);
	 	i++;}
	fclose(fptr);
}

// function untuk case 1 = mendisplay berdasarkan jumlah row yang diminta
void CASE1_Display(){
	int row;
	printf("Number of rows: ");
	scanf("%d", &row); getchar();
	
	while(row <= 0){
		printf("Input should be a positive integer number!\n");
		printf("Number of rows: ");
		scanf("%d", &row); getchar();}
	
	printf("\n");
	printf("%-26s%-20s%-10s%-8s%-10s%-10s%-15s%-20s\n", location, city, price, room, bathroom, carpark, type, furnish);
	int i = 1;
	while (i<=row && i<total){
		printf("%-26s%-20s%-10d%-8d%-10d%-10d%-15s%-20s\n", DAT[i].location, DAT[i].city, DAT[i].price, DAT[i].rooms, DAT[i].bathroom, DAT[i].carpark, DAT[i].Type, DAT[i].Furnish);
	 	i++;
	}
}

// function untuk case 2 = mencari berdasarkan input column dan isi serta mendisplay hasil pencarian bila ada
void CASE2_SelectRow(){
	char column[101];
	char queryValue[101];
	int QueryValue;
	
	printf("Choose column: ");
	scanf("%[^\n]", &column); getchar();
	
	while((strcmp(column,"Location")!=0) && (strcmp(column,"City")!=0) && (strcmp(column,"Price")!=0) && (strcmp(column,"Rooms")!=0) && (strcmp(column,"Bathrooms")!=0) && (strcmp(column,"Carpark")!=0) && (strcmp(column,"Type")!=0) && (strcmp(column,"Furnish")!=0)){
		printf("Your choices are only as follow -> [Location | City | Price | Rooms | Bathrooms | Carpark | Type | Furnish]\n");	
		printf("Choose column: ");
		scanf("%[^\n]", &column); getchar();
	}
	
	printf("What data do you want to find? ");
	if((strcmp(column,"Location")==0) || (strcmp(column,"City")==0) || (strcmp(column,"Type")==0) || (strcmp(column,"Furnish")==0)){
		scanf("%[^\n]", &queryValue); getchar();}
	else{
		scanf("%d", &QueryValue); getchar();}
	printf("\n");
	
	int i;
	int count = 0;
	int valid = 0;
	for(i=1; i<total; i++){
	if(strcmp(column,"Location")==0 && strcmp(queryValue, DAT[i].location)==0){
		if(valid != 1){
			printf("Data Found. Detail of data:\n");
			printf("%-26s%-20s%-10s%-8s%-10s%-10s%-15s%-20s\n", location, city, price, room, bathroom, carpark, type, furnish);
			valid = 1;
		}
		printf("%-26s%-20s%-10d%-8d%-10d%-10d%-15s%-20s\n", DAT[i].location, DAT[i].city, DAT[i].price, DAT[i].rooms, DAT[i].bathroom, DAT[i].carpark, DAT[i].Type, DAT[i].Furnish);
		i++; count++;}
	
	else if(strcmp(column,"City")==0 && strcmp(queryValue, DAT[i].city)==0){
		if(valid != 1){
			printf("Data Found. Detail of data:\n");
			printf("%-26s%-20s%-10s%-8s%-10s%-10s%-15s%-20s\n", location, city, price, room, bathroom, carpark, type, furnish);
			valid = 1;
		}
		printf("%-26s%-20s%-10d%-8d%-10d%-10d%-15s%-20s\n", DAT[i].location, DAT[i].city, DAT[i].price, DAT[i].rooms, DAT[i].bathroom, DAT[i].carpark, DAT[i].Type, DAT[i].Furnish);
		i++; count++;
	}
	else if(strcmp(column,"Price")==0 && QueryValue == DAT[i].price){
		if(valid != 1){
			printf("Data Found. Detail of data:\n");
			printf("%-26s%-20s%-10s%-8s%-10s%-10s%-15s%-20s\n", location, city, price, room, bathroom, carpark, type, furnish);
			valid = 1;
		}
		printf("%-26s%-20s%-10d%-8d%-10d%-10d%-15s%-20s\n", DAT[i].location, DAT[i].city, DAT[i].price, DAT[i].rooms, DAT[i].bathroom, DAT[i].carpark, DAT[i].Type, DAT[i].Furnish);
		i++; count++;
	}
	else if(strcmp(column,"Rooms")==0 && QueryValue == DAT[i].rooms){
		if(valid != 1){
			printf("Data Found. Detail of data:\n");
			printf("%-26s%-20s%-10s%-8s%-10s%-10s%-15s%-20s\n", location, city, price, room, bathroom, carpark, type, furnish);
			valid = 1;
		}
		printf("%-26s%-20s%-10d%-8d%-10d%-10d%-15s%-20s\n", DAT[i].location, DAT[i].city, DAT[i].price, DAT[i].rooms, DAT[i].bathroom, DAT[i].carpark, DAT[i].Type, DAT[i].Furnish);
		i++; count++;
	}
	else if(strcmp(column,"Bathrooms")==0 && QueryValue == DAT[i].bathroom){
		if(valid != 1){
			printf("Data Found. Detail of data:\n");
			printf("%-26s%-20s%-10s%-8s%-10s%-10s%-15s%-20s\n", location, city, price, room, bathroom, carpark, type, furnish);
			valid = 1;
		}
		printf("%-26s%-20s%-10d%-8d%-10d%-10d%-15s%-20s\n", DAT[i].location, DAT[i].city, DAT[i].price, DAT[i].rooms, DAT[i].bathroom, DAT[i].carpark, DAT[i].Type, DAT[i].Furnish);
		i++; count++;
	}
	else if(strcmp(column,"Carpark")==0 && QueryValue == DAT[i].carpark){
		if(valid != 1){
			printf("Data Found. Detail of data:\n");
			printf("%-26s%-20s%-10s%-8s%-10s%-10s%-15s%-20s\n", location, city, price, room, bathroom, carpark, type, furnish);
			valid = 1;
		}
		printf("%-26s%-20s%-10d%-8d%-10d%-10d%-15s%-20s\n", DAT[i].location, DAT[i].city, DAT[i].price, DAT[i].rooms, DAT[i].bathroom, DAT[i].carpark, DAT[i].Type, DAT[i].Furnish);
		i++; count++;
	}
	else if(strcmp(column,"Type")==0 && strcmp(queryValue, DAT[i].Type)==0){
		if(valid != 1){
			printf("Data Found. Detail of data:\n");
			printf("%-26s%-20s%-10s%-8s%-10s%-10s%-15s%-20s\n", location, city, price, room, bathroom, carpark, type, furnish);
			valid = 1;
		}
		printf("%-26s%-20s%-10d%-8d%-10d%-10d%-15s%-20s\n", DAT[i].location, DAT[i].city, DAT[i].price, DAT[i].rooms, DAT[i].bathroom, DAT[i].carpark, DAT[i].Type, DAT[i].Furnish);
		i++; count++;
	}
	else if(strcmp(column,"Furnish")==0 && strcmp(queryValue, DAT[i].Furnish)==0){
		if(valid != 1){
			printf("Data Found. Detail of data:\n");
			printf("%-26s%-20s%-10s%-8s%-10s%-10s%-15s%-20s\n", location, city, price, room, bathroom, carpark, type, furnish);
			valid = 1;
		}
		printf("%-26s%-20s%-10d%-8d%-10d%-10d%-15s%-20s\n", DAT[i].location, DAT[i].city, DAT[i].price, DAT[i].rooms, DAT[i].bathroom, DAT[i].carpark, DAT[i].Type, DAT[i].Furnish);
		i++; count++;
	}}
	if(count == 0){
		printf("Data not Found!\n");}	
}

// function untuk menukar struct
void swapStruct(int a, int b, struct DATA DAT[]){
	struct DATA temp;
	temp = DAT[a];
	DAT[a] = DAT[b];
	DAT[b] = temp;
}

// function untuk case 3 = menyusun data berdasarkan urutan tertentu di lihat dari column tertentu
// kemudian mendisplay 10 data pertama sesuai permintaan soal
void CASE3_SortData (){
	char column[20];
	char asOrDes[12];
	
	printf("Choose column: ");
	scanf("%[^\n]", &column); getchar();
	
	while((strcmp(column,"Location")!=0) && (strcmp(column,"City")!=0) && (strcmp(column,"Price")!=0) && (strcmp(column,"Rooms")!=0) && (strcmp(column,"Bathrooms")!=0) && (strcmp(column,"Carpark")!=0) && (strcmp(column,"Type")!=0) && (strcmp(column,"Furnish")!=0)){
		printf("Your choices are only as follow -> [Location | City | Price | Rooms | Bathrooms | Carpark | Type | Furnish]\n");	
		printf("Choose column: ");
		scanf("%[^\n]", &column); getchar();}
	
	printf("Sort ascending or descending? ");
	scanf("%[^\n]", &asOrDes); getchar();
	
	while((strcmp(asOrDes,"asc")!=0) && (strcmp(asOrDes,"ascending")!=0) && (strcmp(asOrDes,"desccending")!=0) && (strcmp(asOrDes,"des")!=0) && (strcmp(asOrDes,"Asc")!=0) && (strcmp(asOrDes,"Des")!=0) && (strcmp(asOrDes,"Ascending")!=0) && (strcmp(asOrDes,"Descending")!=0)){
		printf("You can write from this option -> [asc | ascending | Asc | Ascending | des | descending | Des | Descending]\n");	
		printf("Sort ascending or descending? ");
		scanf("%[^\n]", &asOrDes); getchar();}
	
	if(strcmp(column,"Location")==0){
		if((strcmp(asOrDes,"asc")==0) || (strcmp(asOrDes,"ascending")==0) || (strcmp(asOrDes,"Asc")==0) || (strcmp(asOrDes,"Ascending")==0)){
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(strcmp(DAT[k].location, DAT[k+1].location)>0){
						swapStruct(k, k+1, DAT);}
				}
			}
		}
		else{
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(strcmp(DAT[k].location, DAT[k+1].location)<0){
						swapStruct(k, k+1, DAT);}
					}
				}	
			}
		}
	else if(strcmp(column,"City")==0){
		if((strcmp(asOrDes,"asc")==0) || (strcmp(asOrDes,"ascending")==0) || (strcmp(asOrDes,"Asc")==0) || (strcmp(asOrDes,"Ascending")==0)){
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(strcmp(DAT[k].city, DAT[k+1].city)>0){
						swapStruct(k, k+1, DAT);}
				}
			}
		}
		else{
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(strcmp(DAT[k].city, DAT[k+1].city)<0){
						swapStruct(k, k+1, DAT);}
					}
				}	
			}
		}
	else if(strcmp(column,"Price")==0){
		if((strcmp(asOrDes,"asc")==0) || (strcmp(asOrDes,"ascending")==0) || (strcmp(asOrDes,"Asc")==0) || (strcmp(asOrDes,"Ascending")==0)){
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(DAT[k].price>DAT[k+1].price){
						swapStruct(k, k+1, DAT);}
					}
				}
			}
		else{
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(DAT[k].price<DAT[k+1].price){
						swapStruct(k, k+1, DAT);}
				}
			}
		}
	}
	else if(strcmp(column,"Rooms")==0){
		if((strcmp(asOrDes,"asc")==0) || (strcmp(asOrDes,"ascending")==0) || (strcmp(asOrDes,"Asc")==0) || (strcmp(asOrDes,"Ascending")==0)){
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(DAT[k].rooms>DAT[k+1].rooms){
						swapStruct(k, k+1, DAT);}
				}
			}
		}
		else{
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(DAT[k].rooms<DAT[k+1].rooms){
						swapStruct(k, k+1, DAT);}
					}
				}
			}
		}
		else if(strcmp(column,"Bathroom")==0){
		if((strcmp(asOrDes,"asc")==0) || (strcmp(asOrDes,"ascending")==0) || (strcmp(asOrDes,"Asc")==0) || (strcmp(asOrDes,"Ascending")==0)){
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(DAT[k].bathroom>DAT[k+1].bathroom){
						swapStruct(k, k+1, DAT);}
				}
			}
		}
		else{
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(DAT[k].bathroom<DAT[k+1].bathroom){
						swapStruct(k, k+1, DAT);}
					}
				}	
			}
		}
		else if(strcmp(column,"Carpark")==0){
		if((strcmp(asOrDes,"asc")==0) || (strcmp(asOrDes,"ascending")==0) || (strcmp(asOrDes,"Asc")==0) || (strcmp(asOrDes,"Ascending")==0)){
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(DAT[k].carpark>DAT[k+1].carpark){
						swapStruct(k, k+1, DAT);}
				}
			}
		}
		else{
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(DAT[k].carpark<DAT[k+1].carpark){
						swapStruct(k, k+1, DAT);}
					}
				}	
			}
		}
		else if(strcmp(column,"Type")==0){
		if((strcmp(asOrDes,"asc")==0) || (strcmp(asOrDes,"ascending")==0) || (strcmp(asOrDes,"Asc")==0) || (strcmp(asOrDes,"Ascending")==0)){
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(strcmp(DAT[k].Type, DAT[k+1].Type)>0){
						swapStruct(k, k+1, DAT);}
				}
			}
		}
		else{
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(strcmp(DAT[k].Type, DAT[k+1].Type)<0){
						swapStruct(k, k+1, DAT);}
					}
				}	
			}
		}
		else if(strcmp(column,"Furnish")==0){
		if((strcmp(asOrDes,"asc")==0) || (strcmp(asOrDes,"ascending")==0) || (strcmp(asOrDes,"Asc")==0) || (strcmp(asOrDes,"Ascending")==0)){
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(strcmp(DAT[k].Furnish, DAT[k+1].Furnish)>0){
						swapStruct(k, k+1, DAT);}
				}
			}
		}
		else{
			int j,k;
			for(j=1; j<3940; j++){
				for(k=1; k<3940-j; k++){
					if(strcmp(DAT[k].Furnish, DAT[k+1].Furnish)<0){
						swapStruct(k, k+1, DAT);}
					}
				}	
			}
		}
	
	printf("\nData found. Detail of data: (The first 10 Data)\n");
	printf("%-26s%-20s%-10s%-8s%-10s%-10s%-15s%-20s\n", location, city, price, room, bathroom, carpark, type, furnish);	
	
	int i;
	for(i=1; i<11; i++){
		printf("%-26s%-20s%-10d%-8d%-10d%-10d%-15s%-20s\n", DAT[i].location, DAT[i].city, DAT[i].price, DAT[i].rooms, DAT[i].bathroom, DAT[i].carpark, DAT[i].Type, DAT[i].Furnish);
	}
}

// function untuk case 4 = mengeksport data ke dalam file csv ( data yang sudah dieksport bisa jadi sudah di sort selama program dijalankan )
void CASE4_ExportData (){
	char fileName[101];
	
	printf("File name: ");
	scanf("%[^\n]", fileName); getchar();
	strcat(fileName, ".csv");
	
	FILE* fp = fopen(fileName, "w");
	fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s\n", location1, city1, price, room, bathroom, carpark, type, furnish1);
	
	int j = 1;
	while (j<total){
		fprintf(fp, "%s,%s,%d,%d,%d,%d,%s,%s\n", DAT[j].location, DAT[j].city, DAT[j].price, DAT[j].rooms, DAT[j].bathroom, DAT[j].carpark, DAT[j].Type, DAT[j].Furnish);
		j++;}
	
	if(fp == NULL){
		printf("Export Failed!\n");}
	else{
		printf("Data successfully written to file %s!\n", fileName);}
	
	fclose(fp);
}

int main(){
	getFile();
	int pilihan;
	system("cls");
	MENU();
	scanf("%d", &pilihan); getchar();
	
	switch(pilihan){
		case 1:{
			CASE1_Display();
			printf("\nPress enter to go back to menu!"); getchar();
			main();
			break;
		}
		case 2:{
			CASE2_SelectRow();
			printf("\nPress enter to go back to menu!"); getchar();
			main();
			break;
		}
		case 3:{
			CASE3_SortData();
			printf("\nPress enter to go back to menu!"); getchar();
			main();
			break;
		}
		case 4:{
			CASE4_ExportData();
			printf("\nPress enter to go back to menu!"); getchar();
			main();
			break;
		}
		case 5:{
			system("cls");
			printf("Thank you for using this program!\n");
			return 0;
			break;
		}
		default:{
			printf("Your pick is not on the menu!\n");
			printf("\nPress enter to go back to menu!"); getchar();
			main();
			break;
		}
	}
	return 0;
}
