class MovieRentingSystem {
public:
    set<vector<int>> rented;  // {price, shop, movie}; sorted by price->shop->movie
    unordered_map<int, set<vector<int>>> unrented;  // [movie] -> {price, shop}]
    unordered_map<int, unordered_map<int, int>> price;   //2D map, price[movie][shop]=price

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto av:entries){
            int shop = av[0];
            int movie = av[1];
            int p = av[2];      // price
            unrented[movie].insert({p, shop});
            price[movie][shop] = p;
        }
    }
    
    vector<int> search(int movie) {
        if(unrented.find(movie) == unrented.end()) return {};
        // just checking which shop sell the movie
        vector<int>ans;
        for(auto av: unrented[movie]){
            int shop = av[1];
            ans.push_back(shop);
            if(ans.size()==5) break;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        // remove from unrented and add in rented thats why I need price
        int p = price[movie][shop];
        unrented[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }
    
    void drop(int shop, int movie) {
        // reverse of rent
        int p = price[movie][shop];
        rented.erase({p, shop, movie});
        unrented[movie].insert({p, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for(auto av: rented){
            int shop = av[1];
            int movie = av[2];
            res.push_back({shop, movie});
            if(res.size()==5) break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */