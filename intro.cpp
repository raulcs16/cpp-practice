#include <bitset>
#include <iomanip>
#include <iostream>

void printBits(const std::string &label, uint8_t value) {
    std::cout << std::left << std::setw(24) << label << std::setw(8) << std::bitset<8>(value) << std::endl;
}
bool checkCostA() {
    std::cout << "A call cost 100 \n";
    return true;
}
bool checkCostB() {
    std::cout << "B call cost 10\n";
    return true;
}
bool checkCostD() {
    std::cout << "D call cost 30\n";
    return false;
}
bool checkCostE() {
    std::cout << "E call cost 500\n";
    return false;
}
int main() {

    {

        //octal literals
        unsigned int oct{0777u};
        int err_oct{055};
        std::cout << oct << "," << err_oct << std::endl;
        //binary literals
        unsigned int binary_literal{0b11111111u};
        std::cout << binary_literal << std::endl;
        //char literals
        char char_literal{'c'};
        int number_literal{15};
        float fractional_literal{1.5f};
        std::string string_literal{"Hit the road jack"};
        std::cout << char_literal << std::endl;
        std::cout << number_literal << std::endl;
        std::cout << fractional_literal << std::endl;
        std::cout << string_literal << std::endl;

        //constant

        const float e{2.75};
        std::cout << e << std::endl;


        //grouping numbers
        unsigned int prize{1'500'00'0u};
        std::cout << "the pricze is : " << prize << std::endl;
    }
    {

        //constexpr
        constexpr double PI{3.145};
        // double circle_0_r{3.5};
        constexpr double circle_1_r{2.1};

        //constexpr double area_0{circle_0_r * PI}; //error
        constexpr double area_1{circle_1_r * PI}; //ok
        std::cout << "area 1" << area_1 << std::endl;
        //static_arert checked at compile time
        // constexpr int SOME_LIB_MAJOR{1};
        //    static_assert(SOME_LIB_MAJOR == 2);//error

        //constint declares variable should be init at compile time, C++20

        // bitwise opersations
    }
    {

        constexpr uint8_t data{0b000010101};
        uint8_t copy{data};
        const uint8_t data2{0b10101000};
        printBits("data:", data);
        printBits("shift left 1:", 1 << data);
        printBits("compound shift left 1:", copy <<= 1);
        copy = data;
        printBits("shift right 1:", data >> 1);
        printBits("compound shift right 1:", copy >>= 1);
        copy = data;
        printBits("not data:", ~data);
        printBits("data and data2:", data & data2);
        printBits("data and= data2:", copy &= data2);
        copy = data;
        printBits("data or data2:", data | data2);
        printBits("data or= data2:", copy |= data2);
        copy = data;
        printBits("data xor data2:", data ^ data2);


        printBits("data xor= data2:", copy ^= data2);
    }
    {

        //masking
        const unsigned char mask_bit_0{0b00000001};
        const unsigned char mask_bit_1{0b00000010};
        const unsigned char mask_bit_2{0b00000100};
        const unsigned char mask_bit_3{0b00001000};
        const unsigned char mask_bit_4{0b00010000};
        const unsigned char mask_bit_5{0b00100000};
        const unsigned char mask_bit_6{0b01000000};
        const unsigned char mask_bit_7{0b10000000};

        //turn on bits using |=(mask)
        unsigned char var{0b00000000};

        var |= mask_bit_3;
        var |= mask_bit_0;
        printBits("turned on 0,and 3", var);
        //turn off bits using &=(~mask)
        printBits("turned off 3", var &= (~mask_bit_3));
        //check if on of off (var & mask_bit_#) >> #
        std::cout << "bit0 is " << ((var & mask_bit_0) >> 0) << std::endl;
        // toggle bit postion ^=(mask)
        std::cout << "toggoling bit 0...";
        var ^= mask_bit_0;
        std::cout << "bit0 is " << ((var & mask_bit_0) >> 0) << std::endl;
    }
    {
        std::cout << "And worst circuit:\n";
        bool result = checkCostA() && checkCostB() && checkCostD();
        std::cout << "And short circuit:\n";
        result = checkCostD() && checkCostA() && checkCostB();
        std::cout << "OR worst circuit:\n";
        result = checkCostE() || checkCostD() || checkCostA();
        std::cout << "OR short circuit:\n";
        result = checkCostA() || checkCostD() || checkCostE();
    }
    {

        //eliminates if and else at part from binary
        if constexpr (true) {
            std::cout << "some really big data comp\n";
        } else {
            std::cout << "some other really big data comp\n";
        }
    }
    {
        int i{5}, a{10}, b{20}, c{25};
        int result = (a *= ++i, b - (++i), c += ++i);
        std::cout << "a:" << a << std::endl;
        std::cout << "b:" << b << std::endl;
        std::cout << "c:" << c << std::endl;
        std::cout << "result" << result << std::endl;
    }
    {
        int some_values[]{1, 3, 3, 5, 4, 8, 82, 9};
        for (int val : some_values) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    {
        char predictions[][90]{
            "a lot of kinds running in the backyard!",
            "a lot of empty beer bottles on your work table.",
            "you partying too much with the kids wearing weird cloths.",
            "you running away from something really scary",
            "clouds gatherin in the sky and an army standing ready for war",
            "dogs running around in a deserted empty city",
            "a lot of cars stuck in a terrible traffic jam",
            "you sitting in the dark typing lots of lines of code on your dirty computer",
            "you yelling at your boss. And oh no! you get fired!",
            "you laughing your lungs out. I've never seen this before",
        };
        bool end{false};


        while (!end) {
            std::cout << "Oh dear " << "I, see ";
            size_t rand_num = static_cast<size_t>((std::rand() % 10));
            std::cout << predictions[rand_num] << std::endl;
            end = rand_num % 2 == 0;
        }
    }
    {
        std::cout << std::isalnum('3') << std::endl;
        std::cout << std::isalpha('3') << std::endl;
        std::cout << std::isdigit('3') << std::endl;
        std::cout << std::islower('a') << std::endl;
        std::cout << std::isupper('a') << std::endl;
        std::cout << std::toupper('a') << std::endl;
        std::cout << std::strlen("abksde8") << std::endl;
        std::cout << sizeof("abksde8") << std::endl;
    }

    {
        using HugeInt = unsigned long long int;
        HugeInt huge_num{18'446'834'073'903'551ull};
        std::cout << "huge num:" << huge_num << std::endl;
    }
    {
        //lambda functions
        //[capture list](parameters) -> return type{
        //
        //}
        []() { std::cout << "Hello Lamnda\n"; }();
        int total = 5;
        auto add_to_total = [&total](int amount) { total += amount; };
        add_to_total(10);
        std::cout << "total: " << total << std::endl;
    }

    return 0;
};
