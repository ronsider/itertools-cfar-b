namespace itertools
{
    class range
    {
    private:
        int _beginn , _end;
    public:
        range(int b, int e): _beginn(b),_end(e){}
    private:
        class iterator
        {
            int _variable;
        public:
            iterator(int r):_variable(r){}

            
            int operator*() const 
            {
                return _variable;
            }

            
            iterator& operator++() 
            {
                ++_variable;
                return *this;
            }

           
            const iterator operator++(int) 
            {
                iterator st= *this;
                ++_variable;
                return st;
            }
            bool operator!=(const iterator& rhs) const 
            {
                return _variable != rhs._variable;
            }

            bool operator==(const iterator& rhs) const 
            {
                return _variable == rhs._variable;
            }

        };

    public:
        iterator begin() const  
        {
            return iterator(_beginn);
        }

        iterator end() const 
        {
            return iterator(_end);
        }
    };
}