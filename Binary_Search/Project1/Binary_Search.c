#include<stdio.h>
#include<windows.h>

//���ֲ��ң�������������
int binary_search(int array[], int lenth, int x){//����������鳤��Ҳ������

	//���ֲ��ң��ҵ������±꣬δ�ҵ�����-1
	int left = 0;//����±�
	int right = lenth - 1;//�Ҳ��±�
	int mid = 0;//�м�Ԫ��ֵ�±�
	while (left <= right){//���������±겻������ʱ���һֱѭ��
		mid = left + ((right - left) >> 1);//�����м��±�ֵ
		if (x > array[mid]){//��С���ҷ�Χ
			left = mid + 1;
		}
		else if (x < array[mid]){
			right = mid - 1;
		}
		else if (x == array[mid]){
			return mid;//�����±�
		}
	}
	return -1;
}
//������ֲ��ҵ��㷨Ҳ�����õݹ�ʵ��
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
/*���Ͼ��� 
��һ����ά����. 
�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����. 
�������������в���һ�������Ƿ���ڡ� 
ʱ�临�Ӷ�С��O(N); 

���飺 
1 2 3 
2 3 4 
3 4 5 


1 3 4 
2 4 5 
4 5 6 

1 2 3 
4 5 6 
7 8 9 */
//�ҵ�����1��δ�ҵ�����-1
//��Ϊ�±������������ز�������������ֻ��ͨ���ı��ⲿ�Ѿ�����õ�ĳЩ����
//ͨ���������������ⲿ����ͨ��ָ��ı�
//���Զ��������ṹ��Ƚ��������
//
int search(int array[][3], int i, int j, int x){//i��j�Ǿ����С
	//�����۰���ң����м�Ԫ�ؽ����������Ϊ���룬���Ӿ����ԭ���������ͬ����
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