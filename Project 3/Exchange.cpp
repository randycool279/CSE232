#include "Exchange.hpp"

#include <algorithm>
#include <iomanip>
#include <map>
#include <sstream>
#include <vector>

#include "utility.hpp"

void Exchange::MakeDeposit(const std::string &username,
                           const std::string &asset, int amount) {
  user_accounts[username].portfolio[asset] += amount;
  user_accounts[username].has_portfolio = true;
}

void Exchange::PrintUserPortfolios(std::ostream &os) const {
  std::ostringstream oss;
  oss << "User Portfolios (in alphabetical order):" << std::endl;
  for (const auto &user : user_accounts) {  // iterate through useraccounts map
    if (user.second.has_portfolio) {
      std::map<std::string, int> temp_portfolio =
          user.second.portfolio;  // create temp_port so it can reflect balance
                                  // for no double spending

      std::vector<std::pair<std::string, int>> assets_sorted;  // sort assets
      for (const auto &asset : temp_portfolio) {
        if (asset.second > 0) {
          assets_sorted.push_back(
              asset);  // report assets that have value greater than 0
        }
      }

      oss << user.first << "'s Portfolio: ";

      if (!assets_sorted.empty()) {
        std::sort(assets_sorted.begin(),
                  assets_sorted.end());  // sort assets based on reqs
        for (const auto &asset : assets_sorted) {
          oss << asset.second << " " << asset.first << ", ";
        }
      }

      oss << std::endl;
    }
  }
  os << oss.str();
}

bool Exchange::MakeWithdrawal(const std::string &username,
                              const std::string &asset, int amount) {
  if (user_accounts[username].portfolio[asset] >=
      amount) {  // check if port has the money/asset to withdraw, then withdraw
    user_accounts[username].portfolio[asset] -= amount;
    return true;
  }
  return false;
}

bool orderMatchingTakerBuy(
    const Order taker, const Order maker,
    const Order
        current_trade_order) {  // helper function to match buy orders with sell
  // If the taker is a buy order, the sell with the lowest price (and under the
  // taker’s buy price) will be the order that participates in a trade
  if (maker.side == "Sell") {  // check if the maker is a sell
    if (maker.asset ==
        taker.asset) {  // check if maker is selling the correct asset
      if (maker.price <= taker.price) {  // check of the maker's sell price is
                                         // under or equal to taker's buy price
        if (maker.price < current_trade_order.price ||
            current_trade_order == Order()) {  // look for LOWEST SELL
          return true;
        }
      }
    }
  }
  return false;
}

bool orderMatchingTakerSell(
    const Order taker, const Order maker,
    const Order
        current_trade_order) {  // helper function to match sell orders with buy
  // If the taker is a sell, then the highest buy (and must be higher than the
  // taker’s sell price) is the best order and will participate in the trade.
  if (maker.side == "Buy") {  // check if the maker is a sell
    if (maker.asset ==
        taker.asset) {  // check if maker is selling the correct asset
      if (maker.price >= taker.price) {  // check of the maker's sell price is
                                         // higher than or equal to taker's sell
                                         // price
        if (maker.price > current_trade_order.price ||
            current_trade_order == Order()) {  // look for HIGHEST BUY
          return true;
        }
      }
    }
  }

  return false;
}

Trade createTrade(int amount, std::string asset, int price, std::string buyer,
                  std::string seller) {  // helper function to create a trade
                                         // with the certain fields
  Trade new_trade = Trade();

  new_trade.amount = amount;
  new_trade.asset = asset;
  new_trade.price = price;
  new_trade.buyer_username = buyer;
  new_trade.seller_username = seller;

  return new_trade;
}

