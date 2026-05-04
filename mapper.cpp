#include <iostream>
#include <string>
#include <fstream>

std::string getColumn(std::string str, uint colNum)
{
    int delimCnt = 0;
    size_t start = 0;
    size_t stop = str.length();
    bool startFound = false; 
    bool inQuotes = false;

    std::string field;

    for (size_t i=0; i<str.length(); i++)
    {
        if (str[i] == '"') {
            inQuotes = !inQuotes;  // Переключение режима "внутри кавычек"
            continue; 
        }

        if(str[i] == ',' && !inQuotes) {
            delimCnt++;
        }
        if(delimCnt == colNum && !startFound && !inQuotes) {

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
    std::string priceStr;
    double price;
    int i = 0;
  
    //for (int i = 1000; i<1023; i++) 
    while(std::getline(std::cin, line))
   {
        i++;
        //std::cout << line << std::endl;
        priceStr = getColumn(line, 9);

        try {
            double price = std::stod(priceStr);
            std::cout << "price\t" << price << "\n";
            } 
        catch (const std::exception& e) {
                //std::cerr << line<< std::endl;
                std::cerr << "price\t" << priceStr << "\n";
            }

    }

    

    return 0;
}
