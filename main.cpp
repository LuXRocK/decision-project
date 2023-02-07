/** @file */

#include <iostream>
#include <fstream>
#include <vector>
#include "functions.h"




int main(int argc, char* argv[])
{
    Args args = parseArgs(argc, argv);


    std::ifstream input_file(args.input);
    std::ifstream tree_file(args.tree);
    std::ofstream output_file(args.output);

    // int n, d;
    // std::string line1;
    // getline(input_file, line1);
    // line1 = line1.substr(0, line1.find('%'));
    // std::stringstream sss;
    // sss << line1;
    // sss >> n >> d;
    // output_file << n << " " << d << " " << "% " << "n=" << n << " przykładow, " << "d=" << d << " atrybuty" << std::endl;


    // std::string line;
    // std::vector<std::string> keys;
    // getline(input_file, line);
    // line = line.substr(0, line.find('%'));
    // std::stringstream ss;
    // ss << line;
    // std::string tmp;
    // while(ss >> tmp){
    //     keys.push_back(tmp);
    // }
    // for(int i = 0; i<keys.size(); i++){
    //     output_file << keys[i] << " ";
    // }
    // output_file << "% nazwy atrybutow" << std::endl;
    info(input_file, output_file);
    PersonData v = readInputFile(input_file, output_file);
    std::vector<Node*> tree = readTreeFile(tree_file);
    connectNodes(tree);

    


    for(int i = 0; i<v.size(); i++){
        for(auto const& x : v[i]){
            output_file << x.second << " ";
        }
        output_file << decide(tree[0], v[i]) << std::endl;
    }
    
    for(int i = 0; i<tree.size(); i++){
        delete tree[i];
    }
 
    output_file.close();
    input_file.close();

    
}