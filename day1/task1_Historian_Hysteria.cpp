//
// Created by sam on 12/2/24.
//

#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <filesystem>
#include <algorithm>
#include <iostream>

class Task1_Historian_Hysteria {

    public:

        // pass input  file to main
        Task1_Historian_Hysteria(const std::filesystem::path& input_file) {
            auto [l1, l2] = Task1_Historian_Hysteria::get_Data(input_file);

            std::cout << Task1_Historian_Hysteria::compute_Distances(l1, l2) << std::endl;
            std::cout << Task1_Historian_Hysteria::compute_Similarity(l1, l2) << std::endl;
        }
        // step 1 read data
        static std::pair<std::vector<int>, std::vector<int>>get_Data(const std::filesystem::path& input_file) {

            std::ifstream file(input_file);
            std::string line;
            std::vector<int> list1;
            std::vector<int> list2;

            // first number in list1 second in list 2, whitespace char is delimeter of numbers
            while (std::getline(file, line)) {
                // todo: make delimeter more generic
                std::string delimeter = "   ";
                list1.push_back(std::stoi(line.substr(0, line.find(delimeter))));
                list2.push_back(std::stoi(line.substr(line.find(delimeter), line.length())));
            }
            // todo: check if both lists have same length
            // step 2 sort both lists
            std::sort(list1.begin(), list1.end());
            std::sort(list2.begin(), list2.end());
            return std::make_pair(std::move(list1), std::move(list2));
        }

        static u_int32_t compute_Distances(const std::vector<int>& list1, std::vector<int>&  list2) {
            // step 3 compute distances
            u_int32_t sum = 0;
            for (int i = 0; i < list1.size(); i++) {
                sum += abs(list1[i] - list2[i]);
            }
            return sum;
        }

        static uint32_t compute_Similarity(std::vector<int> list1, const std::vector<int>&  list2) {
            uint32_t similarity = 0;
            // step 1 create bucket for each unique number in list1
            std::unique(list1.begin(), list1.end()); // l1 contains only unique elems now
            // step 2 count how often each bucket appears in list2 and multiple occurrence with bucket
            for (const auto e : list1) {
                const uint32_t counter = std::count(list2.begin(), list2.end(), e);
                similarity += counter * e;
            }
            return similarity;
        }
};