bool Exchange::AddOrder(const Order &input_order) {
  Order order = input_order;  // taker

  if (order.side == "Buy") {
    int required_usd =
        order.amount * order.price;  // required funds to place trade
    if (user_accounts[order.username].portfolio["USD"] <
        required_usd) {  // check if user has sufficient funds
      return false;
    }

    user_accounts[order.username].portfolio["USD"] -= required_usd;
  } else if (order.side == "Sell") {
    if (user_accounts[order.username].portfolio[order.asset] <
        order.amount) {  // check if user has sufficient funds
      return false;      // user has insufficient funds!
    }

    user_accounts[order.username].portfolio[order.asset] -=
        order
            .amount;  // user has sufficient funds, remove assets from portfolio
  } else {            // if order is not sell or buy do nothing
    return false;
  }

  bool match_found = true;

  while (match_found && order.amount > 0) {
    // Order matching
    Order current_match = Order();
    match_found = false;
    auto match_it = open_orders.begin();
    for (auto it = open_orders.begin(); it != open_orders.end(); ++it) {
      if (order.side == "Buy") {
        if (orderMatchingTakerBuy(order, *it, current_match) == true) {
          current_match = *it;  // store values
          match_it = it;       // store iterator pointing to array to edit later
          match_found = true;  // match was found!
        }
      }
      if (order.side == "Sell") {
        if (orderMatchingTakerSell(order, *it, current_match) == true) {
          current_match = *it;
          match_it = it;
          match_found = true;
        }
      }
    }

    if (match_found) {  // trade occurs
      int trade_amount = 0;
      int trade_price = 0;
      Order buyer_order = Order();
      Order seller_order = Order();
      // Update user accounts
      if (order.side == "Buy") {
        trade_amount = std::min(
            current_match.amount,
            order.amount);  // can only trade min amount between both orders
        trade_price = std::max(current_match.price, order.price);
        user_accounts[order.username].portfolio[order.asset] += trade_amount;
        user_accounts[current_match.username].portfolio["USD"] +=
            trade_amount * trade_price;

        // set trade info
        trade_history.push_back(createTrade(trade_amount, current_match.asset,
                                            trade_price, order.username,
                                            current_match.username));

        // set order info
        if (trade_amount == order.amount) {
          buyer_order = order;
          buyer_order.executed_price = trade_price;
        } else {
          buyer_order.amount = trade_amount;
          buyer_order.asset = order.asset;
          buyer_order.side = "Buy";
          buyer_order.executed_price = trade_price;
        }
        if (trade_amount == current_match.amount) {
          seller_order = current_match;
          seller_order.executed_price = trade_price;
        } else {
          seller_order.amount = trade_amount;
          seller_order.asset = order.asset;
          seller_order.side = "Sell";
          seller_order.executed_price = trade_price;
        }
      }
      if (order.side == "Sell") {
        trade_amount = std::min(current_match.amount, order.amount);
        trade_price = std::min(current_match.price, order.price);
        user_accounts[order.username].portfolio["USD"] +=
            trade_amount * trade_price;
        user_accounts[current_match.username].portfolio[order.asset] +=
            trade_amount;

        // set trade info
        trade_history.push_back(createTrade(trade_amount, current_match.asset,
                                            trade_price, current_match.username,
                                            order.username));

        // set order info
        if (trade_amount == order.amount) {
          seller_order = order;
          seller_order.executed_price = trade_price;
        } else {
          seller_order.amount = trade_amount;
          seller_order.asset = order.asset;
          seller_order.side = "Sell";
          seller_order.executed_price = trade_price;
        }
        if (trade_amount == current_match.amount) {
          buyer_order = current_match;
          buyer_order.executed_price = trade_price;
        } else {
          buyer_order.amount = trade_amount;
          buyer_order.asset = order.asset;
          buyer_order.side = "Buy";
          buyer_order.executed_price = trade_price;
        }
      }
      // add fulfilled orders
      if (order.side == "Buy") {
        user_accounts[order.username].filled_orders.push_back(buyer_order);
        user_accounts[current_match.username].filled_orders.push_back(
            seller_order);
      }
      if (order.side == "Sell") {
        if (order.username == current_match.username) {  // project spec for
                                                         // testcase, threw me
                                                         // off a little
          user_accounts[current_match.username].filled_orders.push_back(
              buyer_order);
          user_accounts[order.username].filled_orders.push_back(seller_order);
        } else {
          user_accounts[order.username].filled_orders.push_back(seller_order);
          user_accounts[current_match.username].filled_orders.push_back(
              buyer_order);
        }
      }
      // Update the open orders
      order.amount -= trade_amount;
      match_it->amount -= trade_amount;
      if (match_it->amount == 0) {
        match_it = open_orders.erase(match_it);
      }
    }
  }
  if (order.amount > 0) {  // if order was not fulfilled add order to
                           // open_orders array and users orders
    // Add the remaining order to open_orders and user's orders list
    open_orders.push_back(order);
    user_accounts[order.username].orders.push_back(order);
  }

  return true;
}

