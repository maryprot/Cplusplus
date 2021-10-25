#include <iostream>
#include <vector>
#include <algorithm>

bool comp (std::pair <int, int> a, std::pair <int, int> b) {
  return a.first < b.first;
}


class StaticMap
{
public:
    StaticMap(const std::vector< std::pair<int, int> >& data_map) : data_map_(data_map) {
        sort(data_map_.begin(), data_map_.end(), comp);
    }

    void put(int key , int value) {
        data_map_.push_back({key, value});
        sort(data_map_.begin(), data_map_.end(), comp);
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
        bool flag = false;
        int l = 0;
        int r = data_map_.size() - 1;
        int mid;

        while((flag != true) && (l <= r)){
            mid = (l + r) / 2;

            if (data_map_[mid].first == key)
                flag = true;
            else if (data_map_[mid].first > key)
                r = mid - 1;
            else
                l = mid + 1;
            }

        if (flag) {
            return data_map_[mid].second;
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
    mapa.put(0, -9);
    mapa.put(5, 0);
    mapa.put(-1, 0);
    mapa.put(-2, 12);
    mapa.put(-3, -3);
    std::cout << mapa.get(2) << std::endl;
    std::cout << mapa.get(3) << std::endl;


    return 0;
}
