/*#include <iostream>
#include <sstream>
#include "Exchange.hpp" //assuming exchange.h is the header file for Exchange class

int main() {
  Exchange e;
  std::ostringstream oss;
  e.MakeDeposit("Nahum", "BTC", 1000);
  e.MakeDeposit("Dolson", "USD", 555555);

  if(e.AddOrder({"Nahum", "Sell", "BTC", 5, 100})){
    std::cout << "Order added successfully" << std::endl;
  }
  else{
    std::cout << "Failed to add order" << std::endl;
  }

  e.PrintUserPortfolios(std::cout);
  oss.str("");
  e.PrintUserPortfolios(oss);
  std::string expected = "User Portfolios (in alphabetical order):\nDolson's Portfolio: 555555 USD, \nNahum's Portfolio: 995 BTC, \n";
  if(oss.str() == expected){
    std::cout << "Passed!" << std::endl;
    std::cout << "------------------------------------"<< std::endl;
  }
  else{
    std::cout << "Failed!" << std::endl;
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << oss.str() << std::endl;
    std::cout << "------------------------------------"<< std::endl;
  }

  e.PrintUsersOrders(std::cout);
  oss.str("");
  e.PrintUsersOrders(oss);
  expected = "Users Orders (in alphabetical order):\nDolson's Open Orders (in chronological order):\nDolson's Filled Orders (in chronological order):\nNahum's Open Orders (in chronological order):\nSell 5 BTC at 100 USD by Nahum\nNahum's Filled Orders (in chronological order):\n";
  if(oss.str() == expected){
    std::cout << "Passed!" << std::endl;
    std::cout << "------------------------------------"<< std::endl;
  }
  else{
    std::cout << "Failed!" << std::endl;
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << oss.str() << std::endl;
    std::cout << "------------------------------------"<< std::endl;
  }

  std::cout << std::endl << std::endl;

  if(e.AddOrder({"Dolson", "Buy", "BTC", 70, 150})){
    std::cout << "Order added successfully" << std::endl;
  }
  else{
    std::cout << "Failed to add order" << std::endl;
  }

  e.PrintUserPortfolios(std::cout);
  oss.str("");
  e.PrintUserPortfolios(oss);
  expected = "User Portfolios (in alphabetical order):\nDolson's Portfolio: 5 BTC, 545055 USD, \nNahum's Portfolio: 995 BTC, 750 USD, \n";
  if(oss.str() == expected){
    std::cout << "Passed!" << std::endl;
    std::cout << "------------------------------------"<< std::endl;
  }
  else{
    std::cout << "Failed!" << std::endl;
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << oss.str() << std::endl;
    std::cout << "------------------------------------"<< std::endl;
  }

  e.PrintUsersOrders(std::cout);
  oss.str("");
  e.PrintUsersOrders(oss);
  expected = "Users Orders (in alphabetical order):\nDolson's Open Orders (in chronological order):\nBuy 65 BTC at 150 USD by Dolson\nDolson's Filled Orders (in chronological order):\nBuy 5 BTC at 150 USD by Dolson\nNahum's Open Orders (in chronological order):\nNahum's Filled Orders (in chronological order):\nSell 5 BTC at 150 USD by Nahum\n";
  if(oss.str() == expected){
  std::cout << "Passed!" << std::endl;
  std::cout << "------------------------------------"<< std::endl;
  }
  else{
  std::cout << "Failed!" << std::endl;
  std::cout << "Expected: " << expected << std::endl;
  std::cout << "Actual: " << oss.str() << std::endl;
  std::cout << "------------------------------------"<< std::endl;
  }
  std::cout << std::endl << std::endl;

  if(e.AddOrder({"Nahum", "Sell", "BTC", 30, 125})){
  std::cout << "Order added successfully" << std::endl;
  }
  else{
  std::cout << "Failed to add order" << std::endl;
  }

  e.PrintUserPortfolios(std::cout);
  oss.str("");
  e.PrintUserPortfolios(oss);
  expected = "User Portfolios (in alphabetical order):\nDolson's Portfolio: 35 BTC, 545055 USD, \nNahum's Portfolio: 965 BTC, 4500 USD, \n";
  if(oss.str() == expected){
  std::cout << "Passed!" << std::endl;
  std::cout << "------------------------------------"<< std::endl;
  }
  else{
  std::cout << "Failed!" << std::endl;
  std::cout << "Expected: " << expected << std::endl;
  std::cout << "Actual: " << oss.str() << std::endl;
  std::cout << "------------------------------------"<< std::endl;
  }

  e.PrintUsersOrders(std::cout);
  oss.str("");
  e.PrintUsersOrders(oss);
  expected = "Users Orders (in alphabetical order):\nDolson's Open Orders (in chronological order):\nBuy 35 BTC at 150 USD by Dolson\nDolson's Filled Orders (in chronological order):\nBuy 5 BTC at 150 USD by Dolson\nBuy 30 BTC at 125 USD by Dolson\nNahum's Open Orders (in chronological order):\nNahum's Filled Orders (in chronological order):\nSell 5 BTC at 150 USD by Nahum\nSell 30 BTC at 125 USD by Nahum\n";
  if(oss.str() == expected){
  std::cout << "Passed!" << std::endl;
  std::cout << "------------------------------------"<< std::endl;
  }
  else{
  std::cout << "Failed!" << std::endl;
  std::cout << "Expected: " << expected << std::endl;
  std::cout << "Actual: " << oss.str() << std::endl;
  std::cout << "------------------------------------" << std::endl;
  }

  if(e.MakeWithdrawal("Dolson", "BTC", 35)){
  std::cout << "Withdrawal made successfully" << std::endl;
  }
  else{
  std::cout << "Failed to make withdrawal" << std::endl;
  }

  return 0;
  }

*/