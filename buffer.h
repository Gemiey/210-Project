#include "Mapper.cpp"
#include "Thread.cpp"

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
      Mapper mappers[4];
      TeraSortItem array[5];
      int sum = 0, avg;
      Mapper mapper0; mapper0 = mappers[0];
      Mapper mapper1; mapper1 = mappers[1];
      Mapper mapper2; mapper2 = mappers[2];
      Mapper mapper3; mapper3 = mappers[3];
    public:
      ShuffelBuffers (int count,int size);
      void append(int buffer_index,teraitem_r * teradata);
      void save(char * file_name);
      void findAvg();
      /* I would overload the [] operator here to return a specific shufflebuffer by index*/
      ~ShuffleBuffers();
};
 void findAvg()
{
    for(int i = 0; i < 4; i++){
        mapper[i].return_cut_pts(array);
        for(int j = 0; j < array.size(); j++){
            sum += array[j];
        }
    }
            avg = sum/20;
}
void append (int buffer_index, teraitem_r *teradata)
{
    shuffelBuffer ** ShuffleBuffers = (ShuffleBuffers **) calloc (sizeof teradata,sizeof (shuffelBuffers *));
    
    
}

void save (char* filename)
{
    
}
