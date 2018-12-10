class Mapper : public Thread
{
protected:
      long long int portionSize;
      Thread thread [4];
      teraitem_r * teradata; 
      TeraSortItem ** terasortItems; 
      int cut_pts[4] = {0,0,0,0,0);
      int p_index; 
      int p_mapper_count = 4; //how many mappers do i have 
      int p_reducer_counts; //how many reducer to i have 
      bool second_phase;
      /*  Add more data here */
      void readFilePortion(); //openfile and get it's size then assign each mapper it's points 
      void buildSample(); //array of pointers pointing to the data in terasort 
      void sortSmaple();
      void createCutPoints();//creat cutpoints by each mapper 
      void Shuffle(); //cutting the data into portions according to the average cutpoints created 
      void return_cut_puts();
    public:
        Mapper(int p_index,char * p_input_filename,int p_mapper_count, int p_reducer_counts,ShuffleBuffers * shuffleBuffers);
        void * threadMainBody (void * arg){
            if ( !second_phase)
            {
              readFilePortion(); 
              buildSample();
              sortSmaple();
              createCutPoints();
              return_cut_puts(); 
              second_phase = true;
            }
            else
            {
              Shuffle();
            }
        }
        ~Mapper();
};
