#pragma once

#include <iostream>

class Product
{
public:
    Product(const unsigned int id) : m_id(id) {}

    int Id() const { return m_id; }
    int Price() const { return m_price; }

    virtual void Print() const { std::cout << "Product with ID=" << Id() << " costs " << Price() << std::endl; }
    
protected:
    void SetPrice(const int price) { m_price = price; }

private:
    const unsigned int m_id;
    int m_price;
};
