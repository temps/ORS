#ifndef MARKET_H
#define MARKET_H

class Market {
public:
    Market();
    double getPrice() const;
    void updatePrice(double demand, double supply);

private:
    double oilPrice;
};

#endif // MARKET_H
