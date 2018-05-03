#include<stdio.h>

int a[4][4],i_pos,j_pos;

int num[2] = { 2,4 };

void print() {

	int i,j;
	printf("Matrix \n");
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}	

}

void get_value() {
	i_pos = rand() % 4;	
	j_pos = rand() % 4;

	while(a[i_pos][j_pos]) {
		get_value();
	}
}

void swapZerosFromLeft() {
	int i,j,k;

	for(i=0;i<4;i++) {
		j=0;k=0;
		while(j<4 && k<4) {
			k=j+1;
			while(j<4 && a[i][j] != 0)
				j+=1;
			while(k<4 && a[i][k] == 0) 
				k+=1;

			if(k>j && j<4 && k<4) {
				int temp = a[i][j];
				a[i][j] = a[i][k];
				a[i][k] = temp;
			}

		}
	}

}

void addFromLeft() {
	int i,j,k;

	for(i=0;i<4;i++) {
		for(j=0;j<3;j++) {
			if(a[i][j] == a[i][j+1]) {
				a[i][j] = a[i][j] + a[i][j+1];
				a[i][j+1] = 0;
			}
		}
	}
}


void moveLeft() {
	swapZerosFromLeft();
	// printf("\nAfter swapZerosFromLeft :");
	// print();
	
	addFromLeft();
	// printf("\nAfter addFromLeft :");
	// print();
	

	swapZerosFromLeft();
	// printf("\nAfter swapZerosFromLeft :");
}


/* Move Right code */
void swapZerosFromRight() {
	int i,j,k;

	for(i=0;i<4;i++) {
		j=3;k=3;
		while(j>=0 && k>=0) {
			k=j-1;
			while(j>=0 && a[i][j] != 0)
				j-=1;
			while(k>=0 && a[i][k] == 0) 
				k-=1;
			if(k<j && j>=0 && k>=0) {
				int temp = a[i][j];
				a[i][j] = a[i][k];
				a[i][k] = temp;
			}
		}
	}
}


void addFromRight() {
	int i,j,k;

	for(i=0;i<4;i++) {
		for(j=3;j>0;j--) {
			if(a[i][j] == a[i][j-1]) {
				a[i][j] = a[i][j] + a[i][j-1];
				a[i][j-1] = 0;
			}
		}
	}
}


void moveRight() {

	swapZerosFromRight();

	addFromRight();

	swapZerosFromRight();

}


/*  Move Top Code  */
void swapZerosFromTop() {
	int i,j,k;

	for(i=0;i<4;i++) {
		j=0;k=0;
		while(j<4 && k<4) {
			k=j+1;
			while(j<4 && a[j][i] != 0)
				j+=1;
			while(k<4 && a[k][i] == 0) 
				k+=1;

			if(k>j && j<4 && k<4) {
				int temp = a[j][i];
				a[j][i] = a[k][i];
				a[k][i] = temp;
			}

		}
	}
}


void addFromTop() {
	int i,j,k;

	for(i=0;i<4;i++) {
		for(j=0;j<3;j++) {
			if(a[j][i] == a[j+1][i]) {
				a[j][i] = a[j][i] + a[j+1][i];
				a[j+1][i] = 0;
			}
		}
	}
}




void moveTop() {

	swapZerosFromTop();

	addFromTop();

	swapZerosFromTop();

}


/* Move Bottom code */
void swapZerosFromBottom() {
	int i,j,k;

	for(i=0;i<4;i++) {
		j=3;k=3;
		while(j>=0 && k>=0) {
			k=j-1;
			while(j>=0 && a[j][i] != 0)
				j-=1;
			while(k>=0 && a[k][i] == 0) 
				k-=1;
			if(k<j && j>=0 && k>=0) {
				int temp = a[j][i];
				a[j][i] = a[k][i];
				a[k][i] = temp;
			}
		}
	}
}


void addFromBottom() {
	int i,j,k;

	for(i=0;i<4;i++) {
		for(j=3;j>0;j--) {
			if(a[j][i] == a[j-1][i]) {
				a[j][i] = a[j][i] + a[j-1][i];
				a[j-1][i] = 0;
			}
		}
	}
}


void moveBottom() {

	swapZerosFromBottom();

	addFromBottom();

	swapZerosFromBottom();

}


void insertAt(int i, int j, int value) {
	a[i][j] = value;
}


int check_for_win() {
	int i,j;
	for(i=0;i<4;i++) 
		for(j=0;j<4;j++)
			if(a[i][j] == 64) 
				return 1;
	return 0;
}

int check_for_lose() {
	int i,j;
	for(i=0;i<4;i++) 
		for(j=0;j<4;j++)
			if(a[i][j] == 0) 
				return 0;
	return 1;	
}


int main() {
	int i,j,k,n,value,play,lose;

/*
	for(i=0;i<4;i++)
		for(j=0;j<4;j++) 
			scanf("%d",&a[i][j]);
*/
	get_value();
	value = rand() % (1 + 1 - 0) + 0;
	insertAt(i_pos,j_pos,num[value]);

	get_value();
	value = rand() % (1 + 1 - 0) + 0;
	insertAt(i_pos,j_pos,num[value]);

	print();

	printf("Moves : 1. Left 2. Right 3. Top 4. Bottom\n");

	do {
		int choice;
		scanf("%d",&choice);

		switch(choice) {
			case 1 :
				moveLeft();
				break;
			case 2 :
				moveRight();
				break;
			case 3 :
				moveTop();
				break;
			case 4 :
				moveBottom();
				break;
			default :
				break;

		}

		play = check_for_win();
		lose = check_for_lose();

		if(play!=1 && lose != 1) {
			get_value();
			value = ((rand() % 2) + (rand() % 2))%2;
			insertAt(i_pos,j_pos,num[value]);
			print();
		}
		printf("play : %d && lose : %d\n", play,lose);
	}while(play!=1 && lose != 1);
		
	if(play && !lose) {
		printf("Hurray You won\n");
		print();
	}

	if(!play && lose) {
		printf("Sorry You lose !!! Try again\n");
	}

	return 0;
}