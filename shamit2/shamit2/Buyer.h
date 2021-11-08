#ifndef  __BUYER_H
#define  __BUYER_H

#include "User.h"
#include "Cart.h"
#include <iostream>
#include <fstream>

class Buyer : virtual public User
{
protected:
	//variables
	Cart* cart;
	vector<Cart*> oldOrdersCarts;

public:
	//c'tor && d'tor
	Buyer();
	Buyer(const string& userName, const string& pass, Address& address);
	Buyer(const Buyer& other);
	const Buyer& operator=(const Buyer& other); // operator= 
	bool operator>(const Buyer& other); // operator> (compare totalCartPrice). return true if buyer cart's price is bigger than other
	Buyer(Buyer&&) = delete; // would u like to change?
	~Buyer();

	//Setters 
	void setCart(Cart& other);

	//Functions
	virtual User* clone() const override { return new Buyer(*this); }
	void BuyeraddProductToCart(Product* productToAdd);
	void BuyerAddCartToOldOrders(Cart& cartToAdd);
	vector<Cart*> getOldOrdersCarts() const;

	friend ostream& operator<<(ostream& os, const Buyer& buyer) // operator <<
	{
		if (typeid(os) == typeid(ofstream))
		{
			os << buyer.userName << " " << buyer.pass << " " << buyer.address;
		}
		else
		{
			os << "usermame:" << buyer.userName << "\n" << "city:" << buyer.pass << "\n"
				<< "street address:" << buyer.address << "\n";
		}

		return os;
	}

	friend istream& operator>>(istream& is, Buyer& buyer)
	{
		is >> buyer.userName >> buyer.pass >> buyer.address;

		return is;
	}

	friend class Manager;
};
#endif
