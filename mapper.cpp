#include <iostream>
#include <string>
#include <fstream>

std::string getColumn(std::string str, uint colNum)
{
    int delimCnt = 0;
    size_t start = 0;
    size_t stop = str.length();
    bool startFound = false;  

    std::string field;

    for (size_t i=0; i<str.length(); i++)
    {
        if(str[i] == ',') {
            delimCnt++;
        }
        if(delimCnt == colNum && !startFound) {

            start = i;  // запятая перед нужным полем
            startFound = true;
        }
        else if (startFound && delimCnt == colNum +1)  {
            stop = i - start-1; // количество символов не включая запятые
            break;
            
        }
    }

    field = str.substr(start+1, stop);
    return field;
}

int main(int argc, char ** argv)
{
    std::string line;
  
   if (std::getline(std::cin, line)) 
   {
        //std::cout << line << std::endl;
        std::cout << getColumn(line, 9) << std::endl;
    }

    return 0;
}
