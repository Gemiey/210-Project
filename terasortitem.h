#include <cstdint>
#include "buffer.h"
class Sortable 
    { 
private: 
public: 
    Sortable(); 
    Sortable (Sortable & sortable); 
        virtual uint128_t key() = 0; 
        virtual void swap (Sortable * p_sortable)=0; //swap functions that we will use in the quick sort 
        virtual bool operator > (Sortable * p_sortable)=0; //overloading the operatprs 
        virtual bool operator < (Sortable * p_sortable)=0; //overloading the operatprs 
        virtual bool operator >= (Sortable * p_sortable)=0; //overloading the operatprs 
        virtual bool operator <= (Sortable * p_sortable)=0; //overloading the operatprs 
        virtual bool operator == (Sortable * p_sortable)=0; //overloading the operatprs 
        virtual bool operator != (Sortable * p_sortable)=0; //overloading the operatprs 
        virtual uint16_t hash(uint16_t p_reducers)=0; //setting the size of the  reducer 
        virtual ~Sortable(); 
    }; 
    typedef struct //struct where the file will be read in each record 
    { 
        uint8_t key[10]; 
        uint8_t b1[2]; 
        char rowid[32]; 
        uint8_t b2[4]; 
        uint8_t filler[48]; 
        uint8_t b3[4]; 
    }teraitem_r; 
    class TeraSortItem : public Sortable //c;ass of terasortitem where the items will be be sorted 
        { 
            private: 
            teraitem_r teraitem; //a teraitem of the struct 
            public:
            TeraSortItem(); //constructor 
            TeraSortItem (TeraSortItem & teraSortItem); //
            void operator = (TeraSortItem * teraSortItem); //operator equal to the terasortitem 
            uint128_t key (); //getting the random index of the key 
            void swap (Sortable * p_sortable); //swap function that swaps the two pointers 
            void * operator new (size_t sz,void * v); //setting a new operator 
            TeraSortItem & operator =(TeraSortItem && TS){} //move contructor 
            bool operator > (Sortable * p_sortable); //operator overload that takes a pointer of type class sortable where it inherets from it 
            bool operator < (Sortable * p_sortable); //operator overload that takes a pointer
            bool operator >= (Sortable * p_sortable); //operator overload that takes a pointer
            bool operator <= (Sortable * p_sortable); //operator overload that takes a pointer
            bool operator == (Sortable * p_sortable); //operator overload that takes a pointer
            bool operator != (Sortable * p_sortable); //operator overload that takes a pointer
            ~TeraSortItem(); //distructor 
        };


};
uint128_t TeraSortItem::key () //getting the random index for the key for the sample 
{
    uint8_t * v = teraitem.key;
    uint128_t k = 0;
    uint8_t * c = (uint8_t *) &k;
    c[0] = v[9];
    c[1] = v[8];
    c[2] = v[7];
    c[3] = v[6];
    c[4] = v[5];
    c[5] = v[4];
    c[6] = v[3];
    c[7] = v[2];
    c[8] = v[1];
    c[9] = v[0];
    return k;
}
void TeraSortItem:: operator+ (TeraSortItem *p_terasortItem) //overloading the operator by getting the key 
{
    this->key()+p_terasortItem->key();
}

void TeraSortItem::operator /(int x) //doing a devided operaypr that takes an int and devide the key with it 
{
    this->key()/x;
}

void TeraSortItem :: operator =(TeraSortItem * TerasortItem) //setting a teraitem pointer of the class to the item 
{
    teraitem= TeraSortItem->teraitem;
}

void TeraSortItem::swap(Sortable *teraitem_r) //doing the swap functions 
{
    TeraSortItem* temp; //creating a pointer of type terasortitem
    temp->teraitem=p_terasortItem->teraitem_r; //pointer temp poiting to teraitem which points to object of teraitem_r
    p_terasortItem->teraitem=this->teraitem; //p_terasortItem points to teraitem equal to this pointer teraitem
    this->teraitem_r=temp->teraitem; //setting the struct teraitem_r to the temp pointer to the teraitem
}
