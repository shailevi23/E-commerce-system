#ifndef __BuyerAndSeller_H
#define __BuyerAndSeller_H

#include "User.h"
#include "Buyer.h"
#include "Seller.h"
#include <iostream>
#include <fstream>

class BuyerAndSeller : public Buyer, public Seller
{

public:
	//c'tor && d'tor
	BuyerAndSeller();
	BuyerAndSeller(const string& userName, const string& pass, Address& address);
	BuyerAndSeller(const BuyerAndSeller& other);
	BuyerAndSeller(BuyerAndSeller&&) = delete;

	//Functions
	virtual User* clone() const override { return new BuyerAndSeller(*this); }

	friend ostream& operator<<(ostream& os, const BuyerAndSeller& buyerandseller) // operator <<
	{
		if (typeid(os) == typeid(ofstream))
		{
			os << buyerandseller.userName << " " << buyerandseller.pass << " " << buyerandseller.address;
		}
		else
		{
			os << "usermame:" << buyerandseller.userName << "\n" << "city:" << buyerandseller.pass << "\n"
				<< "street address:" << buyerandseller.address << "\n";
		}

		return os;
	}

	friend istream& operator>>(istream& is, BuyerAndSeller& buyerandseller)
	{
		is >> buyerandseller.userName >> buyerandseller.pass >> buyerandseller.address;

		return is;
	}

	friend class Manager;
};
#endif