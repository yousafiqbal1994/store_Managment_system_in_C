   Our project is about the database of a departmental store : it has two modes 1. as a customer 2. as a cashier









#include <stdio.h>
void removeitem(FILE *cfptr);
void additem(FILE *cfptr);
void updateitem (FILE *cfptr);
void userinfo(FILE *cuptr);
int k=0,j=0;
struct item{
	     int itemserial;
		 char itemname[200];
		 double itemprice;
		 int itemquantity;
} ;  
struct user{
 int userno;
	char name[100];
	int itemquantity;
	int itemserialno[200];
	double bill;
};
int main(){ struct user i;
	        struct item s;
			FILE *cuptr;
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
			double price[200]={0};
			int option;
			int j=0;
			int k=0;
			cuptr=fopen("user.txt","wb");
			cfptr=fopen("item.txt","rb+");
             printf("                   Current items in database are :\n");
				  fread(&s,sizeof(struct item),1,cfptr);//checking condition of serial number
				printf("%s\t%s\t%s\t%s\t\n","Item Serial:","Item Name:","Item Price:","Item Quantity:");
				 while(!feof(cfptr)){
					 if(s.itemserial!=0){//sentinel value
					printf("%-17d%-15s\t%-15.2f\t%-15d\t\n",s.itemserial,s.itemname,s.itemprice,s.itemquantity);
		           } fread(&s,sizeof(struct item),1,cfptr);			
				 }
				printf("\n       Press 1 to enter as a customer\n");
			    printf("       Press 2 to enter as a cashier \n");
			scanf("%d",&choice);
			switch(choice){
			case 1:
				if((cfptr=fopen("item.txt","rb+"))==NULL){
						printf("file couldn't be loaded\n");
				  }else {  printf("enter your name please :\n");
					 scanf("%s",&i.name);
					   printf("enter the user no. or enter 0 user no. exit\n");
					scanf("%d",&i.userno);
					   printf("enter the serial number of item you want to buy :\n");
                             printf("or enter 0 to end shopping\n");
						   scanf("%d",&s.itemserial);
						i.bill=0;
						fseek(cuptr,(i.userno-1)*sizeof(struct user),SEEK_SET);
						fwrite(&i,sizeof(struct user),1,cuptr);
						while(s.itemserial!=0){
								fseek(cfptr,(s.itemserial-1)*sizeof(struct item),SEEK_SET);
						fread(&s,sizeof(struct item),1,cfptr);
						printf("enter the quantity of item you want to buy :\n");
						scanf("%d",&quantityreq);
						price[j]=quantityreq*s.itemprice;
						i.bill=i.bill+price[j];
						i.itemserialno[j]=s.itemserial;
						i.itemquantity=quantityreq;
						s.itemquantity=s.itemquantity-quantityreq;
						   fseek(cfptr,(s.itemserial-1)*sizeof(struct item),SEEK_SET);
							fwrite(&s,sizeof(struct item),1,cfptr);
							fseek(cuptr,(i.userno-1)*sizeof(struct user),SEEK_SET);
							fwrite(&i,sizeof(struct user),1,cuptr);
							if (s.itemquantity<=0){
								printf("   \n  The stock of this item has been ended!  \n");
								printf("       Ask the cashier to update it's quantity:    \n");
									} else
						printf("\n  enter the serial number of next item please or enter serial no. 0 to exit \n");
					      scanf("%d",&s.itemserial);
						  
							    
						++j;
						++k;
						  
							}
			      fseek(cuptr,(i.userno-1)*sizeof(struct user),SEEK_SET);
						fwrite(&i,sizeof(struct user),1,cuptr);
							rewind(cuptr);
						fclose(cuptr);
						printf(" your total bill is : %.2f\n",i.bill);
						printf("enter your cash please:\n");
						   scanf("%d",&cash);
						   if(cash<i.bill){
							printf("\n  sorry you don't have enough money to buy this item\n");
						} else{
							printf(" \n Here are ur details :\n");
							cuptr=fopen("user.txt","rb");
							fread(&i,sizeof(struct user),1,cuptr);
							printf("%s%15s%24s%18s%18s\n","UserNo:","User Name:","Serials of item:","Quantity:","Bill:");
							i.bill=0;
							while(!feof(cuptr)){
								for(j=0;j<k;j++){	
								if(i.itemserialno[j]!=0){
									printf("%d ",i.userno);
									printf("%20s",i.name);
									printf("%20d",i.itemserialno[j]);
									printf("%17d  ",i.itemquantity);
									printf("%20.2f\n",price[j]);
								i.bill=price[j]+i.bill;
							}  fread(&i,sizeof(struct user),1,cuptr);
								
							}printf("\n   Your total bill is : %.2f",i.bill);
							}printf("\n    Your balance is %.2f \n",cash-i.bill);
				printf("    \n        Thank you for shopping here !!!!\n");
						 }rewind(cfptr);
						fclose(cfptr);
			fwrite(&i,sizeof(struct user),1,cuptr);	}
				rewind(cuptr);
				
				  fclose(cuptr);
					  break;
			case 2:
				cfptr=fopen("item.txt","rb+");
				printf(" \n         Enter your option that you want to select :\n"
					     "Press 1 to remove an item\n"
						 "Press 2 to update information of an item\n"
						 "Press 3 to add a new item\n"
						 "Press 4 to view user's info\n");
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
				case 4:
					userinfo(cuptr);
					break;
				default:
					printf("wrong choice entered \n");
					break;
		}
					
      break;
			default:
				printf(" Wrong choice entered \n");
				break;
			
			}
			

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
				 int choice;
				 printf("Enter the serial number of item whose info you want to update\n");
				 printf("Or enter 0 serial number to exit from updating\n");
				 scanf("%d",&s.itemserial);
				 while(s.itemserial!=0){
					 fseek(cfptr,(s.itemserial-1)*sizeof(struct item),SEEK_SET);
					 fread(&s,sizeof(struct item),1,cfptr);
					 printf("Info of this item is : \n");
					 printf("%s%12s%22s%17s\n","Serial No.:","Name:","Price:","Quantity:");
					 printf("%-17d%-15s\t%-15.2f\t%-15d\t\n",s.itemserial,s.itemname,s.itemprice,s.itemquantity);
					 printf("\n Press 1 to change price of item\n");
					 printf(" Press 2 to change quantity of item\n");
					 scanf("%d",&choice);
					 switch(choice){
					 case 1:
						 printf("enter new price of this item:\n");
						 scanf("%lf",&s.itemprice);
					  fseek(cfptr,(s.itemserial-1)*sizeof(struct item),SEEK_SET);
					  fwrite(&s,sizeof(struct item),1,cfptr);
					  
                      break;
					 case 2:
						 printf("enter new quantity of this item:\n");
						 scanf("%d",&s.itemquantity);
						 fseek(cfptr,(s.itemserial-1)*sizeof(struct item),SEEK_SET);
					  fwrite(&s,sizeof(struct item),1,cfptr);
					 break;
				
					}
					printf("enter serial number of next item to update info:\n");
					  scanf("%d",&s.itemserial);
					  
	}    fclose(cfptr);
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
				printf("enter serial number of next item to enter:\n");
				scanf("%d",&s.itemserial);
			}   fclose(cfptr);
	}
void userinfo(FILE *cuptr){
	             struct user i;
				 
				 cuptr=fopen("user.txt","rb");
				
				 printf("enter user's no whose record is required :\n");
				 scanf("%d",&i.userno);
				  printf("%s%15s%24s%18s%18s\n","UserNo:","User Name:","Serials of item:","Quantity:","Bill:");
				 fseek(cuptr,(i.userno-1)*sizeof(struct user),SEEK_SET);
				 fread(&i,sizeof(struct user),1,cuptr);
				 while(i.itemserialno!=0){
					  		printf("%d ",i.userno);
									printf("%20s",i.name);
                               	printf("%20d,",i.itemserialno[j]);
									printf("%17d  ",i.itemquantity);
									printf("%20.2f\n",i.bill);
									i.bill=i.bill+i.bill;
							
				  
								fread(&i,sizeof(struct user),1,cuptr);
				j++;  }
								printf("\n total bill was : %.2f\n",i.bill);
} 
	     