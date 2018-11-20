#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;



class Item
{
    public:
        Item(string name, string desc, int pieceOf, int attack, int defence, int heal, int shopPrice, int sellPrice);
        Item();

        //Getters:
        string getName();
        string getDescription();
        int getPieceOf();
        int getAttack();
        int getDefence();
        int getHeal();
        int getShopPrice();
        int getSellPrice();

        //Setters:
        void setName(string name);
        void setDescription(string desc);
        void setPieceOf(int pieceOf);
        void setAttack(int attack);
        void setDefence(int defence);
        void setHeal(int heal);
        void setShopPrice(int shopPrice);
        void setSellPrice(int sellPrice);



    private:


        //name of the item:
        string _name;
        //item description:
        string _description;
        //How many pieces do you have from the item:
        int _pieceOf;
        //attack value, if any:
        int _attack;
        //defence value, if any:
        int _defence;
        //heal value, if any:
        int _heal;
        //shop-price of item:
        int _shopPrice;
        //selling-price of item:
        int _sellPrice;
};

#endif // ITEM_H
