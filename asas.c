#include <stdio.h>
struct store{
	        int itemserial;
		  char itemname[200];
			double itemprice;
		  int itemquantity;
}; int main(){      int i=0;
	int request;
	struct store s[20]={0};
				FILE *cfptr;
				if((cfptr=fopen("store.txt","w"))==NULL){
					   printf("File couldn't be loaded\n");
				}else { printf("enter the items you want to include in your store :\n");
							printf("or enter EOF to end input \n");
							printf("?\n");
							printf("enter the serial number,name,price(Rs.) and quantity of your item :\n");
							fprintf(cfptr,"%s%20s%20s%20s\n","Serial No:","Item Name:","Item price:","Item Quantity:");
							for(i=0;i<3;i++){
							scanf("%d%s%lf%d",&s[i].itemserial,&s[i].itemname,&s[i].itemprice,&s[i].itemquantity);
							 	  fprintf(cfptr,"%d\t %20s\t %10.2fRs.\t %10d\t\n",s[i].itemserial,s[i].itemname,s[i].itemprice,s[i].itemquantity);
								   printf("?Next item's info please:\n");
					} 
							  }	 
				rewind(cfptr);
							  fclose(cfptr);
				printf("          Items in your current database are :\n");
				if((cfptr=fopen("store.txt","r"))==NULL){
					  printf("Your file coudln't be loaded\n");
				}else{    printf("%s %15s %15s %15s\n","Serial No:","Item Name:","Item price:","Item Quantity:"); 
				i=0;                      
				for(i=0;i<3;i++){
				fscanf(cfptr,"%d%s%lf%d",&s[i].itemserial,&s[i].itemname,&s[i].itemprice,&s[i].itemprice);
			printf("%d\t %20s\t %10.2f\t %10d\t\n",s[i].itemserial,s[i].itemname,s[i].itemprice,s[i].itemquantity);
					}
				fclose(cfptr);
				}  return 0;
}

	           