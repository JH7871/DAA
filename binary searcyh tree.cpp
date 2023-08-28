#include<stdio.h>
int binarySearch(int arr[],int left,int right,int target) {
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            return mid; 
        }else if(arr[mid]<target){
            left=mid+1; 
        }else{
            right=mid-1; 
        }
    }
    return -1;
}
int main(){
    int n,target;
    printf("enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the sorted elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the element to be searched: ");
    scanf("%d",&target);
    int result=binarySearch(arr,0,n-1,target);
    if(result!=-1){
        printf("element found at index %d.\n",result);
    }else{
        printf("element not found in the array.\n");
    }
    return 0;
}

