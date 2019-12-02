#include<stdio.h>
#include<windows.h>

//二分查找，假设数组升序
int binary_search(int array[], int lenth, int x){//把数组和数组长度也传进来

	//二分查找，找到返回下标，未找到返回-1
	int left = 0;//左侧下标
	int right = lenth - 1;//右侧下标
	int mid = 0;//中间元素值下标
	while (left <= right){//左右两个下标不相遇的时候就一直循环
		mid = left + ((right - left) >> 1);//计算中间下标值
		if (x > array[mid]){//缩小查找范围
			left = mid + 1;
		}
		else if (x < array[mid]){
			right = mid - 1;
		}
		else if (x == array[mid]){
			return mid;//返回下标
		}
	}
	return -1;
}
//这个二分查找的算法也可以用递归实现
int Binary_Search(int arr[],int len,int x){
	int left = 0;
	int right = len - 1;
	int mid = 0;
	while (left <= right){
		mid = left + ((right - left) >> 1); 
		if (x > arr[mid]){
			return Binary_Search(arr+mid, right-mid, x);
		}
		else if (x < arr[mid]){
			return Binary_Search(arr, mid - 1, x);
		}
		else if(x == arr[mid]){
			return mid;
		}
	}
	return -1;
}
/*杨氏矩阵 
有一个二维数组. 
数组的每行从左到右是递增的，每列从上到下是递增的. 
在这样的数组中查找一个数字是否存在。 
时间复杂度小于O(N); 

数组： 
1 2 3 
2 3 4 
3 4 5 


1 3 4 
2 4 5 
4 5 6 

1 2 3 
4 5 6 
7 8 9 */
//找到返回1，未找到返回-1
//因为下标是两个，返回不了两个数，则只能通过改变外部已经定义好的某些变量
//通过将传进函数的外部参数通过指针改变
//可以定义数组或结构体等将结果带出
//
int search(int array[][3], int i, int j, int x){//i，j是矩阵大小
	//类似折半查找，找中间元素将整个矩阵分为两半，其子矩阵跟原矩阵具有相同规律
	int mid_row = i >> 1;
	int mid_col = j >> 1;
	while (mid_row >= 0 && mid_row < i&&mid_col >= 0 && mid_col<j){
		if (x > array[mid_row][mid_col]){
			mid_row = (mid_row + 1 + i) >> 1;
			mid_col = (mid_col + 1 + j) >> 1;

		}
		else if (x < array[mid_row][mid_col]){
			mid_row = (mid_row - 1) >> 1;
			mid_col = (mid_col - 1) >> 1;
		}
		else if (x == array[mid_row][mid_col]){
			return 1;
		}
	}
	return -1;
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int ret = 0;
	ret = binary_search(arr, sizeof(arr) / sizeof(arr[0]), 5);
	printf("%d\n", ret);
	ret = binary_search(arr, sizeof(arr) / sizeof(arr[0]), 12);
	printf("%d\n", ret);

	ret = Binary_Search(arr, sizeof(arr) / sizeof(arr[0]), 5);
	printf("%d\n", ret);
	ret = Binary_Search(arr, sizeof(arr) / sizeof(arr[0]), 12);
	printf("%d\n", ret);
	
	int yang_arr[3][3] = { 
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 } };
	ret = search(yang_arr, 3, 3, 5);
	printf("%d\n", ret);

	ret = search(yang_arr, 3, 3, 12);
	printf("%d\n", ret);


	system("pause");
	return 0;
}