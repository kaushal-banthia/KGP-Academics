//loops and nested loops
//branch cndition
int x = 0;

int main()
{
	int matrux[4][4];
	int i,j,k;
	int n=4;
	i=0;
	int a=3,r=2;
	
	while(i<4){//while loop
		for(j=0;j<4;j++){//nested for loop
			matrux[i][j] = a;
			a *= r;
		}
		i++;
	}
	i=3;
	do{//do while loop
		matrux[i][i] = 0;
		i--;
	}	while (i!=0);
	int sum=0;
	float avg;
	for(i=0;i<4;i++){
		for(j=3;j>=0;j--){
			sum+=matrux[i][j];
		}
	}
	avg = (float)sum/16;
	printf("average: %d",avg);
	return 0;
}