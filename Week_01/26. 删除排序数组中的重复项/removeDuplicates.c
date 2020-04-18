int removeDuplicates(int* nums, int numsSize)
{
    int count = 1;
    int *q = nums;
    if ( numsSize == 0 )
        return 0;
    
    for ( int i = 0; i < numsSize; i++ ) {
        if ( nums[count - 1] != q[i] ) {
            count++;
            nums[count - 1] = q[i];
        }
    }
    return count;
}