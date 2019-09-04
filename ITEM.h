#ifndef ITEM_TEMPLATE_H_
#define ITEM_TEMPLATE_H_

using namespace std;

class ITEM {
public:
	string name;
	int quantity;
	ITEM() : name(""), quantity(0){}
	~ITEM() {}
	ITEM(string name) : name(name), quantity(0) {}
	virtual bool Process_Purchase(istream &cin, ostream &cout) {
        cout << "processing ... \n";
		return true;
	}
	virtual int Get_Cost() const {
		cout<<"don't call this function"<<endl;
		return 0;
	}
    bool operator<(const ITEM& rhs) {
		return this->name < rhs.name;
	}
	virtual void Print(ostream &out=cout) const {
		out<<"Print the derived class info instead of this"<<endl;
	}
};
ostream & operator<<(ostream &out, const ITEM &rhs) {
	rhs.Print(out);
	return out;
}
bool compare_pointers_to_items(ITEM *lhs, ITEM *rhs) {
	return *lhs < *rhs;
}


class BALLS : public ITEM {
public:
    ~BALLS() {}
    int size;
    
    // takes input from user - returns true if successful purchase
    bool Process_Purchase(istream &cin, ostream &cout){
        cout << endl << "Cannon Balls come in three sizes:" << endl;
        cout << "  1) Small     6 pieces of eight per Cannon Ball" << endl;
        cout << "  2) Medium   15 pieces of eight per Cannon Ball" << endl;
        cout << "  3) Large    52 pieces of eight per Cannon Ball" << endl;
        cout << "What size would you like? ";
        cin >> size;
        if ((size < 1) || (size > 3)){
            return false;
        }
        // assign names for correct receipt sorting
        switch (size){
            case 1:{
                name = "d";
            } break;
            case 2:{
                name = "e";
            } break;
            case 3:{
                name = "f";
            } break;
        }
        
        cout << "How many would you like? ";
        cin >> quantity;
        if (quantity <= 0){
            return false;
        }
        cout << "Happy hunting!" << endl;
        return true;
    }
    
    // prints output to console
    void Print(ostream &out=cout) const {
        string plural = "Balls";
        if (quantity == 1){
            plural = "Ball";
        }
        
        switch (size){
            case 1:{
                out << quantity << " Small Cannon " << plural;
            } break;
            case 2:{
                out << quantity << " Medium Cannon " << plural;
            } break;
            case 3:{
                out << quantity << " Large Cannon " << plural;
            } break;
        }
    }
    
    // returns price of purchase
    int Get_Cost() const {
        switch (size){
            case 1:{
                return (6 * quantity);
            } break;
            case 2:{
                return (15 * quantity);
            } break;
            case 3:{
                return (52 * quantity);
            } break;
        }
        return 0;
    }
};

class RUM : public ITEM {
public:
    ~RUM() {}
    int type;
    
    // takes input from user - returns true if successful purchase
    bool Process_Purchase(istream &cin, ostream &cout){
        cout << endl << "We have three different qualities of Rum in stock:" << endl;
        cout << "  1) Swill     1 pieces of eight per barrel" << endl;
        cout << "  2) Grog      5 pieces of eight per barrel" << endl;
        cout << "  3) Fine Rum 19 pieces of eight per barrel" << endl;
        cout << "What kind would you like? ";
        cin >> type;
        // assign names for correct receipt sorting
        switch (type){
            case 1:{
                cout << "Gotta keep the crew happy!" << endl;
                name = "h";
            } break;
            case 2:{
                cout << "The officers will love it!" << endl;
                name = "i";
            } break;
            case 3:{
                cout << "Nothing but the best for the captain!" << endl;
                name = "j";
            } break;
            default: return false;
        }
        
        cout << "How many barrels would you like? ";
        cin >> quantity;
        if (quantity <= 0){
            return false;
        }
        return true;
    }
    
    // prints output to console
    void Print(ostream &out=cout) const {
        string plural = "Barrels";
        if (quantity == 1){
            plural = "Barrel";
        }
        
        switch (type){
            case 1:{
                out << quantity << " " << plural << " of Swill";
            } break;
            case 2:{
                out << quantity << " " << plural << " of Grog";
            } break;
            case 3:{
                out << quantity << " " << plural << " of Fine Rum";
            } break;
        }
    }

    // returns price of purchase
    int Get_Cost() const {
        switch (type){
            case 1:{
                return (1 * quantity);
            } break;
            case 2:{
                return (5 * quantity);
            } break;
            case 3:{
                return (19 * quantity);
            } break;
        }
        return 0;
    }
};

class LIMES : public ITEM {
public:
    ~LIMES() {}
    int dozens = 0;
    
    // takes input from user - returns true if successful purchase
    bool Process_Purchase(istream &cin, ostream &cout){
        cout << endl << "Limes arrr delicious. They're on sale for 7 pieces of eight per dozen." << endl;
        cout << "How many dozen would you like? ";
        cin >> dozens;
        quantity = dozens * 12;
        if (quantity <= 0){
            return false;
        }
        // assign name for correct receipt sorting
        name = "g";
        return true;
    }
    
    // prints output to console
    void Print(ostream &out=cout) const {
        out << (quantity) << " Limes";
    }
        
    // returns price of purchase
    int Get_Cost() const {
        return (7 * dozens);
    }
};

class APPAREL : public ITEM {
public:
    ~APPAREL() {}
    int type;
    
    // takes input from user - returns true if successful purchase
    bool Process_Purchase(istream &cin, ostream &cout){
        cout << endl << "That looks like a rough injury." << endl;
        cout << "  1) Eyepatch  4 pieces of eight" << endl;
        cout << "  2) Pegleg   13 pieces of eight" << endl;
        cout << "  3) Hook     43 pieces of eight" << endl;
        cout << "You're going to need a ... ";
        cin >> type;
        if ((type < 1) || (type > 3)){
            return false;
        }
        // assign names for correct receipt sorting
        switch (type){
            case 1:{
                name = "a";
            } break;
            case 2:{
                name = "c";
            } break;
            case 3:{
                name = "b";
            } break;
        }
        
        quantity = 1;
        if(type == 2){
            cout << "We'll be getting more crutches in stock early next week." << endl;
        }
        return true;
    }
    
    // prints output to console
    void Print(ostream &out=cout) const {
        switch (type){
            case 1:{
                out << "1 Eyepatch";
            } break;
            case 2:{
                out << "1 Pegleg";
            } break;
            case 3:{
                out << "1 Hook";
            } break;
        }
    }
    
    // returns price of purchase
    int Get_Cost() const {
        switch (type){
            case 1:{
                return 4;
            } break;
            case 2:{
                return 13;
            } break;
            case 3:{
                return 43;
            } break;
        }
        return 0;
    }
};
#endif
