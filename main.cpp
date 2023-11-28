#include <tclap/CmdLine.h>

#include <iostream>
#include <string>

int main(int argc, char** argv) {
  try {
    // Define the command line object.
    TCLAP::CmdLine cmd("Test simple command line parsing", ' ', "0.0.1");

    // Define a value argument and add it to command line.
    TCLAP::ValueArg<std::string> nameArg("n", "name", "Name to print", true, "",
                                         "string");
    cmd.add(nameArg);

    // Define a switch and add it to the command line.
    TCLAP::SwitchArg reverseSwitch("r", "reverse", "Print name in reverse", cmd,
                                   false);

    // Define an optional value argument and add it to the command line.
    TCLAP::ValueArg<int> ageArg("a", "age", "Age of the person", false, 0,
                                "int");
    cmd.add(ageArg);

    // Parse the command line arguments.
    cmd.parse(argc, argv);

    // Get the value parsed by each argument.
    std::string name = nameArg.getValue();
    bool reverse = reverseSwitch.getValue();
    int age = ageArg.getValue();

    // Do reverse
    if (reverse) {
      std::reverse(name.begin(), name.end());
    }

    // Print out
    std::cout << "Name: " << name << std::endl;
    if (age > 0) {
      std::cout << "Age: " << age << std::endl;
    }

  } catch (TCLAP::ArgException& e) {
    std::cerr << "Error: " << e.error() << " for arg " << e.argId()
              << std::endl;
    return 1;
  }
  return 0;
}
