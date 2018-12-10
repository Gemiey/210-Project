#include "Mapper.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include "algorthims.h"
#include "buffer.h"
using namespace std; 
void Mapper::readFilePortion
{
    ifstream in;
    ofstream out;
    teraitem_r * termites;
    TeraSortItem ** terasortItem;
    teraitem_r struct_array[teraitems];
    FILE * f = fopen ("terasort_dataset","rb" );
    if ( f != NULL ) 
        { 
            fseek(f,0,SEEK_END); 
            long fsize = ftell(f); 
            rewind(f);
            for(int i = 0; i < 4; i++)
                thread[i] = fsize/4;
            while(!in.eof())
            {
                fread(teraitems,xxx,sizeof(teraitem_r),f);
                f >> struct_array[teraitems].key >> struct_array[teraitems].b1 >> struct_array[teraitems].rowid >> struct_array[terraitems].b2 >> struct_array[teraitems].filler >> struct_array[teraitems].b3;
            }
        }
        long int portionSize = ( teraitems / 6 );
        buildsample(struct_array, portionsize); 
}


void Mapper::buildSample(struct array[],long int size)
{
    size = ( teraitems / 6 );
        int sample_size= 1000; 
    Teraitem_r * teraitems  = (teraitem_r *) calloc (portionSize,sizeof(teraitem_r));
TeraSortItem ** terasortItems = (TeraSortItem **) calloc (sample_size,sizeof (TeraSortItem *));
for ( int i = 0 ;i < Sample ;i++)
	terasortItems[i] = new TeraSortItem (&teraitems[j]);
sortsample(terasortItems, sample_size);
}

void Mapper::sortSample(int *array[], int size) 
{
    creatCutPoints(quicksort(*array,size));
}
 
 void Mapper::creatCutPoints(int *array[]) //each 200object we have a cutpoint. 
 {
     int count = 0;
     for (int i = 0; i < sample_size; i++){
         if (count == 200) {
             if (cut_pts[0] == 0)
                    cut_pts[0] == array[i];
                    
            else if (cut_pts[1] == 0)
                cut_pts[1] == array[i];
                
            else if (cut_pts[2] == 0)
                cut_pts[2] == array[i];
                
            else if (cut_pts[3] == 0)
                cut_pts[3] == array[i];
                
            else if (cut_pts[4] == 0)
                cut_pts[4] == array[i];
                    
             count = 0;   
         }
         count++;
    }
             
}
 
 void Mapper::Shuffle()
 {
        for(int i = 0; i < teraitem_r; i++)
        {
            ShuffleBuffers = struct_array.teraitem_r[teraitem_r];
        }
 }
 
 void Mapper::return_cut_puts(TeraSortItem array[]){
     for(int i = 0; i < cut_pts.size(); i++){
         array[i] = cut_pts[i];
     }
 }
