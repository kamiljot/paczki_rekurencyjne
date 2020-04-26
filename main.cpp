#include <cstdio>
using namespace std;

struct item{
int weight;
int value;
};

int max(int a, int b){
    return (a > b)? a : b;
}


int truck(item* tab, int n, int capacity) {
    if (n == 0 || capacity == 0) {
        return 0;
    }
    if (tab[n - 1].weight > capacity) {
        return truck(tab, n - 1, capacity);
    } else {
        return max(tab[n - 1].value + truck(tab, n - 1, capacity - tab[n - 1].weight), truck(tab, n - 1, capacity));
    }
}

int main(){
int n, trucks, capacity;
    scanf("%d", &trucks);
    for (int truckCounter = 0; truckCounter < trucks; truckCounter++) {
        scanf("%d", &n);
        item *tab;
        tab= new item[n];
        for (int i = 0; i < n; i++){
            scanf("%d", &tab[i].value);
        }
        for (int i = 0; i < n; i++){
            scanf("%d", &tab[i].weight);
            if (tab[i].weight > 100){
                if (tab[i].value > 5){
                    tab[i].value -= 5;
                } else{
                    tab[i].value = 0;
                }
            }
        }
        scanf("%d", &capacity);
    int profit = truck(tab, n, capacity);
        if (profit > 20){
            printf("%d\n", profit - 20);
        } else {
            printf("%d\n", 0);
        }
        delete [] tab;
    }
    return 0;
}