void Exchange::PrintUsersOrders(std::ostream &os) const {
  os << "Users Orders (in alphabetical order):";
  auto last_user_iter = user_accounts.end();
  --last_user_iter;
  for (const auto &user : user_accounts) {  // iterate through useraccount map
    os << std::endl
       << user.first << "'s Open Orders (in chronological order):" << std::endl;
    for (const auto &order : open_orders) {
      if (order.username == user.first) {  // make sure on correct user
        os << order.side << " " << order.amount << " " << order.asset << " at "
           << order.price << " USD by " << user.first << std::endl;
      }
    }
    os << user.first << "'s Filled Orders (in chronological order):";
    bool first_filled_order = true;
    for (const auto &filled_order :
         user_accounts.at(user.first).filled_orders) {
      if (!first_filled_order) {
        os << std::endl;
      } else {
        first_filled_order = false;
        if (!user_accounts.at(user.first)
                 .filled_orders.empty()) {  // Add this check bcz program would
                                            // add unwanted newline
                                            // for no orders on fill
          os << std::endl;
        }
      }
      if (filled_order.side == "Buy") {
        os << "Buy " << filled_order.amount << " " << filled_order.asset
           << " at " << filled_order.executed_price << " USD by " << user.first;
      } else if (filled_order.side == "Sell") {
        os << "Sell " << filled_order.amount << " " << filled_order.asset
           << " at " << filled_order.executed_price << " USD by " << user.first;
      }
    }
  }
  os << std::endl;
}

void Exchange::PrintTradeHistory(std::ostream &os) const {
  os << "Trade History (in chronological order):" << std::endl;
  for (const auto &trade : trade_history) {  // simple trade history iteration
    os << trade.buyer_username << " Bought " << trade.amount << " of "
       << trade.asset << " From " << trade.seller_username << " for "
       << trade.price << " USD" << std::endl;
  }
}

void Exchange::PrintBidAskSpread(std::ostream &os) const {
  std::map<std::string, std::pair<int, int>>
      bid_ask_spread;  // create map for bidask spread

  for (const auto &order : open_orders) {
    if (order.side == "Buy") {
      bid_ask_spread[order.asset].first =
          std::max(bid_ask_spread[order.asset].first, order.price);
    } else if (order.side == "Sell") {
      if (bid_ask_spread[order.asset].second == 0) {
        bid_ask_spread[order.asset].second = order.price;
      } else {
        bid_ask_spread[order.asset].second =
            std::min(bid_ask_spread[order.asset].second, order.price);
      }
    }
  }

  os << "Asset Bid Ask Spread (in alphabetical order):" << std::endl;
  for (const auto &spread : bid_ask_spread) {
    os << spread.first << ": ";
    if (spread.second.first == 0) {
      os << "Highest Open Buy = NA USD";
    } else {
      os << "Highest Open Buy = " << spread.second.first << " USD";
    }
    os << " and ";
    if (spread.second.second == 0) {
      os << "Lowest Open Sell = NA USD";
    } else {
      os << "Lowest Open Sell = " << spread.second.second << " USD";
    }
    os << std::endl;
  }
}