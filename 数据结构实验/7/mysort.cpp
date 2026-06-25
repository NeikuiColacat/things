#include <bits/stdc++.h>
using namespace std;
//堆排序
void heap_sort(vector<int>&h,int n) {
    int _size=n;
    auto down = [&](int x,auto self)->void {
        //表下标
        //小于等于size是因为要保证存在左右节点，并且要保证up上来的节点是两个子节点中较小的一个
        int temp = x;
        if (x * 2 <= _size && h[x] > h[2 * x])temp = 2 * x;
        if (x * 2 + 1 <= _size && h[2 * x + 1] < h[temp]) temp = x * 2 + 1;
        if (temp != x) {
            swap(h[x], h[temp]);
            self(temp,self);
        }
    };
    for (int i = 1;i < n;i++) cin >> h[i];
    for (int i = n / 2;i;i--) down(i,down);
    while (n--) {
        h[1] = h[_size--];
        down(1,down);
    }
}
//快排
void quick_sort(vector<int>& a, int l, int r) {
    if (l >= r)return;
    int i = l - 1;
    int j = r + 1;
    int x = a[l + r >> 1];
    while (i < j) {
        do i++;while (a[i] < x);//注意不能取等于，保证当标志数取到最大值或最小值的时候左边右边的指针不会数组越界。
        do j--;while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}
//归并排序
vector<int> temp(1e4);
void merge_sort(vector<int>& a, int l, int r) {
	if (l >= r) return;
	int mid = l + r >> 1;
	merge_sort(a, l, mid);
	merge_sort(a, mid + 1, r);
	int i = l, j = mid + 1,cnt =0;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j])temp[cnt++] = a[i++];//取小于等于，若遇到两个数据相等取第一个数放入temp，故稳定排序
		else temp[cnt++] = a[j++];
	}
	while (i <= mid) temp[cnt++] = a[i++];
	while (j <= r) temp[cnt++] = a[j++];
	for (int i = l,j=0; i <=r; i++,j++) a[i] = temp[j];
}

const int N = 1e5;
vector<int> A(1e5+10);
mt19937 gen(100);
uniform_int_distribution<int> distribution(1, N);
void merge_test() {
    int t = 10;
    //10个测试样例随机数
    while (t--) {
        for (int i = 1;i <= N;i++) {
            A[i] = distribution(gen);
        }
        merge_sort(A, 1, N);
    }
    //有序和逆序数据测试
    for (int i = 1;i <= N;i++) A[i] = i;
    merge_sort(A, 1, N);
    for (int i = 1;i <= N;i++) A[i] = N - i + 1;
    merge_sort(A, 1, N);
}
void qsort_test() {
    int t = 10;
    //10个测试样例随机数
    while (t--) {
        for (int i = 1;i <= N;i++) {
            A[i] = distribution(gen);
        }
        quick_sort(A, 1, N);
    }
    //有序和逆序数据测试
    for (int i = 1;i <= N;i++) A[i] = i;
    quick_sort(A, 1, N);
    for (int i = 1;i <= N;i++) A[i] = N - i + 1;
    quick_sort(A, 1, N);
}
void heap_test() {
    int t = 10;
    //10个测试样例随机数
    while (t--) {
        for (int i = 1;i <= N;i++) {
            A[i] = distribution(gen);
        }
        heap_sort(A, N);
    }
    //有序和逆序数据测试
    for (int i = 1;i <= N;i++) A[i] = i;
    heap_sort(A, N);
    for (int i = 1;i <= N;i++) A[i] = N - i + 1;
    heap_sort(A, N);
}
int main() {
    //执行时间测试
    auto func = [&](auto function) {
        auto start_time = std::chrono::high_resolution_clock::now();
        function();
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        std::cout << "程序执行时间: " << duration.count() << " 毫秒" << std::endl;
    };
    func(merge_test);
    func(qsort_test);
    func(heap_test);
    return 0;
}