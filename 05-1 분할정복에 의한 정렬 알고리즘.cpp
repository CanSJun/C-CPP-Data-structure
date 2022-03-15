#include <iostream>

using namespace std;

/*
ㅇ분할정복(divide and conquer)
-주어진 문제의 규모가 너무 커서 한번에 해결하기 어려운 경우
이를 작은 부분 문제로 나누어서 해결하는 방식이다.

3가지 단계로 나뉜다
1.분할(divide) : 주어진 문제를 동일한 방식으로 해결할 수 있는 부분 문제로 나누기
2.정복(conquer) : 각 부분 문제에 대한 솔루션/해결방법 구하기
3.결합(combine) : 각 부분 문제의 솔루션을 결합하여 전체 문제에 대해 솔루션 구하기


ㅇ정렬에는
병합정렬(merge sort)
퀵정렬(quick sort)
힙정렬(heap sort)

이 강의에선 병합 , 퀵 정렬을 본다

ㅇ병합정렬
-분할 정복에 의한 정렬 알고리즘 중 하나이다.
-입력 배열을 두개의 부분 배열로 분할
-부분 배열을 재귀적으로 정렬
각 부분 배열의 원소가 하나가 될때까지 반복한다.
-부분 배열을 병합한다
이때 병합된 배열의 원소가 정해진 정렬 순서에 부합되도록 순서를 조정

ex)26741853
->2674 1853
->26 74 18 53
->2 6 7 4 1 8 5 3
->병합할때 오름차순 또는 내림차순 형태로 2개를 병합
->26 47 18 35
->2467 1358
->12345678

될떄 2467 1358 이 있다면
k로 병합된 배열에 지정해주고 서로 두개의 배열을 i j 로 지정해서
두개를 비교해 작은걸 k에 넣어주고 그 배열의 값을 ++를 시켜서 쭉 해준다.

시간의 복잡도는 
-배열을 분할 또는 병합하는 단계 :  log2  n
-부분배열을 병합하는 경우는 하나씩 참조하는 과정이 있다. 그러면 넣은 값에 비례 : O(n)
두개를 합쳐서 O(n log n) 이다.

ㅇ병합정렬의 특징
-실제 정렬이 이루어지는 시점은 두개의 부분 배열이 병합하는 단계이다.
-안정된 정렬이며, 데이터의 초기 순서에 영향을 크게 받지 않는다.
-병합 과정에서 임시 배열을 필요로 한다 (공간 복잡도 : O(n))


사용법

int data[] = {2,6,7,4,1,8,5,3};
merge_sort(data, 0, 7);


*/
int buff[255];
void merge(int data[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right) {
		if (data[i] <= data[j]) buff[k++] = data[i++];
		else
			buff[k++] = data[i++];
	}
	while (i <= mid)
		buff[k++] = data[i++];
	while (j <= right)
		buff[k++] = data[j++];

	for (int x = left; x <= right; x++)data[x] = buff[x];
}
void merge_sort(int data[], int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(data, left, mid); // 왼쪽배열 
		merge_sort(data, mid + 1, right); // 오른쪽 배열
		merge(data, left, mid, right);
	}

}

/*
ㅇ퀵 정렬
-분할 정복에 의한 정렬 알고리즘이다
-특정 원소를 피벗(pivot)으로 선택하고, 주어진 배열을 피벗보다 작은 부분과 큰 부분으로 분할
해서 분할된 부분배열에 대해 재귀적으로 퀵 정렬 분할 작업을 반복한다.

ex) 5 6 7 3 1 9 2 4 8
여기서 5를 피벗으로하면

1 4 2 3 (작은 원소)  5  ( 큰 원소 )9 7 6 8 이다
여기서 또 피벗을 나누다 보면
작은값이 앞으로가고 큰 값이 뒤로가는 오름차순으로 정렬이 된다.

즉 왼쪽에선 5보다 큰 값을 찾고 오른쪽은 5보다 작은걸 찾아서 서로 swap해준다.

ㅇ시간복잡도
최선의 경우 :  O(n log n) (입력 배열이 두개로 나누어지는 과정이 전체 log2의 n만큼 단계로 생각 할 수 있고 각 단계에서 
입력 단계에서 피벗 보다 작은건 외족 오른쪽은 오른쪽으로 재 배치하는 과정이 O(n)만큼의 시간 복잡도로 나타낼 수 있어서다)

최악의 경우: O(n^2) (한쪽은 1개, 다른쪽은 n-1개로 분할되는경우 )

즉 한개 여러개
한개 여러개
한개 여러개

ㅇ퀵정렬 특징
-실제 정렬이 이루어지는 시점이 배열 피벗 기준으로 분할하는 단계이다
-안정되지 않은 정렬이다. 데이터의 초기 순서의 영향을 크게 받는다
-평균저긍로 가장 빠른 정렬 알고리즘이다


사용법

int data[] = {5,6,7,3,1,9,2,4,8};
quick_sort(data, 0, size(data) - 1);
*/

int partition(int data[],int left,int right) {
	int pivot = data[left];
	int i = left + 1, j = right;

	while (true) {
		while (data[i] <= pivot && i <= right)
			i++;
		while (data[j] > pivot && j > left)j--;
		if (i < j)
			swap(data[i], data[j]);
		else
			break;
	}
	swap(data[left], data[j]);
	return j;
}
void quick_sort(int data[], int left, int right) {
	if (left < right) {
		int p = partition(data, left, right); // 입력 배열이 있으면 첫번쨰원소를 피벗으로
		//설정하고 가운대로 위치시키고 작은건 왼쪽, 큰건 오른족으로 배열을 재 배치하는 함수
		quick_sort(data, left, p - 1);
		quick_sort(data, p + 1, right);
	}
}