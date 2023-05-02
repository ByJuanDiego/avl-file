//
// Created by juandiego on 4/28/23.
//


#include "../inc/avl.hpp"
#include "../inc/record.hpp"

int main() {
    std::string heap_file = "./database/movies_and_series.dat";
    std::string index_file = "./database/avl_indexed_by_dataId.dat";

    std::function<int(MovieRecord &)> index = [](MovieRecord &movie) { return movie.dataId; };
    AVLFile<int, MovieRecord> avl(heap_file, index_file, true, index); // The dataId is a Primary Key

    int dataId;
    std::cout << "Enter the dataId: ";
    std::cin >> dataId;
    std::vector<MovieRecord> records = avl.search(dataId);
    for (MovieRecord &movie: records) {
        std::cout << movie.to_string() << std::endl;
    }
}
