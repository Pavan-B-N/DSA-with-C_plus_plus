// subarray with the given sum - sliding window concept
/*
arr={1,4,3,8}
sum=4;
output:
[4]
[1,3]
*/

#include <stdio.h>

void printSubArray(int arr[],int n,int sum);
int main()
{
    int arr[] = {1, 4, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printSubArray(arr,n,8);
}

// Time complexity is o(n)
// sliding window concept
void printSubArray(int arr[],int n,int sum){
    int start=0,end=0,counter=0;
    
    for(end=0;end<n;end++){
        counter+=arr[end];

        while(counter>sum){
            counter-=arr[start];
            start++;
        }

        if(counter==sum){
            //print the subarray
            printf("[ ");
            for(int i=start;i<=end;i++){
                printf("%d ",arr[i]);
            }
            printf("]");
            // break;
        }
    }
}