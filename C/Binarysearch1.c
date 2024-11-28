#include <stdio.h>

int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int target = 6;
    int low = 0, high = 4;
    while(low <= high)
    {
            int mid = (low + high)/2;

            if(target == arr[mid])
            {
               printf("%d", mid);
                return 0;
            }
            if(arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
    }
}