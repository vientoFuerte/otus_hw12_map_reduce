#include <iostream>
#include <string>


int main(int argc, char ** argv)
{
    size_t count = 0;
    std::string line;
    double sum = 0;
    while (std::getline(std::cin, line))
    {
        try {
            double price = std::stod(line);
            sum += price;
            count++;
        } catch (const std::exception& e) {
        // вывели некорректные данные
        std::cerr << "price\t" << line << "\n";
        }
    }
    
    if (count > 0) {
        double mean = sum / count; // среднее
        std::cout << mean << "\n";
    }
    
    return 0;
}
