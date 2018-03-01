#include <cassert>
#include <iostream>
#include <string>
#include <vector>

/// Implementation of is_perfect main function

std::vector<int> get_proper_divisors(const int value)
{
//Collect the proper divisors
std::vector<int> proper_divisors;
if (value == 2)
{
  proper_divisors.push_back(1);
}
else if (value > 2)
{
  for (int denominator=1; denominator!=value-1; ++denominator)
  {
    if (value % denominator == 0)
    {
      proper_divisors.push_back(denominator);
    }
  }
}
return proper_divisors;
}

int do_main(const std::vector<std::string>& args)
{
  if (args.size() != 2)
  {
    return 1;
  }
  try
  {
    const int value = std::stoi(args[1]);
    // Negative values are not perfect
    if (value < 0) {
       std::cout << "false\n"; return 0;
    }
    // Zero is not perfect
    if (value == 0) {
       std::cout << "false\n"; return 0;
    }
    // Zero is not perfect
    if (value == 1) {
       std::cout << "false\n"; return 0;
    }
    std::vector<int> proper_divisors = get_proper_divisors(value);
    //sum the proper divisors, if not known if number is perfect
    int sum{0};
    for (const int proper_divisor: proper_divisors) { sum += proper_divisor; }
    if (sum == value){
        std::cout << "true\n"; return 0;
    }
    else {
    std::cout << "false\n"; return 0;
    }
  }
  catch (const std::exception&)
  {
    return 1;
  }
  return 0;
}

/// is_perfect main function, that also tests its implementation
int main(int argc, char* argv[])
{
    assert(do_main( { "is_perfect" } ) == 1);
    assert(do_main( { "is_perfect", "0" } ) == 0);
    assert(do_main( { "is_perfect", "1" } ) == 0);
    assert(do_main( { "is_perfect", "4" } ) == 0);
    assert(do_main( { "is_perfect", "6" } ) == 0);
    assert(do_main( { "is_perfect", "2" } ) == 0);
    assert(do_main( { "is_perfect", "28" } ) == 0);
    assert(do_main( { "is_perfect", "123456789101112131415161718" } ) == 1);
    assert(do_main( { "is_perfect", "nonsense" } ) == 1);
    assert(do_main( { "is_perfect", "7","42" } ) == 1);
    assert(do_main( { "is_perfect", "-4" } ) == 0);
    const std::vector<std::string> args (argv, argv + argc);
    return do_main(args);
}
