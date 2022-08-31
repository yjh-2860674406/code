#include <iostream>
using namespace std;
void bubbleSort(int a[],int l,int r) {
    // ???????
	for(int i=l; i<r; i++) {
		for(int j=i+1; j<=r; j++) {
			if(a[j]<a[i]) swap(a[i],a[j]);
		}
	}
}

int Partition(int a[],int l,int r,int val) {
    // ????????
	int pos;
	for(int q=l; q<=r; q++) {
		if(a[q]==val) {
		    pos=q;
			break;
		}
	}
	swap(a[l],a[pos]);

	int i=l,j=r+1,x=a[l];
	while(1) {
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j)break;
		swap(a[i],a[j]);
	}
	a[l]=a[j];
	a[j]=x;
	return j;
}

int Select(int a[],int l,int r,int k) {
    // ???????????k?????
	if(r-l<75) {
		bubbleSort(a,l,r);
		return a[l+k-1];
	}
	//??????????????????r-l-4???????????n-5
	for(int i=0; i<=(r-l-4)/5; i++) {
        //????????????????????????[l,l+(r-l-4)/4]
		int s=l+5*i,t=s+4;
		for(int j=0; j<3; j++) {
			for(int n=s; n<t-j; n++) {
				if(a[n]>a[n+1])swap(a[n],a[n-1]);
			}
		}
		swap(a[l+i],a[s+2]);//??????????????????????
	}
	//(r-l-4)/5???????-1????[l,l+(r-l-4)/5]???????????????
	int x=Select(a,l,l+(r-l-4)/5,(r-l+1)/10); //????????????????
	// (r-l+1)/10 = (l+(r+l-4)/5-l+1)/2
	int i=Partition(a,l,r,x),j=i-l+1;
	if(k<=j)return Select(a,l,i,k);
	else return Select(a,i+1,r,k-j);
}

int* getResult (int* a, int l, int r, int len, int k) {
    int mid = Select(a, l, r, len/2); // ?????????
    int* b = new int[len];
    for (int i=0; i<len; i++) {
        int x = a[i] - mid;
        if (x>=0) b[i] = x;
        else b[i] = -x;
    }
    int result = Select(b, l, r, k+1);
    int *nums = new int[2];
    nums[0] = mid; nums[1] = result;
    return nums;
}

int main() {
	int a[20];
    int k;
	cout << "??????k?????" << endl;
	cin >> k;
    for (int i=0; i<20; i++) a[i] = i%10;
    int* nums = getResult(a, 0, 19, 20, k);
    int mid = nums[0]; int x = nums[1];
    int couter = 0;
    for (int i=0; i<20; i++) {
        int y = a[i] - mid;
        if (y < 0) y = -y;
        if (y < x) {
            cout << a[i] << " ";
            couter++;
        }
    }
    for (int i=0; i<20 && k-couter; i++) {
        int y = a[i] - mid;
        if (y < 0) y = -y;
        if (y == x) {
            cout << a[i] << " ";
            couter++;
        }
    }
    cout << endl;
}