//write a simple string class that overloads assignment operator and checks if the two 
//strings are same or not ----
#include<iostream>
#include<cstring>
class mystring 
{
   char* m_buffer ;
    unsigned int m_size;
  public:

    mystring():m_buffer(nullptr)
    {
    }

    mystring(const char* str)
    { 
      // ------------------1 st way------------------
      // int count = 0;
      // const char *p = str;
      // while(*p)
      // {
      //   ++count; // this count is the size of the string 
      //   ++p;
      // }
      // after getting size you would be taking dynamic memory 
      //   m_buffer = new char[size];
      //   now copy each charater into the array 
      //    for(int i = 0; i<size ; i++)
      //    {   m_buffer[i] = str[]    }
      //
      //---------------------2 nd way----------------
      int size = strlen(str);// note that strlen does not count the character null 
                              // while returning the length
      m_size = size ;                               
      m_buffer = new char[size +1 ];
      //strcpy(m_buffer,str); // both the things work 
       int i;
       for(i = 0; i<size ; i++)
        {  
           m_buffer[i] = str[i];
        }
        m_buffer[i] = '\0' ; 
    }

    ~mystring()
    {
      delete[] m_buffer;
      m_buffer = nullptr ;
      std::cout<<"memory released"<<std::endl;
    }

    mystring(const mystring& other)
    {
          m_buffer = new char[m_size+1];
          strcpy(m_buffer,other.m_buffer);// including null character 

    }

    void operator = (const mystring& other)
    {
        if(this!= &other)
        { 
          //deleting the old memory
          delete[] m_buffer ;

          m_buffer = new char[m_size + 1];
          strcpy(m_buffer,other.m_buffer);
        }

    }

    bool operator ==(const mystring& other)
    {
        if(this->m_size == other.m_size)
        {
            for(int i =0;i<m_size;++i)  
            {
                if(m_buffer[i] != other.m_buffer[i])
                  return false ;
            }
        }
        return true ;
    }

    void Display()
    {
      std::cout<<m_buffer<<std::endl;
    }
};

int main()
{
    mystring str("hello");
    mystring str2("hello");

    // {mystring str2 = str;
    // }
    // str.Display();
    if(str == str2)
      std::cout<<"same strings "<<std::endl;
    else 
      std::cout<<"not same"<<std::endl;
    //std::cin.get();
}
