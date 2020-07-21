#include"z3++.h"
#include<bits/stdc++.h>

using u32 = uint32_t;

std::string create_input(std::vector<std::string> inputs) {
    std::srand(std::time(0));
    std::string params;
    for(const auto& _ : inputs) {
        int x = std::rand() % 10;
        params.append(std::to_string(x)).append(" ");
    }
    
    return params.substr(0, params.length() - 1);
}

int main(int argc, char *argv[]) {
    // read program name
    std::string program_name(argv[1]);
    
    // create spec and output names
    std::string spec_name = program_name + std::string(".kspec");
    std::string output_name = program_name + std::string(".keles");
    std::vector<std::string> inputs;
    std::string IO_prog_name("./");
    // read spec from file
    std::ifstream spec_file(spec_name);
    std::string spec_line;
    while (getline (spec_file, spec_line)) {
        std::cout << spec_line << std::endl;
        if(spec_line[0] == 'I') {
            inputs.push_back(spec_line.substr(3));
        } else if (spec_line[0] == 'C') {
            
        } else if (spec_line[0] == 'P') {
            IO_prog_name.append(spec_line.substr(3));
        }
    }

    std::string generated_input = create_input(inputs);
    
    std::system((IO_prog_name + std::string(" ") + generated_input + std::string(" > ")+ program_name + std::string(".out")).c_str()); 
    std::stringstream ss;
    ss << std::ifstream(program_name + std::string(".out")).rdbuf();
    std::string output = ss.str();
    int out = std::atoi(output.c_str());

    
    return 0;
}