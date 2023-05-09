#pragma once
#include <iostream>
#include <string>

struct Order {
  std::string username;
  std::string side;  // Can be "Buy" or "Sell"
  std::string asset;
  int amount;
  int price;
  int executed_price = 0;
  int executed_amount =0;
  friend std::ostream& operator<<(std::ostream &os, const Order &order) {
    os << order.side << " " << order.amount << " " << order.asset << " at " << order.price << " USD by " << order.username;
    return os;
    }
  bool operator==(const Order &other) const {
    return (username == other.username) && (side == other.side) && (asset == other.asset) && (amount == other.amount) && (price == other.price);
  }

};

struct Trade {
  std::string buyer_username;
  std::string seller_username;
  std::string asset;
  int amount;
  int price;
};