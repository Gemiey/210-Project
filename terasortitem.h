#include <cstdint>
#include "buffer.h"
class Sortable 
    { 
private: 
public: 
    Sortable(); 
    Sortable (Sortable & sortable); 
        virtual uint128_t key() = 0; 
        virtual void swap (Sortable * p_sortable)=0; 
        virtual bool operator > (Sortable * p_sortable)=0; 
        virtual bool operator < (Sortable * p_sortable)=0; 
        virtual bool operator >= (Sortable * p_sortable)=0; 
        virtual bool operator <= (Sortable * p_sortable)=0; 
        virtual bool operator == (Sortable * p_sortable)=0; 
        virtual bool operator != (Sortable * p_sortable)=0; 
        virtual uint16_t hash(uint16_t p_reducers)=0; 
        virtual ~Sortable(); 
    }; 
    typedef struct 
    { 
        uint8_t key[10]; 
        uint8_t b1[2]; 
        char rowid[32]; 
        uint8_t b2[4]; 
        uint8_t filler[48]; 
        uint8_t b3[4]; 
    }teraitem_r; 
    class TeraSortItem : public Sortable
        { 
            private: 
            teraitem_r teraitem; 
            public:
            TeraSortItem(); 
            TeraSortItem (TeraSortItem & teraSortItem); 
            void operator = (TeraSortItem * teraSortItem);
            uint128_t key (); 
            void swap (Sortable * p_sortable); 
            void * operator new (size_t sz,void * v);
            bool operator > (Sortable * p_sortable); 
            bool operator < (Sortable * p_sortable); 
            bool operator >= (Sortable * p_sortable); 
            bool operator <= (Sortable * p_sortable); 
            bool operator == (Sortable * p_sortable); 
            bool operator != (Sortable * p_sortable); 
            ~TeraSortItem(); 
        };


};
uint128_t TeraSortItem::key ()
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
void TeraSortItem:: operator+ (TeraSortItem *p_terasortItem)
{
    this->key()+p_terasortItem->key();
}

void TeraSortItem::operator /(int x)
{
    this->key()/x;
}

void TeraSortItem :: operator =(TeraSortItem * TerasortItem)
{
    teraitem= TeraSortItem->teraitem;
}

void TeraSortItem::swap(Sortable *teraitem_r)
{
    TeraSortItem* temp;
    temp->teraitem=p_terasortItem->teraitem_r;
    p_terasortItem->teraitem=this->teraitem;
    this->teraitem_r=temp->teraitem;
}
