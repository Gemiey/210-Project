#include <iostream>
using namespace std; 
class Reducer : public Thread
{
  private:
    ShuffleBuffer * shuffleBuffer;
  public:
    Reducer(ShufferBuffer * p_shuffleBuffer);
    // Quick sort main function
    template <typename ITEM> void quickSort (ITEM * items, int left,int right) {
        if ( left+50 <= right) 
        {
            const ITEM & pivot = median3(items,left,right);
            int i = left,j=right-1;
            for (;;) 
            {
                while (items[++i] < pivot);
                while ( pivot < items[--j]);
                if ( i < j ) std::swap(items[i], items[j]); 
                else break;
            }
        std::swap(items[i],items[right-1]);
        quickSort(items,left,i-1);
        quickSort(items,i+1,right);
        }
        else insertionSort(items+left,right-left+1);
    }
    
    // median3
    template <typename ITEM>const ITEM & median3 (ITEM * items, int left,int right) 
    {
        int center =(left+right)/2;
        if ( items[center] < items[left] )
            std::swap(items[left],items[center]);
        if ( items[right] < items[left] )
            std::swap(items[left],items[right]);
        if ( items[right] < items[center] )
            std::swap(items[center],items[right]);
            std::swap(items[center],items[right-1]);
    return items[right-1];
    }
    
    // helper function to call main quick sort function
    template <typename ITEM> void * threadMainBody (void * arg)
    {
        quickSort (items,0,list_size-1);
    }
    
    
    ~Reducer();
}
