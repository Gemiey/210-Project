#include "Mapper.cpp"
#include "Thread.cpp"
#include <mutex> 
std :: mutex mtx; 

class ShuffleBuffer: public Mapper
{
    private:
        teraitem_r * teradata;
    public:
        ShuffleBuffer(int size);
        ~ShuffleBuffer();
};

class ShuffleBuffers : ShuffleBuffer
{
    private:
      ShuffleBuffer ** shuffleBuffers; //array of shuffle buffer 
      TeraSortItem array[5];
      int sum = 0, avg[2];
    public:
      ShuffleBuffers (int count,int size);
      void append(int buffer_index,teraitem_r * teradata);
      void save(char * file_name);
      void findAvg();
      /* I would overload the [] operator here to return a specific shufflebuffer by index*/
      ~ShuffleBuffers();
};
 void findAvg() //calculating the average cutpoints that gets the cutpoints from each array and set it ew
{
    int count = 0;
    for(int i = 0; i < mapper.size(); i++){ //an array of that goes over each mapper's cutpoint 
        mapper[i].return_cut_pts(array); count++;
        for(int j = 0; j < array.size(); j++){ //anohther array that adds the cutpoints of all the arrays 
            sum += array[j];
        }
        if(count == 2){
            avg[0] = sum/20; //getting the average of the cutpoints 
            sum = 0;
        }
        if(count == 4)
            avg[1] = sum/20;
    }
            append (avg);
}
void append (int buffer_index, teraitem_r *teradata, int * cutpoints[]) //takes each mapper and compares them to the 
{
    mtx.lock();
    TeraSortItem *shuffle_arr;
    TeraSortItem greater[5];
    TeraSortItem smaller[5];
    TeraSortItem medium[5];
    for(int i = 0; i < 4; i++)
    {
        mapper[i].return_objects(shuffle_arr);
        for(int i = 0; i < array.size(); i++){
            if(array[i] > shuffle_arr[i])
                greater[i]=array[i];
            else if(shuffle_array[i] > array[i])
                smaller[i]=array[i];
            else
                medium[i]=array[i];
      }
    shuffleBuffer ** ShuffleBuffers = (ShuffleBuffers **) calloc (sizeof teradata,sizeof (shuffelBuffers *));
    }
    
 mtx.unlock();
}

void save (char* filename) //writing the sorted array into the file output that the user inputs s
{
    file * fopen= ("filename","rb")
    while (!TeraSortItem.empty)
    {
        fwrite<<Reducer; 
    }
    
}
