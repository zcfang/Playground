#include <string>
#include <map>
#include <vector>
#include <utility>
#include <assert.h>

/**
 * Problem from LeetCode 599: Minimum Index Sum of Two Lists. You can find the
 * problem
 * <a href="https://leetcode.com/problems/minimum-index-sum-of-two-lists/">
 * here</a>.
 *
 * @param[in] list1: A vector of restaurant names
 * @param[in] list2: A vector of restaurant names
 * @returns Common restaurant(s) between list1 and list2 where the index sum is
 * minimum 
 */
std::vector<std::string> find_restaurant(std::vector<std::string> &list1,
                                         std::vector<std::string> &list2);

int main(int argc, char const *argv[]) {
    std::vector<std::string> list1{"Shogun",
                                   "Tapioca Express",
                                   "Burger King",
                                   "KFC"};
    std::vector<std::string> list2{"Piatti",
                                   "The Grill at Torrey Pines",
                                   "Hungry Hunter Steakhouse",
                                   "Shogun"};
    std::vector<std::string> solution_1{"Shogun"};

    assert(find_restaurant(list1, list2) == solution_1);

    return 0;
}

std::vector<std::string> find_restaurant(std::vector<std::string> &list1,
                                         std::vector<std::string> &list2) {
    std::map<std::string, int> common_restaurant;
    std::map<std::string, int> restaurant_map;
    std::vector<std::string> output;
    uint32_t min_index = 0xFFFFFFFF;
    
    for (std::size_t i = 0; i < list1.size(); i++) {
        restaurant_map[list1[i]] = i;
    }
    for (std::size_t i = 0; i < list2.size(); i++) {
        if (restaurant_map.count(list2[i])) {
            common_restaurant[list2[i]] = i + restaurant_map[list2[i]];
            if (min_index > common_restaurant[list2[i]]) {
                min_index = common_restaurant[list2[i]];
            }
        }
    }
    for (const std::pair<std::string, int> restaurant : common_restaurant) {
        if (restaurant.second == min_index) {
            output.push_back(restaurant.first);
        }
    }

    return output;
}
