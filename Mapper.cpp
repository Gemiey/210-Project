#include "Mapper.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include "algorthims.h"
#include "buffer.h"
using namespace std; 
void Mapper::readFilePortion //ezch mapper reads a portion of the file of the data then stores it in the array of structs 
{
    ifstream in; //istream of the opening files 
    ofstream out;
    teraitem_r * termites; //pointer of type teraitem_r struct 
    TeraSortItem ** terasortItem; //array of pointers of terasortitem
    teraitem_r struct_array[teraitems]; //array of structs for the teraitem_r 
    FILE * f = fopen ("terasort_dataset","rb" ); //opening the file to read from 
    if ( f != NULL ) //if they file is not empty we go into the condition 
        { 
            fseek(f,0,SEEK_END); //seek the pointer to the end and get the size and store it in fsize 
            long fsize = ftell(f); 
            rewind(f); //rewind the pointer to the begining 
            for(int i = 0; i < 4; i++) //for loop to creat thread for each size of the thread 
                thread[i] = fsize/4; //assigning portions to the threads 
            while(!in.eof())  
            {
                fread(teraitems,fsize/4,sizeof(teraitem_r),f); //reading from the file and then storing it in the terasort_r
                f >> struct_array[teraitems].key >> struct_array[teraitems].b1 >> struct_array[teraitems].rowid >> struct_array[terraitems].b2 >> struct_array[teraitems].filler >> struct_array[teraitems].b3;
            }
        }
        long int portionSize = ( struct_array / mapper_count ); //deviding the struct array to the mapper_count 
        buildsample(struct_array, portionsize, fsize); 
}


void Mapper::buildSample(struct array[],long int size, int long fsize)
{
    size = ( teraitems / 6 );
        int sample_size= 1000; 
    Teraitem_r * teraitems  = (teraitem_r *) calloc (portionSize,sizeof(teraitem_r));
TeraSortItem ** terasortItems = (TeraSortItem **) calloc (sample_size,sizeof (TeraSortItem *));
for ( int i = 0 ;i < Sample ;i++)
	terasortItems[i] = new TeraSortItem (&teraitems[j]);
sortsample(terasortItems, sample_size, fsize);
}

void Mapper::sortSample(int *array[], int size, int long fsize) 
{
    creatCutPoints(quicksort(*array,size)); //send the sort sample of the array of pointers to quicksost then we send the sorted array to cutpoints 
    shuffle(fsize); //we send the size of the array to the shuffle to send the whole struct array index by index to the buffers 
}
 
 void Mapper::creatCutPoints(int *array[], int long fsize) //each 200object we have a cutpoint, we we creat the cutpoints based on that 
 {
     int count = 0; //eachtime we have a count =0 
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
                    
             count = 0;   //reset the count each 200, which means that each 200 we get a cutpoint and store it in an array 
         }
         count++;
    }
             
}
 
 void Mapper::Shuffle(int long fsize) //a function that passes objects to the shuffle buffer object by object to be compared to the cutpoints 
 {
     Teraitem_r * teraitems  = (teraitem_r *) calloc (struct_array,sizeof(teraitem_r)); //creating an array of pointers pointing to objects and each object points to a struct in the array 
     TeraSortItem ** terasortItems = (TeraSortItem **) calloc (fsize,sizeof (TeraSortItem *));
        for(int i = 0; i < fsize; i++)
        {
            terasortItems[i] = new TeraSortItem (&teraitems[j]); //creating a new object for each index and setting it in terasortItem array 
            ShuffleBuffers->terasortItems[i]; //passing item by item into the shuffle buffers class 
        }
 }
 
 void Mapper::return_cut_pts(TeraSortItem array[]) //passing the cutpoints to be calculated in the shufflebuffers items 
 {
     for(int i = 0; i < cut_pts.size(); i++)
        {
         array[i] = cut_pts[i];
        }
 }
 
 void Mapper::return_objects(TeraSortItem arr[]){
     for(int i = 0; i < fsize; i++){
         arr[i] = terasortItems[i];
     }
 }
