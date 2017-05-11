/*==============================================================================
    > File Name: 堆排序.cpp
    > Author: zzq
    > Mail: zhengziqiang1@gmail.com 
    > Created Time: 2016年11月17日 星期四 16时47分46秒
 ==========================================================================*/

#include<iostream>
#include<vector>
using namespace std;
void adjust(int *a,int i,int size){
	int tmp=i;
	int left=i*2;
	int right=i*2+1;
	if(i<=(size/2)){
		if(left<=size&&a[left]>a[tmp])
			tmp=left;
		if(right<=size&&a[right]>a[tmp])
			tmp=right;
		if(tmp!=i){
			swap(a[i],a[tmp]);
			adjust(a,tmp,size);
		}
	}

}
void build(int *a,int size){
	for(int i=size/2;i>=0;i--){
		adjust(a,i,size);
	}
}
void heapsort(int *a,int size){
	build(a,size);
	for(int i=size-1;i>=1;i--){
		swap(a[1],a[i]);//交换堆顶和最后一个元素
		adjust(a,1,i-1);//重新调整堆节点成为大顶堆
	}
}
int main(){
	int a[5]={
		2,3,1,8,7
	};
	heapsort(a,5);
	for(int i=0;i<5;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
