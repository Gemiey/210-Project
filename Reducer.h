#include <iostream>
using namespace std; 
class Reducer : public Thread
{
  private:
    ShuffleBuffer * shuffleBuffer;
  public:
    Reducer(ShufferBuffer * p_shuffleBuffer);
    quickSort *quicksort; 
    ~Reducer();
}
