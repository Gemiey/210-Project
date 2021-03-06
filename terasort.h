#include "buffer.h"
#include "mapper.h"
class TeraSort
{
    private:
      char * p_input_filename; //array of char the file name that we open 
      char * p_output_filename; //array of char the file name that we open 
      int p_mapper_count; //the mapper count that the user puts 
      int p_reducer_count; //the number of reducers that user inputs 
      ShuffelBuffers * shuffleBuffer; //pointer of type shuffleBuffers 
    public:
        TeraSort(char * p_input_filename, char * p_output_filename,int p_mapper_count, int p_reducer_count);
        void sort(){
              /* You need to setup the ShuffleBuffers here*/
              p_mapper_count=p_mapper_count; 
              p_reducer_count=p_reducer_count; 
              *p_input_filename = *p_input_filename;
              ThreadManager * mappersThreadManager = new ThreadManager();
              for ( int i = 0 ; i  < p_mapper_count ; i ++ )
                  mappersThreadManager->addThread(new Mapper(i,input_filename,
                                                  mapper_count, p_reducer_counts,shuffleBuffer));
              /* phase 1 */
              mappersThreadManager->startRR();
              mappersThreadManager->barrier();
              /* phase 2 */
              mappersThreadManager->startRR();
              mappersThreadManager->barrier();

              ThreadManager * reducersThreadManager = new ThreadManager();
              for ( int i = 0 ; i  < p_mapper_count ; i ++ )
                  reducersThreadManager->addThread(new Reducer(shuffleBuffer[i]));
              reducersThreadManager->startRR();
              reducersThreadManager->barrier();

              shuffleBuffer.save();
        }
        ~Terasort();
