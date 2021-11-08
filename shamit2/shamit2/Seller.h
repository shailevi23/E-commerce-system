#ifndef __Seller_H
#define __Seller_H

#include "User.h"
#include "Feedback.h"
#include "Product.h"
#include "Array.h"
#include <iostream>
#include <fstream>

class Seller : virtual public User
{
protected:
	//variables
	Array<Feedback*> feedbacks;
	vector<Product*> products;

public:
	//c'tor && d'tor
	Seller();
	Seller(const string& userName, const string& pass, Address& address);
	Seller(const Seller& other);
	Seller(Seller&& other); //move c'tor
	const Seller& operator=(const Seller& other); // operator= 
	~Seller();

	 //Functions
	 virtual User* clone() const override { return new Seller(*this); }
	 void readNewProduct(Product &product, int& serialNum, const string& sellerUserName);
	 void SellerAddProduct(int& serialNum);
	 

	 friend ostream& operator<<(ostream& os, const Seller& seller) // operator <<
	 {
		 if (typeid(os) == typeid(ofstream))
		 {
			 os << seller.userName << " " << seller.pass << " " << seller.address;
		 }
		 else
		 {
			 os << "usermame:" << seller.userName << "\n" << "city:" << seller.pass << "\n"
				 << "street address:" << seller.address << "\n";
		 }

		 return os;
	 }

	 friend istream& operator>>(istream& is, Seller& seller)
	 {
		 is >> seller.userName >> seller.pass >> seller.address;

		 return is;
	 }

	 friend class Manager;
};
#endif
