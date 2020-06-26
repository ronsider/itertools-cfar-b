#pragma once


#include <iostream>
#include <vector>
#include <iterator>

typedef struct 
{
    template <typename T>
    auto operator()(const T& r , const T& R) const
    {
        return r+R;
    }
} _result;

namespace itertools
{
    template<class C,class F = _result>
    class accumulate
    {

    protected:
        
        const C& _cont;
        const F& _func;
    public:

        accumulate(const C& c, const F& f=_result()):_cont(c),_func(f){} 

        
        class iterator 
        {

        private:
            
            const accumulate& _accu;
            decltype(_cont.begin()) iter; 
            typename std::decay<decltype(*(_cont.begin()))>::type res;

            

        public:
            
            iterator(const accumulate& cc,decltype(_cont.begin()) k): _accu(cc),iter(k)
                    
            {
                if (k != _accu._cont.end())
                res=*k;
            }

            

            
            iterator& operator++()
             {
                ++iter;
                if(iter!=_accu._cont.end())
                {
                    res=_accu._func(res,*(iter));
                }
                return *this; 
            }

            
            const iterator operator++(int) 
            {
                iterator tmp=*this; 
                iter++;
                if(iter!=_accu._cont.end())
                {
                    res=_accu._func(res,*(iter));
                }
                return *tmp; 
            }
            auto operator*() const 
            {
                return res;
            }

            bool operator==(const iterator& iterator) const
            {
                return iterator.iter==iter;
            }

            bool operator!=(const iterator& iterator) const 
            {
                return iterator.iter!=iter;
            }
        }; 


        iterator begin() const 
        {
            return iterator(*this,_cont.begin());
        }

        iterator end() const
         {
            return iterator(*this, _cont.end());
        }
    };
}