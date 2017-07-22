#include <stdio.h>
void removeitem(FILE *cfptr);
void additem(FILE *cfptr);
void updateitem (FILE *cfptr);
struct item{
	     int itemserial;
		 char itemname[200];
		 double itemprice;
		 int itemquantity;
} ;    
int main(){
	        struct item s;
			FILE *cfptr;//creating a pointer towards file
			//if ((cfptr=fopen("item.txt","wb"))==NULL){//opening file to write in binary mode
				//   printf("enter file couldn't be loaded \n");
			//} else {
			  //  printf("enter the serial no. of item :\n");
				//	printf("Or enter serial no. 0 to exit \n");
				//	scanf("%d",&s.itemserial);
                 //  while(s.itemserial!=0){//sentinel value to exit
					// printf("enter name,price and quantity of item :\n");
					 // fscanf(stdin,"%s%lf%d",&s.itemname,&s.itemprice,&s.itemquantity);
					 //fseek(cfptr,(s.itemserial-1)*sizeof(struct item),SEEK_SET);//setting offset position to enter data
					  // fwrite(&s,sizeof(struct item),1,cfptr);
					  //printf("enter serial no. of next item :\n");
					  //scanf("%d",&s.itemserial); 
				   //}  
	//		}rewind(cfptr);//setting pointer to 0th position
		//	fclose(cfptr);
			
		//	if ((cfptr=fopen("item.txt","rb"))==NULL){//opening file to read in binary mode
			//	printf("file couldnt be loaded \n");
			//} else {
				  //  printf("items in database are :\n");
				  // fread(&s,sizeof(struct item),1,cfptr);//checking condition of serial number
				//printf("%s\t%s\t%s\t%s\t\n","Item Serial:","Item Name:","Item Price:","Item Quantity:");
				 //  while(!feof(cfptr)){
	//		 if(s.itemserial!=0){//sentinel value
			//			printf("%-17d%-15s\t%-15.2f\t%-15d\t\n",s.itemserial,s.itemname,s.itemprice,s.itemquantity);
		//	  } fread(&s,sizeof(struct item),1,cfptr);		 
						//  } 
					//}
			//rewind(cfptr);
			//fclose(cfptr);
			int choice;
			int quantityreq;
			int cash;
			int price=0;
			int option;
			cfptr=fopen("item.txt","rb+");
             printf("     Current items in database are :\n");
				  fread(&s,sizeof(struct item),1,cfptr);//checking condition of serial number
				printf("%s\t%s\t%s\t%s\t\n","Item Serial:","Item Name:","Item Price:","Item Quantity:");
				 while(!feof(cfptr)){
					 if(s.itemserial!=0){//sentinel value
					printf("%-17d%-15s\t%-15.2f\t%-15d\t\n",s.itemserial,s.itemname,s.itemprice,s.itemquantity);
		           } fread(&s,sizeof(struct item),1,cfptr);			
				 }
				printf("press 1 to enter as a customer\n");
			printf("press 2 to enter as a cashier \n");
			scanf("%d",&choice);
			switch(choice){
			case 1:
				if((cfptr=fopen("item.txt","rb+"))==NULL){
						printf("file couldn't be loaded\n");
				  }else {  printf("enter the serial number of item you want to buy :\n");
					      printf("or enter 0 to end shopping\n");
						scanf("%d",&s.itemserial);
						while(s.itemserial!=0){
						  fseek(cfptr,(s.itemserial-1)*sizeof(struct item),SEEK_SET);
						fread(&s,sizeof(struct item),1,cfptr);
						printf("enter the quantity of item you want to buy :\n");
						scanf("%d",&quantityreq);
						price=quantityreq*s.itemprice;
						printf("enter your cash please:\n");
						scanf("%d",&cash);
						if(cash<price){
							printf("sorry you don't have enough money to buy this item\n");
						}else {
							printf("here is your %s in quantity of %d and your balance is %d\n",s.itemname,quantityreq,cash-price);
						}
					printf("enter the serial number of next item please:\n");
					scanf("%d",&s.itemserial);
						}printf("    Thank you for shopping here !!!!\n");
						rewind(cfptr);
						fclose(cfptr);
				}  
			case 2:
				cfptr=fopen("item.txt","rb+");
				printf(" Enter your option that you want to select :\n"
					     "Press 1 to remove an item\n"
						 "Press 2 to update information of an item\n"
						 "Press 3 to add a new item\n");
				scanf("%d",&option);
				switch(option){
				case 1:
					removeitem(cfptr);
					break;
				case 2:
					updateitem(cfptr);
					break;
				case 3: 
					additem(cfptr);
			        break;
				default:
					printf("wrong choice entered \n");
					break;
		}
					
      break;}
			fclose(cfptr);
}
void removeitem(FILE *cfptr){
	        struct item s;
			struct item blank={0," ",0,0};
	printf("enter the serial number of item you want ot remove from database:\n");
	printf("or enter 0 serial number to exit form removing\n");
	scanf("%d",&s.itemserial);
	while (s.itemserial!=0){
		        fseek(cfptr,(s.itemserial-1)*sizeof(struct item),SEEK_SET);
		         fwrite(&blank,sizeof(struct item),1,cfptr);
				 printf("enter serial number of next item you want to remove\n");
				 scanf("%d",&s.itemserial);
} fclose (cfptr);
}  
	void updateitem(FILE *cfptr){
		         struct item s;
				 printf("enter the serial number of item whose info you want to update\n");
				 printf("Or enter 0 serial number to exit from updating\n");
				 scanf("%d",&s.itemserial);
				 while(s.itemserial!=0){
					 fseek(cfptr,(s.itemserial-1)*sizeof(struct item),SEEK_SET);
					 fread(&s,sizeof(struct item),1,cfptr);
					 printf("%-17d%-15s\t%-15.2f\t%-15d\t\n",s.itemserial,s.itemname,s.itemprice,s.itemquantity);
					 printf("enter the new price and quantity of this item:\n");
					 scanf("%lf%d",&s.itemprice,&s.itemquantity);
					  fseek(cfptr,(s.itemserial-1)*sizeof(struct item),SEEK_SET);
					  fwrite(&s,sizeof(struct item),1,cfptr);
					  printf("enter serial number of next item to update info:\n");
					  scanf("%d",&s.itemserial);
				 }  fclose(cfptr);
	}   
	void additem(FILE *cfptr){
		    struct item s;
			printf("enter serial number for new item:\n");
			printf("enter serial number 0 to exit\n");
			scanf("%d",&s.itemserial);
			while(s.itemserial!=0){
				fseek(cfptr,(s.itemserial-1)*sizeof(struct item),SEEK_SET);
				printf("enter name,price and quantity of this item:\n");
				scanf("%s%lf%d",&s.itemname,&s.itemprice,&s.itemquantity);
				fwrite(&s,sizeof(struct item),1,cfptr);
				printf("enter serial number of next item:\n");
				scanf("%d",&s.itemserial);
			}   fclose(cfptr);
	}
		

	     