#include "Market.h"

Market::Market() : oilPrice(70.0) {}

double Market::getPrice() const {
    return oilPrice;
}

void Market::updatePrice(double demand, double supply) {
    oilPrice += 0.1 * (demand - supply);
    if (oilPrice < 1.0) oilPrice = 1.0;
}
