#include <iostream>
#include <string>
#include <vector>
void print_vector(std::vector<std::vector<std::string> > vec){
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            std::cout << vec[i][j] << std::endl;
        }
    }
}
std::vector<std::string> takeInput() {
    std::vector<std::string> value;
    for (std::string line; std::getline(std::cin, line);){
        value.push_back(line);
    }
    return value;
}
std::vector<std::vector<std::string> > split_spaces(std::vector<std::string> raw){
    std::vector<std::vector<std::string> > split;
    for (int i = 0; i < raw.size(); i++){
        std::string str = raw[i];
        split.resize(i+1);
        std::string delimiter = " ";
        int start = 0;
        int end = str.find(" ");
        while (end != -1) {
            split[i].push_back(str.substr(start, end - start));
            start = end + delimiter.size();
            end = str.find(delimiter, start);
        }
        split[i].push_back(str.substr(start, end - start));
    }
    return split;
}
int main() {
    std::vector<std::string> initial = takeInput();
    std::vector<std::vector<std::string> > split = split_spaces(initial);
    print_vector(split);
    return 0;
}