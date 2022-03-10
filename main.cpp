#include <iostream>
#include <string>

#include <string_view>


int main() 
{
        std::string original = "message";
         // creates "message" and assigns new space to original
        std::string copy1 = original;
         // create a new space with message;
        std::string_view view1 {original};
         // view does not  create a new copy  with message , instead it just locates it

         original = "new message";
         copy1 = copy1 + copy1;


        std::cout << "original: " << original << std::endl;
        std::cout << "copy1: " << copy1 << std::endl;
        std::cout << "view1: " << view1 << std::endl;

       

       

  
};



            
