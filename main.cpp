#include <iostream>
#include <array>
#include <vector>
#include <random>
#include <map>
#include "Utilities.hpp"


typedef int Digit;

constexpr Digit numDigits{4};
constexpr Digit target{24};

typedef float (*Operator)(float, float);
typedef std::map<char, Operator> Operators;

// operators
float add(float a, float b) {return a+b;}
float subtract(float a, float b) {return a-b;}
float multiply(float a, float b) {return a*b;}
float divide(float a, float b) {return a/b;}
float power(float a, float b) {return powf(a,b);}

const Operators operators = {{'+', add}, {'-', subtract}, {'*', multiply}, {'/', divide}, {'^', power}};
const std::map<Operator, char> operators_inverse = flip_map(operators);  // new map with keys and values swapped

typedef std::array<Digit, numDigits> digits;
digits d;

void print_solution(const std::array<Digit, numDigits>& nums, std::vector<char> &ops) {
    std::string accum (numDigits-2, '(');
    for(unsigned i=0; i<numDigits-1; ++i) {
        accum += std::to_string(nums[i]);
        if (i!=0) accum += ')';
        accum += std::string(&ops[i], 1);
    }
    accum += std::to_string(nums[numDigits-1]);
    printf("%s\n",accum.c_str());
}

int main() {

    d = {3,6,10, 4};

    if(std::accumulate(d.begin(), d.end(), 0) == target) {
        std::vector<char> v(numDigits-1,'+');
        print_solution(d, v);
    }
    if(std::accumulate(d.begin(), d.end(), 1, multiply) == target) {
        std::vector<char> v(numDigits-1,'*');
        print_solution(d, v);
    }

    auto keys = map_keys(operators);   // vector of map keys
    auto ops = map_values(operators);  // vector of map values
    std::sort(d.begin(), d.end());
    std::sort(ops.begin(), ops.end());
    do {
        do{
            float last = ops[0](d[0], d[1]);   // init with inner-most value

            for(unsigned i=1; i<numDigits-1; ++i) {  // - 2 cause there are |d|-1 operators
                last = ops[i](d[i+1], last);
            }

            if(last == target) {
                std::vector<char> v;
                for(Operator o : ops) {
                    v.push_back(operators_inverse.at(o));
                }
                print_solution(d, v);
            }
        } while (std::next_permutation(d.begin(), d.end()));
    } while (std::next_permutation(ops.begin(), ops.end()));

    return 0;
}


