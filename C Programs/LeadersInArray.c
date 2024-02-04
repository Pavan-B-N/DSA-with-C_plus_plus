// leaders in an array
/*
{7, 10, 4, 3, 6, 5, 2}
10 6 5 2 are said to be leaders because they are greatest from their right side
*/
#include <stdio.h>
int main()
{
    int arr[] = {7, 10, 4, 3, 6, 5, 2};
    // int arr[]={30,20,10};

    int len=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i++){
        int flag=1;
        for(int j=i+1;j<len;j++){
            if(arr[i]<arr[j]){
                flag=0;
                break;
            }
        }
        if(flag){
            printf("%d ",arr[i]);
        }
    }
}
/*
int main()

{

    int a[] = {7, 10, 4, 3, 6, 5, 2};

    int curr = a[6];

    cout << curr << " ";

    for(int i = 5; i >= 0 ;i--) {

        if (a[i] > curr) {

            curr = a[i];

            cout << a[i] << " ";

        }

    }

    return 0;

}
*/