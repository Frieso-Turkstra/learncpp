#include <iostream>
#include <utility> // for std::swap()

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) };

    // sort array
    for (int iteration{ 0 }; iteration < (length - 1); ++iteration)
    {   
        bool swapped { false };

        for (int index{ 0 }; index < (length - iteration - 1); ++index)
        {
            if (array[index] > array[index + 1])
            {
                std::swap(array[index], array[index + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            std::cout << "Early termination on interation " << iteration + 1 << '\n';
            break;
        }
    }

    // print array
    for (int i{ 0 }; i < length; ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    return 0;
}
