#include <vector>
#include <iostream>
using namespace std;

struct Item {
    int id, val, imptn, preced;
    Item(int id_, int val_, int imptn_, int preced_):
    id(id_), val(val_), imptn(imptn_), preced(preced_) {}
};

bool check_preced(vector<Item> cart, Item item) {
    if (item.preced==0) return true;
    else {
        bool flag;
        for (Item item_ : cart) {
            if (item_.id==item.preced) {
                flag = true;
                break;
            }
        }
        return flag;
    }
}

int val_comb(vector<Item> cart, vector<Item> wishlist, int budget) {
    int max_val=0, total_val=0, total_cost = 0;
    for (Item item : cart) {
        total_val += item.val * item.imptn;
        total_cost += item.val;
    }
    max_val = total_val;
    for (int i=0; i<wishlist.size(); i++) {
        Item item = wishlist[i];
        if (check_preced(cart, item) and total_cost+item.val<=budget) {
            auto new_cart = cart;
            new_cart.push_back(item);
            vector<Item> new_wishlist;
            for (int j=0; j<wishlist.size(); j++) {
                if (j!=i) new_wishlist.push_back(wishlist[j]);
            }
            total_val = val_comb(new_cart, new_wishlist, budget);
            if (total_val>max_val) max_val = total_val;
        }
    }
    return max_val;
}

int main() {
    int budget, n_items;
    cin >> budget >> n_items;
    int val_, imptn_, preced_;
    vector<Item> wishlist;
    for (int i=0; i<n_items; i++) {
        cin >> val_ >> imptn_ >> preced_;
        wishlist.push_back(Item(i+1, val_, imptn_, preced_));
    }
    
    vector<Item> cart;
    cout << val_comb(cart, wishlist, budget) << endl;
    
    return 0;
}