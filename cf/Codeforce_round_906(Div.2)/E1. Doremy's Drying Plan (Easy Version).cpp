#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {

    }
  }
}
#include<iostream>
#include<cstdio>
#define MaxSize 1000
using namespace std;

// 定义树结点结构
struct node{		
	int l;		// 结点表示的左端点
	int r;		// 结点表示的右端点
	int data;	// 结点表示的区间的和
	int lz;		//	懒惰标记
}tree[MaxSize];	// 线段树需要开辟 4*n + 1 的空间	

void build_tree(int arr[],node tree[],int i,int start,int end){
	// 建树
	//	以 i 编号 为根节点，建立 arr[start,end] 的线段树
	tree[i].l = start;
	tree[i].r = end;

	// 递归出口
	if(start == end){
		tree[i].data = arr[start];
		return ;
	}


	int mid = (start + end) / 2;
	int left_node  = 2 * i;
	int right_node = 2 * i + 1;
	build_tree(arr,tree,left_node, start,mid);
	build_tree(arr,tree,right_node,mid+1,end);
	tree[i].data = tree[left_node].data + tree[right_node].data;
	return ;

}

/*
int search(int arr[],node tree[],int i,int L,int R){
	// 区间查询

	// 剪枝，完全被包含，则不用往下
	if(tree[i].l >= L && tree[i].r <= R)	return tree[i].data;

	// 剪枝，若没有交集，则返回0
	if(tree[i].l > R || tree[i].r < L)	return 0;

	// 递归出口
	if(tree[i].l == tree[i].r){
		return tree[i].data;
	}

	int mid = (tree[i].l + tree[i].r) / 2;
	int left_node  = 2 * i;
	int right_node = 2 * i + 1;
	int s = 0;
	if(mid >= L ){
		// 左儿子有交集，则查询左儿子
		s += search(arr,tree,left_node,L,R);
	}
	if(mid+1 <= R){
		// 右儿子有交集，则查询右儿子
		s += search(arr,tree,right_node,L,R);
	}
	return s;

}*/

void add(int arr[],node tree[],int i,int idx,int val){
	//单点修改,将 arr[idx] 的值的变化量 val ，并更新 tree[]

	if(tree[i].l == tree[i].r){
		tree[i].data += val;
		arr[idx] += val;
		return ;
	}

	int mid = (tree[i].l + tree[i].r) / 2;
	int left_node  = 2 * i;
	int right_node = 2* i + 1;

	if(idx <= mid)			// 若在左子树里，则修改左子树
	add(arr,tree,left_node, idx,val);
	else					// 若在右子树里，则修改右子树
	add(arr,tree,right_node,idx,val);

							// 更新其父结点的值
	tree[i].data = tree[left_node].data + tree[right_node].data;
	return ;
}

// 懒惰标记：
//	当一个区间的值发生 加减变化时，我不把它立刻实现，而是存放在父节点的 lz 域中，要查询时直接从父节点返回
//	1、如果当前区间被完全覆盖在目标区间里，将这个区间的sum + k*(tree[i].r-tree[i].l+1)

//	2、如果没有完全覆盖，则先下传懒标记

//	3、如果这个区间的左儿子和目标区间有交集，那么搜索左儿子

//	4、如果这个区间的右儿子和目标区间有交集，那么搜索右儿子
void push_down(int i){
	if(tree[i].lz != 0){
		// 将编号为 i 的结点的懒惰标记下传给子结点 （注意，只传一代）
	int left_node  = 2 * i;
	int right_node = 2 * i + 1;

	// 与 父结点 一样，上面传下来懒惰标记，可能我也先暂存起来不下传，而且也是累加的
	tree[left_node].lz  += tree[i].lz;
	tree[right_node].lz += tree[i].lz;

	tree[left_node].data  += (tree[left_node].r  - tree[left_node].l + 1)  * tree[i].lz;
	tree[right_node].data += (tree[right_node].r - tree[right_node].l + 1) * tree[i].lz;
	
	
	// 既然已经下传，父结点的 lz 标记清零
	tree[i].lz = 0;

	return ;
	}

}
void add(int arr[],node tree[],int i,int L,int R,int k){
	// 区间修改 ,arr[L - > R] 区间内所有值 +k
	if(tree[i].l >= L && tree[i].r <= R){	
		// 如果完全包含，则直接修改该结点的值域，不慌修改子结点,（这就是懒惰的地方）
		tree[i].data += (tree[i].r - tree[i].l + 1) * k;		//原数 + 节点个数 * 变化量
		tree[i].lz += k;	// 相对标记，可以累加				  添加懒惰标记
		return ;
	}

	// 如果不是完全包含，则需要往下做修改，将懒惰标记下传给儿子节点，再求和
	push_down(i);

	int mid = (tree[i].l + tree[i].r ) / 2;
	int left_node  = 2 * i;
	int right_node = 2 * i + 1;
	if(L <= mid){		// 若与左区间有交集，则更新左区间
		add(arr,tree,left_node, L,R,k);
	}	
	if(R >= mid+1){		// 若与右区间有交集，则更新右区间
		add(arr,tree,right_node,L,R,k);
	}
	
	//更新该节点的值
	tree[i].data = tree[left_node].data + tree[i].data;
	return ;

}




int search(int arr[],node tree[],int i,int L,int R){
	// 带 push_down 的区间查询

	// 如果完全包含，则直接返回 data 即可，因为在区间修改时至少已经更改了 data域的值
	if(tree[i].l >= L && tree[i].r <= R){
		return tree[i].data;
	}

	// 如果没有交集,则返回0
	if(tree[i].r < L || tree[i].l > R)	return 0;

	// 如果不是完全包含，就要 push_down
	push_down(i);

	int s = 0;
	int mid = (tree[i].l + tree[i].r ) / 2;
	int left_node  = 2 * i;
	int right_node = 2 * i + 1;
	if(L <= mid){
		// 如果左子树有交集，则查询左子树
		s += search(arr,tree,left_node,L,R);
	}
	if(mid+1 <= R){
		// 如果右子树有交集，则查询右子树
		s += search(arr,tree,right_node,L,R);
	}
	return s;
}


int main(){
	int arr[] = {0,1,2,3,4,5};
	const int size = (sizeof(arr)/sizeof(*arr));

	build_tree(arr,tree,1,1,5);

	for(int i =1;i<=3*size;++i){
		printf("tree[%d] = %d\n",i,tree[i].data);
	}

	printf("\n");

	add(arr,tree,1,5,1);

	for(int i =1;i<=3*size;++i){
		printf("tree[%d] = %d\n",i,tree[i].data);
	}
	printf("\n");

	printf("sum[%d-%d] = %d\n",1,5,search(arr,tree,1,1,5));

	for(int i =1;i<=size;++i){
		printf("arr[%d] = %d\n",i,search(arr,tree,1,i,i));
	}


	return 0;
}