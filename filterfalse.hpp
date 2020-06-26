#pragma once
#include <iterator>

namespace itertools
{
    template<class F_1,class F_2> class filterfalse 
    {

    protected:
        
        const F_2& _cont;
        const F_1& tnay;
    public:
        
        filterfalse( const F_1& ck,const F_2& cont ):_cont(cont),tnay(ck){}

        
        class iterator 
        {

        private:
            
            const filterfalse& f_f;
            decltype(_cont.begin()) iter; 

        public:
            
            iterator(const filterfalse& try_it,decltype(_cont.begin()) itt ):f_f(try_it),iter(itt)
                    
            {
                
                while(iter!=f_f._cont.end() && f_f.tnay(*iter)) iter++;
            }

            auto operator*() const 
            {
                return *iter;
            }

            
            iterator& operator++() 
            {
                ++iter;
                
                while(iter!=f_f._cont.end() && f_f.tnay(*iter))++iter ;
                return *this;
            }

            
            
            bool operator!=(const iterator& iterator) const 
            {
                return iterator.iter!=iter;
            }

            bool operator==(const iterator& iterator) const 
            {
                return iterator.iter==iter;
            }
            const iterator operator++(int)
            {
                iterator tmp= *this;
                ++iter;
                return tmp;
            }

            
        }; 


        iterator begin() const 
        {
            return iterator(*this,_cont.begin());
        }

        iterator end() const 
        {
            return iterator(*this,_cont.end());
        }
    };

}