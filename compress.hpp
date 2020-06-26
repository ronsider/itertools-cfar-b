#pragma once
#include <iterator>

namespace itertools
{
    template <class T_1 , class T_2> class compress
    {

    protected:
        
        const T_1& containerObj;
        const T_2& containerBool;
    public:
        
        compress(const T_1& obj , const T_2& bol) : containerObj(obj) , containerBool(bol){}

        
        class iterator
        {

        private:
            
            const compress& _compression;
            decltype(containerObj.begin()) iter_ob;
            decltype(containerBool.begin()) iter_boo;
        public:
            
            iterator(decltype(containerObj.begin()) iter_ob , decltype(containerBool.begin()) itBool , const compress& co) : iter_ob(iter_ob), _compression(co)
                   
            {
                if(iter_boo!=co.containerBool.end()) iter_boo=itBool;
                while(iter_boo!=_compression.containerBool.end() && *iter_boo == false) 
                {
                    
                    iter_boo++;
                    iter_ob++;
                }
            }

            iterator& operator++()
            {
                
                ++iter_boo;
                ++iter_ob;
                while( !(*iter_boo)&&iter_boo!=_compression.containerBool.end()) 
                {
                    iter_ob++;
                    iter_boo++;
                }
                return *this; 
            }

            

            

            const iterator operator++(int)
            {
                iterator temp = *this;
                ++iter_ob;
                ++iter_boo;
                return temp;
            }
            bool operator==(const iterator& it) const
            {
                return iter_ob == it.iter_ob;
            }

            auto operator*()
            {
                return *iter_ob;
            }
            bool operator!=(const iterator& it) const
            {
                return iter_ob != it.iter_ob;
            }

        }; 

        iterator begin() const
        {
            return iterator(containerObj.begin(), containerBool.begin(), *this);
        }

        iterator end() const 
        {
            return iterator(containerObj.end(), containerBool.end(), *this);
        };
    };
}