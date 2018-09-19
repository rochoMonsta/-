#include <stdio.h>

typedef struct misto{
    int index;
    int misto;
    char street[20];
    int number;
}year;

int to_Vvid (year rc[], int n){
	int a;
	for (a=0; a<n; a++){
		printf("\n%d Index mista: ", a+1);
    	scanf("%d", &rc[a].index);
    	printf("\n%d Misto: ", a+1);
    	scanf("%d", &rc[a].misto);
    	while (rc[a].misto>5 || rc[a].misto<0){
    		scanf("%d", &rc[a].misto);
		}
    	printf("\n%d Street: ", a+1);
    	scanf("%s", &rc[a].street);
    	printf("\n%d Nomer Bydunky: ", a+1);
    	scanf("%d", &rc[a].number);
    }
}

int to_Sort (year rc[], int n, year b){
	int a, k;
	for (k=0; k<n-1; k++){
		for (a=0; a<n-1; a++){
			if(rc[a].index>rc[a+1].index){
				b=rc[a];
				rc[a]=rc[a+1];
				rc[a+1]=b;
			}else{
				continue;
			}
		}
	}
}

int to_Comparison (year rc[], int n,  int rocho[]){
	int i, a;
	for (i=0; i<n; i++){
		switch (rc[i].misto){
			case 1:  rocho[0]+=1;  break;
			case 2:  rocho[1]+=1;  break;
			case 3:  rocho[2]+=1;  break;
			case 4:  rocho[3]+=1;  break;
			case 5:  rocho[4]+=1;  break;
		}
	}
}

int to_zanes(int rocho[]){
	int i; 
	for (i=0; i<5; i++){
		rocho[i]=0;
	}
}

int to_Max (int rocho[]){
	int a=0;
	int max;
	if (rocho[a]<rocho[a+1]){
		max=rocho[a+1];
	}else{
		max=rocho[a];
	}
	for (a=2; a<5; a++){
		if (max<rocho[a]){
			max=rocho[a];
		}else{
			max=max;
		}
	}
	return max;
}

int to_find (int z, int rocho[]){
	int i, a=0;
	for (i=0; i<5; i++){
		if (z==rocho[i]){
			break;
		}else{
			a++;
		}
	}
	return a;
}



int main(void){
	int M, i, z, a;
	int mass[5];
	to_zanes(mass);
	char sity[5][20]={"NewYork", "Brooklyn", "NewJersey", "SanFrancisco", "Chicago"};
	printf("VVedit kilkist Mist: ");
	scanf("%d", &M);
	year mas[M], *pst, b;
	printf("VVedit nomer Mista:\n NewYork-1\n Brooklyn-2\n NewJersey-3\n SanFrancisco-4\n Chicago-5\n");
	to_Vvid (mas, M);
	printf("------Vashi Mista (neuporyadkovani)------\n\n");
	for (pst=mas; pst<(mas+M); pst++){
		printf("Index mista: %d   Misto: %s   Street: %s   NomerHouse: %d   \n", pst->index, sity[pst->misto-1], pst->street, pst->number);
	}
	printf("\n\n");
	to_Comparison (mas, M, mass);
	to_Sort (mas, M, b);
	z=to_Max (mass);
	a=to_find (z, mass);
	printf("------Vashi Mista (uporyadkovani)------\n\n");
	for (pst=mas; pst<(mas+M); pst++){
		printf("Index mista: %d   Misto: %s   Street: %s   NomerHouse: %d   \n", pst->index, sity[pst->misto-1], pst->street, pst->number);
	}
	
	printf ("\n\nMisto z Max: %s = %d", sity[a], z);
	return 0;
	
}
