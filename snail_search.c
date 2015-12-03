/**
 * date : 2015-12-03
 * file : snail_search.c
 * author : Chae Mi Rue
 */
#include <stdio.h>
#include <stdlib.h>

/*===========array initialize start=============*/
/*
 * 배열의 size를 받아와서 동적할당한후 포인터 주소를 반환하여 줍니다.
*/
int** initialize_array(int size){
	int i = 0;
	int j = 0;
	int num = 1;
	int **temp_arr = (int**)malloc(sizeof(int*) * size);
	
	for(i = 0; i < size; i++)
		temp_arr[i] = (int*)malloc(sizeof(int) * size);
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j++)
			temp_arr[i][j] = num++;
	return temp_arr;
}
/*===========array initialize end=============*/
/*
 * 이중포인터를 동적할당 하였으므로, 반복문을 통해 할당한 메모리를 해제하여 Memory leek을 방지합니다.
*/
void free_array(int** array, int size){
	int i = 0;
	for(i = 0; i < size; i++) free(array[i]);
	free(array);
}
/*===========search start=============*/
/*
 * 배열을 달팽이 모양으로 탐색을 하고 프린트 해줍니다.
 * 탐색을 하나 할 때마다 탐색한 곳을 0으로 채움으로써 배열의 모든 요소를 거쳤는지 체크하여 유효성 검사를 실시합니다.
*/
void search_to_array(int **array, int size){
	int row = size-1;
	int column = size-1;
	int i = size;
	
	for(i = 0; i < size; i++) { 
		printf("%d -> ", array[row--][column]); 
		array[row+1][column] = 0;
	}
	row++;
	int count = size - 1;

	while(count > 0){
		for(i = 0; i < count; i++){
			column--;
			printf("%d -> ", array[row][column]);
			array[row][column] = 0;
		}
		for(i = 0; i < count; i++){
			row++;
			printf("%d -> ", array[row][column]);
			array[row][column] = 0;
		}
		count--;
		for(i = 0; i < count; i++){
			column++;
			printf("%d -> ", array[row][column]);
			array[row][column] = 0;
		}
		for(i = 0; i < count; i++){
			row--;
			printf("%d -> ", array[row][column]);
			array[row][column] = 0;
		}
		count--;
	}
	
}
/*===========search end=============*/

/*===========Number range check start==========*/
/*배열의 크기 N의 범위를 체크하는 부분입니다.*/
int range_check(int size){
	if(size > 100 || size < 1){
		printf("Range is 1 to 100\n");
		return -1;
	}
	return 0;
}
/*==============Number range check end===============*/
/*==============validation_array start===============*/
/*이 부분을 실행하여 모든 배열이 0이 된다면 배열의 모든 요소를 탐색했음을 알 수 있습니다.*/
void validation_array(int **array, int size){
	int i, j;

	printf("\n");
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}
/*==============validation_array end===============*/

/*===========main function start==========*/
/*프로그램 실행시 첫번째 argument로 배열의 크기를 입력받도록 하였습니다.*/
int main(int argc, char** argv){
	int size = atoi(argv[1]);

	printf("size :: > %d X %d\n", size, size);
	
	if(range_check(size) == -1) return 0;

	int **array = initialize_array(size);
	search_to_array(array, size);
	validation_array(array, size);
	free_array(array, size);
	return 0;
}
/*===========main function end==========*/
