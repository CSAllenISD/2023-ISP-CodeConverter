#include <iostream>
#include <string>
#include <vector>
void print_vector(std::vector<std::string> vec){
    for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << std::endl;
    }
}
std::vector<std::string> takeInput() {
    std::vector<std::string>  value;
    for (std::string line; std::getline(std::cin, line);){
        value.push_back(line);
    }
    return value;
}
std::vector<std::string>  remove_spaces(std::vector<std::string>  raw){
    std::vector<std::string> newOne;
    for (int i = 0; i < raw.size(); i++){
        std::string emp;
        for (int j = 0; j < raw[i].length(); j++){
            if (!isspace(raw[i][j])){
                emp = emp + raw[i][j];
            } 
        }
        newOne.push_back(emp);
    }
    return newOne;
}


int main() {
    std::vector<std::string> lines = remove_spaces(takeInput());
    print_vector(lines);
    //std::vector<Variable> variables;
    return 0;
}