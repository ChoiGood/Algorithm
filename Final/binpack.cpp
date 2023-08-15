#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct  item 
{
    int index;
    int weight;
} item_t;

struct compare {
    bool operator()(item_t u, item_t v) {
        if (u.weight > v.weight)
            return true;
        return false;
    }
};



typedef priority_queue<item_t, vector<item_t>, compare> pqueue_t;
typedef vector<item_t> bin_t;


void binpack(int W, int n, pqueue_t PQ, vector<bin_t> & bins) {
    while(!PQ.empty()) {
        item_t item = PQ.top(); PQ.pop();
        bool isPacked = false;
        vector<bin_t>::iterator bin_ptr = bins.begin();
        for(; !isPacked && bin_ptr != bins.end(); bin_ptr++) {
            if( ableToFit(&bin_ptr, item, W)) {
                bin_ptr->push_back(item);
                isPacked = true;
            }
        }

        if(!isPacked) {
            bin_t bin;
            bin.push_back(item);
            bins.push_back(bin);
        }
    }
}



int main()
{
    int W, n;
    cin >> W >> n;

    pqueue_t PQ;
    for (int i = 1; i<=n; i++) {
        item_t item;
        item.index = i;
        cin >> item.weight;
        PQ.push(item);
    }
    vecotr<bin_t> bins;
    binpack(W,n, PQ, bins);
    cout << bins.size() << endl;

    return 0;
}