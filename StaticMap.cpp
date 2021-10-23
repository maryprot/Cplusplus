#include <iostream>
#include <vector>

class StaticMap
{
public:
StaticMap(const std::vector< std::pair<int, int> >& data_map) : data_map_(data_map) {}

void put(int key , int value) {
    data_map_.push_back({key, value});
}

void add(int key , int increment) {
    bool flag = false;
    for (int i=0; i < data_map_.size(); ++i) {
        if (data_map_[i].first == key) {
            flag = true;
            data_map_[i].second += increment;
            break;
        }
    }
    if (!flag){
        throw std::runtime_error (" key not found ");
    }
}

int get(int key) {
    for (int i=0; i < data_map_.size(); ++i) {
        if (data_map_[i].first == key) {
            return data_map_[i].second;
        }
    }
    throw std::runtime_error (" key not found ");
}

private:
    std::vector<std::pair<int, int>> data_map_;
};


int main() {
    StaticMap mapa({{1, 1}, {2, 4}});
    mapa.put(3, 7);
    mapa.add(3, 2);
    std::cout << mapa.get(2) << std::endl;
    std::cout << mapa.get(3) << std::endl;


    return 0;
}
