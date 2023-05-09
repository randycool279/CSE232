#pragma once
#include <map>
#include <string>
#include <vector>
#include "utility.hpp"

struct UserAccount {
    std::map<std::string, int> portfolio; // asset -> quantity 
    std::vector<Order> orders; //all orders or just open orders?
    std::vector<Order> filled_orders; 
    bool has_portfolio = false;
    int balance; //usd value ?
};
