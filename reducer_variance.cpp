#include <iostream>
#include <string>



int main(int argc, char ** argv)
{
    size_t count = 0;
    std::string line;
    double sum = 0;      // сумма
    double sumSq = 0;    // сумма квадратов
    double variance = 0; // дисперсия

    while (std::getline(std::cin, line))
    {
        try {
            double price = std::stod(line);
                sum += price;
                sumSq += price * price;
                count++;
        } catch (const std::exception& e) {
        // вывели некорректные данные
        std::cerr << "price\t" << line << "\n";
        }
    }
    
    if (count > 0) {
        double mean = sum / count; // среднее
        variance = (sumSq / count) - (mean * mean);
        std::cout << variance << "\n";
    }
    
    return 0;
}