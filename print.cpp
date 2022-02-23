void print_unordered_set_int(c){
    std::copy(c.begin(),
            c.end(),
            std::ostream_iterator<int>(std::cout, " aaa "));
}