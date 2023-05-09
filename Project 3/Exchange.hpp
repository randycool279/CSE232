#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

#include "userAccounts.hpp"
#include "utility.hpp"

class Exchange {
 public:
  void MakeDeposit(const std::string &username, const std::string &asset,
                   int amount);
  void PrintUserPortfolios(std::ostream &os) const;
  bool MakeWithdrawal(const std::string &username, const std::string &asset,
                      int amount);
  bool AddOrder(const Order &order);
  void PrintUsersOrders(std::ostream &os) const;
  void PrintTradeHistory(std::ostream &os) const;
  void PrintBidAskSpread(std::ostream &os) const;

 private:
  std::map<std::string, UserAccount> user_accounts;
  std::vector<Order> open_orders;
  std::vector<Trade> trade_history;
  
  bool executeTrade(Order &taker_order, Order &maker_order);
  void updateBidAskSpread(const Order &order);
  std::map<std::string, std::pair<int, int>> bid_ask_spread;
};
