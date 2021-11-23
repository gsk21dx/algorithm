const int N = 1000010;

int q[N], tmp[N]/*辅助数组*/;

void merge_sort(int q[], int l, int r)
{
    if( l >= r) return;

    int mid = (l + r) >> 1;//确定中点mid

    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);//递归排序两边

    int k = 0, i = l, j = mid + 1;//此时两边都是有序数组,i是左边有序数组的最小值,j是右边有序数组的最小值
    while(i <= mid && j <= r) {//i, j两个还没有指到数组尽头
        if(q[i] <= q[j]) tmp[k ++] = q[i ++];
        else tmp[k ++] = q[j ++];
    }
    //当i, j其中一个走到尽头之后,循环结束,然后把另一个有序数组的后半部分补到tmp[]数组后面
    while(i <= mid) tmp[k ++] = q[i ++];
    while(j <= r) tmp[k ++] = q[ j ++];

    for(i = l, j = 0; i <= r; i ++, j ++) q[i] = tmp[j];//把tmp[]复制给q[]

}